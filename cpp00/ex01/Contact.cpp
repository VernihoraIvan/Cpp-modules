/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanvernihora <ivanvernihora@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:09:40 by ivanverniho       #+#    #+#             */
/*   Updated: 2025/06/26 23:09:41 by ivanverniho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void) {
    return;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

Contact::~Contact(void)
{
    return;
}

std::string Contact::getFirstName(void)
{
    return this->first_name;
}

std::string Contact::getLastName(void)
{
    return this->last_name;
}

std::string Contact::getNickname(void)
{
    return this->nickname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->phone_number;
}

std::string Contact::getDarkestSecret(void)
{
    return this->darkest_secret;
}