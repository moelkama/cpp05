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
        out<<"          @              @              &#     &\n";
        out<<"            %           %                @&#  #&\n";
        out<<"             &         ^                   &^#^#     @%\n";
        out<<"    %@        #^     #^            ^        #^#    %^\n";
        out<<"      ^       ^#^  #^        %     #^    ^#^    %#*\n";
        out<<"       #^       #^#^      %  ^       #^  ^#^   %#^* \n";
        out<<"        ^#^      #^        ^#^        # ^#^  %#^*\n";
        out<<"         *#^@     ^#^     #^*         *^#^@#^*\n";
        out<<"          *&^#@    ^#@ #$^        #^ ^$#^#*\n";
        out<<"             *&#^@  &^bd#^          #^$#^*\n";
        out<<"               *$#&@  &^#@         ^$$#^*\n";
        out<<"                 *$#@  *^$#@      ^$$#^\n";
        out<<"                   *$#@ *$#    ^$$#^\n";
        out<<"                     ^$#@ &$#  #$$#^\n";
        out<<"                       #$bd#bd#&^\n";
        out<<"                         $#&^^\n";
        out<<"                         #$$#&^\n";
        out<<"                        $$$$$#^^%@@"<<std::endl;
        out.close();
    }
    else
        throw   GradeTooLowException();
}