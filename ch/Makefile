# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 10:54:09 by xinzhang          #+#    #+#              #
#    Updated: 2019/05/27 11:05:39 by xinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = checker

LIBFT_F = ../ps_libft/
LIBFT = libft.a

LIBPS = libps.a
LIBPS_F = ../pushswap/

OUT = ../

CFILE = checker.c
OFILE = $(CFILE:.c=.o)

all: $(NAME)

$(NAME):
		@if [ ! -e $(LIBPS_F)$(LIBPS) ]; then \
	 		make -C $(LIBPS_F); \
		fi
		@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
	 		make -C $(LIBFT_F); \
		fi
		gcc -Wall -Werror -Wextra -c $(CFILE)
		gcc -Wall -Werror -Wextra $(OFILE) $(LIBPS_F)$(LIBPS) $(LIBFT_F)$(LIBFT) -o $(NAME)
		mv $(NAME) $(OUT)$(NAME);
	

clean:
	@rm -rf $(OFILE)

fclean: clean
	@rm -rf $(OUT)$(NAME)

re: fclean all
