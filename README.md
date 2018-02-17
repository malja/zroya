[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Documentation Status](https://readthedocs.org/projects/zroya/badge/?version=master)](http://zroya.readthedocs.io/en/master/?badge=master)
[![PyPI version](https://badge.fury.io/py/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![PyPI status](https://img.shields.io/pypi/status/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://gitHub.com/malja/zroya/graphs/commit-activity)

# zroya
Zroya is python wrapper around win32 API for creating Windows notification. See [Read The Docs documentation](http://zroya.readthedocs.io).

## Prerequisites

Zroya requires you to install ``pypiwin32``.

```
> pip install pypiwin32
```

## Installation

Zroya is available from pypi:

```
> pip install zroya
```

## Example

```python

# Import NotificationCenter
from zroya import NotificationCenter

quit = False

# This function is called when user clicks on notification
def click_callback(nid, data):
    global quit

    print("User clicked on your notification!")
    quit = True

# Create instance of NotificationCenter
nc = NotificationCenter()

# Create new notification
nc.create("Test Notification", "Longer notification description. \n With multiline support!", on_click = click_callback)

# Update function should be called in your event loop. In this example, we will create our own event loop:
while nc.update():
    if quit:
        nc.quit()
```

## In action

You may use one for three predefined notification types:

**NotificationCenter.ICON_INFO**

```python
nc.create("Info notification", "This is informative notification.\nClick on me!", icon=NotificationCenter.ICON_INFO)
```

![Info notification][info_notification]

**NotificationCenter.ICON_WARNING**

```python
nc.create("Warning notification", "This is warning notification.\nClick on me for sure!", icon=NotificationCenter.ICON_WARNING)
```

![Warning notification][warning_notification]

**NotificationCenter.ICON_ERROR**

```python
nc.create("Error", "This is error notification.\nDo not click me, you would find out!", icon=NotificationCenter.ICON_ERROR)
```

![Error notification][error_notification]

**Custom icon**

Or pass an absolute path to .ICO file as ``icon`` parameter and use whatever icon you like.

**Notification center**

All notifications are automatically added to Windows 10 notification center after timeout:
![Windows 10 notification center example][notification_center]

[info_notification]: https://github.com/malja/zroya/blob/master/doc/static/info_notification.png "Info notification"
[warning_notification]: https://github.com/malja/zroya/blob/master/doc/static/warning_notification.png "Warning notification"
[error_notification]: https://github.com/malja/zroya/blob/master/doc/static/error_notification.png "Error notification"
[notification_center]: https://github.com/malja/zroya/blob/master/doc/static/notification_center.png "Windows 10 notification center"
