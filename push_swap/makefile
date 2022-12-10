CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

NAME = push_swap
HEADER = push_swap.h

SRCS =	function_helper.c	\
		function_helper1.c	\
		function_helper2.c	\
		function_helper3.c	\
		node.c				\
		push_swap.c			\
		split.c				\
		validation.c		\
		cmd_stack.c			\
		cmd_stack1.c		\
		sort.c				\

BONUS_SRCS = get_next_line.c 			\
			 checker.c					\
			 function_helper_bonus.c	\
			 function_helper1_bonus.c	\
			 function_helper2_bonus.c	\
			 function_helper3_bonus.c	\
			 validation_bonus.c			\
			 node_bonus.c				\
			 cmd_stack_bonus.c			\
			 cmd_stack1_bonus.c			\
			 split_bonus.c				\

SRCS_OBJS = ${SRCS:%.c=%.o}
BONUS_OBJS = ${BONUS_SRCS:%.c=%.o}


all: ${NAME}

${NAME}:${SRCS_OBJS}
	${CC} ${CFLAGS} $^ -o push_swap

bonus :${BONUS_OBJS}
	${CC} ${CFLAGS} $^ -o checker
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all