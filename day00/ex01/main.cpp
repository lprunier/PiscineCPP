#include "phonebook.class.hpp"

void    add(book *phonebook) {
    contact contact;

    if (phonebook->get_nb_contacts() >= 8) {
        std::cout << "Your phonebook is full." << std::endl;
        return ;
    }
    std::cout << "First name: ";
    std::getline(std::cin, contact.firstname);
    std::cout << "Last name: ";
    std::getline(std::cin, contact.lastname);
    std::cout << "Nickname: ";
    std::getline(std::cin, contact.nickname);
    std::cout << "Login: ";
    std::getline(std::cin, contact.login);
    std::cout << "Postal address: ";
    std::getline(std::cin, contact.address);
    std::cout << "Email address: ";
    std::getline(std::cin, contact.email);
    std::cout << "Phone number: ";
    std::getline(std::cin, contact.phone);
    std::cout << "Birthday date: ";
    std::getline(std::cin, contact.birthday);
    std::cout << "Favorite meal: ";
    std::getline(std::cin, contact.meal);
    std::cout << "Underwear color: ";
    std::getline(std::cin, contact.underwear);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, contact.secret);

    phonebook->addContact(contact);
    phonebook->set_nb_contacts();
}

void    search(book *phonebook) {

    if (phonebook->get_nb_contacts() == 0) {
        std::cout << "Your phonebook is empty... So sad!" << std::endl;
        return ;
    }
    phonebook->setContacts();
    std::string rep;
    std::cout << "Wich id did you choose? ";
    std::getline(std::cin, rep);
    
    int id = rep[0] - '0' - 1;
    if (rep.length() != 1 || id < 0 || id >= phonebook->get_nb_contacts())
        std::cout << "Invalid id." << std::endl;
    else {
        contact contact = phonebook->get_contact(id);
        std::cout << std::endl << "First name: " << contact.firstname << std::endl;
        std::cout << "Last name: " << contact.lastname << std::endl;
        std::cout << "Nickname: " << contact.nickname << std::endl;
        std::cout << "Login: " << contact.login << std::endl;
        std::cout << "Postal address: " << contact.address << std::endl;
        std::cout << "Email address: " << contact.email << std::endl;
        std::cout << "Phone number: " << contact.phone << std::endl;
        std::cout << "Birthday date: " << contact.birthday << std::endl;
        std::cout << "Favorite meal: " << contact.meal << std::endl;
        std::cout << "Underwear color: " << contact.underwear << std::endl;
        std::cout << "Darkest secret: " << contact.secret << std::endl << std::endl;
    }
}

int     main(void) {
    std::string input;
    book        phonebook;

    std::cout << "Welcome in your PhoneBook :)" << std::endl;
    while (1) {
        std::cout << "Do you want to ADD, SEARCH or EXIT?" << std::endl;
        std::cout << "_";
        getline(std::cin, input);
        if (input.compare("EXIT") == 0)
            break ;
        else if (input.compare("ADD") == 0)
            add(&phonebook);
        else if (input.compare("SEARCH") == 0)
            search(&phonebook);
        else
            std::cout << "Sorry, I don't understand, you can try again... ¯\\_(ツ)_/¯" << std::endl;
        
    }
    std::cout << "Bye! See you soon..." << std::endl;
    return 0;
}