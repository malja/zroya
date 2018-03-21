#pragma once
#include <string>

namespace zroya {

	/**
	 * Initialize WinToastLib with provided parameters.
	 */
    bool init(const std::string &app_name, const std::string &company_name, const std::string &product_name, const std::string &sub_product, const std::string &version);

	/**
	 * Initialize WinToastLib with random parameters. Used for automatical init when user does not call init function explicitly.
	 */
    bool init();
}