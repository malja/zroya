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
        self.assertIsInstance(zroya.Template(zroya.TemplateType.Text1), zroya.Template)

    ### FIRST LINE

    def test_firstLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertIsInstance(template.firstLine(), str)

    def test_firstLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(ValueError, lambda: template.firstLine(-1))

    def test_firstLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.firstLine("Test"))

    def test_firstLine_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.firstLine("Test")
        self.assertEqual(template.firstLine(), "Test")

    ### SECOND LINE
    
    def test_secondLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        self.assertIsInstance(template.secondLine(), str)
        
    def test_secondLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        self.assertRaises(ValueError, lambda: template.secondLine(-1))
        
    def test_secondLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        template.firstLine("Test")
        self.assertTrue(template.secondLine("Test Line 2"))

    def test_secondLine_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.Text2)
        template.firstLine("Test")
        template.secondLine("Test Line 2")
        self.assertEqual(template.secondLine(), "Test Line 2")

    def test_secondLine_UnsuportedTemplateType(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.firstLine("Test")
        self.assertFalse(template.secondLine("Test Line 2"))

    ### THIRD LINE
    def test_thirdLine_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        self.assertIsInstance(template.thirdLine(), str)

    def test_thirdLine_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        self.assertRaises(ValueError, lambda: template.thirdLine(-1))

    def test_thirdLine_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text4)
        template.firstLine("Test")
        template.secondLine("Test2")
        self.assertTrue(template.thirdLine("Test Line 3"))

    def test_thirdLine_UnsuportedTemplateType(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertFalse(template.thirdLine("Test Line 2"))

    ### Expire

    def test_expire_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(TypeError, lambda: template.expire("Test"))

    def test_expire_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertEqual(template.expire(), 0)

    def test_expire_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.expire(10))

    def test_expire_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.expire(10)
        self.assertEqual(template.expire(), 10)

    ### AUDIO

    def test_audio_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertRaises(ValueError, lambda: template.audio(-1))

    def test_audio_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        # TODO: Upravit
        print(template.audio())

    def test_audio_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.audio(zroya.Audio.Mail))

    def test_audio_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.audio(audio=zroya.Audio.Mail, mode=zroya.AudioMode.Loop))

    def test_audio_ProperParams3(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        self.assertTrue(template.audio(mode=zroya.AudioMode.Loop))

    def test_audio_ProperParams4(self):
        template = zroya.Template(zroya.TemplateType.Text1)
        template.audio(zroya.Audio.IM, zroya.AudioMode.Silence)
        self.assertEqual(template.audio(), "ms-winsoundevent:Notification.IM")

    ### IMAGE

    def test_image_InvalidParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertRaises(ValueError, lambda: template.image(-1))

    def test_image_EmptyParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        # TODO: Upravit
        print(template.image())

    def test_image_FileDoesNotExist(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertRaises(FileNotFoundError, lambda: template.image("./non_existing_file.png"))

    def test_image_ProperParams(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        self.assertTrue(template.image("./files/image.png"))

    def test_audio_ProperParams2(self):
        template = zroya.Template(zroya.TemplateType.ImageAndText1)
        template.image("./files/image.png")
        self.assertEqual(template.image(), "./files/image.png")
