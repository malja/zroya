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
        PyObject *zroya_template_line(zroya_Template *self, PyObject *args, PyObject *kwargs, int line = 0);

        PyDoc_STRVAR(zroya_template_firstLine__doc__,
            "firstLine(text=None)\n"
            "--\n\n"
            "Set or return first line of notification text. \n"
            ":param str text: Text to be set as the first line. \n"
            ":return: With _text_ parameter set, returns True/False. Without _text_, current first line is returned."
        );
        PyObject *zroya_template_firstLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

        PyDoc_STRVAR(zroya_template_secondLine__doc__,
            "secondLine(text=None)\n"
            "--\n\n"
            "Set or return second line of notification text. \n"
            ":param str text: Text to be set as the second line. \n"
			":throw: ValueError if second line is not supported by selected notification type. \n"
            ":return: With _text_ parameter set, returns True/False. Without _text_, current second line is returned."
        );
        PyObject *zroya_template_secondLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

        PyDoc_STRVAR(zroya_template_thirdLine__doc__,
            "thirdLine(text=None)\n"
            "--\n\n"
            "Set or return third line of notification text. \n"
            ":param str text: Text to be set as the third line. \n"
			":throw: ValueError if third line is not supported by selected notification type. \n"
            ":return: With _text_ parameter set, returns True/False. Without _text_, current third line is returned."
        );
        PyObject *zroya_template_thirdLine(zroya_Template *self, PyObject *args, PyObject *kwargs);

        PyDoc_STRVAR(zroya_template_image__doc__,
            "image(path=None)\n"
            "--\n\n"
            "Set or return notification image path. \n"
            ":param str path: Path to image. \n"
            ":return: With _path_ parameter set, it returns True/False. Without _text_, current image path is returned."
        );
        PyObject *zroya_template_image(zroya_Template *self, PyObject *args);

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