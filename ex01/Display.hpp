#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>

const std::string ExplanationHeader = "Welcome to the PhoneBook application.";
const std::string CommandMessage = "Enter the command ADD, SEARCH, or EXIT.\n";
const std::string Cursor = "> ";
const std::string CommandCursor = CommandMessage + Cursor;
const std::string ListSelectMessage =
    "Enter the index of the contact to view details:\n";
const std::string ListSelectCursor = ListSelectMessage + Cursor;
const std::string NoCommandMessage = "No command entered. Please try again.\n";
const std::string InvalidIndexMessage = "Invalid index. Please try again.\n";
const std::string NoContactsMessage = "No contacts available.\n";

// error messages
const std::string RuntimeErrorMessage =
    "An error occurred while running the PhoneBook application.\n";

class Display {
   public:
    static void show(const std::string &message);
    static void prompt(const std::string &message);
    static void error(const std::string &message);

   private:
    Display();
};

#endif /* DISPLAY_HPP */