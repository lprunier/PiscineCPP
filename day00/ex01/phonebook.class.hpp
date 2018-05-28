#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact.class.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class   book {

public:
    book(void);
    int     get_nb_contacts(void) const ;
    void    set_nb_contacts(void);
    void    addContact(contact contact);
    void    setContacts(void);
    contact get_contact(int id);

private:
    contact _contacts[8];
    int     _nb_contacts;
};

#endif