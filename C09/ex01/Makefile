INCLUDES = includes/ft.h

SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

LIBC	= ar rcs

RM		= rm -f

%.o: %.c ${INCLUDES}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

.PHONY: all clean fclean re

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
