#include "Form.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  bur("mkatfi", 100);
        Form        form("istimara", 1, 21);
        bur.signForm(form);
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
   return 0;
}