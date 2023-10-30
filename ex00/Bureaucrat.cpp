#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
    if (grade > 150)
        throw   std::out_of_range("Bureaucrat::GradeTooLowException");
    else if (grade < 1)
        throw   std::out_of_range("Bureaucrat::GradeTooHighException");
    this->grade = grade;
}

std::string     Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::increment_grade()
{
    if (this->grade <= 1)
        throw   std::out_of_range("Bureaucrat::GradeTooHighException");
    this->grade--;
}

void    Bureaucrat::decrement_grade()
{
    if (this->grade >= 150)
        throw   std::out_of_range("Bureaucrat::GradeTooLowException");
    this->grade++;
}

std::ostream&    operator<<(std::ostream& out, const Bureaucrat& bur)
{
    out<<bur.getName()<<", bureaucrat grade "<<bur.getGrade();
    return (out);
}