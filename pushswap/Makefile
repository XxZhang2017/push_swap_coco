# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinzhang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/26 23:35:02 by xinzhang          #+#    #+#              #
#    Updated: 2019/05/26 23:35:03 by xinzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = push_swap
# NAME2 = checker
# CHECHER_F = checker/
LIBPS = libps.a

LIBFT_F = ../ps_libft/
LIBFT = libft.a


OUT = ../


CFILES = test_main.c
CFILES += action.c
CFILES += eval.c
CFILES += eval_help.c
CFILES += free.c
CFILES += genaction.c
CFILES += genoptimizer.c
CFILES += initstack.c
CFILES += instruction.c
CFILES += isfinished.c
CFILES += move.c
CFILES += p_op.c
CFILES += r_op.c
CFILES += rr_op.c
CFILES += s_op.c
CFILES += score.c
CFILES += searching_a.c
CFILES += searching_b.c
CFILES += sort_small.c
CFILES += stack_info.c
CFILES += strategy_build.c



OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "make re $(LIBFT)"; \
		make re -C $(LIBFT_F); \
	fi
	@if [ -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) is compiling"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(LIBFT_F)$(LIBFT) -o $(NAME); \
		mv $(NAME) $(OUT)$(NAME); \
		ar rc $(LIBPS) $(OFILES); \
		ranlib $(LIBPS); \
	else \
		echo "something wrong with $(LIBFT)"; \
	fi

clean:
	@rm -rf $(OFILES)


fclean: clean
	@rm -rf $(OUT)$(NAME)
	@rm -rf $(LIBPS)


re: fclean all
