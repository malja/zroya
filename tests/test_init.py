import zroya
import unittest

class zroya_init(unittest.TestCase):

    def test_NoParam(self):
        self.assertRaises(ValueError, lambda: zroya.init())

    def test_FewParams(self):
        self.assertRaises(ValueError, lambda: zroya.init("a", "b"))

    def test_FewParamsKeywords(self):
        self.assertRaises(ValueError, lambda: zroya.init(app_name="a", company_name="b"))

    def test_EmptyParams(self):
        self.assertRaises(ValueError, lambda: zroya.init("", "", "", "", ""))

    def test_EmptyParamsKeywoards(self):
        self.assertRaises(ValueError, lambda: zroya.init(
            app_name="", company_name="", product_name="", sub_product="", version="")
        )

    def test_ProperInit(self):
        self.assertTrue(zroya.init("a", "b", "c", "d", "e"))

    def test_ProperInitKeywords(self):
        self.assertTrue(zroya.init(app_name="a", company_name="b", product_name="c", sub_product="d", version="e"))

if __name__ == "__main__":
    unittest.main()

