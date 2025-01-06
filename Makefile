NAME            = push_swap.a
CHECK           = checker
LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
RM              = rm -f
AR              = ar rcs

# Quellen für Push-Swap
SRCS            = $(wildcard src/*.c utils/*.c) // schauen wir noch

# Quellen für Checker
CHECK_SRCS      = $(wildcard src/instructions.c checker.c utils/*.c) // schauen wir noch

# Objektdateien für Push-Swap
OBJS            = $(SRCS:.c=.o)

# Objektdateien für Checker
CHECK_OBJS      = $(CHECK_SRCS:.c=.o)

# Standardziel: beide Ziele erstellen
all:            $(NAME) $(CHECK)

# Erstelle die Bibliothek push_swap.a
$(NAME):        $(OBJS) $(LIBFT)
				$(AR) rcs $(NAME) $(OBJS) $(LIBFT)

# Erstelle das Checker-Programm
$(CHECK):       $(CHECK_OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(CHECK_OBJS) $(LIBFT) -o $(CHECK)

# Regel für das Erstellen von libft.a, falls noch nicht erstellt
$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

# Bereinigen der Objektdateien
clean:
				$(MAKE) clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)
				$(RM) $(CHECK_OBJS)

# Komplettes Aufräumen
fclean:         clean
				$(RM) $(NAME)
				$(RM) $(CHECK)

# Neu bauen
re:             fclean all

.PHONY:         all clean fclean re
