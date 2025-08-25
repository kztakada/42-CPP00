#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>

class Display {
   public:
    static void show(const std::string& message);
    static void show(const char* message);
    static void prompt(const std::string& message);
    static void error(const std::string& message);

    // Message constants as static members
    static const char* const EXPLANATION_HEADER;
    static const char* const COMMAND_MESSAGE;
    static const char* const CURSOR;
    static const char* const LIST_SELECT_MESSAGE;
    static const char* const NO_COMMAND_MESSAGE;
    static const char* const INVALID_INDEX_MESSAGE;
    static const char* const NO_CONTACTS_MESSAGE;
    static const char* const RUNTIME_ERROR_MESSAGE;

    // Utility methods for composite messages
    static std::string getCommandCursor();
    static std::string getListSelectCursor();

   private:
    Display();
};

#endif /* DISPLAY_HPP */