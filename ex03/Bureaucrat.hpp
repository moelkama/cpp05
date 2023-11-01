#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class AForm;

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
    void            signForm(AForm& form) const;
    void            executeForm(const AForm & form);
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bur);

#endif