CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

NAME = push_swap
HEADER = push_swap.h

SRCS =	cmd.c				\
		cmd1.c				\
		ft_split.c			\
		ft_substr.c			\
		function_helper.c	\
		list.c				\
		push_swap.c			\
		utils.c				\
		validation.c		\
		sort_stack.c		\
		ft_trim.c


SRCS_OBJS = ${SRCS:%.c=%.o}


all: ${NAME}

${NAME}:${SRCS_OBJS}
	${CC} ${CFLAGS} $^ -o push_swap

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all