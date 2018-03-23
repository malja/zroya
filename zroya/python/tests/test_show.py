import zroya
import unittest

def on_click(id):
    pass

class zroya_show(unittest.TestCase):

    def test_NoParam(self):
        """
        Show function requires some parameters.
        exception
        """

        failed = False

        try:
            zroya.show()
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_FewParams(self):
        """
        Show function requires template parameter.
        exception
        """

        failed = False

        try:
            zroya.show( on_click=on_click)
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_BadType(self):
        """
        Show function requires template parameter to be of zroya.Template type
        exception
        """

        failed = False

        try:
            zroya.show( None )
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_ProperParams(self):
        """
        Proper call of show function
        integer
        """

        t = zroya.Template(zroya.Template.TYPE_IMAGE_TEXT1 )
        t.firstLine("Test")

        self.assertIsInstance( zroya.show(t), int)

if __name__ == "__main__":
    unittest.main()