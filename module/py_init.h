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
            "Initialize Zroya module. You should call this function before any other manipulation with this module. \n"
            "If you do not call this function explicitely, randomly generated strings will be used as default parameters. \n"
            ":param str app_name: Application name. \n"
            ":param str company_name: Part of unique ID created for this application. \n"
            ":param str product_name: Part of unique ID created for this application. \n"
            ":param str sub_product: Part of unique ID created for this application. \n"
            ":param str version: Part of unique ID created for this application. \n"
            ":return: True if initialization is completed, False otherwise."
        );
        PyObject *zroya_init(PyObject *self, PyObject *args, PyObject *kwargs);

        PyDoc_STRVAR(zroya_show__doc__,
            "show(template, on_click=None, on_action=None, on_dismiss=None, on_fail=None)\n"
            "--\n\n"
            "Show selected notification template. If any of on_* parameter is set, corresponding event is registered. \n"
			":param zroya.Template template: Template instance. \n"
			":param callable on_click: Callback for OnClick event. Occurs when user activates a toast notification through a click or touch. \n"
			":param callable on_action: Callback for OnAction event. Occurs when user click toast notification action button. \n"
			":param callable on_dismiss: Callback for OnDismiss event. Occurs when a toast notification leaves the screen, either by expiring or being explicitly dismissed by the user. \n"
			":param callable on_fail: Callback for OnFail event. Occurs when an error is caused when Windows attempts to raise a toast notification. \n"
			":return: Notification ID if notification was shown. False otherwise."
        );
        PyObject *zroya_show(PyObject *module, PyObject *args, PyObject *kwargs);
        
        PyDoc_STRVAR(zroya_hide__doc__,
            "hide(nid)\n"
            "--\n\n"
            "Hide notification by ID. \n"
			":param integer nid: Notification ID obtained from zroya.show function. \n"
			":return: True if notification was hidden, false otherwise."
        );
        PyObject *zroya_hide(PyObject *module, PyObject *arg, PyObject *kwarg);

#ifdef __cplusplus
    }
#endif