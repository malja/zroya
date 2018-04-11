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

PyObject *zroya_template_setLine(zroya_Template *self, PyObject *args, PyObject *kwargs, int line) {

	// Number of lines for each WinToastLib::WinToastTemplate::WinToastTemplateType
    int number_of_lines[] = { 1, 2, 2, 3, 1, 2, 2, 3 };

    char* keywords[] = { (char*)"text", nullptr };

	// Fail for non supported template types
    if (line + 1 > number_of_lines[self->_type]) {
		Py_XINCREF(Py_False);
		return Py_False;
    }

    PyObject *param = nullptr;

    // Get parameter
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", keywords, &param)) {
        return nullptr;
    }

    // Is parameter an Unicode string?
	if (!PyUnicode_Check(param)) {
		PyErr_SetString(PyExc_ValueError, "text parameter is required to be a string.");
		return nullptr;
	}

    wchar_t *text = PyUnicode_AsWideCharString(param, nullptr);
    
	// Set line-th line text
    self->_template->setTextField(
        std::wstring(text), static_cast<WinToastLib::WinToastTemplate::TextField>(line)
    );

    // Clean up
    PyMem_Free(text);

	Py_XINCREF(Py_True);
    return Py_True;
}

PyObject *zroya_template_getLine(zroya_Template *self, int line) {
	// Number of lines for each WinToastLib::WinToastTemplate::WinToastTemplateType
	int number_of_lines[] = { 1, 2, 2, 3, 1, 2, 2, 3 };

	// Fail for non supported template types
	if (line + 1 > number_of_lines[self->_type]) {
		return PyUnicode_FromString("");
	}

	// Get line-th line text
	std::wstring text = self->_template->textField(
		static_cast<WinToastLib::WinToastTemplate::TextField>(line)
	);

	// Return it
	return Py_BuildValue("u", text.c_str());
}

PyObject *zroya_template_setFirstLine(zroya_Template *self, PyObject *args, PyObject *kwargs) {
    return zroya_template_setLine(self, args, kwargs, 0);
}

PyObject *zroya_template_getFirstLine(zroya_Template *self) {
	return zroya_template_getLine(self, 0);
}

PyObject *zroya_template_setSecondLine(zroya_Template *self, PyObject *args, PyObject *kwargs) {
    return zroya_template_setLine(self, args, kwargs, 1);
}

PyObject *zroya_template_getSecondLine(zroya_Template *self) {
	return zroya_template_getLine(self, 1);
}

PyObject *zroya_template_setThirdLine(zroya_Template *self, PyObject *args, PyObject *kwargs) {
    return zroya_template_setLine(self, args, kwargs, 2);
}

PyObject *zroya_template_getThirdLine(zroya_Template *self) {
	return zroya_template_getLine(self, 2);
}

PyObject *zroya_template_setImage(zroya_Template *self, PyObject *args, PyObject *kwargs) {

    PyObject *path_obj = nullptr;
    char* keywords[] = { (char*)"path", nullptr };

	// Fail for non supported toast types
	// Make sure it corresponds with value in WinToastLib::WinToastTemplate::WinToastTemplateType::ImageAndText04
	if (self->_type > 3) {
		Py_XINCREF(Py_False);
		return Py_False;
	}

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", keywords, &path_obj)) {
        return nullptr;
    }

	if (!PyUnicode_Check(path_obj)) {
		PyErr_SetString(PyExc_ValueError, "path is not a string.");
		return nullptr;
	}

	// Non-existing file
	if (!file_exists(path_obj)) {
		// Throw exception
		PyErr_SetString(PyExc_FileNotFoundError, "file with notification image does not exist");
		return nullptr;
	}

    // Get path parameter
    wchar_t *path = PyUnicode_AsWideCharString(path_obj, nullptr);

    // Set path parameter
	std::wstring p = std::wstring(path);
    self->_template->setImagePath(p);

    // Free memory
    PyMem_Free(path);

    // Return True
    Py_XINCREF(Py_True);
    return Py_True;

}

PyObject *zroya_template_getImage(zroya_Template *self) {
	
	std::wstring p = self->_template->imagePath();

	// Return current path
	return Py_BuildValue("u", p.c_str());
}

