import zroya
import unittest


def on_click(id):
    pass


class zroya_show(unittest.TestCase):

    def test_NoParam(self):
        self.assertRaises(ValueError, zroya.show())

    def test_FewParams(self):
        self.assertRaises(ValueError, lambda: zroya.show(on_click=on_click))

    def test_BadType(self):
        self.assertRaises(ValueError, lambda: zroya.show(None))

    def test_ProperParams(self):
        t = zroya.Template(zroya.Template.TYPE_IMAGE_TEXT1 )
        t.firstLine("Test")
        self.assertIsInstance(zroya.show(t), int)


if __name__ == "__main__":
    unittest.main()