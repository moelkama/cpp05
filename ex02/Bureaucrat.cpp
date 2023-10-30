#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    // std::cout<<"Bureaucrat Default Constractor called"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
    if (grade > 150)
        throw   std::out_of_range("Bureaucrat::GradeTooLowException");
    else if (grade < 1)
        throw   std::out_of_range("Bureaucrat::GradeTooHighException");
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name)
{
    *this = other;
}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return (*this);
}

std::string     Bureaucrat::getName() const
{
    return (this->name);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout<<"Bureaucrat Destructor called"<<std::endl;
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

void    Bureaucrat::signForm(const AForm& form) const
{
    if (this->grade <= form.getGradeSign())
        std::cout<<this->name<<" signed "<<form.getName();
    else
        std::cout<<this->name<<" couldn't sign "<<form.getName()<<" because permission denied"<<std::endl;
}

void    Bureaucrat::executeForm(const AForm& form)
{
    try
    {
        form.execute(*this);
        std::cout<<this->getName()<<" executed "<<form.getName()<<" successfuly"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}