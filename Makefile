NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = Libft
LIBFT_LIB = libft.a
AR = ar rc
RM = rm -f

SRCS = char_output.c dec_to_hex.c decimal_output.c ft_printf.c ptr_output.c read_flags.c \
       string_output.c u_output.c width_output.c x_output.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^

bonus : all

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
