#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    // std::cout<<"RobotomyRequestForm Default constractor called"<<std::endl
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    this->AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout<<"RobotomyRequestForm Destructor called"<<std::endl
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
}