NAME = push_swap
CC = cc
INCLUDES_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)
SRCS = main.c \
	tan_houko.c \
	operations.c \
	three_sort.c \
	check_sort.c \
	minizer.c \
	find_number.c \
	six_sort.c \
	input_value.c \
	big_sort.c \
	new_big_sort.c \
	operations_2.c \
	operations_3.c \
	tan_houko_2.c
	
OBJS = $(SRCS:.c=.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re