#include "event_handler.h"

void zroya::EventHandler::toastActivated(INT64 notificationID) const {
    std::cout << "Cpp: EventHandler: Activated: " << notificationID << std::endl;
	
	auto it = this->callbacks.find(notificationID);
	if (it != this->callbacks.end()) {

		std::cout << "Cpp: EventHandler: Activated: Event found" << std::endl;

		PyObject *onClicked = it->second->clicked;

		if (onClicked) {

			std::cout << "Cpp: EventHandler: Activated: Event handler is set" << std::endl;

			if (PyCallable_Check(onClicked)) {

				std::cout << "Cpp: EventHandler: Activated: Event handler is callable" << std::endl;
				
				PyGILState_STATE gstate;
				gstate = PyGILState_Ensure();

				PyObject *args = Py_BuildValue("(L)", notificationID);

				PyObject_CallObject(onClicked, args);

				PyGILState_Release(gstate);
			}
		}
	}
}

void zroya::EventHandler::toastActivated(int actionIndex, INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Activated2: " << notificationID << std::endl;

	auto it = this->callbacks.find(notificationID);
	if (it != this->callbacks.end()) {

		std::cout << "Cpp: EventHandler: Activated2: Event found" << std::endl;

		PyObject *onAction = it->second->action;

		if (onAction) {

			std::cout << "Cpp: EventHandler: Activated2: Event handler is set" << std::endl;

			if (PyCallable_Check(onAction)) {

				std::cout << "Cpp: EventHandler: Activated2: Event handler is callable" << std::endl;

				PyGILState_STATE gstate;
				gstate = PyGILState_Ensure();

				PyObject *args = Py_BuildValue("(L, i)", notificationID, actionIndex);

				PyObject_CallObject(onAction, args);

				PyGILState_Release(gstate);
			}
		}
	}
}

void zroya::EventHandler::toastDismissed(WinToastLib::IWinToastHandler::WinToastDismissalReason state, INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Dismiss: " << notificationID << std::endl;

	auto it = this->callbacks.find(notificationID);
	if (it != this->callbacks.end()) {

		std::cout << "Cpp: EventHandler: Dismiss: Event found" << std::endl;

		PyObject *onDismiss = it->second->dismissed;

		if (onDismiss) {

			std::cout << "Cpp: EventHandler: Dismiss: Event handler is set" << std::endl;

			if (PyCallable_Check(onDismiss)) {

				std::cout << "Cpp: EventHandler: Dismiss: Event handler is callable" << std::endl;

				PyGILState_STATE gstate;
				gstate = PyGILState_Ensure();

				PyObject *zroya_module = PyImport_ImportModule("zroya");
				if (!zroya_module) {
					std::cout << "no zroya module" << std::endl;
					return;
				}

				PyObject *zroya_DissmissReason = PyObject_GetAttrString(zroya_module, "DismissReason");
				if (!zroya_DissmissReason) {
					std::cout << "No dismiss reason class" << std::endl;
					return;
				}

				PyObject* zroya_DismissReason_instance = PyObject_CallFunction(zroya_DissmissReason, "i", (int)state);
				PyObject *args = Py_BuildValue("(L, O)", notificationID, zroya_DismissReason_instance);
				//PyObject *args = Py_BuildValue("(L, i)", notificationID, (int)state );

				PyObject_CallObject(onDismiss, args);

				PyGILState_Release(gstate);
			}
		}
	}
}

void zroya::EventHandler::toastFailed(INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Failed: " << notificationID << std::endl;

	auto it = this->callbacks.find(notificationID);
	if (it != this->callbacks.end()) {

		std::cout << "Cpp: EventHandler: Failed: Event found" << std::endl;

		PyObject *onFailed = it->second->failed;

		if (onFailed) {

			std::cout << "Cpp: EventHandler: Failed: Event handler is set" << std::endl;

			if (PyCallable_Check(onFailed)) {

				std::cout << "Cpp: EventHandler: Failed: Event handler is callable" << std::endl;

				PyGILState_STATE gstate;
				gstate = PyGILState_Ensure();

				PyObject *args = Py_BuildValue("(L)", notificationID);

				PyObject_CallObject(onFailed, args);

				PyGILState_Release(gstate);
			}
		}
	}
}

void zroya::EventHandler::addCallbacks(INT64 notificationID, PyObject *clicked, PyObject *action, PyObject *dismissed, PyObject *failed) {

    this->callbacks.insert(
		std::pair<INT64, Event*>(
			notificationID, 
			new Event(clicked, action, dismissed, failed)
		)
	);
}