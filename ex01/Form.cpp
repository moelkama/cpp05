#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form name not set"), grade_sign(1), grade_execute(1)
{
    this->sign = 0;
    // std::cout<<"Form Default Constrator called"<<std::endl;
}

Form::Form(std::string name, int grade_sign, int grade_execute):name(name), grade_sign(grade_sign), grade_execute(grade_execute) 
{
    this->sign = 0;
    if (this->grade_execute < 1 || this->grade_sign < 1)
        throw   GradeTooHighException();
    if (this->grade_execute > 150 || this->grade_sign > 150)
        throw   GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), grade_sign(other.grade_sign), grade_execute(other.grade_execute)
{
    *this = other;
}

Form&   Form::operator=(const Form& other)
{
    this->sign = other.sign;
    return (*this);
}

Form::~Form()
{
    // std::cout<<"Form Destrutor called"<<std::endl;
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSign() const
{
    return (this->sign);
}

int Form::getGradeSign() const
{
    return (this->grade_sign);
}

int Form::getGradeExecute() const
{
    return (this->grade_execute);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form::GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form::GradeTooLowException");
}

void    Form::beSigned(const Bureaucrat& bur)
{
    if (bur.getGrade() <= this->grade_sign)
        sign = 1;
    else
        throw GradeTooLowException();
}

std::ostream&    operator<<(std::ostream& out, const Form& form)
{
    out<<"form's name : "<<form.getName()<<" sign status :"<<form.getSign()<<" it's sign grade : "<<form.getGradeSign()<<" and excute grade : "<<form.getGradeExecute();
    return (out);
}