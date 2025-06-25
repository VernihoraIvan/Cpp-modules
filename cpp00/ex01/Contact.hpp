#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    public:
        Contact(void);
        Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        ~Contact(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);

    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

};


#endif