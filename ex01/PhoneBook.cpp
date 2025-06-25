#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->count = 0;
    this->max_count = 8;
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void PhoneBook::printContact(int index)
{
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::printLine(std::string input)
{
	std::string str = input;
	if (input.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << "|" << std::setw(10) << std::right << str;
}

void PhoneBook::runPhoneBook(void)
{
    std::string command;
    std::cout << GREETING << std::endl;
    std::cout << COMMANDS << std::endl;
    while (1)
    {
        std::cout << ENTER_COMMAND;
        std::cin >> command;
        if (command == "ADD")
        {
            this->processAdd();
        }
        else if (command == "SEARCH")
        {
            this->processSearch();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << INVALID_COMMAND << std::endl;
        }
    }
}

void PhoneBook::processAdd(void)
{
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        while (1)
        {
            std::cout << ENTER_FIRST_NAME;
            std::cin >> first_name;
            std::cout << ENTER_LAST_NAME;
            std::cin >> last_name;
            std::cout << ENTER_NICKNAME;
            std::cin >> nickname;
            std::cout << ENTER_PHONE_NUMBER;
            std::cin >> phone_number;
            while (!isAllDigits(phone_number))
            {
                std::cout << PHONE_NUMBER_MUST_CONTAIN_ONLY_DIGITS << std::endl;
                std::cout << ENTER_PHONE_NUMBER;
                std::cin >> phone_number;
            }
            std::cout << ENTER_DARKEST_SECRET;
            std::cin >> darkest_secret;
            break;
        }
    this->addContact(first_name, last_name, nickname, phone_number, darkest_secret);
}


void PhoneBook::processSearch(void)
{
    std::string current_index;
    std::cout << SEPARATOR << std::endl;
    std::cout << HEADER << std::endl;
    std::cout << SEPARATOR << std::endl;
    for (int i = 0; i < this->count; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i;
        this->printLine(this->contacts[i].getFirstName());
        this->printLine(this->contacts[i].getLastName());
        this->printLine(this->contacts[i].getNickname());
        std::cout << "|" << std::endl;
        std::cout << SEPARATOR << std::endl;
    }
    std::cin >> current_index;
    if (isAllDigits(current_index))
    {
        int index = std::stoi(current_index);
        if (index >= count || index < 0)
        {
            std::cout << INDEX_OUT_OF_RANGE << std::endl;
            return;
        }
        if (index >= 0 && index < this->count)
        {
            this->printContact(index);
        }
    }
    else {
        std::cout << INDEX_MUST_BE_A_NUMBER << std::endl;
    }
}

void PhoneBook::addContact(std::string new_first_name, std::string new_last_name, std::string new_nickname, std::string new_phone_number, std::string new_darkest_secret)
{
    if (this->count >= this->max_count)
    {
        for (int i = this->max_count - 1; i > 0; i--)
        {
            this->contacts[i] = this->contacts[i - 1];
        }
        this->contacts[0] = Contact(new_first_name, new_last_name, new_nickname, new_phone_number, new_darkest_secret);
        this->count = this->max_count;
        return;
    }
    this->contacts[this->count] = Contact(new_first_name, new_last_name, new_nickname, new_phone_number, new_darkest_secret);
    this->count++;
}
