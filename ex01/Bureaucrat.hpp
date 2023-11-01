#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class Form;

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
    class GradeTooHighException: public std::exception
    {
        public:
            const char* what();
    };
    class GradeTooLowException: public std::exception
    {
        public:
            const char* what();
    };
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string     getName() const;
    int             getGrade() const;
    void            increment_grade();
    void            decrement_grade();
    void            signForm(Form form) const;
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bur);

#endif