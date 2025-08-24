#include "Display.hpp"

Display::Display() {}

void Display::show(const std::string& message) {
    std::cout << message << std::endl;
}
void Display::prompt(const std::string& message) {
    std::cout << message << std::flush;
}
void Display::error(const std::string& message) {
    std::cerr << message << std::endl;
}
