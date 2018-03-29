#include "event_handler.h"

void zroya::EventHandler::toastActivated(INT64 notificationID) const {
    std::cout << "Cpp: EventHandler: Activated: " << notificationID << std::endl;
}
void zroya::EventHandler::toastActivated(int actionIndex, INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Activated2: " << notificationID << std::endl;
}
void zroya::EventHandler::toastDismissed(WinToastLib::IWinToastHandler::WinToastDismissalReason state, INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Dismiss: " << notificationID << std::endl;
}
void zroya::EventHandler::toastFailed(INT64 notificationID) const {
	std::cout << "Cpp: EventHandler: Failed: " << notificationID << std::endl;
}