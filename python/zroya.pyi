class Template:
	"""
	Notification template. You may show instance of template via zroya.show function.
	"""

	AUDIO_ALARM = 5

	AUDIO_ALARM10 = 14

	AUDIO_ALARM2 = 6

	AUDIO_ALARM3 = 7

	AUDIO_ALARM4 = 8

	AUDIO_ALARM5 = 9

	AUDIO_ALARM6 = 10

	AUDIO_ALARM7 = 11

	AUDIO_ALARM8 = 12

	AUDIO_ALARM9 = 13

	AUDIO_CALL = 15

	AUDIO_CALL10 = 24

	AUDIO_CALL2 = 16

	AUDIO_CALL3 = 17

	AUDIO_CALL4 = 18

	AUDIO_CALL5 = 19

	AUDIO_CALL6 = 20

	AUDIO_CALL7 = 21

	AUDIO_CALL8 = 22

	AUDIO_CALL9 = 23

	AUDIO_DEFAULT = 0

	AUDIO_IM = 1

	AUDIO_MAIL = 2

	AUDIO_REMINDER = 3

	AUDIO_SMS = 4

	AUDIO_TYPE_DEFAULT = 0

	AUDIO_TYPE_LOOP = 2

	AUDIO_TYPE_SILENCE = 1

	TYPE_IMAGE_TEXT1 = 0

	TYPE_IMAGE_TEXT2 = 1

	TYPE_IMAGE_TEXT3 = 2

	TYPE_IMAGE_TEXT4 = 3

	TYPE_TEXT1 = 4

	TYPE_TEXT2 = 5

	TYPE_TEXT3 = 6

	TYPE_TEXT4 = 7

	def audio(self, audio=None, mode=None):
		"""
		Set audio to be played and playback type or return current audio. 
		:param int audio: One of zroya.Template.AUDIO_* property. 
		:param int mode: One of zroya.Template.AUDIO_TYPE_* property. 
		:return: With _audio_ parameter provided, it sets new audio. In addition, if _type_ parameter is set, playback type is changed. Otherwise default playback type is used. True/False is returned.
		 Without _audio_ parameter set, current audio is returned.
		"""
		pass

	def expire(self, ms=0):
		"""
		Set or return expiration time in milliseconds. 
		:param int ms: Number of milliseconds for expiration time. Zero means no expiration. 
		:return: If you set _ms_ parameter to any positive integer, expiration time is set. Without any parameter, current expiration time is returned.
		"""
		pass

	def firstLine(self, text=None):
		"""
		Set or return first line of notification text. 
		:param str text: Text to be set as the first line. 
		:return: With _text_ parameter set, returns True/False. Without _text_, current first line is returned.
		"""
		pass

	def image(self, path=None):
		"""
		Set or return notification image path. 
		:param str path: Path to image. 
		:return: With _path_ parameter set, it returns True/False. Without _text_, current image path is returned.
		"""
		pass

	def secondLine(self, text=None):
		"""
		Set or return second line of notification text. 
		:param str text: Text to be set as the second line. 
		:throw: ValueError if second line is not supported by selected notification type. 
		:return: With _text_ parameter set, returns True/False. Without _text_, current second line is returned.
		"""
		pass

	def thirdLine(self, text=None):
		"""
		Set or return third line of notification text. 
		:param str text: Text to be set as the third line. 
		:throw: ValueError if third line is not supported by selected notification type. 
		:return: With _text_ parameter set, returns True/False. Without _text_, current third line is returned.
		"""
		pass

def hide(nid):
	"""
	Hide notification by ID. 
	:param integer nid: Notification ID obtained from zroya.show function. 
	:return: True if notification was hidden, false otherwise.
	"""
	pass

def init(app_name, company_name, product_name, sub_product, version):
	"""
	Initialize Zroya module. You should call this function before any other manipulation with this module. 
	If you do not call this function explicitely, randomly generated strings will be used as default parameters. 
	:param str app_name: Application name. 
	:param str company_name: Part of unique ID created for this application. 
	:param str product_name: Part of unique ID created for this application. 
	:param str sub_product: Part of unique ID created for this application. 
	:param str version: Part of unique ID created for this application. 
	:return: True if initialization is completed, False otherwise.
	"""
	pass