PyObject *zroya_template_audio(zroya_Template *self, PyObject *arg, PyObject *kwargs) {

	PyObject *audio_obj = nullptr;
	PyObject *type_obj = nullptr;

	char* keywords[] = { (char*)"audio", (char*)"mode", nullptr };

    // Get parameter (if any)
    if (!PyArg_ParseTupleAndKeywords(arg, kwargs, "|OO", keywords, &audio_obj, &type_obj)) {
        return nullptr;
    }

    wchar_t *audio = nullptr;
    if (audio_obj) {
        // Is it Enum?
        if (PyObject_HasAttrString(audio_obj, "value")) {
            PyObject *audio_value = PyObject_GetAttrString(audio_obj, "value");
            if (PyUnicode_Check(audio_value)) {
                  audio = PyUnicode_AsWideCharString(audio_value, nullptr);
            }

            Py_XDECREF(audio_value);
        } else {
            // Unsuported parameter type
            PyErr_SetString(PyExc_ValueError, "audio parameter is not int or Enum");
            return nullptr;
        }
    }

    int type = (int)WinToastLib::WinToastTemplate::AudioOption::Default;

    if (type_obj) {

        if (PyLong_Check(type_obj)) {
            type = PyLong_AsLong(type_obj);

        } else {
            // Is it Enum?
            if (PyObject_HasAttrString(type_obj, "value")) {

                PyObject *tmp_type = PyObject_GetAttrString(type_obj, "value");

                if (PyLong_Check(tmp_type)) {
                    type = PyLong_AsLong(tmp_type);
                }
                Py_XDECREF(tmp_type);

            // Unsuported parameter type
            } else {
                PyErr_SetString(PyExc_ValueError, "mode parameter is not int or Enum");
                return nullptr;
            }
        }
    }

	// Make sure type parameter is in range
	if (type < 0 || type > WinToastLib::WinToastTemplate::AudioOption::Loop) {
		PyErr_SetString(PyExc_ValueError, "mode parameter is out of range");
		return nullptr;
	}

	// Set audio type no mater what ;)
	self->_template->setAudioOption((WinToastLib::WinToastTemplate::AudioOption)type);

	// Set new audio?
	if (audio) {
		self->_template->setAudioPath(audio);

    // No parameters, return path
	} else if (!audio && !type_obj) {
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

    PyObject *template_type;

    /* TODO: Validace typu - kontrola na neplatn� hodnoty */
	if (!PyArg_ParseTuple(args, "O", &template_type)) {
		PyErr_SetString(PyExc_ValueError, "unable to parse arguments.");
		return -1;
	}

	int value = -1;
	if (PyLong_Check(template_type)) {
	    value = PyLong_AsLong(template_type);
	} else {
	    PyObject *tmp_value = PyObject_GetAttrString(template_type, "value");
	    if (PyLong_Check(tmp_value)) {
	        value = PyLong_AsLong(tmp_value);
	    }
	    Py_DECREF(tmp_value);
    }

	if (value < 0 || value > 7 /* Index of last record in WinToastLib::WinToastTemplate::WinToastTemplateType */) {
		PyErr_SetString(PyExc_ValueError, "template type is not valid.");
		return -1;
	}

	self->_type = static_cast<WinToastLib::WinToastTemplate::WinToastTemplateType>(
		value
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
    { "setFirstLine", (PyCFunction)zroya_template_setFirstLine, METH_VARARGS | METH_KEYWORDS, zroya_template_setFirstLine__doc__ },
	{ "getFirstLine", (PyCFunction)zroya_template_getFirstLine, METH_VARARGS, zroya_template_getFirstLine__doc__ },


    { "setSecondLine", (PyCFunction)zroya_template_setSecondLine, METH_VARARGS | METH_KEYWORDS, zroya_template_setSecondLine__doc__ },
	{ "getSecondLine", (PyCFunction)zroya_template_getSecondLine, METH_VARARGS, zroya_template_getSecondLine__doc__ },

    { "setThirdLine", (PyCFunction)zroya_template_setThirdLine, METH_VARARGS | METH_KEYWORDS, zroya_template_setThirdLine__doc__ },
	{ "getThirdLine", (PyCFunction)zroya_template_getThirdLine, METH_VARARGS, zroya_template_getThirdLine__doc__ },

    { "setImage", (PyCFunction)zroya_template_setImage, METH_VARARGS | METH_KEYWORDS, zroya_template_setImage__doc__ },
	{ "getImage", (PyCFunction)zroya_template_getImage, METH_VARARGS, zroya_template_getImage__doc__ },

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
    "Notification template. You may show instance of template via zroya.show function.",           /* tp_doc */
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
