# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 21:09:35 by bthomas           #+#    #+#              #
#    Updated: 2024/06/10 15:34:59 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCDIR	= srcs
CFILES	= main.c \
		  utils1.c \
		  ft_atoi.c \
		  lst_funcs.c \
		  ps_ops1.c \
		  ps_ops2.c \
		  ps_ops3.c \
		  sort1.c

SRCS	= $(addprefix $(SRCDIR)/,$(CFILES:.c=.o))

OBJDIR 	= objs
OBJS	=$(addprefix $(OBJDIR)/,$(CFILES:.c=.o))

CFLAGS	= -Wall -Werror -Wextra -g3
CC		= cc

INCS	= -I ./includes/

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing program..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
