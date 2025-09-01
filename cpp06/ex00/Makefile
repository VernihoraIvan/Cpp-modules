COMPILER = c++
SRCS = main.cpp ScalarConverter.cpp
TEST_SRCS = test_main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
NAME = convert
TEST_NAME = test_convert
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJS)
	$(COMPILER) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME)

test: $(TEST_NAME)
	./$(TEST_NAME)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
