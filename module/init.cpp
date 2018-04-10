#include "wintoastlib.h"
#include "utils.h"
#include "init.h"

bool zroya::init(const std::string &app_name, const std::string &company_name, const std::string &product_name, const std::string &sub_product, const std::string &version) {

    // Set application name
    WinToastLib::WinToast::instance()->setAppName(
        convert(app_name)
    );

    // Setup new application ID
    WinToastLib::WinToast::instance()->setAppUserModelId(
        WinToastLib::WinToast::configureAUMI(
            convert(company_name), convert(product_name), convert(sub_product), convert(version)
        )
    );

    // Init WinToast library
    if (!WinToastLib::WinToast::instance()->initialize()) {
        return false;
    }

    return true;
}

/**
* Initialize library with random strings as company_name, product_name, sub_product and version. This version
* will be called when user does not call init explicitly.
*/
bool zroya::init() {
    return zroya::init(
        std::string("python"),
        random_string(5),
        random_string(5),
        random_string(5),
        random_string(5)
    );
}