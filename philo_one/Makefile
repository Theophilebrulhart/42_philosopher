SRCS	= main.c\
			initialize.c\
			utils.c\
			create_fork.c\
			error_exit.c\
			create_threads.c\
			philo_start.c\
			action.c\
			write.c\
			time_to_die.c\

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CLANG	= clang

FLAGS	= -Wall -Wextra -Werror -g -fsanitize=address 

INCLUDE	= -lpthread

HEADER	= philo.h




all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	$(CLANG) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c $(HEADER)
	$(CLANG) $(FLAGS) -c $<  -o $(<:.c=.o)
.PHONY:		all clean fclean re