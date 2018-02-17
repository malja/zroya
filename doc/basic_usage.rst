.. _basic_usage:

===========
Basic Usage
===========

Install zroya package as described in :ref:`installation`.

After successful installation, import zroya into your project.

.. code-block:: python

    from zroya import NotificationCenter

    nc = NotificationCenter()
    nc.create("My Nofification", "Longer text with\nmultiline support")

This example creates simple notification with title, text and info icon. This may be sufficient, however what
if you would like to react to user clicking on your notification?

.. code-block:: python

    from zroya import NotificationCenter

    exit = False

    def click_callback(nid, data):
        global exit
        print("User clicked on notification")
        exit = True

    nc = NotificationCenter()
    nc.create("My Nofification", "Longer text with\nmultiline support", on_click=click_callback)

    while nc.update():
        if exit:
            nc.quit()

Notification ID
---------------

Before I dive into the source code written above, I would like to introduce you to concept of 
Notification IDs. It is a numerical representation of each created notification. Every time
you call :py:meth:`zroya.NotificationCenter.create`, unique number is returned.

.. code-block:: python

    # zroya is imported and NotificationCenter instance is in _nc_ variable
    nID = nc.create("Test", "Longer Test")
    print(nID) # Prints 1

It is completely up to you, what you decide to do with it. You may not even use it at all :).

Events
------

Now back to source code. First of all, we defined ``click_callback`` function. It will be called
when user clicks on notification box. First parameter is a notification ID and second one is
dictionary with all data you used when creating this notification.

You have to **register** this callback function to notification when you call 
:py:meth:`zroya.NotificationCenter.create` method as ``on_click`` parameter. 

You may register four different events: ``on_click``, ``on_show``, ``on_hide``, ``on_timeout``.
We already discussed ``on_click``. 

``on_show`` is called whenever notification is shown to user.
``on_hide`` should be called when user hide your notification. 
The last one, ``on_timeout`` is used as information that notification was shown to user for some period of time, however he/she
did not react to it. Notification like this ends up in Windows notification center.

Loop
----

Finally we move to :py:meth:`zroya.NotificationCenter.update` method. You should call it from your
application's event loop. It basically pulls all waiting events, runs callbacks and returns True.
It is **non-blocking** however it needs to be called periodically for callback to be called as
soon as possible.

Without this function, events will never be fired!