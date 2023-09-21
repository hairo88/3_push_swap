NAME = libft.a
CC = cc
INCL = libft.h
CFLAGS = -Wall -Wextra -Werror -I$(INCL)
SRCS =  ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

SRCS += ./ft_printf/new_printf.c \
	./ft_printf/printf_utils.c \
	./ft_printf/put_dec_to_hex.c \
	./ft_printf/put_nbr.c \
	./ft_printf/put_pointer.c \
	./ft_printf/put_string.c

OBJS += ./ft_printf/new_printf.o \
	./ft_printf/printf_utils.o \
	./ft_printf/put_dec_to_hex.o \
	./ft_printf/put_nbr.o \
	./ft_printf/put_pointer.o \
	./ft_printf/put_string.o

INCL += -Ift_printf.h


# PRIDIR = ./ft_printf
# PRIBFT = $(PRIDIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
