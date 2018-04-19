#pragma once

#include <Python.h>

#ifdef __cplusplus
    extern "C" {
#endif

		/**
		 * File with some utilities for zroya module.
		 */

		/// Call python os.path.isfile to ensure file 'file_name' exists.
        bool file_exists(PyObject *file_name);

		/// Call Python function os.path.abspath to get absolute path from 'relpath'.
		/// Returns Py_False on error.
		PyObject *abspath(PyObject *relpath);

#ifdef __cplusplus
    }
#endif