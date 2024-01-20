NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fPIC
RM = rm -rf
INCLUDE = -L ./libft -lft
SRCS = main.c \
	createlist.c \
	parsing.c \
	free.c \
	sort1.c \
	sort2.c \
	sort3.c \
	sort4.c \
	operations1.c \
	operations2.c \
	utils1.c \
	utils2.c \

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	@cd libft/ && $(MAKE) clean

fclean : clean
	$(RM) $(NAME)
	@cd libft/ && $(MAKE) fclean

re : fclean all

