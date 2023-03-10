#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &w);
    Warlock& operator=(Warlock const &w);

    public:
    std::string const & getName() const;
    std::string const & getTitle() const;

    void setTitle(std::string const & new_title);
    Warlock(std::string new_name, std::string new_title);
    ~Warlock();

    void introduce() const;
};

#endif