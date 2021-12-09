SRCS		= ft_printf.c ft_printf_utils.c ft_printf_utils_aux.c

BONUS		= ft_printf_bonus.c ft_printf_bonus_bonus.c ft_printf_utils_aux_bonus.c ft_printf_utils_bonus.c ft_printf_bonus_aux_bonus.c

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS  = $(BONUS:.c=.o)

NAME		= libftprintf.a

CC			= gcc

ARRC		= ar rcs

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
				${ARRC} $(NAME) $(OBJS)

all:		${NAME}

bonus:		fclean	$(BONUS_OBJS)
				${ARRC} $(NAME) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
