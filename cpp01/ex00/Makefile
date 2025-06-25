COMPILER = c++
TARGET = zombie
SRCS = Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = zombie
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

re: fclean all

.PHONY: all clean fclean re