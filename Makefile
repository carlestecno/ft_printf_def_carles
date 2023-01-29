SRCS =	ft_printf.c\
		ft_printfunctions.c \

OBJS =	${SRCS:.c=.o}
HEADER =	ft_printf.h
NAME =	libftprintf.a
CC =	gcc
RM =	rm -f
CFLAGS =	-Wall -Wextra -Werror
%.o : %.c ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@
all :	${NAME}
${NAME} :	${OBJS}
		ar rcs	${NAME} ${OBJS}
clean :
	${RM} ${OBJS}
fclean :	clean
	${RM} ${NAME}
re :	fclean all
.PHONY :    all clean fclean re
