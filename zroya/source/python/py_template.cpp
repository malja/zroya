#include <string>

#include "py_template.h"
#include "py_utils.h"

/// Map of all Windows supported sound effects
const wchar_t* supported_audio_files[] = {
	L"ms-winsoundevent:Notification.Default",
	L"ms-winsoundevent:Notification.IM",
	L"ms-winsoundevent:Notification.Mail",
	L"ms-winsoundevent:Notification.Reminder",
	L"ms-winsoundevent:Notification.SMS",
	L"ms-winsoundevent:Notification.Looping.Alarm",
	L"ms-winsoundevent:Notification.Looping.Alarm2",
	L"ms-winsoundevent:Notification.Looping.Alarm3",
	L"ms-winsoundevent:Notification.Looping.Alarm4",
	L"ms-winsoundevent:Notification.Looping.Alarm5",
	L"ms-winsoundevent:Notification.Looping.Alarm6",
	L"ms-winsoundevent:Notification.Looping.Alarm7",
	L"ms-winsoundevent:Notification.Looping.Alarm8",
	L"ms-winsoundevent:Notification.Looping.Alarm9",
	L"ms-winsoundevent:Notification.Looping.Alarm10",
	L"ms-winsoundevent:Notification.Looping.Call",
	L"ms-winsoundevent:Notification.Looping.Call2",
	L"ms-winsoundevent:Notification.Looping.Call3",
	L"ms-winsoundevent:Notification.Looping.Call4",
	L"ms-winsoundevent:Notification.Looping.Call5",
	L"ms-winsoundevent:Notification.Looping.Call6",
	L"ms-winsoundevent:Notification.Looping.Call7",
	L"ms-winsoundevent:Notification.Looping.Call8",
	L"ms-winsoundevent:Notification.Looping.Call9",
	L"ms-winsoundevent:Notification.Looping.Call10"
};

/// List of all Template class properties
zroya_Template_Property zroya_template_properties[] = {
	{ "AUDIO_TYPE_DEFAULT", (int)WinToastLib::WinToastTemplate::AudioOption::Default },
	{ "AUDIO_TYPE_SILENCE", (int)WinToastLib::WinToastTemplate::AudioOption::Silent },
	{ "AUDIO_TYPE_LOOP", (int)WinToastLib::WinToastTemplate::AudioOption::Loop },
			
	{ "AUDIO_DEFAULT", 0 },
	{ "AUDIO_IM", 1 },
	{ "AUDIO_MAIL", 2 },
	{ "AUDIO_REMINDER", 3 },
	{ "AUDIO_SMS", 4 },
	{ "AUDIO_ALARM", 5 },
	{ "AUDIO_ALARM2", 6 },
	{ "AUDIO_ALARM3", 7 },
	{ "AUDIO_ALARM4", 8 },
	{ "AUDIO_ALARM5", 9 },
	{ "AUDIO_ALARM6", 10 },
	{ "AUDIO_ALARM7", 11 },
	{ "AUDIO_ALARM8", 12 },
	{ "AUDIO_ALARM9", 13 },
	{ "AUDIO_ALARM10", 14 },
	{ "AUDIO_CALL", 15 },
	{ "AUDIO_CALL2", 16 },
	{ "AUDIO_CALL3", 17 },
	{ "AUDIO_CALL4", 18 },
	{ "AUDIO_CALL5", 19 },
	{ "AUDIO_CALL6", 20 },
	{ "AUDIO_CALL7", 21 },
	{ "AUDIO_CALL8", 22 },
	{ "AUDIO_CALL9", 23 },
	{ "AUDIO_CALL10", 24 },
			
	{ "TYPE_IMAGE_TEXT1", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText01 },
	{ "TYPE_IMAGE_TEXT2", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText02 },
	{ "TYPE_IMAGE_TEXT3", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText03 },
	{ "TYPE_IMAGE_TEXT4", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText04 },
	{ "TYPE_TEXT1", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::Text01 },
	{ "TYPE_TEXT2", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::Text02 },
	{ "TYPE_TEXT3", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::Text03 },
	{ "TYPE_TEXT4", (int)WinToastLib::WinToastTemplate::WinToastTemplateType::Text04 },
	{ nullptr, 0 }
};

