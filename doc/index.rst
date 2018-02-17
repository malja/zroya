zroya documentation
=====================

`ZROYA <https://github.com/malja/zroya>`_ is a Python wrapper of win32 API for creating Windows notifications. 

Features:
---------

    - Creating Windows 10 notification.
    - No Sound support.
    - Events (click, timeout, hidden).

Requires:
---------

Zroya requires `pypiwin32 <https://pypi.python.org/pypi/pypiwin32>`_ library to work properly. See: :ref:`installation`.

User guide
----------

.. toctree::
    :maxdepth: 2

    installation
    basic_usage
    examples
    reference

Reference
---------

.. autosummary::
    :nosignatures:

    zroya.NotificationCenter
    zroya.NotificationCenter.create
    zroya.NotificationCenter.quit
    zroya.NotificationCenter.update


Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`