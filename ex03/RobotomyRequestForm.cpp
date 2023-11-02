#include "RobotomyRequestForm.hpp"
#include <cstdlib>

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

void    RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
    std::string info[2] = {" has been robotomized successfully.", " the robotomy failed."};
    srand(time(0));
    if (this->getSign() && executor.getGrade() <= this->getGradeExecute())
    {
        std::cout<<"some drilling noises"<<std::endl;
        std::cout<<this->target<<info[rand() % 2]<<std::endl;
    }
    else
        throw GradeTooLowException();
}