#include "py_utils.h"

bool file_exists(PyObject *file_name) {

    Py_XINCREF(file_name);

    PyObject *import_name = PyUnicode_FromString("os.path");

    if (!import_name) {

        Py_XDECREF(file_name);
        return false;
    }

    PyObject *module = PyImport_Import(import_name);

    if (!module) {

        Py_XDECREF(file_name);
        Py_XDECREF(import_name);
        return false;
    }

    PyObject *path_isfile = PyObject_GetAttrString(module, "isfile");
    if (!path_isfile) {

        Py_XDECREF(file_name);
        Py_XDECREF(import_name);
        Py_XDECREF(module);
        return false;
    }

    PyObject *arguments = PyTuple_Pack(1, file_name);

    if (!arguments) {
        Py_XDECREF(file_name);
        Py_XDECREF(import_name);
        Py_XDECREF(module);
        Py_XDECREF(path_isfile);
        return false;
    }

    PyObject *ret_val = PyObject_CallObject(path_isfile, arguments);
    if (!ret_val) {
        Py_XDECREF(file_name);
        Py_XDECREF(import_name);
        Py_XDECREF(module);
        Py_XDECREF(path_isfile);
        Py_XDECREF(arguments);
        return false;
    }

    int result = PyObject_IsTrue(ret_val);

    // Clean up
    Py_XDECREF(file_name);
    Py_XDECREF(import_name);
    Py_XDECREF(module);
    Py_XDECREF(path_isfile);
    Py_XDECREF(arguments);
    Py_XDECREF(ret_val);

    return result == 1;
}