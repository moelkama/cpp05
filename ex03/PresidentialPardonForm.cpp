#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    // std::cout<<"PresidentialPardonForm Default constractor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    this->AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout<<"PresidentialPardonForm Destructor called"<<std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() && executor.getGrade() <= this->getGradeExecute())
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        throw GradeTooLowException();
}