#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("form name not set"), grade_sign(1), grade_execute(1)
{
    this->sign = 0;
    // std::cout<<"AForm Default constractor called"<<std::endl;
}

AForm::AForm(std::string name, int grade_sign, int grade_execute):name(name), grade_sign(grade_sign), grade_execute(grade_execute) 
{
    this->sign = 0;
    if (this->grade_execute < 1 || this->grade_sign < 1)
        throw   GradeTooHighException();
    if (this->grade_execute > 150 || this->grade_sign > 150)
        throw   GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    *this = other;
}

AForm& AForm::operator=(const AForm& other)
{
    this->sign = other.sign;
    return (*this);
}

AForm::~AForm()
{
    // std::cout<<"AForm Default Destructor called"<<std::endl;
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSign() const
{
    return (this->sign);
}

int AForm::getGradeSign() const
{
    return (this->grade_sign);
}

int AForm::getGradeExecute() const
{
    return (this->grade_execute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form::GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form::GradeTooLowException");
}

void    AForm::beSigned(Bureaucrat bur)
{
    if (bur.getGrade() <= this->grade_sign)
        sign = 1;
    else
        throw GradeTooLowException();
}

std::ostream&    operator<<(std::ostream& out, const AForm& form)
{
    out<<"Aform's name : "<<form.getName()<<" sign status :"<<form.getSign()<<" it's sign grade : "<<form.getGradeSign()<<" and excute grade : "<<form.getGradeExecute();
    return (out);
}