# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 14:22:06 by svydrina          #+#    #+#              #
#    Updated: 2023/10/07 06:11:47 by svydrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS = push_swap.c cost.c ps_errors.c push.c reverse_rotate.c sort_utils1.c\
       swap.c assign_ab_utils.c deal_with_ba.c ps_utils1.c rotate.c\
       stack_utils1.c assign_ba_utils.c ps_utils2.c sort_stack.c strategy.c

SRC_BON = checker.c ps_errors.c ps_utils1.c ps_utils2.c push.c swap.c\
rotate.c reverse_rotate.c stack_utils1.c

OBJS = $(SRCS:.c=.o)

OBJ_BON = $(SRC_BON:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -lft -Llibft

all: $(NAME) bonus

bonus: $(BONUS)

$(NAME): $(OBJS) libft/libft.a
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(BONUS): $(OBJ_BON) libft/libft.a
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) -I. -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(OBJ_BON)

fclean: clean
	$(MAKE) -C libft clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re libft
