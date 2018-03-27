import python
import unittest


def on_click(id):
    pass


class zroya_show(unittest.TestCase):

    def test_NoParam(self):
        self.assertRaises(ValueError, python.show())

    def test_FewParams(self):
        self.assertRaises(ValueError, lambda: python.show(on_click=on_click))

    def test_BadType(self):
        self.assertRaises(ValueError, lambda: python.show(None))

    def test_ProperParams(self):
        t = python.Template(python.Template.TYPE_IMAGE_TEXT1)
        t.firstLine("Test")
        self.assertIsInstance(python.show(t), int)


if __name__ == "__main__":
    unittest.main()