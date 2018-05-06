#pragma once

#include <string>
#include <Python.h>

#include "wintoastlib.h"

#ifdef __cplusplus
    extern "C" {
#endif

		/**
		 * This file create new python class - Template. It is used for creating notification
		 * template - text, audio, image, etc. Template is shown to user later on by calling
		 * zroya.show() function.
		 */

		/// C representation of Template class
        typedef struct {
			// Always start with this
            PyObject_HEAD
			/// Underhood representation of template
            WinToastLib::WinToastTemplate *_template;
			/// Underhood representation of template type. Used for various checks in template methods.
            WinToastLib::WinToastTemplate::WinToastTemplateType _type;
        } zroya_Template;

		/// C representatio of Template property
		typedef struct {
			/// Name of property
			const char *name;
			/// Integer value of property
			int value;
		} zroya_Template_Property;

        /// Wrapper for setting line text. It checks if line number is supported for selected template
		/// type.
        PyObject *zroya_template_setLine(zroya_Template *self, PyObject *args, PyObject *kwargs, int line = 0);

		/// Return text for specified line.
		PyObject *zroya_template_getLine(zroya_Template *self, int line = 0);

        PyDoc_STRVAR(zroya_template_setFirstLine__doc__,
            "setFirstLine(text)\n"
            "--\n\n"
            "Set first line of notification text. \n"
			"\n"
			"Args: \n"
			"\ttext (str): Text to be set as the first line. \n"
			"\n"
			"Raises: \n"
			"\tTypeError: When text is not a string. \n"
			"\n"
            "Returns: \n"
			"\tbool: True if first line was set, False on error."
        );
        PyObject *zroya_template_setFirstLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getFirstLine__doc__,
			"getFirstLine()\n"
			"--\n\n"
			"Get first line of notification text. \n"
			"\n"
			"Returns: \n"
			"\tstr: First line, or empty string when there is not text to be returned."
		);
		PyObject *zroya_template_getFirstLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setSecondLine__doc__,
            "setSecondLine(text)\n"
            "--\n\n"
            "Set second line of notification text. \n"
			"\n"
			"**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. \n"
			"\n"
			"Args: \n"
			"\ttext (str): Text to be set as the second line. \n"
			"\n"
			"Raises: \n"
			"\tTypeError: When text is not a string. \n"
            "\n"
			"Returns: \n"
			"\tbool: True if second line is supported by current template type and text was set. False otherwise."
        );
        PyObject *zroya_template_setSecondLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getSecondLine__doc__,
			"getSecondLine()\n"
			"--\n\n"
			"Get second line of notification text. \n"
			"\n"
			"**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. \n"
			"\n"
			"Returns: \n"
			"\tstr: Empty string when second line is not set or it is not supported by current template type. Second line text in other cases."
		);
		PyObject *zroya_template_getSecondLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setThirdLine__doc__,
            "setThirdLine(text)\n"
            "--\n\n"
            "Set third line of notification text. \n"
			"\n"
			"**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. \n"
            "\n"
			"Args: \n"
			"\ttext (str): Text to be set as the third line. \n"
			"\n"
			"Raises: \n"
			"\tTypeError: When text is not a string. \n"
			"\n"
			"Returns: \n"
			"\tbool: True if third line is supported for current type and the text was set. False otherwise."
        );
        PyObject *zroya_template_setThirdLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getThirdLine__doc__,
			"getThirdLine()\n"
			"--\n\n"
			"Get third line text. \n"
			"\n"
			"**Note**: Third line is not supported by each notification type. See :py:class:`zroya.TemplateType`. \n"
			"\n"
			"Returns: \n"
			"\tstr: Empty string if third line is not supported or empty. In other cases, third line."
		);
		PyObject *zroya_template_getThirdLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setImage__doc__,
            "setImage(path)\n"
            "--\n\n"
			"Set path to image used in notification. \n"
			"\n"
			"**Note**: Image is not supported by each notification type. See :py:class:`zroya.TemplateType`.\n"
			"\n"
			"Args: \n"
			"\tpath (str): Path to image. \n"
			"\n"
			"Raises: \n"
			"\tFileNotFoundError: Image does not exist. \n"
			"\n"
            "Returns: \n"
			"\tbool: True is image was set or False for unsupported template type."
        );
        PyObject *zroya_template_setImage(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getImage__doc__,
			"getImage()\n"
			"--\n\n"
			"Get path to image from notification. \n"
			"\n"
			"Returns: \n"
			"\tstr: Empty string or path to current template image."
		);
		PyObject *zroya_template_getImage(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_setAudio__doc__,
			"setAudio(audio, mode)\n"
			"--\n\n"
			"Set audio and playback mode for notification. Audio is a one of predefined system sounds. \n"
			"Audio mode sets how, or even if the sound is played. \n"
			"\n"
			"Args: \n"
			"\taudio (int): One of sounds defined in :py:class:`zroya.Audio` \n"
			"\tmode (int): One of modes available from :py:class:`zroya.AudioMode`. Or leave it empty for :py:attr:`zroya.AudioMode.Default`. \n"
			"\n"
			"Returns: \n"
			"\tbool:True if audio was set, false otherwise."
		);
        PyObject *zroya_template_setAudio(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_getAudio__doc__,
			"getAudio()\n"
			"--\n\n"
			"Get notification audio. Audio is a sound played to get user's attention. \n"
			"\n"
			"Returns:\n"
			"\t:py:class:`zroya.Audio`: Current audio."
		);
		PyObject *zroya_template_getAudio(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_getAudioMode__doc__,
			"getAudioMode()\n"
			"--\n\n"
			"Get notification audio mode. It sets how or even if the sound is played. \n"
			"\n"
			"Returns: \n"
			"\t:py:class:`zroya.AudioMode`: Current audio mode."
		);
		PyObject *zroya_template_getAudioMode(zroya_Template *self);
		
        PyDoc_STRVAR(zroya_template_setExpiration__doc__,
            "setExpiration(ms)\n"
            "--\n\n"
            "Set expiration time in milliseconds. Expiration time is time before the notification is "
			"removed from Action Center. This fires up the onDismiss event with dismiss reason set "
			"to :py:attr:`zroya.DismissReason.Expired`. \n"
			"\n"
			"Args: \n"
			"\tms (int): Number of milliseconds for expiration time. Zero means no expiration. \n"
			"\n"
            "Returns: \n"
			"\tbool: True for positive value of *ms*."
        );
        PyObject *zroya_template_setExpiration(zroya_Template *self, PyObject *arg, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getExpiration__doc__,
			"getExpiration()\n"
			"--\n\n"
			"Get expiration time in milliseconds. Expiration time is time before the notification is "
			"removed from Action Center. This fires up the onDismiss event with dismiss reason set "
			"to :py:attr:`zroya.DismissReason.Expired`. \n"
			"\n"
			"Returns: \n"
			"\n"
			"\tint: Number of milliseconds or zero for no expiration time."
		);
		PyObject *zroya_template_getExpiration(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_addAction__doc__,
			"addAction(label)\n"
			"--\n\n"
			"Add button to notification. User may click it and onAction event is fired up.\n"
			"Each notification got its own ID counting up from zero. This ID is handed back to "
			"event handler. \n"
			"\n"
			"**Note**: Action is one of \"modern\" features. Windows 8.1 or newer is required. \n"
			"\n"
			".. figure:: _static/example_full_features_action.png \n"
			"\t:alt: Image showing action buttons highlighted in notification. \n"
			"\n"
			"\tAction buttons are highlighted. \n"
			"\n"
			"Args: \n"
			"\tlabel (str): Button's text. \n"
			"\n"
			"Returns: \n"
			"\tint: Index of action."
		);
		PyObject *zroya_template_addAction(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_setAttribution__doc__,
			"setAttribution(label)\n"
			"--\n\n"
			"Set notification's attribution text. \n"
			"\n"
			"**Note:** Attribution text is one of \"modern\" features. Windows 8.1 or newer is required. \n"
			"\n"
			".. figure:: _static/example_full_features_attribution.png \n"
			"\t:alt: Image showing attribution text highlighted in notification. \n"
			"\n"
			"\tAttribution text is highlighted.\n"
			"\n"
			"Args: \n"
			"\tlabel (str): Attribution text. \n"
			"\n"
			"Returns: \n"
			"\tbool: True on success, False otherwise."
		);
		PyObject *zroya_template_setAttribution(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_getAttribution__doc__,
			"getAttribution()\n"
			"--\n\n"
			"Get attribution text from notification. \n"
			"\n"
			"**Note:** Attribution text is one of \"modern\" features. Windows 8.1 or newer is required. \n"
			"\n"
			".. figure:: _static/example_full_features_attribution.png \n"
			"\t:alt: Image showing highlighted attribution text in notification. \n"
			"\n"
			"\tAttribution text is highlighted.\n"
			"\n"
			"Returns: \n"
			"\tstr: Attribution text."
		);
		PyObject *zroya_template_getAttribution(zroya_Template *self, PyObject *arg);

		PyDoc_STRVAR(zroya_template_setDuration__doc__,
			"setDuration()\n"
			"--\n\n"
			"Sets the duration of notification being shown before it is moved to Action Center. \n"
			"\n"
			"Args: \n"
			"\tduration (:py:class:`zroya.TemplateDuration`): On of available duration values."
			"Returns: \n"
			"\tbool: Always returns True."
		);
		PyObject *zroya_template_setDuration(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_getDuration__doc__,
			"getDuration()\n"
			"--\n\n"
			"Get duration of notification being shown before it is moved to Action Center. \n"
			"\n"
			"Returns: \n"
			"\t:py:class:`zroya.TemplateDuration`: One of duration values."
		);
		PyObject *zroya_template_getDuration(zroya_Template *self, PyObject *arg);

        /// Create new empty zroya.Template object without inner values set up.
        PyObject *zroya_template_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

        /// Set inner values in instance created in zroya_template_new.
        int zroya_template_init(zroya_Template *self, PyObject *args, PyObject *kwargs);

        /// Free zroya.Template instance.
        void zroya_template_dealloc(zroya_Template *self);

		/// List of supported audio files (this is defined by Windows)
		extern const wchar_t* supported_audio_files[];
		/// List of Template class properties
		extern zroya_Template_Property zroya_template_properties[];
		/// List of Template methods
        extern PyMethodDef zroya_template_methods[];
		/// Template class settings
		extern PyTypeObject zroya_template_type;
        

#ifdef __cplusplus
    }
#endif