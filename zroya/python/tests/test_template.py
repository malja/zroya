import unittest
import zroya

class zroya_Template(unittest.TestCase):

    ### CONSTRUCTOR

    def test_constructor_EmptyParams(self):

        self.assertRaises(ValueError, lambda: zroya.Template())

    def test_constructor_InvalidParams(self):
        self.assertRaises(ValueError, lambda: zroya.Template(-1))

    def test_constructor_InvalidParams2(self):
        self.assertRaises(ValueError, lambda: zroya.Template(50))

    def test_constructor_ProperParams(self):
        self.assertIsInstance(zroya.Template(zroya.Template.TYPE_TEXT1), zroya.Template)

    ### FIRST LINE

    def test_firstLine_EmptyParams(self):
        template = zroya.Template(zroya.Template.TYPE_TEXT1)
        self.assertIsInstance(template.firstLine(), str)

    def test_firstLine_InvalidParams(self):
        template = zroya.Template(zroya.Template.TYPE_TEXT1)
        self.assertRaises(ValueError, lambda: template.firstLine(-1))

    def test_firstLine_ProperParams(self):
        template = zroya.Template(zroya.Template.TYPE_TEXT1)
        self.assertTrue(template.firstLine("Test"))

    ###