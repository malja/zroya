#include <Python.h>

#include "wintoastlib.h"
#include "event_handler.h"

#ifdef __cplusplus
    extern "C" {
#endif

		/**
		 * This file defines few core functions required for zroya module.
		 */

		 /// Zroya global state
		typedef struct {
			/// Underhood library for notifications
			WinToastLib::WinToast *_win_toast;
			/// My custom event handler
			zroya::EventHandler *_handler;
		} zroya_State;

        PyDoc_STRVAR(zroya_init__doc__,
            "init(app_name, company_name, product_name, sub_product, version)\n"
            "--\n\n"
            "Initialize Zroya module. \n"
			"\n"
			"**Note**: You should call this function before any other manipulation with this module. \n"
            "If you do not call this function explicitely, randomly generated strings will be used as default parameters. \n"
			"\n"
			"Args: \n"
			"\tapp_name (str): Application name. \n\n"
			"\tcompany_name (str): Part of unique ID created for this application. \n\n"
			"\tproduct_name (str): Part of unique ID created for this application. \n\n"
			"\tsub_product (str): Part of unique ID created for this application. \n\n"
			"\tstr version (str): Part of unique ID created for this application. \n\n"
            "\n"
			"Returns: \n"
			"\tbool: True if initialization is completed, False otherwise."
        );
        PyObject *zroya_init(PyObject *self, PyObject *args, PyObject *kwargs);

        PyDoc_STRVAR(zroya_show__doc__,
            "show(template, on_click=None, on_action=None, on_dismiss=None, on_fail=None)\n"
            "--\n\n"
			"Create instance of notification template and show it. If any of on_* parameter is set, corresponding event is registered. See :doc:`tutorials/callbacks`.\n"
			"\n"
			"Args: \n"
			"\ttemplate (:py:class:`zroya.Template`): Template instance. \n\n"
			"\ton_click (callable): Callback for onClick event. Occurs when user activates a toast notification through a click or touch. \n\n"
			"\ton_action (callable): Callback for onAction event. Occurs when user click on action button. \n\n"
			"\ton_dismiss (callable): Callback for onDismiss event. Occurs when the notification leaves the screen, either by expiring or being explicitly dismissed by the user. \n\n"
			"\ton_fail (callable): Callback for onFail event. Occurs when an error is caused when Windows attempts to raise a toast notification. \n\n"
			"\n"
			"Returns: \n"
			"\tbool: Notification ID if notification was shown. False otherwise."
        );
        PyObject *zroya_show(PyObject *module, PyObject *args, PyObject *kwargs);
        
        PyDoc_STRVAR(zroya_hide__doc__,
            "hide(nid)\n"
            "--\n\n"
            "Hide notification by ID. This will trigger onDismiss event.\n"
			"\n"
			"Args: \n"
			"\tnid (int): Notification ID obtained from :py:func:`zroya.show` function. \n"
			"\n"
			"Returns: \n"
			"\tbool: True if notification was hidden, false otherwise."
        );
        PyObject *zroya_hide(PyObject *module, PyObject *arg, PyObject *kwarg);

#ifdef __cplusplus
    }
#endif