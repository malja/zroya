#include "event_handler.h"

void zroya::EventHandler::toastActivated(INT64 notificationID) const {
    std::cout << "ID: " << notificationID << " activated 1" << std::endl;
}
void zroya::EventHandler::toastActivated(int actionIndex, INT64 notificationID) const {
	std::cout << "ID: " << notificationID << " activated 2" << std::endl;
}
void zroya::EventHandler::toastDismissed(WinToastLib::IWinToastHandler::WinToastDismissalReason state, INT64 notificationID) const {
	std::cout << "ID: " << notificationID << " dismiss" << std::endl;
}
void zroya::EventHandler::toastFailed(INT64 notificationID) const {
	std::cout << "ID: " << notificationID << " failed" << std::endl;
}