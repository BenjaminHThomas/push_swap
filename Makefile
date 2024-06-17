# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 21:09:35 by bthomas           #+#    #+#              #
#    Updated: 2024/06/16 21:58:02 by bthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = push_swap

SRCDIR  = srcs
CFILES  = main.c \
		  init.c \
		  sort1.c \
		  sort2.c \
		  sort3.c \
		  a_solvable.c \
		  ps_operators/ps_ops1.c \
		  ps_operators/ps_ops2.c \
		  ps_operators/ps_ops3.c \
		  utilities/utils1.c \
		  utilities/utils2.c \
		  utilities/lst_funcs.c \
		  utilities/cleanup.c \
		  utilities/quick_sort.c

SRCS	= $(addprefix $(SRCDIR)/, $(CFILES))
OBJDIR	= objs
OBJS	= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

CFLAGS	= -Wall -Werror -Wextra -g3
CC		= cc

PRINTF_LIB	= libftprintf.a
PRINTF_DIR	= ./includes/ft_printf
PRINTF		= $(PRINTF_DIR)$(PRINTF_LIB)

LINK		= -L $(PRINTF_DIR) -lftprintf

INCS	= -I./includes/ \
		  -I $(PRINTF_DIR)

all: $(OBJDIR) $(PRINTF) $(NAME)
	@echo "Making push_swap..."

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)/ps_operators $(OBJDIR)/utilities

$(PRINTF):
	@echo "Making printf..."
	@$(MAKE) -sC $(PRINTF_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(LINK)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)
	@$(MAKE) clean -sC $(PRINTF_DIR)

fclean: clean
	@echo "Removing program..."
	@rm -f $(NAME)
	@$(MAKE) fclean -sC $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re


