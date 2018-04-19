Callbacks
=========

In the previous part of the tutorial, action buttons were added. But they did nothing. In this tutorial,
I'll teach you how to make them alive.

But first I have to introduce you into zroya's callback system. Zroya registers four different events:

* **onClick** - Fired every time user clicks on notification.
* **onAction** - Activated when action button is clicked.
* **onDismiss** - When the notification is dismissed by user or automatically.
* **onFail** - Something went wrong.

If you want to be informed, when any of them happens, register event handler with **on_** parameters of
:py:func:`zroya.show`. Event handler is nothing more than a regular function taking one, or two parameters. Number of
parameters depends on the event you register for.

On Click
---------

On click handler takes one parameter and it is notification ID. This is the number you get as a return value from
:py:func:`zroya.show`.

.. code-block:: python

    def onClickHandler(notification_id):
        pass

On Action
---------

On Action handler takes two parameters, notification ID and action ID. Action ID is number returned by
:py:meth:`zroya.Template.addAction`.

.. code-block:: python

    def onActionHandler(notification_id, action_id):
        pass

On Dismiss
----------

On Dismiss handler is function with two parameters. First one is notification ID. The second one is
:py:class:`zroya.DismissReason`.

.. code-block:: python

    def onDismissHandler(notification_id, reason):
        pass

On Fail
-------

Last, on fail handler is function with one parameter, the same as on click callback. The parameter is notification ID
returned from :py:func:`zroya.show`.

.. code-block:: python

    def onFailHandler(notification_id):
        pass

Adding handlers
---------------

Let's go back a bit. In :doc:`template`, we created a notification for simple bot asking user "How are you?". Now
we add response to each of the action button.

.. code-block:: python

    import zroya
    import time

    # Initialization is required. But in real usage, check the return code, please.
    zroya.init("python", "a", "b", "c", "d")

    # Template for question
    ask_template = zroya.Template(zroya.TemplateType.ImageAndText4)
    ask_template.setFirstLine("Hi, I am NotifyBot.")
    ask_template.setSecondLine("It is nice to meet you.")
    ask_template.setThirdLine("How are you?")
    ask_template.setImage("./files/image.png")
    ask_template.addAction("I'm OK, I guess")
    ask_template.addAction("Fine")

    # Response for Fine
    fine_template = zroya.Template(zroya.TemplateType.Text1)
    fine_template.setFirstLine("Glad to hear that!")

    # Response for OK
    ok_template = zroya.Template(zroya.TemplateType.Text1)
    ok_template.setFirstLine("I'm sorry to hear that!")


    # prepare handler
    def onAction(nid, action_id):
        global fine_template, ok_template

        if action_id == 0:
            zroya.show(ok_template)
        else:
            zroya.show(fine_template)

    # Show question
    zroya.show(ask_template, on_action=onAction)

    # Keep application running, unless onAction handler is never executed.
    time.sleep(10)

Adding images to answers with emoticons, changing sounds etc. would take this to whole new level. You can always play
with it as you wish.

I owe you one more answer. How did I know that "I'm OK", gets action ID 0 and "Fine" is ID 1? See
:py:meth:`zroya.Template.addAction` ;) Now enjoy the result:

.. figure:: ../_static/tutorials_callbacks_final.gif
    :alt: Process of asking "How are you" followed with the response on me clicking on "I'm fine".

    Pretty impressive, isn't it?
