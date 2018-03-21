zroya documentation
=====================

`ZROYA <https://github.com/malja/zroya>`_ is a Python wrapper of win32 API for creating Windows notifications. 

Features:
---------

    - Creating Windows 10 notification.
    - No Sound support.
    - Events (click, hidden, shown).

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

    zroya.TrayIcon
    zroya.TrayIcon.create
    zroya.TrayIcon.quit
    zroya.TrayIcon.update


Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`