NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS	= push_swap.c moves_swap.c moves_push.c moves_rotate.c moves_rrotate.c \
		  sort_utils.c sort_3.c sort_100.c check_params.c map_nums.c \
		  sort_100_utils.c

LIBFT	= libft/

MAKE_LIB= make bonus

INCLUDE	= -L${LIBFT} -lft 

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

OS		:= $(shell uname -s)

ifeq ($(OS), Linux)
	INCLUDE += -static-libasan
	MAKE_LIB = make so
endif

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I${LIBFT} $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${MAKE_LIB} -C ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

clean:
		@${RM} ${OBJS} *.dSYM

fclean:		clean
		@${RM} ${NAME}

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all
