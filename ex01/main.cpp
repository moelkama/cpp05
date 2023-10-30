#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  bur("mkatfi", 40);
        Form    var("istimara", 6, 3);
        var.beSigned(bur);
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
   return 0;
}