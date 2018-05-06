#include "py_module.h"

/**
 * 
 */
PyObject *zroya_init(PyObject *module, PyObject *args, PyObject *kwargs) {

	// List of all parameters this function may get
	static char *keywords[] = { (char*)"app_name", (char*)"company_name", (char*)"product_name", (char*)"sub_product", (char*)"version", nullptr };

	const char* app_name, *company_name, *product_name, *sub_product, *version;

	// Parse arguments
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sssss", keywords, &app_name, &company_name, &product_name, &sub_product, &version)) {
		PyErr_SetString(PyExc_ValueError, "all parameters must be string");
		return nullptr;
	}

	if (strlen(app_name) == 0 ||
		strlen(company_name) == 0 ||
		strlen(product_name) == 0 ||
		strlen(sub_product) == 0 ||
		strlen(version) == 0) {
		PyErr_SetString(PyExc_ValueError, "empty parameters are not allowed");
		return nullptr;
	}

	// Initialize underlying library with provided parameters.
	bool retcode = zroya::init(
		std::string(app_name),
		std::string(company_name),
		std::string(product_name),
		std::string(sub_product),
		std::string(version)
	);

	if (retcode) {
		Py_INCREF(Py_True);
		return Py_True;
	}
	else {
		Py_INCREF(Py_False);
		return Py_False;
	}

}

PyObject *zroya_show(PyObject *module, PyObject *args, PyObject *kwargs) {

	// List of all parameters thsi function accept
	static char *keywords[] = { (char*)"template", (char*)"on_click", (char*)"on_action", (char*)"on_dismiss", (char*)"on_fail", nullptr };

	PyObject *toast = nullptr, *on_click = nullptr, *on_action = nullptr, *on_dismiss = nullptr, *on_fail = nullptr;

	// Parse arguments
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|OOOO", keywords, &toast, &on_click, &on_action, &on_dismiss, &on_fail)) {
		return nullptr;
	}

	// Make sure template parameter is of zroya.Template type
	if (strcmp(toast->ob_type->tp_name, "zroya.Template") != 0) {
		PyErr_SetString(PyExc_ValueError, "first parameter must be of zroya.Template type.");
		return nullptr;
	}

	// Make sure WinToastLib is initialized
	if (!WinToastLib::WinToast::instance()->isInitialized()) {
		if (!zroya::init()) {
			PyErr_SetString(PyExc_SystemError, "initialization failed");
			return nullptr;
		}
	}

	zroya_State *state = static_cast<zroya_State*>(PyModule_GetState(module));

	// Try to show notification and save its ID
	INT64 notificationID = WinToastLib::WinToast::instance()->showToast(*(((zroya_Template*)toast)->_template), static_cast<zroya_State*>(PyModule_GetState(module))->_handler);

	if (notificationID > 0) {
		Py_XINCREF(on_click);
		Py_XINCREF(on_action);
		Py_XINCREF(on_dismiss);
		Py_XINCREF(on_fail);

		state->_handler->addCallbacks(notificationID, on_click, on_action, on_dismiss, on_fail);
	}

	return PyLong_FromLongLong(notificationID);
}

PyObject *zroya_hide(PyObject *module, PyObject *arg, PyObject *kwarg) {

	static char *keywords[] = { (char*)"nid" };

	PyObject *notificationID = nullptr;

	if (!PyArg_ParseTupleAndKeywords(arg, kwarg, "O", keywords, &notificationID)) {
		return nullptr;
	}

	INT64 nID = -1;

	// Check if parameter is integer
	if (!PyLong_Check(notificationID)) {
		PyErr_SetString(PyExc_ValueError, "nid parameter is required to be an integer.");
		return nullptr;
	}

	// Get notification ID as integer
	nID = PyLong_AsLongLong(notificationID);

	// Ignore unvalid values
	if (nID < 0) {
		PyErr_SetString(PyExc_ValueError, "nid may not be negative.");
		return nullptr;
	}

	if (WinToastLib::WinToast::instance()->hideToast(nID)) {
		Py_INCREF(Py_True);
		return Py_True;
	}
	else {
		Py_INCREF(Py_False);
		return Py_False;
	}
}

/// Clear zroya module
int zroya_clear(PyObject *self) {
    zroya_State* state = static_cast<zroya_State*>(PyModule_GetState(self));

    // Free
    state->_win_toast = nullptr;
	delete state->_handler;

    return 0;
}

/// List of all module functions.
struct PyMethodDef zroya_module_functions[] = {
    { "init", (PyCFunction)zroya_init, METH_VARARGS | METH_KEYWORDS, zroya_init__doc__ },
    { "show", (PyCFunction)zroya_show, METH_VARARGS | METH_KEYWORDS, zroya_show__doc__ },
    { "hide", (PyCFunction)zroya_hide, METH_VARARGS | METH_KEYWORDS, zroya_hide__doc__ },
    { nullptr, nullptr, 0, nullptr }
};

/// Module definition
struct PyModuleDef zroya_module_definition = {
    PyModuleDef_HEAD_INIT, /* Always start definition with this :) */
    "zroya", /* Module name */
	zroya__doc__, /*DOCSTRING*/
    sizeof(zroya_State), /* Set module state as global. */
    zroya_module_functions, /* Module functions */
    nullptr, /* Slots for multi-phase initialization */
    nullptr, /* travelsal function */
    zroya_clear, /* Clean function */
    nullptr /* Free function */
};

/// Module entry point.
PyMODINIT_FUNC PyInit__zroya() {
            
	// Check if there is zroya module configuration
    if (PyType_Ready(&zroya_template_type) < 0) {
        return nullptr;
    }

	// Create new module named zroya
    PyObject *module = PyModule_Create(&zroya_module_definition);
    if (!module) {
        return nullptr;
    }

	// Add Template class to zroya module
    if (PyModule_AddObject(module, "Template", (PyObject*)&zroya_template_type) < 0) {
        return nullptr;
    }

	PyObject *template_dict = zroya_template_type.tp_dict;
		
    // WinToast singleton should be accessible from anywhere, but keeping instance 
    // should prevent from unwanted destroying.
    zroya_State *state = (zroya_State*)PyModule_GetState(module);
    state->_win_toast = WinToastLib::WinToast::instance();
	state->_handler = new zroya::EventHandler;

	if (!PyEval_ThreadsInitialized()) {
		PyEval_InitThreads();
	}
            
    return module;
}
