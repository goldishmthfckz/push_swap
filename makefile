NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

SRCS = main.c \
	createlist.c \
	parsing.c \
	utils.c \
	ftaajouteralibft.c \
	sort.c \
	operations1.c \

RM = rm -rf

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

