#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  var("mkatfi", 150);
        var.decrement_grade();
        std::cout<<var<<std::endl;
        var.increment_grade();
        std::cout<<var<<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what()<<std::endl;
    }
    return 0;
}