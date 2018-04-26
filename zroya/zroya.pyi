class Template:
	"""Template for any notification you create. You may show any number of notifications based on this template with :py:func:`zroya.show()` method."""

	def addAction(self, label):
		"""
		Add button to notification. User may click it and onAction event is fired up.
		Each notification got its own ID counting up from zero. This ID is handed back to event handler. 
		
		**Note**: Action is one of "modern" features. Windows 8.1 or newer is required. 
		
		.. figure:: _static/example_full_features_action.png 
		        :alt: Image showing action buttons highlighted in notification. 
		
		        Action buttons are highlighted. 
		
		Args: 
		        label (str): Button's text. 
		
		Returns: 
		        int: Index of action.
		"""
		pass

	def getAttribution(self):
		"""
		Get attribution text from notification. 
		
		**Note:** Attribution text is one of "modern" features. Windows 8.1 or newer is required. 
		
		.. figure:: _static/example_full_features_attribution.png 
		        :alt: Image showing highlighted attribution text in notification. 
		
		        Attribution text is highlighted.
		
		Returns: 
		        str: Attribution text.
		"""
		pass

	def getAudio(self):
		"""
		Get notification audio. Audio is a sound played to get user's attention. 
		
		Returns:
		        :py:class:`zroya.Audio`: Current audio.
		"""
		pass

	def getAudioMode(self):
		"""
		Get notification audio mode. It sets how or even if the sound is played. 
		
		Returns: 
		        :py:class:`zroya.AudioMode`: Current audio mode.
		"""
		pass

	def getExpiration(self):
		"""
		Get expiration time in milliseconds. Expiration time is time before the notification is removed from Action Center. This fires up the onDismiss event with dismiss reason set to :py:attr:`zroya.DismissReason.Expired`. 
		
		Returns: 
		
		        int: Number of milliseconds or zero for no expiration time.
		"""
		pass

	def getFirstLine(self):
		"""
		Get first line of notification text. 
		
		Returns: 
		        str: First line, or empty string when there is not text to be returned.
		"""
		pass

	def getImage(self):
		"""
		Get path to image from notification. 
		
		Returns: 
		        str: Empty string or path to current template image.
		"""
		pass

	def getSecondLine(self):
		"""
		Get second line of notification text. 
		
		**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. 
		
		Returns: 
		        str: Empty string when second line is not set or it is not supported by current template type. Second line text in other cases.
		"""
		pass

	def getThirdLine(self):
		"""
		Get third line text. 
		
		**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. 
		
		Returns: 
		        str: Empty string if third line is not supported or empty. In other cases, third line.
		"""
		pass

	def setAttribution(self, label):
		"""
		Set notification's attribution text. 
		
		**Note:** Attribution text is one of "modern" features. Windows 8.1 or newer is required. 
		
		.. figure:: _static/example_full_features_attribution.png 
		        :alt: Image showing attribution text highlighted in notification. 
		
		        Attribution text is highlighted.
		
		Args: 
		        label (str): Attribution text. 
		
		Returns: 
		        bool: True on success, False otherwise.
		"""
		pass

	def setAudio(self, audio, mode):
		"""
		Set audio and playback mode for notification. Audio is a one of predefined system sounds. 
		Audio mode sets how, or even if the sound is played. 
		
		Args: 
		        audio (int): One of sounds defined in :py:class:`zroya.Audio` 
		        mode (int): One of modes available from :py:class:`zroya.AudioMode`. Or leave it empty for :py:attr:`zroya.AudioMode.Default`. 
		
		Returns: 
		        bool:True if audio was set, false otherwise.
		"""
		pass

	def setExpiration(self, ms):
		"""
		Set expiration time in milliseconds. Expiration time is time before the notification is removed from Action Center. This fires up the onDismiss event with dismiss reason set to :py:attr:`zroya.DismissReason.Expired`. 
		
		Args: 
		        ms (int): Number of milliseconds for expiration time. Zero means no expiration. 
		
		Returns: 
		        bool: True for positive value of *ms*.
		"""
		pass

	def setFirstLine(self, text):
		"""
		Set first line of notification text. 
		
		Args: 
		        text (str): Text to be set as the first line. 
		
		Raises: 
		        TypeError: When text is not a string. 
		
		Returns: 
		        bool: True if first line was set, False on error.
		"""
		pass

	def setImage(self, path):
		"""
		Set path to image used in notification. 
		
		**Note**: Image is not supported by each notification type. See :py:class:`zroya.TemplateType`.
		
		Args: 
		        path (str): Path to image. 
		
		Raises: 
		        FileNotFoundError: Image does not exist. 
		
		Returns: 
		        bool: True is image was set or False for unsupported template type.
		"""
		pass

	def setSecondLine(self, text):
		"""
		Set second line of notification text. 
		
		**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. 
		
		Args: 
		        text (str): Text to be set as the second line. 
		
		Raises: 
		        TypeError: When text is not a string. 
		
		Returns: 
		        bool: True if second line is supported by current template type and text was set. False otherwise.
		"""
		pass

	def setThirdLine(self, text):
		"""
		Set third line of notification text. 
		
		**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. 
		
		Args: 
		        text (str): Text to be set as the third line. 
		
		Raises: 
		        TypeError: When text is not a string. 
		
		Returns: 
		        bool: True if third line is supported for current type and the text was set. False otherwise.
		"""
		pass

