#pragma once
#include <string>

namespace zroya {

	/**
	 * Convert const char* to std::wstring.
	 */
    std::wstring convert(const char* text);

	/**
	 * Convert std::string to std::wstring.
	 */
    std::wstring convert(const std::string &text);

	/**
	 * Generate random string of selected length.
	 */
    std::string random_string(int max_length);

}