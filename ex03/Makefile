OBJS =	main.o Bureaucrat.o AForm.o\
		PresidentialPardonForm.o\
		ShrubberyCreationForm.o\
		RobotomyRequestForm.o Intern.o

NAME = throw

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re