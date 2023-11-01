#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;

class  AForm
{
private:
    const std::string   name;
    const int           grade_sign;
    const int           grade_execute;
    bool                sign;
public:
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
    AForm();
    AForm(std::string name, int grade_sign, int grade_execute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool    getSign() const;
    int     getGradeSign() const;
    int     getGradeExecute() const;
    void    beSigned(Bureaucrat bur);
    virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&    operator<<(std::ostream& out, const AForm& bur);

#endif