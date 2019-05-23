#!/usr/bin/make -f
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = \
	atoi\
	bzero\
	isalnum\
	isalpha\
	isascii\
	isdigit\
	isprint\
	isspace\
	itoa\
	lstadd\
	lstdel\
	lstdelone\
	lstiter\
	lstmap\
	lstnew\
	memalloc\
	memccpy\
	memchr\
	memcmp\
	memcpy\
	memdel\
	memmove\
	memset\
	putchar\
	putchar_fd\
	putendl\
	putendl_fd\
	putnbr\
	putnbr_fd\
	putstr\
	putstr_fd\
	strcat\
	strchr\
	strclr\
	strcmp\
	strcpy\
	strdel\
	strdup\
	strequ\
	striter\
	striteri\
	strjoin\
	strlcat\
	strlen\
	strmap\
	strmapi\
	strncat\
	strncmp\
	strncpy\
	strnequ\
	strnew\
	strnstr\
	strrchr\
	strsplit\
	strstr\
	strsub\
	strtrim\
	tolower\
	toupper\


OBJ = $(patsubst %, ft_%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $(OBJ)
	ranlib $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
