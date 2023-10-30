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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
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
        std::ofstream   out("tst", std::ofstream::out);
        //     out<<"\n
        //                                       8         8\n
        //          8              8              75     77\n
        //            9           9                875  57\n
        //             7         6                   76565     89   
        //    98        56     56            6        565    96
        //      6       656  556        9     56    656    950
        //       56       5656      9  6       56  656   9560 
        //        656      56        656        5 656  9560
        //         1568     656     560         165568560
        //          17658    6558 546        56 645650
        //             17568  76bd56          564560
        //               14578  7658         644560   
        //                 1458  16458      64456         
        //                   14558 1455    64456        
        //                     6458 7455  54456
        //                       54bd555bd5576     
        //                         455555766
        //                         544555776
        //                         54445(o)6  8 0         
        //                         5444o567(890         
        //                     188 5444o5776         
        //                        1)444o5776         
        //                         544(o)776        
        //                        8544445776         
        //                        65444457768          
        //                       6544445576668 
        //                   88865444445576666988"<<std::endl;
        out<<"chjra"<<std::endl;
        out.close();
    }
    else
        throw   std::out_of_range("ShrubberyCreationForm::execute : Grade is out of range");
}