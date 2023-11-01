#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Name not set")//grade
{
    // std::cout<<"Bureaucrat Default Constractor Called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
    this->grade = grade;
    if (grade > 150)
        throw   GradeTooLowException();
    else if (grade < 1)
        throw   GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout<<"Bureaucrat Destructor Called"<<std::endl;
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
        throw   GradeTooHighException();
    this->grade--;
}

void    Bureaucrat::decrement_grade()
{
    if (this->grade >= 150)
        throw   GradeTooLowException();
    this->grade++;
}

std::ostream&    operator<<(std::ostream& out, const Bureaucrat& bur)
{
    out<<bur.getName()<<", bureaucrat grade "<<bur.getGrade();
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what()
{
    return ("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what()
{
    return ("Bureaucrat::GradeTooLowException");
}

void    Bureaucrat::signForm(Form form) const
{
    try
    {
        form.beSigned(*this);
        std::cout<<this->name<<" signed "<<form.getName()<<std::endl;
    }
    catch(std::exception& e)
    {
        std::cout<<this->name<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
    }
}