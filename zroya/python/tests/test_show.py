import zroya
import unittest

def on_click(id):
    pass

class ModuleShow(unittest.TestCase):

    def test_module_show_NoParam(self):
        """
        Show function requires some parameters.
        Expecting show function to fail.
        """

        failed = False

        try:
            zroya.show()
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_show_FewParams(self):
        """
        Show function requires template parameter.
        Expecting show function to fail.
        """

        failed = False

        try:
            zroya.show( on_click=on_click)
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_show_BadType(self):
        """
        Show function requires template parameter to be of zroya.Template type
        Expecting show function to fail.
        """

        failed = False

        try:
            zroya.show( None )
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_module_show_ProperParams(self):
        """
        Proper call of show function
        Expecting show function to fail.
        """

        failed = False

        t = zroya.Template(zroya.Template.TYPE_IMAGE_TEXT1 )
        t.firstLine("Test")

        try:
            zroya.show( t )
        except Exception as e:
            failed = True

        self.assertFalse(failed)

if __name__ == "__main__":
    unittest.main()