PyObject *zroya_template_line(zroya_Template *self, PyObject *arg, int line) {

	// Number of lines for each WinToastLib::WinToastTemplate::WinToastTemplateType
    int number_of_lines[] = { 1, 2, 2, 3, 1, 2, 2, 3 };

	// Fail for non supported template types
    if (line + 1 > number_of_lines[self->_type]) {
		Py_XINCREF(Py_False);
		return Py_False;
    }

    PyObject *param = nullptr;

    // Get parameter
    if (!PyArg_UnpackTuple(arg, "text", 0, 1, &param)) {
        PyErr_SetString(PyExc_ValueError, "unable to parse argument.");
        return nullptr;
    }

    // Was something found? And is it of required type?
    if (param && PyUnicode_Check(param)) {

        wchar_t *text = PyUnicode_AsWideCharString(param, nullptr);
        // Set line-th line next
        self->_template->setTextField(
            std::wstring(text), static_cast<WinToastLib::WinToastTemplate::TextField>(line)
        );

        // Clean up
        PyMem_Free(text);

	// No parameter? Just return text
    } else if (!param) {

        std::wstring text = self->_template->textField(
            static_cast<WinToastLib::WinToastTemplate::TextField>(line)
        );

        return Py_BuildValue("u", text.c_str());

	} else {
		PyErr_SetString(PyExc_ValueError, "text parameter is required to be a string. Or leave it empty.");
		return nullptr;
	}

    Py_XINCREF(Py_True);
    return Py_True;
}

PyObject *zroya_template_firstLine(zroya_Template *self, PyObject *arg) {
    return zroya_template_line(self, arg, 0);
}

PyObject *zroya_template_secondLine(zroya_Template *self, PyObject *arg) {
    return zroya_template_line(self, arg, 1);
}

PyObject *zroya_template_thirdLine(zroya_Template *self, PyObject *arg) {
    return zroya_template_line(self, arg, 2);
}

PyObject *zroya_template_image(zroya_Template *self, PyObject *args) {

    PyObject *param = nullptr;

	// Fail for non supported toast types
	if (self->_type > 3 /*WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText04*/) {
		Py_XINCREF(Py_False);
		return Py_False;
	}

    // Get parameter (if any)
    if (!PyArg_UnpackTuple(args, "image", 0, 1, &param)) {

        // Throw exception
        PyErr_SetString(PyExc_FileNotFoundError, "unable to parse arguments.");
        return nullptr;

    }

    // Was something found? And is it of required type?
    if (param && PyUnicode_Check(param)) {

        // Get path parameter
        wchar_t *path = PyUnicode_AsWideCharString(param, nullptr);

        // Unable to get path
        if (!path) {

            // Return False
            Py_XINCREF(Py_False);
            return Py_False;

        }

        // Non-existing file
        if (!file_exists(param)) {

            // Throw exception
            PyErr_SetString(PyExc_FileNotFoundError, "file with notification image does not exist");
            return nullptr;

        }

        // Set path parameter
		std::wstring p = std::wstring(path);
        self->_template->setImagePath(p);

        // Free memory
        PyMem_Free(path);

    } else {

        std::wstring p = self->_template->imagePath();

        // Return current path
        return Py_BuildValue("u", p.c_str());

    }

    // Return True
    Py_XINCREF(Py_True);
    return Py_True;

}

