[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# zroya
Zroya is python wrapper around win32 API for creating Windows notification.

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

