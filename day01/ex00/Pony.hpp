#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class   Pony {
public:
    Pony(std::string name, std::string color, std::string runner, int rank);
    ~Pony(void);
    std::string get_name(void) const;
    std::string get_placement(void) const;
    std::string get_runner(void) const;
    int         get_rank(void) const;

private:
    std::string _name;
    std::string _placement;
    std::string _runner;
    int         _rank;
};

#endif