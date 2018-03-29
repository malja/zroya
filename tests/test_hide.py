import zroya
import unittest

class zroya_hide(unittest.TestCase):

    def test_NoParam(self):
        self.assertRaises(TypeError, lambda: zroya.hide())

    def test_BadType(self):
        self.assertRaises(ValueError, lambda: zroya.hide("test"))

    def test_NegativeId(self):
        self.assertRaises(ValueError, lambda: zroya.hide(-1))

    def test_ProperParam(self):
        nid = zroya.show(t)
        self.assertTrue(zroya.hide(nid))

    def test_ProperParamKeywords(self):
        notID = zroya.show(t)
        self.assertTrue(zroya.hide(nid=notID))


if __name__ == "__main__":
    unittest.main()
