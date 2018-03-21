#pragma once

#include "py_init.h"
#include "py_template.h"
#include "event_handler.h"
#include "py_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * This file sets a new python module - zroya. Coresponding Cpp file contains module
	 * entry point and all required function for creation and destruction of this module.
	 */

	PyDoc_STRVAR(zroya__doc__,
		"zroya\n"
		"--\n\n"
		"Library for creating native Windows 8, Window 9 and Windows 10 notifications. \n"
	);

#ifdef __cplusplus
}
#endif