PyObject *zroya_template_audio(zroya_Template *self, PyObject *arg, PyObject *kwargs) {

	int audio = -1;
	int type = WinToastLib::WinToastTemplate::AudioOption::Default;

	char* keywords[] = { (char*)"audio", (char*)"type", nullptr };

    // Get parameter (if any)
    if (!PyArg_ParseTupleAndKeywords(arg, kwargs, "|ii", keywords, &audio, &type)) {
        // Well, it is not very informative :/
        PyErr_SetString(PyExc_ValueError, "unable to parse arguments.");
        return nullptr;
    }

	// Make sure type parameter is in range
	if (type < 0 || type > WinToastLib::WinToastTemplate::AudioOption::Loop) {
		PyErr_SetString(PyExc_ValueError, "type parameter is out of range");
		return nullptr;
	}

	// https://docs.microsoft.com/cs-cz/uwp/schemas/tiles/toastschema/element-audio
	if (audio >= sizeof(supported_audio_files)/sizeof(supported_audio_files[0] ) ) {
		PyErr_SetString(PyExc_ValueError, "audio parameter is out of range");
		return nullptr;
	}

	// Set audio type no mater what ;)
	self->_template->setAudioOption((WinToastLib::WinToastTemplate::AudioOption)type);

	// Set new audio?
	if (audio >= 0 ) {

		self->_template->setAudioPath(supported_audio_files[audio]);

	// Return audio?
	} else {

        std::wstring p = self->_template->audioPath();

        // Return current path
        return Py_BuildValue("u", p.c_str());

    }

    // Return True
    Py_XINCREF(Py_True);
    return Py_True;
}

PyObject *zroya_template_expire(zroya_Template *self, PyObject *arg) {

    long long expiration = -1;

    // Get parameter if any
    if (!PyArg_ParseTuple(arg, "|L", &expiration)) {
        // Well, it is not very informative :/
        PyErr_SetString(PyExc_ValueError, "unable to parse arguments.");
        return nullptr;
    }

    // Is expiration set and valid?
    if (expiration > 0) {
        // Set expiration
        self->_template->setExpiration(expiration);
            
	} else {

		// Get expiration
        expiration = self->_template->expiration();
		return Py_BuildValue("L", expiration);

    }

    return Py_BuildValue("L", expiration);
}

PyObject *zroya_template_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {

    zroya_Template *self = (zroya_Template *)type->tp_alloc(type, 0);

    if (!self) {
        Py_DECREF(self);
        return nullptr;
    }

    self->_template = nullptr;
    return (PyObject*)self;

}

int zroya_template_init(zroya_Template *self, PyObject *args, PyObject *kwargs) {

    int template_type;

    /* TODO: Validace typu - kontrola na neplatné hodnoty */
	if (!PyArg_ParseTuple(args, "i", &template_type)) {
		PyErr_SetString(PyExc_ValueError, "unable to parse arguments.");
		return -1;
	}

	if (template_type < 0 || template_type > 7 /* Index of last record in WinToastLib::WinToastTemplate::WinToastTemplateType */) {
		PyErr_SetString(PyExc_ValueError, "template type is not valid.");
		return -1;
	}

	self->_type = static_cast<WinToastLib::WinToastTemplate::WinToastTemplateType>(
		template_type
    );

    self->_template = new WinToastLib::WinToastTemplate(
        self->_type            
    );

    if (!self->_template) {
        PyErr_SetString(PyExc_MemoryError, "unable to create template");
        return -1;
    }

	// Make sure expiration time is set
	self->_template->setExpiration(0);

    return 0;
}

void zroya_template_dealloc(zroya_Template *self) {
    delete self->_template;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyMethodDef zroya_template_methods[] = {
    { "firstLine", (PyCFunction)zroya_template_firstLine, METH_VARARGS, zroya_template_firstLine__doc__ },
    { "secondLine", (PyCFunction)zroya_template_secondLine, METH_VARARGS, zroya_template_secondLine__doc__ },
    { "thirdLine", (PyCFunction)zroya_template_thirdLine, METH_VARARGS, zroya_template_thirdLine__doc__ },

    { "image", (PyCFunction)zroya_template_image, METH_VARARGS, zroya_template_image__doc__ },
    { "audio", (PyCFunction)zroya_template_audio, METH_VARARGS | METH_KEYWORDS, zroya_template_audio__doc__ },
    { "expire", (PyCFunction)zroya_template_expire, METH_VARARGS, zroya_template_expire__doc__ },
    { nullptr, nullptr, 0, nullptr }
};

PyTypeObject zroya_template_type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "zroya.Template",             /* tp_name */
    sizeof(zroya_Template),             /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)zroya_template_dealloc, /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT |
    Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "TODO: Documentation",           /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    zroya_template_methods,             /* tp_methods */
    0,             /* tp_members */
    0,           /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)zroya_template_init,      /* tp_init */
    0,                         /* tp_alloc */
    zroya_template_new                 /* tp_new */
};
