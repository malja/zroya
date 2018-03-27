#pragma once

#include "wintoastlib.h"

namespace zroya {

	/**
	 * Notification handler. Each of toast* methods is called by WinToastLib when corresponding
	 * event fires. Event handler get a notification ID and looks if it has registered callback.
	 * If so, it is called.
	 */
    class EventHandler : public WinToastLib::IWinToastHandler {
        void toastActivated(INT64 notificationID) const;
        void toastActivated(int actionIndex, INT64 notificationID) const;
        void toastDismissed(WinToastDismissalReason state, INT64 notificationID) const;
        void toastFailed(INT64 notificationID) const;
    };
}