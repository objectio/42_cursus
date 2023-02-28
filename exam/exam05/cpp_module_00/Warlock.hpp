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
    std::string getName() const;
    std::string getTitle() const;

    void setTitle(std::string title);
    Warlock(std::string name, std::string title);
    ~Warlock();
};

#endif