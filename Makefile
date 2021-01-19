NAME =	minishell

SRCS =	srcs/main.c\
		srcs/parser.c\
		srcs/pipe.c\
		srcs/command.c\
		srcs/args.c\
		srcs/bin.c\
		srcs/builtins.c\
		srcs/bash.c\
		srcs/cd.c\
		srcs/export.c\
		srcs/unset.c\
		srcs/utils.c\
		srcs/lens.c\
		srcs/remove.c\
		srcs/exit.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Werror -Wextra 

RM = rm -rf

LIBFT = libft.a
LIBFTDIR = libft/
LIBFTLINK = -L $(LIBFTDIR) -lft


all:		$(NAME)

$(NAME):	complib $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFTLINK)

complib:
	$(MAKE) -C libft/

%.o:		%.c
	$(CC) -c $(CFLAGS) -o $@ $<
	printf "$(GREEN)██"

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re:		fclean all

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

git:
	make fclean
	git add .
	git commit -m "make done"
	git push

norme:
	norminette ./srcs/* ./libft/*

.PHONY:		all clean fclean re leaks git norme
