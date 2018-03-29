#include "py_init.h"
#include "init.h"
#include "utils.h"
#include "wintoastlib.h"
#include "py_template.h"
#include "event_handler.h"

#include <iostream>

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

	// Try to show notification and save its ID
    INT64 notificationID = WinToastLib::WinToast::instance()->showToast(*(((zroya_Template*)toast)->_template), static_cast<zroya_State*>(PyModule_GetState(module))->_handler );

	return PyLong_FromLongLong(notificationID);
}

PyObject *zroya_hide(PyObject *module, PyObject *arg, PyObject *kwarg) {

    static char *keywords[] = { (char*)"nid" };

    PyObject *notificationID = nullptr;

    if (!PyArg_ParseTupleAndKeywords(arg, kwarg, "O", keywords, &notificationID )) {
        return nullptr;
    }


    /*
    // Parse arguments
    if (!PyTuple_Check(arg)) {
        PyErr_SetString(PyExc_TypeError, "function takes tuple as parameter.");
        return nullptr;
    }

	// Exactly one parameter is required
    if (PyTuple_Size(arg) != 1) {
        PyErr_SetString(PyExc_ValueError, "function requires only one parameter.");
        return nullptr;
    }*/

    INT64 nID = -1;
	
    /*
	// Get number from PyObject representing tuple
    PyObject *tuple = PyTuple_GetItem(arg, 0);
	notificationID = PyLong_AsLongLong(tuple);
    */

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
    } else {
        Py_INCREF(Py_False);
        return Py_False;
    }


}
