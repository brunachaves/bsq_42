NAME = bsq

SRCS = main.c create_grid.c

OBJS = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra  

all:	${NAME}

${NAME}: ${OBJS}
	cc -o  ${NAME}  ${SRCS} ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all