def show(template, on_click=None, on_action=None, on_dismiss=None, on_fail=None):
	"""
	Show selected notification template. If any of on_* parameter is set, corresponding event is registered. 
	:param zroya.Template template: Template instance. 
	:param callable on_click: Callback for OnClick event. Occurs when user activates a toast notification through a click or touch. 
	:param callable on_action: Callback for OnAction event. Occurs when user click toast notification action button. 
	:param callable on_dismiss: Callback for OnDismiss event. Occurs when a toast notification leaves the screen, either by expiring or being explicitly dismissed by the user. 
	:param callable on_fail: Callback for OnFail event. Occurs when an error is caused when Windows attempts to raise a toast notification. 
	:return: Notification ID if notification was shown. False otherwise.
	"""
	pass

class Audio:
	"""
	
    This enumeration contains all accepted values for parameter _audio_ of zroya.Template.audio method.
    Usage: template.audio(audio=zroya.Audio.IM)
    
	"""

	Alarm = "ms-winsoundevent:Notification.Looping.Alarm"

	Alarm10 = "ms-winsoundevent:Notification.Looping.Alarm10"

	Alarm2 = "ms-winsoundevent:Notification.Looping.Alarm2"

	Alarm3 = "ms-winsoundevent:Notification.Looping.Alarm3"

	Alarm4 = "ms-winsoundevent:Notification.Looping.Alarm4"

	Alarm5 = "ms-winsoundevent:Notification.Looping.Alarm5"

	Alarm6 = "ms-winsoundevent:Notification.Looping.Alarm6"

	Alarm7 = "ms-winsoundevent:Notification.Looping.Alarm7"

	Alarm8 = "ms-winsoundevent:Notification.Looping.Alarm8"

	Alarm9 = "ms-winsoundevent:Notification.Looping.Alarm9"

	Call = "ms-winsoundevent:Notification.Looping.Call"

	Call10 = "ms-winsoundevent:Notification.Looping.Call10"

	Call2 = "ms-winsoundevent:Notification.Looping.Call2"

	Call3 = "ms-winsoundevent:Notification.Looping.Call3"

	Call4 = "ms-winsoundevent:Notification.Looping.Call4"

	Call5 = "ms-winsoundevent:Notification.Looping.Call5"

	Call6 = "ms-winsoundevent:Notification.Looping.Call6"

	Call7 = "ms-winsoundevent:Notification.Looping.Call7"

	Call8 = "ms-winsoundevent:Notification.Looping.Call8"

	Call9 = "ms-winsoundevent:Notification.Looping.Call9"

	Default = "ms-winsoundevent:Notification.Default"

	IM = "ms-winsoundevent:Notification.IM"

	Mail = "ms-winsoundevent:Notification.Mail"

	Reminder = "ms-winsoundevent:Notification.Reminder"

	SMS = "ms-winsoundevent:Notification.SMS"

class AudioMode:
	"""
	
    Values for _mode_ parameter of zroya.Template.audio method.
    Usage: template.audio(mode=zroya.AudioMode.Silence)

    Attributes:
    -----------
    Default - Use default audio mode. Selected audio will be played only once.
    Silence - No audio is played at all.
    Loop    - Play audio in loop until it is moved to Action Center. This time may vary due to different user
              configuration.
    
	"""

	Default = 0

	Loop = 2

	Silence = 1

class TemplateType:
	"""
	
    All possible values for zroya.Template constructor.
    Usage: zroya.Template(zroya.TemplateType.ImageAndText2)

    Attributes:
    -----------
    ImageAndText1 - A large image and a single string wrapped across three lines of text.
    ImageAndText2 - A large image, one string of bold text on the first line, one string of regular text wrapped across
                    the second and third lines.
    ImageAndText3 - A large image, one string of bold text wrapped across the first two lines, one string of regular
                    text on the third line.
    ImageAndText4 - A large image, one string of bold text on the first line, one string of regular text on the second
                    line, one string of regular text on the third line.
    Text1         - Single string wrapped across three lines of text.
    Text2         - One string of bold text on the first line, one string of regular text wrapped across the second and
                    third lines.
    Text3         - One string of bold text wrapped across the first two lines, one string of regular text on the third
                    line.
    Text4         - One string of bold text on the first line, one string of regular text on the second line, one
                    string of regular text on the third line.
    
	"""

	ImageAndText1 = 0

	ImageAndText2 = 1

	ImageAndText3 = 2

	ImageAndText4 = 3

	Text1 = 4

	Text2 = 5

	Text3 = 6

	Text4 = 7

class DismissReason:
	"""
	
    Attributes:
    -----------

    User    - The user dismissed the toast.
    App     - The application hid the toast using zroya.hide.
    Expired - The toast has expired.
    
	"""

	App = 1

	Expired = 2

	User = 0

