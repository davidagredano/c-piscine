INCLUDES = ft_cat.h

SRCS	= main.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_cat

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

.PHONY: all clean fclean

all: ${NAME} 

%.o: %.c ${INCLUDES}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} $^ -o $@

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}
