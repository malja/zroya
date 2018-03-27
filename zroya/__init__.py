import threading
import logging
import os
import time

# Read the docs does not work with pypiwin32. Import it only
# for local build.
if os.environ.get('READTHEDOCS') != 'True':
    from win32api import GetModuleHandle
    from win32con import *
    from win32gui import *
else:
    # Import kind of mock for Read the Docs
    from .read_the_docs import *


class TrayIcon(object):
    """
    TrayIcon represents an application icon. You may add one bubble notification.
    """

    NOTIFICATION_EVENT = WM_USER + 1  #: Event ID for all events associated with notifications.
    EVENT_BALLOON_SHOW = WM_USER + 2  #: Event ID fired when notification is created.
    EVENT_BALLOON_HIDE = WM_USER + 4  #: Event ID used when notification is hidden from code.
    EVENT_BALLOON_TIMEOUT = WM_USER + 3 #: Event ID for notification with expired timeout.
    EVENT_BALLOON_CLICK = WM_USER + 5  #: Event ID used when user clicks on notification.

    ICON_INFO = NIIF_INFO  #: This could be passed as icon parameter of create method. In this case, info icon is used.
    ICON_WARNING = NIIF_WARNING  #: This could be passed as icon parameter of create method. It will use warning icon.
    ICON_ERROR = NIIF_ERROR  #: This could be passed as icon parameter of create method. It will use error icon.

    def __init__(self):

        # Current bubble data
        self._bubble = None

        self.logger = logging.getLogger("zroya")

        # Event mapping. Keys is event type and value callback function.
        self._event_map = {
            WM_DESTROY: self.quit,
        }

        # Create window
        self._window_class = WNDCLASS()
        self._window_class.lpszClassName = str("Notification")
        self._window_class.lpfnWndProc = self._eventLoop
        self._class = RegisterClass(self._window_class)
        self._handle = GetModuleHandle(None)

        self._window = CreateWindow(self._class, "Notification", 0,
            0, 0, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, self._handle, None
        )

        # Draw window
        UpdateWindow(self._window)

        self.logger.debug("TrayIcon created.")

    def quit(self):
        """
        Ends notification event loop.

        :returns: Nothing.
        """

        DestroyWindow(self._window)
        UnregisterClass(self._window_class.lpszClassName, None)
        PostQuitMessage(0)
        self.logger.debug("TrayIcon is going to quit.")

    def update(self):
        """
        Polls all waiting events. This function should be called periodically in event loop. It polls all
        waiting events from queue and calls corresponding callbacks.

        :returns: False when notification center was shut down. True otherwise.
        """
        return PumpWaitingMessages() == 0

    def create(self, title, message, icon=None, sound=True, on_click=None, on_show=None, on_hide=None ):
        """
        Shows notification. All callback functions take two parameters. First one is integer with notification ID,
        second is dict with parameters used for creation (title, message, icon).

        :param str          title:      Notification title.
        :param str          message:    Short notification text.
        :param str/int      icon:       Path to the icon file or one of TrayIcon.ICON_*. Use None for info icon.
        :param bool         sound:      Should sound be played when notification appears?
        :param callable     on_click:   On click callback. Called when user clicks on notification.
        :param callable     on_show:    On show callback. Called when notification is shown.
        :param callable     on_hide:    On hide callback. Called when notification is hidden by user.
        :returns: Notification ID.
        """

        if not icon:
            icon = TrayIcon.ICON_INFO

        # Hide current bubble
        if self._bubble:
            self.hide()
            return False

        # Create thread with notification
        threading.Thread(target=self._create, kwargs={
            "window": self._window,
            "title": title,
            "message": message,
            "icon_param": icon,
            "sound": sound,
            "logger": self.logger,
        }).start()

        self.logger.debug("Notification created.")

        # Create notification info.
        self._bubble = {
            TrayIcon.EVENT_BALLOON_CLICK: on_click,
            TrayIcon.EVENT_BALLOON_SHOW: on_show,
            TrayIcon.EVENT_BALLOON_HIDE: on_hide,
            "data": {
                "title": title,
                "message": message,
                "icon": icon,
                "sound": sound,
            },
            "shown": False
        }

        return True

    def hide(self):
        """
        Remove notification. If notification was not shown yet, return false.
        :return: True if notification was hidden, False otherwise.
        """

        # There is not bubble at the moment.
        if not self._bubble:
            return True

        # Can not hide notification before it is shown
        if not self._bubble["shown"]:
            return False

        # Remove notification from system
        data = (self._window, 0)
        Shell_NotifyIcon(NIM_DELETE, data)

        # Trigger hide event
        PostMessage(self._window, TrayIcon.NOTIFICATION_EVENT, 0, TrayIcon.EVENT_BALLOON_HIDE)

    def _create(self, window, title, message, logger, icon_param=None, sound=True):
        """
        Representation of notification thread.

        :param window: Window instance.
        :param title: Notification title.
        :param message: Notification text.
        :param timeout: Notification timeout.
        :param icon_param: Notification icon path or one of TrayIcon.ICON_*. Only .ICO and .BMP formats are
        supported.
        :returns: Nothing.
        """

        # Flags for notification
        flags = NIF_MESSAGE

        # Flags used for default icons (Error, Info, Warning) and no sound parameter.
        additional_flags = 0

        icon = None

        # Is path used?
        if icon_param:
            if type(icon_param) == str:
                flags |= NIF_ICON

                # Load icon from file
                try:
                    icon = LoadImage(
                        None,
                        icon_param,
                        IMAGE_ICON, 0, 0,
                        LR_LOADFROMFILE | LR_DEFAULTSIZE
                    )
                    logger.debug("Icon loaded.")

                except Exception as e:
                    # Use info icon as default
                    additional_flags |= TrayIcon.ICON_INFO
                    logger.warning(
                        "Unable to load icon {} for notification. Using info icon instead. Error: {}"
                            .format(icon_param, e)
                    )

            # Set one of predefined icons
            elif type(icon_param) == int:
                logger.debug("Using default icon {} for notification.".format(icon_param))
                additional_flags |= icon_param

        else:
            logger.debug("Using default icon {} for notification.".format(icon_param))
            additional_flags |= TrayIcon.ICON_INFO

        # Disable sound effect
        if not sound:

            logger.debug("Sound effect disabled for notification.")
            additional_flags |= NIIF_NOSOUND

        # Create tray icon notification
        nid = (window, 0, flags, TrayIcon.NOTIFICATION_EVENT, icon, "Tooltip")
        Shell_NotifyIcon(NIM_ADD, nid)

        # Create notification
        Shell_NotifyIcon(NIM_MODIFY, (
            window, 0, NIF_INFO,
            TrayIcon.NOTIFICATION_EVENT,
            icon,
            "Tooltip",
            message,
            0,
            title,
            additional_flags
        ))

        logger.debug("Notification created.")

    def _onNotificationEvent(self, notification_id, event_id):
        """
        Calls notification callback when needed.

        :param int  notification_id:    ID of notification which created event.
        :param int  event_id:           Event ID (one of TrayIcon.EVENT_*.
        :return: Number one.
        """

        # Handle non-existing notification
        if not self._bubble:
            return False

        notification_data = self._bubble

        # Is there callback handler
        if event_id in notification_data and callable(notification_data[event_id]):
            # Call it
            notification_data[event_id](notification_data)
            self.logger.info(
                "Callback for notification with event {} called.".format(event_id)
            )
        else:
            self.logger.info("No callback for notification with event {}".format(event_id))

        # Handle event on our own
        if event_id == TrayIcon.EVENT_BALLOON_HIDE:
            self._bubble = None

        return True

    def _eventLoop(self, window, event, w_param, l_param):
        """
        Custom representation of event loop. It separates events created within notifications and calls corresponding
        callbacks.

        :param window: Windows instance?
        :param int  event: Event type.
        :param int  w_param: First parameter. In case of notification event, it contains notification ID.
        :param int  l_param: Second parameter. In case of notification event, it contains event ID.
        :return: ??.
        """

        # Handle events for notifications
        if event == TrayIcon.NOTIFICATION_EVENT:
            return self._onNotificationEvent(w_param, l_param)

        # Handle rest of the events
        return DefWindowProc(window, event, w_param, l_param)

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.quit()

__ALL__ = ["TrayIcon"]
