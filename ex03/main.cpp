#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat  bur("mkatfi", 2);
        Intern      intern;
        AForm *form = intern.makeForm("RobotomyRequestForm", "ayub");

        bur.signForm(*form);
        bur.executeForm(*form);
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    while (1);
   return 0;
}