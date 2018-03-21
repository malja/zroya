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

#ifdef __cplusplus
    }
#endif