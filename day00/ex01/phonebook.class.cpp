#include "phonebook.class.hpp"

book::book(void) {
    this->_nb_contacts = 0;
}

int     book::get_nb_contacts(void) const {
    return(this->_nb_contacts);
}

void    book::set_nb_contacts(void) {
    this->_nb_contacts++;
}

void    book::addContact(contact contact) {
    int i = this->_nb_contacts;
    this->_contacts[i] = contact;
    std::cout << contact.nickname << " is now on your phonebook." << std::endl;
}

void    book::setContacts(void) {
    std::cout << "    id    |first name|last name | nickname " << std::endl;
    std::cout << "__________|__________|__________|__________" << std::endl;
    std::cout << "          |          |          |          " << std::endl;
    for (int i = 0; i < this->_nb_contacts; ++i) {
        
        std::cout << std::setw(10) << i + 1 << std::setfill(' ') << "|";

        std::string firstname = this->_contacts[i].firstname;
		if (firstname.size() > 10)
			firstname = firstname.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstname << std::setfill(' ') << "|";

		std::string lastname = this->_contacts[i].lastname;
		if (lastname.size() > 10)
			lastname = lastname.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastname << std::setfill(' ') << "|";

		std::string nickname = this->_contacts[i].nickname;
		if (nickname.size() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << std::setfill(' ') << std::endl;
    }
    std::cout << "          |          |          |          " << std::endl;
}

contact book::get_contact(int id) {
    return (this->_contacts[id]);
}