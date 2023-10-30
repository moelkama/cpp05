#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
private:
    const std::string   name;
    const int           grade_sign;
    const int           grade_execute;
    bool                sign;
public:
    Form(std::string name, int grade_sign, int grade_execute);
    std::string getName() const;
    bool    getSign() const;
    int     getGradeSign() const;
    int     getGradeExecute() const;
    void    beSigned(Bureaucrat bur);
};

std::ostream&    operator<<(std::ostream& out, const Form& bur);

#endif