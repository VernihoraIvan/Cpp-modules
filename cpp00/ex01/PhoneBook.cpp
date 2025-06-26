/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:09:48 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:09:50 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->count = 0;
    this->max_count = MAX_CONTACTS;
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
	if (input.length() > MAX_FIELD_LENGTH)
	{
		str.resize(MAX_FIELD_LENGTH - 1);
		str.append(".");
	}
	std::cout << "|" << std::setw(MAX_FIELD_LENGTH) << std::right << str;
}

void PhoneBook::runPhoneBook(void)
{
    std::string command;
    std::cout << GREETING << std::endl;
    std::cout << COMMANDS << std::endl;
    while (1)
    {
        std::cout << ENTER_COMMAND;
        if (!std::getline(std::cin, command))
            break;
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
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    while (first_name.empty()) {
        std::cout << ENTER_FIRST_NAME;
        std::getline(std::cin, first_name);
        if (first_name.empty()) std::cout << FIELD_CANNOT_BE_EMPTY << std::endl;
    }
    while (last_name.empty()) {
        std::cout << ENTER_LAST_NAME;
        std::getline(std::cin, last_name);
        if (last_name.empty()) std::cout << FIELD_CANNOT_BE_EMPTY << std::endl;
    }
    while (nickname.empty()) {
        std::cout << ENTER_NICKNAME;
        std::getline(std::cin, nickname);
        if (nickname.empty()) std::cout << FIELD_CANNOT_BE_EMPTY << std::endl;
    }
    while (true) {
        std::cout << ENTER_PHONE_NUMBER;
        std::getline(std::cin, phone_number);
        if (!phone_number.empty() && isAllDigits(phone_number))
            break;
        if (phone_number.empty())
             std::cout << FIELD_CANNOT_BE_EMPTY << std::endl;
        else
            std::cout << PHONE_NUMBER_MUST_CONTAIN_ONLY_DIGITS << std::endl;
    }
    while (darkest_secret.empty()) {
        std::cout << ENTER_DARKEST_SECRET;
        std::getline(std::cin, darkest_secret);
        if (darkest_secret.empty()) std::cout << FIELD_CANNOT_BE_EMPTY << std::endl;
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
        std::cout << "|" << std::setw(MAX_FIELD_LENGTH) << std::right << i;
        this->printLine(this->contacts[i].getFirstName());
        this->printLine(this->contacts[i].getLastName());
        this->printLine(this->contacts[i].getNickname());
        std::cout << "|" << std::endl;
        std::cout << SEPARATOR << std::endl;
    }
    std::cout << ENTER_INDEX;
    if (!std::getline(std::cin, current_index))
        return;
    if (isAllDigits(current_index) && !current_index.empty())
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
