NAME = libft.a

SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
          ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c \
          ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
          ft_memcmp.c ft_calloc.c ft_strdup.c ft_strncmp.c ft_strlcpy.c \
          ft_strlcat.c ft_strnstr.c ft_strtrim.c \
          ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
          ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_freetab.c \
          ft_tablen.c ft_strcmp.c

BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
                ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
                ft_lstmap.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c libft.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	$(AR) $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus