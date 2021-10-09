NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS	= push_swap.c moves_swap.c moves_push.c moves_rotate.c moves_rrotate.c \
		  sort_utils.c sort_3.c sort_100.c

LIBFT	= libft

INCLUDE	= -L ${LIBFT} -lft

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

all: ${NAME}

%o: %c
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@make bonus -C ${LIBFT}
	@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS} *.dSYM

fclean:		clean
		@${RM} ${NAME}

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all

