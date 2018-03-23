import zroya
import unittest

class zroya_init(unittest.TestCase):

    def test_NoParam(self):
        """
        Check that init function does require some parameters.
        exception
        """

        failed = False

        try:
            zroya.init()
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_FewParams(self):
        """
        Check init function behavior when too few parameters is provided.
        exception
        """

        failed = False

        try:
            zroya.init("a", "b")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_FewParamsKeywords(self):
        """
        Init module with keywoards, but omnit some.
        exception
        """

        failed = False

        try:
            zroya.init(app_name="a", company_name="b")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_EmptyParams(self):
        """
        Make sure init function requires non-empty strings
        exception
        """

        failed = False

        try:
            zroya.init("", "", "", "", "")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_EmptyParamsKeywoards(self):
        """
        Make sure init function requires non-empty strings
        exception
        """

        failed = False

        try:
            zroya.init(app_name="", company_name="", product_name="", sub_product="", version="")
        except Exception as e:
            failed = True

        self.assertTrue(failed)



    def test_ProperInit(self):
        """
        Init module
        true
        """

        self.assertTrue(zroya.init("a", "b", "c", "d", "e"))

    def test_ProperInitKeywords(self):
        """
        Init module with keywords
        true
        """

        self.assertTrue(zroya.init(app_name="a", company_name="b", product_name="c", sub_product="d", version="e"))

if __name__ == "__main__":
    unittest.main()

