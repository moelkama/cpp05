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
    class               GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class               GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
public:
    Form();
    Form(std::string name, int grade_sign, int grade_execute);
    Form(const Form& other);
    Form&   operator=(const Form& other);
    ~Form();
    std::string getName() const;
    bool    getSign() const;
    int     getGradeSign() const;
    int     getGradeExecute() const;
    void    beSigned(const Bureaucrat& bur);
};

std::ostream&    operator<<(std::ostream& out, const Form& bur);

#endif