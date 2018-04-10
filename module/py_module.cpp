#include <Python.h>

#include "py_module.h"
#include "wintoastlib.h"

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

	// Add class properties to Template class
	for (int i = 0; zroya_template_properties[i].name != nullptr; i++) {
		PyDict_SetItemString(template_dict, zroya_template_properties[i].name, Py_BuildValue("i", zroya_template_properties[i].value));
	}
	
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
