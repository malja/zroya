import unittest
import os
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
        self.assertIsInstance(zroya.Template(zroya.TemplateType.Text1), zroya.Template)

    ### FIRST LINE

    def test_setFirstLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.setFirstLine())

    def test_setFirstLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.setFirstLine(-1))

    def test_setFirstLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.setFirstLine("Test"))

    def test_getFirstLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.setFirstLine("Test")
        self.assertEqual(template.getFirstLine(), "Test")

    ### SECOND LINE
    
    def test_setSecondLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        self.assertRaises(TypeError, lambda: template.setSecondLine())
        
    def test_setSecondLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        self.assertRaises(TypeError, lambda: template.setSecondLine(-1))
        
    def test_setSecondLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        template.setFirstLine("Test")
        self.assertTrue(template.setSecondLine("Test Line 2"))

    def test_getSecondLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        template.setFirstLine("Test")
        template.setSecondLine("Test Line 2")
        self.assertEqual(template.getSecondLine(), "Test Line 2")

    def test_setSecondLine_UnsuportedTemplateType(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertFalse(template.setSecondLine("Test Line 2"))

    ### THIRD LINE
    def test_setThirdLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        self.assertRaises(TypeError, lambda: template.setThirdLine())

    def test_setThirdLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        self.assertRaises(TypeError, lambda: template.setThirdLine(-1))

    def test_setThirdLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        template.setFirstLine("Test")
        template.setSecondLine("Test2")
        self.assertTrue(template.setThirdLine("Test Line 3"))

    def test_getThirdLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        template.setThirdLine("Test Line 3")
        self.assertEqual(template.getThirdLine(), "Test Line 3")

    def test_thirdLine_UnsuportedTemplateType(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertFalse(template.setThirdLine("Test Line 2"))

    ### Expire

    def test_setExpiration_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.setExpiration("Test"))

    def test_setExpiration_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.setExpiration())

    def test_setExpire_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.setExpiration(10))

    def test_getExpiration_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.setExpiration(10)
        self.assertEqual(template.getExpiration(), 10)

    ### AUDIO

    def test_setAudio_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(ValueError, lambda: template.setAudio(-1))

    def test_setAudio_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.setAudio())

    def test_setAudio_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.setAudio(zroya.Audio.Mail))

    def test_setAudio_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.setAudio(audio=zroya.Audio.Mail, mode=zroya.AudioMode.Loop))

    def test_getAudio_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.setAudio(zroya.Audio.IM, zroya.AudioMode.Silence)
        self.assertEqual(template.getAudio(), zroya.Audio.IM)

    ### IMAGE

    def test_setImage_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertRaises(ValueError, lambda: template.setImage(-1))

    def test_setImage_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertRaises(TypeError, lambda: template.setImage())

    def test_setImage_FileDoesNotExist(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertRaises(FileNotFoundError, lambda: template.setImage("./non_existing_file.png"))

    def test_setImage_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertTrue(template.setImage("./tests/files/image.png"))

    def test_getImage_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        path = os.path.abspath("./tests/files/image.png")
        template.setImage(path)
        self.assertEqual(template.getImage(), path)
