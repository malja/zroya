import unittest
import python

class zroya_Template(unittest.TestCase):

    ### CONSTRUCTOR

    def test_constructor_EmptyParams(self):

        self.assertRaises(ValueError, lambda: python.Template())

    def test_constructor_InvalidParams(self):
        self.assertRaises(ValueError, lambda: python.Template(-1))

    def test_constructor_InvalidParams2(self):
        self.assertRaises(ValueError, lambda: python.Template(50))

    def test_constructor_ProperParams(self):
        self.assertIsInstance(python.Template(python.Template.TYPE_TEXT1), python.Template)

    ### FIRST LINE

    def test_firstLine_EmptyParams(self):
        template = python.Template(python.Template.TYPE_TEXT1)
        self.assertIsInstance(template.firstLine(), str)

    def test_firstLine_InvalidParams(self):
        template = python.Template(python.Template.TYPE_TEXT1)
        self.assertRaises(ValueError, lambda: template.firstLine(-1))

    def test_firstLine_ProperParams(self):
        template = python.Template(python.Template.TYPE_TEXT1)
        self.assertTrue(template.firstLine("Test"))

    ###