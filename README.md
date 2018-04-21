[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PyPI version](https://badge.fury.io/py/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![PyPI status](https://img.shields.io/pypi/status/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://gitHub.com/malja/zroya/graphs/commit-activity)

# zroya2
This branch is dedicated to developing new zroya version. V2 is a C/C++ module built around C++ [WinToast](https://github.com/mohabouje/WinToast). This way, native Windows notifications are supported and no taskbar icon is required for Toast notification.

Zroya2 is in beta testing. I would be grateful for any bug reports.

## Prerequisites

There are no requirements at the moment.

## Installation

Zroya2 is now available from pypi:

```
python -m pip install zroya
```

## Example

```python

import zroya

# Initialize zroya module. Make sure to call this function.
# All parameters are required
zroya.init("YourAppName", "CompanyName", "ProductName", "SubProduct", "Version")

# Create notification template. TYPE_TEXT1 means one bold line withou image.
template = zroya.Template( zroya.TemplateType.Text1 )
# Set first line
template.setFirstLine("My First line")

# Save notification id for later use
notificationID = zroya.show(template)

# .. do something, maybe sleep?

# Hide notification
zroya.hide(notificationID)
```

## Documentation

You may find some limited documentation on [Zroya Page](https://malja.github.io/zroya)
