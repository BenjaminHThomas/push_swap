# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 21:09:35 by bthomas           #+#    #+#              #
#    Updated: 2024/06/12 18:42:24 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = push_swap

SRCDIR  = srcs
CFILES  = main.c \
		  init.c \
		  sort1.c \
		  sort2.c \
		  ps_operators/ps_ops1.c \
		  ps_operators/ps_ops2.c \
		  ps_operators/ps_ops3.c \
		  utilities/utils1.c \
		  utilities/utils2.c \
		  utilities/ft_atoi.c \
		  utilities/lst_funcs.c \
		  utilities/cleanup.c \
		  utilities/quick_sort.c

SRCS	= $(addprefix $(SRCDIR)/, $(CFILES))
OBJDIR	= objs
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

CFLAGS	= -Wall -Werror -Wextra -g3
CC		= cc

INCS	= -I./includes/

all: $(OBJDIR) $(NAME)
	@echo "Making push_swap..."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/ps_operators $(OBJDIR)/utilities

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing program..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


