#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
public:
    Bureaucrat(std::string name, int grade);
    std::string     getName() const;
    int             getGrade() const;
    void            increment_grade();
    void            decrement_grade();
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bur);

#endif