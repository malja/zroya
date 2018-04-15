class Template:
	"""
	Template class is a template for any notification you create. 
	You may show any number of notifications based on this template with zroya.show() method.
	"""

	def addAction(self, label):
		"""
		Add button action to notification. 
		:param str label: Action text. 
		:return: Index of action.
		"""
		pass

	def getAttribution(self):
		"""
		Return attribution text from notification. 
		:return: Attribution text.
		"""
		pass

	def getAudio(self):
		"""
		Get notification audio. 
		:return: zroya.Audio.
		"""
		pass

	def getAudioMode(self):
		"""
		Get notification audio mode. 
		:return: zroya.AudioMode.
		"""
		pass

	def getExpiration(self):
		"""
		Return expiration time in milliseconds. 
		:return: Number of milliseconds or zero for no expiration time.
		"""
		pass

	def getFirstLine(self):
		"""
		Get first line of notification text. 
		:return: First line, or empty string when there is not text to be returned.
		"""
		pass

	def getImage(self):
		"""
		Get notification image path. 
		:return: Empty string or path to current template image.
		"""
		pass

	def getSecondLine(self):
		"""
		Get second line of notification text. 
		:return: Empty string when second line is not set or it is not supported for current template type. 
		Second line text in other cases.
		"""
		pass

	def getThirdLine(self):
		"""
		Get third line of notification text. 
		:return: Empty string for unsuported line for current template type or when third line is not set yet. 
		In other cases, third line text is returned.
		"""
		pass

	def setAttribution(self, label):
		"""
		Add attribution text to notification. 
		:param str label: Attribution text. 
		:return: True on success.
		"""
		pass

	def setAudio(self, audio, mode):
		"""
		Set audio and playback mode for notification. 
		:param int audio: One of zroya.Audio. 
		:param int mode: One of zroya.AudioMode. Or leave empty for zroya.AudioMode.Default. 
		:return: True if audio was set, false otherwise.
		"""
		pass

	def setExpiration(self, ms):
		"""
		Set expiration time in milliseconds. 
		:param int ms: Number of milliseconds for expiration time. Zero means no expiration. 
		:return: Return True for positive value of _ms_.
		"""
		pass

	def setFirstLine(self, text):
		"""
		Set first line of notification text. 
		:param str text: Text to be set as the first line. 
		:raises: ValueError when text is not a string. 
		:return: True if first line was set, False on error.
		"""
		pass

	def setImage(self, path):
		"""
		Set notification image path. 
		:param str path: Path to image. 
		:raises: FileNotFoundError when path is not a valid file. 
		:return: True is image was set or False for unsupported template type.
		"""
		pass

	def setSecondLine(self, text):
		"""
		Set second line of notification text. 
		:param str text: Text to be set as the second line. 
		:raises: ValueError when text is not a string. 
		:return: True if second line is supported for current template type and text was set. False otherwise.
		"""
		pass

	def setThirdLine(self, text):
		"""
		Set third line of notification text. 
		:param str text: Text to be set as the third line. 
		:raises: ValueError when text is not a string. 
		:return: True if third line is supported for current type and the text was set. False otherwise.
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
	
    This class represents a notification dismiss reason. It is passed to callback registered in on_dismiss parameter
    of zroya.show function.

    You can print it to get a reason description or compare it with any of following attributes.

    Attributes:
    -----------

    User    - The user dismissed the toast.
    App     - The application hid the toast using zroya.hide.
    Expired - The toast has expired.
    
	"""

	App = 1

	Expired = 2

	User = 0

