#include <locale>
#include <codecvt>
#include <sstream>
#include <random>

#include "utils.h"

std::wstring zroya::convert(const char* text) {
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return std::wstring(converter.from_bytes(text));
}

std::wstring zroya::convert(const std::string &text) {
    std::wostringstream convert;
    convert << text.c_str();
    return std::wstring(convert.str());
}

std::string zroya::random_string(int max_length) {

    std::string possible_characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(0, possible_characters.size() - 1);
    std::string ret = "";

    for (int i = 0; i < max_length; i++) {
        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
        ret += possible_characters[random_index];
    }

    return ret;
}