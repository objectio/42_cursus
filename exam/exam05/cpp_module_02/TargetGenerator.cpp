#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}
void TargetGenerator::learnTargetType(ATarget* target)
{
    Target_Book::iterator it = target_book.find(target->getType());
    if (it == target_book.end())
    {
        target_book.insert(Target(target->getType(), target->clone()));
    }
}

void TargetGenerator::forgetTargetType(std::string const & name)
{
    Target_Book::iterator it = target_book.find(name);
    if (it != target_book.end())
    {
        delete it->second;
        target_book.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const & name)
{
    Target_Book::iterator it = target_book.find(name);
    if (it != target_book.end())
        return it->second;
    return NULL;
}