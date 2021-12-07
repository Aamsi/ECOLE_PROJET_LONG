SRCFOLD		= srcs/

SRCS		= ${SRCFOLD}main.c \
				${SRCFOLD}get_next_line.c \
				${SRCFOLD}get_next_line_utils.c \
				${SRCFOLD}parse_map.c \
				${SRCFOLD}init.c \
				${SRCFOLD}binds.c

OBJS		= ${SRCS:.c=.o}

NAME		= so_long

CC			= @clang

CFLAGS		= -Wall -Wextra -Werror -g3

RM			= @rm -f

%.o: %.c
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -Iincludes -Ilibft -c $< -o ${<:.c=.o}

${NAME}:		 ${OBJS}
	@make --no-print-directory -C mlx_linux
	@make --no-print-directory -C libft
	@${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Llibft -lft -Imlx_linux -lXext -lX11 -lm -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS}
	@make clean --no-print-directory -C libft/

fclean:			clean
	${RM} ${NAME}
	@make clean --no-print-directory  -C mlx_linux/
	@make fclean --no-print-directory -C libft/

re:				fclean all

.PHONY:			all clean fclean re