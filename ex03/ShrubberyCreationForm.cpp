#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137)
{
    // std::cout<<"ShrubberyCreationForm Default constractor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137)
{
    *this = other;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    this->AForm::operator=(other);
    this->target = other.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout<<"ShrubberyCreationForm Destructor called"<<std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() && executor.getGrade() <= this->getGradeExecute())
    {
        std::ofstream   out((target + "_shrubbery").c_str() , std::ofstream::out);
        out<<"          8              8              75     77\n";
        out<<"            9           9                875  57\n";
        out<<"             7         6                   76565     89\n";
        out<<"    98        56     56            6        565    96\n";
        out<<"      6       656  556        9     56    656    950\n";
        out<<"       56       5656      9  6       56  656   9560 \n";
        out<<"        656      56        656        5 656  9560\n";
        out<<"         1568     656     560         165568560\n";
        out<<"          17658    6558 546        56 645650\n";
        out<<"             17568  76bd56          564560\n";
        out<<"               14578  7658         644560\n";
        out<<"                 1458  16458      64456\n";
        out<<"                   14558 1455    64456\n";
        out<<"                     6458 7455  54456\n";
        out<<"                       54bd555bd5576\n";
        out<<"                         455555766\n";
        out<<"                         544555776\n";
        out<<"                        44444566988"<<std::endl;
        out.close();
    }
    else
        throw   std::out_of_range("ShrubberyCreationForm::execute::Grade is out of range");
}