def hide(nid):
	"""
	Hide notification by ID. This will trigger onDismiss event.
	
	Args: 
	        nid (int): Notification ID obtained from :py:func:`zroya.show` function. 
	
	Returns: 
	        bool: True if notification was hidden, false otherwise.
	"""
	pass

def init(app_name, company_name, product_name, sub_product, version):
	"""
	Initialize Zroya module. 
	
	**Note**: You should call this function before any other manipulation with this module. 
	If you do not call this function explicitely, randomly generated strings will be used as default parameters. 
	
	Args: 
	        app_name (str): Application name. 
	
	        company_name (str): Part of unique ID created for this application. 
	
	        product_name (str): Part of unique ID created for this application. 
	
	        sub_product (str): Part of unique ID created for this application. 
	
	        str version (str): Part of unique ID created for this application. 
	
	
	Returns: 
	        bool: True if initialization is completed, False otherwise.
	"""
	pass

def show(template, on_click=None, on_action=None, on_dismiss=None, on_fail=None):
	"""
	Create instance of notification template and show it. If any of on_* parameter is set, corresponding event is registered. See :doc:`tutorials/callbacks`.
	
	Args: 
	        template (:py:class:`zroya.Template`): Template instance. 
	
	        on_click (callable): Callback for onClick event. Occurs when user activates a toast notification through a click or touch. 
	
	        on_action (callable): Callback for onAction event. Occurs when user click on action button. 
	
	        on_dismiss (callable): Callback for onDismiss event. Occurs when the notification leaves the screen, either by expiring or being explicitly dismissed by the user. 
	
	        on_fail (callable): Callback for onFail event. Occurs when an error is caused when Windows attempts to raise a toast notification. 
	
	
	Returns: 
	        bool: Notification ID if notification was shown. False otherwise.
	"""
	pass

class Audio:
	"""
    Audio enumeration contains values for  accepted values for `audio` parameter of :py:meth:`zroya.Template.setAudio`
    method.

    Example:
        .. code-block:: python

            # t is an instance of zroya.Template
            t.setAudio( audio=zroya.Audio.IM )

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
    AudioMode is enumeration holds all valid parameters accepted by :py:meth:`zroya.Template.setAudio` method's `mode`
    parameter.

    Example:
        .. code-block:: python

            # t is an instance of zroya.Template
            t.setAudio( mode=zroya.AudioMode.Silence )

    """

	Default = 0

	Loop = 2

	Silence = 1

class TemplateType:
	"""
    All possible values for :py:class:`zroya.Template` constructor.

    Example:
        .. code-block:: python

            zroya.Template(zroya.TemplateType.ImageAndText2)

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
    of :py:func:`zroya.show` function.

    You can print it to get a reason description or compare it with any of following attributes.
    """

	App = 1

	Expired = 2

	User = 0

