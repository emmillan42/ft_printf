# -------------------------------- VARIABLES --------------------------------- #

NAME		=	libftprintf.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs
RM			=	rm -f

HFILES		=	ft_printf.h

SRCS		=	ft_printf.c \
				ft_print_format.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putbase.c \
				ft_putnbr.c \
				ft_putunsigned.c \
				ft_puthex.c \
				ft_putptr.c

OBJS		=	$(SRCS:.c=.o)

# ---------------------------------- RULES ----------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
			$(AR) $(NAME) $(OBJS)

%.o: %.c $(HFILES)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
