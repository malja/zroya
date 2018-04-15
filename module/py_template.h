#pragma once

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
            ":param str text: Text to be set as the first line. \n"
			":raises: ValueError when text is not a string. \n"
            ":return: True if first line was set, False on error."
        );
        PyObject *zroya_template_setFirstLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getFirstLine__doc__,
			"getFirstLine()\n"
			"--\n\n"
			"Get first line of notification text. \n"
			":return: First line, or empty string when there is not text to be returned."
		);
		PyObject *zroya_template_getFirstLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setSecondLine__doc__,
            "setSecondLine(text)\n"
            "--\n\n"
            "Set second line of notification text. \n"
            ":param str text: Text to be set as the second line. \n"
			":raises: ValueError when text is not a string. \n"
            ":return: True if second line is supported for current template type and text was set. False otherwise."
        );
        PyObject *zroya_template_setSecondLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getSecondLine__doc__,
			"getSecondLine()\n"
			"--\n\n"
			"Get second line of notification text. \n"
			":return: Empty string when second line is not set or it is not supported for current template type. \nSecond line text in other cases."
		);
		PyObject *zroya_template_getSecondLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setThirdLine__doc__,
            "setThirdLine(text)\n"
            "--\n\n"
            "Set third line of notification text. \n"
            ":param str text: Text to be set as the third line. \n"
			":raises: ValueError when text is not a string. \n"
			":return: True if third line is supported for current type and the text was set. False otherwise."
        );
        PyObject *zroya_template_setThirdLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getThirdLine__doc__,
			"getThirdLine()\n"
			"--\n\n"
			"Get third line of notification text. \n"
			":return: Empty string for unsuported line for current template type or when third line is not set yet. \nIn other cases, third line text is returned."
		);
		PyObject *zroya_template_getThirdLine(zroya_Template *self);

        PyDoc_STRVAR(zroya_template_setImage__doc__,
            "setImage(path)\n"
            "--\n\n"
            "Set notification image path. \n"
            ":param str path: Path to image. \n"
			":raises: FileNotFoundError when path is not a valid file. \n"
            ":return: True is image was set or False for unsupported template type."
        );
        PyObject *zroya_template_setImage(zroya_Template *self, PyObject *args, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getImage__doc__,
			"getImage()\n"
			"--\n\n"
			"Get notification image path. \n"
			":return: Empty string or path to current template image."
		);
		PyObject *zroya_template_getImage(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_setAudio__doc__,
			"setAudio(audio, mode)\n"
			"--\n\n"
			"Set audio and playback mode for notification. \n"
			":param int audio: One of zroya.Audio. \n"
			":param int mode: One of zroya.AudioMode. Or leave empty for zroya.AudioMode.Default. \n"
			":return: True if audio was set, false otherwise."
		);
        PyObject *zroya_template_setAudio(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_getAudio__doc__,
			"getAudio()\n"
			"--\n\n"
			"Get notification audio. \n"
			":return: zroya.Audio."
		);
		PyObject *zroya_template_getAudio(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_getAudioMode__doc__,
			"getAudioMode()\n"
			"--\n\n"
			"Get notification audio mode. \n"
			":return: zroya.AudioMode."
		);
		PyObject *zroya_template_getAudioMode(zroya_Template *self);
		
        PyDoc_STRVAR(zroya_template_setExpiration__doc__,
            "setExpiration(ms)\n"
            "--\n\n"
            "Set expiration time in milliseconds. \n"
            ":param int ms: Number of milliseconds for expiration time. Zero means no expiration. \n"
            ":return: Return True for positive value of _ms_."
        );
        PyObject *zroya_template_setExpiration(zroya_Template *self, PyObject *arg, PyObject *kwargs);

		PyDoc_STRVAR(zroya_template_getExpiration__doc__,
			"getExpiration()\n"
			"--\n\n"
			"Return expiration time in milliseconds. \n"
			":return: Number of milliseconds or zero for no expiration time."
		);
		PyObject *zroya_template_getExpiration(zroya_Template *self);

		PyDoc_STRVAR(zroya_template_addAction__doc__,
			"addAction(label)\n"
			"--\n\n"
			"Add button action to notification. \n"
			":param str label: Action text. \n"
			":return: Index of action."
		);
		PyObject *zroya_template_addAction(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_setAttribution__doc__,
			"setAttribution(label)\n"
			"--\n\n"
			"Add attribution text to notification. \n"
			":param str label: Attribution text. \n"
			":return: True on success."
		);
		PyObject *zroya_template_setAttribution(zroya_Template *self, PyObject *arg, PyObject *kwarg);

		PyDoc_STRVAR(zroya_template_getAttribution__doc__,
			"getAttribution()\n"
			"--\n\n"
			"Return attribution text from notification. \n"
			":return: Attribution text."
		);
		PyObject *zroya_template_getAttribution(zroya_Template *self, PyObject *arg);

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