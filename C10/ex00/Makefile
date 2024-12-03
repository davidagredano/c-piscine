SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.PHONY: all clean fclean

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} $^ -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
