import zroya
import unittest

class zroya_hide(unittest.TestCase):

    def test_NoParam(self):
        """
        hide function require notification ID as paramater
        exception
        """

        failed = False

        try:
            zroya.hide()
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_BadType(self):
        """
        hide function requires ID to be an integer
        exception
        """

        failed = False

        try:
            zroya.hide("test")
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_NegativeId(self):
        """
        hide function requires ID to be positive
        exception
        """

        try:
            zroya.hide(-1)
        except Exception as e:
            failed = True

        self.assertTrue(failed)

    def test_ProperParam(self):
        """
        hide notification
        true
        """

        t = zroya.Template(zroya.Template.TYPE_TEXT1)
        nid = zroya.show(t)

        self.assertTrue(zroya.hide(nid))

    def test_ProperParamKeywords(self):

        t = zroya.Template(zroya.Template.TYPE_TEXT1)
        notID = zroya.show(t)

        self.assertTrue(zroya.hide(nid=notID))


if __name__ == "__main__":
    unittest.main()
