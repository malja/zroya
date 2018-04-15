import zroya
import time
import unittest


def action_handler(notification_index, action_index):
    """
    This is a callback function for onAction event. It is called when user clicks on an action button attached to the
    notification.

    :param notification_index:  Index of notification in which event occurred.
    :param action_index:        Index of clicked action. Indexes start from zero (first action) and increase as you add more
                                actions.
    """

    print("Notification with ID={} was activated. User clicked on action with index={}.".format(
        notification_index, action_index
    ))


class TestTemplateActions(unittest.TestCase):

    def test_basic_action_handler(self):

        # Make sure zroya is initialized
        status = zroya.init(app_name="a", company_name="b", product_name="c", sub_product="d", version="e")

        self.assertTrue(status)

        # Create a template with two lines of text
        template = zroya.Template(zroya.TemplateType.Text1)

        self.assertIsInstance(template, zroya.Template)

        # Add text to it
        template.setFirstLine("My first line is there")
        template.setSecondLine("My second line is super catchy.")

        # Add actions
        first_action_index = template.addAction("Click me!")
        second_action_index = template.addAction("Don't click me!")

        self.assertEqual(first_action_index, 0)
        self.assertEqual(second_action_index, 1)

        print("Index first index={}, second index={}".format(first_action_index, second_action_index))

        # Create a notification with on_action callback attached.
        status = zroya.show(template, on_action=action_handler)

        self.assertTrue(status)

        # Make sure application runs for a while
        time.sleep(5)

if __name__ == "__main__":
    unittest.main()
