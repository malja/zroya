import zroya
import unittest

class ModuleInit(unittest.TestCase):

    def test_module_init_NoParam(self):
        """
        Check that init function does require some parameters.
        Expecting init function to fail.
        """

        failed = False

        try:
            zroya.init()
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_init_FewParams(self):
        """
        Check init function behavior when too few parameters is provided.
        Expecting init function to fail.
        """

        failed = False

        try:
            zroya.init("a", "b")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_init_FewParamsKeywords(self):
        """
        Init module with keywoards, but omnit some.
        Expecting init function to work.
        """

        failed = False

        try:
            zroya.init(app_name="a", company_name="b")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_init_EmptyParams(self):
        """
        Make sure init function requires non-empty strings
        Expecting init function to fail.
        """

        failed = False

        try:
            zroya.init("", "", "", "", "")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_init_EmptyParamsKeywoards(self):
        """
        Make sure init function requires non-empty strings
        Expecting init function to fail.
        """

        failed = False

        try:
            zroya.init(app_name="", company_name="", product_name="", sub_product="", version="")
        except Exception as e:
            failed = True

        self.assertTrue(failed)



    def test_module_init_ProperInit(self):
        """
        Init module
        Expecting init function to work.
        """

        failed = False

        try:
            zroya.init("a", "b", "c", "d", "e")
        except Exception as e:
            failed = True

        self.assertFalse(failed)

    def test_module_init_ProperInitKeywords(self):
        """
        Init module with keywords
        Expecting init function to work.
        """

        failed = False

        try:
            zroya.init(app_name="a", company_name="b", product_name="c", sub_product="d", version="e")
        except Exception as e:
            failed = True

        self.assertFalse(failed)

if __name__ == "__main__":
    unittest.main()

