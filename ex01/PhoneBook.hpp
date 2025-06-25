#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

#define MAX_CONTACTS 8
#define MAX_FIELD_LENGTH 10
#define SEPARATOR "|----------|----------|----------|----------|"
#define HEADER "|   Index  |First Name| Last Name| Nickname |"
#define GREETING "Welcome to your PhoneBook!"
#define COMMANDS "Available commands: ADD, SEARCH, EXIT"
#define INVALID_COMMAND "Invalid command"
#define ENTER_FIRST_NAME "Enter a first name: "
#define ENTER_LAST_NAME "Enter a last name: "
#define ENTER_NICKNAME "Enter a nickname: "
#define ENTER_PHONE_NUMBER "Enter a phone number: "
#define ENTER_DARKEST_SECRET "Enter a darkest secret: "
#define ENTER_COMMAND "Enter a command: "
#define INDEX_OUT_OF_RANGE "Index is out of range"
#define INDEX_MUST_BE_A_NUMBER "Index must be a number"
#define PHONE_NUMBER_MUST_CONTAIN_ONLY_DIGITS "Phone number must contain only digits"

class PhoneBook {
    public:
    PhoneBook(void);
    ~PhoneBook(void);

    void runPhoneBook(void);


    private:
    void addContact(std::string new_first_name, std::string new_last_name, std::string new_nickname, std::string new_phone_number, std::string new_darkest_secret);
    void processAdd(void);
    void printLine(std::string field);
    void processSearch(void);
    void printContact(int index);

    private:
    Contact contacts[8];
    int count;
    int max_count;

};

bool isAllDigits(const std::string& str);

#endif