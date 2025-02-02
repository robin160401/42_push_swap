NAME            = push_swap
LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
RM              = rm -f

# Quellen für Push-Swap
SRCS            = src/chunk_split.c \
                  src/create_stack_functions.c \
                  src/errors.c \
                  src/free_functions.c \
                  src/helper_functions.c \
                  src/helper2_functions.c \
                  src/helper3_functions.c \
                  src/move_functions.c \
                  src/node_functions.c \
                  src/operations.c \
                  src/operations2.c \
                  src/sort_functions.c \
                  src/sort_numbers_functions.c \
                  src/sort_three_functions.c \
                  push_swap.c

# Objektdateien für Push-Swap
OBJS            = $(SRCS:.c=.o)

# Standardziel
all:            $(NAME)

# Erstelle das Push-Swap-Programm (Executable)
$(NAME):        $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Regel für das Erstellen von libft.a, falls noch nicht erstellt
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Bereinigen der Objektdateien
clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

# Komplettes Aufräumen (auch libft.a entfernen)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) $(LIBFT)

# Neu bauen
re: fclean all

.PHONY: all clean fclean re

