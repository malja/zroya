[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Documentation Status](https://readthedocs.org/projects/zroya/badge/?version=master)](http://zroya.readthedocs.io/en/master/?badge=master)
[![PyPI version](https://badge.fury.io/py/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![PyPI status](https://img.shields.io/pypi/status/zroya.svg)](https://pypi.python.org/pypi/zroya/)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://gitHub.com/malja/zroya/graphs/commit-activity)

# zroya2
This branch is dedicated to developing new zroya version. V2 is a C/C++ module built around C++ [WinToast](https://github.com/mohabouje/WinToast). This way, native Windows notifications are supported and no taskbar icon is required for Toast notification.

Zroya2 is not stable yet so I would be grateful for testing, bug reports etc.

## Prerequisites

There are no requirements at the moment.

## Installation

Zroya2 is currently available only as a source code. Download source code, create virtual environment and run:

```python
python setup.py build
```

in /zroya/python. This will create build directory with zroya. 
Final version will be released to pypi.

## Example

```python

import zroya

# Initialize zroya module. Make sure to call this function.
# All parameters are required
zroya.init("YourAppName", "CompanyName", "ProductName", "SubProduct", "Version")

# Create notification template. TYPE_TEXT1 means one bold line withou image.
template = zroya.Template( zroya.Template.TYPE_TEXT1 )
# Set first line
template.firstLine("My First bold line")

# Save notification id for later use
notificationID = zroya.show(template)

# .. do something, maybe sleep?

# Hide notification
zroya.hide(notificationID)
```

## Documentation

You may find some limited documentation in source code. 

### zroya.init

```python
zroya.init(app_name, company_name, product_name, sub_product, version):
    """
    Initialize zroya module. You have to call it in full form as shown in example. If you don't, zroya will asign random values to each parameter.
    :param str app_name:
    :param str company_name:
    :param str product_name:
    :param str sub_product:
    :param str version:
    """
    pass
```

### zroya.show
```python
zroya.show(template):
    """
    Show template.
    :param zroya.Template template: Instance of Template class.
    :return: Positive notification ID on success, negative on failure.
    """
    pass
```

### zroya.hide
```python
zroya.show(id):
    """
    Hide already shown notification.
    :param integer id: Notification ID from zroya.show.
    :return: True/False
    """
    pass
```

### zroya.Template

Representation of Toast notification template.

```python
class Template(object):

    def _init_(type):
        """
        :param integer type: One of zroya.Template.TYPE_IMAGE_TEXT1 (Image and one string wrapped across three lines), TYPE_IMAGE_TEXT2 (A large image, one string of bold text on the first line, one string of regular text wrapped across the second and third lines),TYPE_IMAGE_TEXT3(A large image, one string of bold text wrapped across the first two lines, one string of regular text on the third line.),
        TYPE_IMAGE_TEXT4 (A large image, one string of bold text on the first line, one string of regular text on the second line, one string of regular text on the third line.), TYPE_TEXT1 (Single string wrapped across three lines of text.), TYPE_TEXT2 (One string of bold text on the first line, one string of regular text wrapped across the second and third lines.), TYPE_TEXT3 (One string of bold text wrapped across the first two lines, one string of regular text on the third line.), TYPE_TEXT4 (One string of bold text on the first line, one string of regular text on the second line, one string of regular text on the third line.)
        """
        pass

    def firstLine([text]):
        """
        :param str text: First line of text.
        :return: With _text_ set returns True/False. Without any parameter returns current first line.
        """

    def secondLine([text]):
        pass

    def thirdLine([text]):
        pass

    def audio([type, playback]):
        """
        Set audio file played when notification is activated and playback type.
        :param int type: One of zroya.Template.AUDIO_DEFAULT, AUDIO_IM, AUDIO_MAIL, AUDIO_REMINDER, AUDIO_SMS, AUDIO_ALARM, AUDIO_ALARM2, AUDIO_ALARM3, AUDIO_ALARM4, AUDIO_ALARM5, AUDIO_ALARM6, AUDIO_ALARM7, AUDIO_ALARM8, AUDIO_ALARM9, AUDIO_ALARM10, AUDIO_CALL, AUDIO_CALL2, AUDIO_CALL3, AUDIO_CALL4, AUDIO_CALL5, AUDIO_CALL6, AUDIO_CALL7, AUDIO_CALL8, AUDIO_CALL9, AUDIO_CALL10

        :param int playback: One of zroya.Template.AUDIO_TYPE_DEFAULT, AUDIO_TYPE_SILENCE, AUDIO_TYPE_LOOP.
        :return: True/False with type/playback set or string with current audio type.
        """
        pass

    def image([path]):
        """
        Set or get current path to notification image. Make sure current notification type supports image.
        :param str path: Path to image.
        :return: With path provided returns True/False. Without path, returns current image path (if any).
        """
        pass

    def expire([ms]):
        """
        Make notification to disappear after ms milliseconds. Set zero for no expiration.
        :param integer ms: Milliseconds from now.
        :return: With ms, returns True/False. Without it, returns current expire time.
        """
        pass
```