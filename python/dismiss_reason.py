class DismissReason(object):

    """
    This class represents a notification dismiss reason. It is passed to callback registered in on_dismiss parameter
    of zroya.show function.

    You can print it to get a reason description or compare it with any of following attributes.

    Attributes:
    -----------

    User    - The user dismissed the toast.
    App     - The application hid the toast using zroya.hide.
    Expired - The toast has expired.
    """

    User = 0
    App = 1
    Expired = 2

    def __init__(self, reason):
        """
        Create an instance of dismiss reason. Zroya uses this class to return a dismiss reason of notification back to
        python callback. For instance, when you create a notification with on_dismiss callback set:

            def myDismissCallback(notificationID, reason):
                print("Notification {} was dismissed by user. Reason: {}.".format(notificationID, reason))

           # t is an instance of zroya.Template
           zroya.show(t, on_dismiss = myCallback)

        this class will be used as a second parameter 'reason'. Since this is kind of C->Python bridge class, you
        will probably never create an instance of it.

        :param int reason: Integer representation of C dismiss reason.
        """

        self._reason = reason

    def __str__(self):

        # Make sure, numbers corresponds with actual dismiss reasons from Windows core:
        # Search ToastDismissalReason::ToastDismissalReason_UserCanceled in wintoastlib.h

        if self._reason == DismissReason.User:
            return "The user dismissed the toast."
        if self._reason == DismissReason.App:
            return "The application hid the toast using zroya.hide."
        if self._reason == DismissReason.Expired:
            return "The toast has expired."

        return "Unknown dismiss reason. If you are seeing this, please report it as a bug. Thank you."

    def __eq__(self, other):
        if isinstance(other, int):
            return other == self._reason

        return False

    def __ne__(self, other):
        return not other == self
