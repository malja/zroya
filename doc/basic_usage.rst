.. _basic_usage:

===========
Basic Usage
===========

Install zroya package as described in :ref:`installation`.

After successful installation, import zroya into your project.

.. code-block:: python

    from zroya import TrayIcon

    nc = TrayIcon()
    nc.create("My Nofification", "Longer text with\nmultiline support")

This example creates simple notification with title, text and info icon. This may be sufficient, however what
if you would like to react to user clicking on your notification?

.. code-block:: python

    from zroya import TrayIcon

    exit = False

    def click_callback(data):
        global exit
        print("User clicked on notification")
        exit = True

    nc = TrayIcon()
    nc.create("My Nofification", "Longer text with\nmultiline support", on_click=click_callback)

    while nc.update():
        if exit:
            nc.quit()

Events
------

First of all, we defined ``click_callback`` function. It will be called
when user clicks on notification box. The only parameter is
dictionary with all data you used when creating this notification.

You have to **register** this callback function to notification when you call 
:py:meth:`zroya.TrayIcon.create` method as ``on_click`` parameter.

You may register four different events: ``on_click``, ``on_show``, ``on_hide``.
We already discussed ``on_click``. 

``on_show`` is called whenever notification is shown to user.
``on_hide`` should be called when user hide your notification.

Loop
----

Finally we move to :py:meth:`zroya.TrayIcon.update` method. You should call it from your
application's event loop. It basically pulls all waiting events, runs callbacks and returns True.
It is **non-blocking** however it needs to be called periodically for callback to be called as
soon as possible.

Without this function, events will never be fired!