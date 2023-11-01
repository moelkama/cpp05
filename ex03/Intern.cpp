#include "Intern.hpp"

Intern::Intern()
{
    // std::cout<<"Intern Default Constractor Called"<<std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern&    Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    // std::cout<<"Intern Destructor Called"<<std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
    AForm       *ptr[3] = {new PresidentialPardonForm(target), new ShrubberyCreationForm(target), new RobotomyRequestForm(target)};
    AForm       *form;
    std::string msg("the form name passed as parameter doesn’t exist");

    form = NULL;
    for (int i = 0; i < 3; i++)
    {
        if (ptr[i]->getName() == name)
        {
            form = ptr[i];
            msg = "Intern creates " + name;
        }
        else
            delete ptr[i];
    }
    std::cout<<msg<<std::endl;
    return (form);
}