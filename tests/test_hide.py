import python
import unittest

class zroya_hide(unittest.TestCase):

    def test_NoParam(self):
        self.assertRaises(ValueError, lambda: python.hide())

    def test_BadType(self):
        self.assertRaises(ValueError, lambda: python.hide("test"))

    def test_NegativeId(self):
        self.assertRaises(ValueError, lambda: python.hide(-1))

    def test_ProperParam(self):
        t = python.Template(python.Template.TYPE_TEXT1)
        nid = python.show(t)
        self.assertTrue(python.hide(nid))

    def test_ProperParamKeywords(self):
        t = python.Template(python.Template.TYPE_TEXT1)
        notID = python.show(t)
        self.assertTrue(python.hide(nid=notID))


if __name__ == "__main__":
    unittest.main()
