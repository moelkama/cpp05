#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int grade_sign, int grade_execute):name(name), grade_sign(grade_sign), grade_execute(grade_execute) 
{
    this->sign = 0;
    if (this->grade_execute < 1 || this->grade_sign < 1)
        throw   std::out_of_range("Form::GradeTooHighException");
    if (this->grade_execute > 150 || this->grade_sign > 150)
        throw   std::out_of_range("Form::GradeTooLowException");
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

void    Form::beSigned(Bureaucrat bur)
{
    if (bur.getGrade() <= this->grade_sign)
        sign = 1;
    else
        throw std::out_of_range("Form::GradeTooLowException");
}

std::ostream&    operator<<(std::ostream& out, const Form& form)
{
    out<<"form's name : "<<form.getName()<<" sign status :"<<form.getSign()<<" it's sign grade : "<<form.getGradeSign()<<" and excute grade : "<<form.getGradeExecute();
    return (out);
}