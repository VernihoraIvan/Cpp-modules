COMPILER = c++
SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = bureaucracy
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *.txt

re: fclean all

.PHONY: all clean fclean re
