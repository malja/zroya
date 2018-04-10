#pragma once

#include "wintoastlib.h"
#include <Python.h>

namespace zroya {

	/**
	 * Notification handler. Each of toast* methods is called by WinToastLib when corresponding
	 * event fires. Event handler get a notification ID and looks if it has registered callback.
	 * If so, it is called.
	 */
    class EventHandler : public WinToastLib::IWinToastHandler {

        enum EventType {
            Activated,
            Action,
            Dismissed,
            Failed
        };

		class Event {
			
			public: 
				PyObject *clicked;
				PyObject *action;
				PyObject *failed;
				PyObject *dismissed;

				Event(PyObject *clicked, PyObject *action, PyObject *dismissed, PyObject *failed) {
					this->clicked = clicked;
					this->action = action;
					this->dismissed = dismissed;
					this->failed = failed;
				}

				~Event() {
					Py_XDECREF(this->clicked);
					Py_XDECREF(this->action);
					Py_XDECREF(this->dismissed);
					Py_XDECREF(this->failed);
				}

		};

        public:
            void toastActivated(INT64 notificationID) const;
            void toastActivated(int actionIndex, INT64 notificationID) const;
            void toastDismissed(WinToastDismissalReason state, INT64 notificationID) const;
            void toastFailed(INT64 notificationID) const;

            void addCallbacks(INT64 notificationID, PyObject *activated, PyObject *action = nullptr, PyObject *dismissed = nullptr, PyObject *failed = nullptr);

			~EventHandler() {
				for (auto it = callbacks.begin(); it != callbacks.end(); it++) {
					delete it->second;
				}
			}
            
        protected:

            std::map<INT64, Event*> callbacks;
    };
}