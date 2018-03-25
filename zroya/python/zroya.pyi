class Template:
	"""
	TODO: Documentation
	"""

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

