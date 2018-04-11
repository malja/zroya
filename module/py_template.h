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
			":return: Empty string when second line is not set or it is not supported for current template type. \n"
			"Second line text in other cases."
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
			":return: Empty string for unsuported line for current template type or when third line is not set yet. \n"
			"In other cases, third line text is returned."
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

        PyDoc_STRVAR(zroya_template_audio__doc__,
            "audio(audio=None, mode=None)\n"
            "--\n\n"
            "Set audio to be played and playback type or return current audio. \n"
            ":param int audio: One of zroya.Template.AUDIO_* property. \n"
			":param int mode: One of zroya.Template.AUDIO_TYPE_* property. \n"
            ":return: With _audio_ parameter provided, it sets new audio. In addition, if _type_ parameter is set, playback type is changed. Otherwise default playback type is used. True/False is returned.\n Without _audio_ parameter set, current audio is returned."
        );
        PyObject *zroya_template_audio(zroya_Template *self, PyObject *arg, PyObject *kwarg);

        PyDoc_STRVAR(zroya_template_expire__doc__,
            "expire(ms=0)\n"
            "--\n\n"
            "Set or return expiration time in milliseconds. \n"
            ":param int ms: Number of milliseconds for expiration time. Zero means no expiration. \n"
            ":return: If you set _ms_ parameter to any positive integer, expiration time is set. Without any parameter, current expiration time is returned."
        );
        PyObject *zroya_template_expire(zroya_Template *self, PyObject *arg);

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