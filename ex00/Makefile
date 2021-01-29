# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 19:18:02 by lsuardi           #+#    #+#              #
#    Updated: 2021/01/28 21:01:40 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		whatever

SRCDIR =	src
OBJDIR =	.obj
INCDIR =	inc

SRC =		main.cpp
OBJ =		$(SRC:.cpp=.o)

OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))
SRCPATH =	$(addprefix $(SRCDIR)/, $(SRC))

CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCDIR)

all: $(NAME)
	@echo '$(NAME) is up to date'

$(OBJDIR):
	@mkdir $@

$(NAME): $(OBJDIR) $(OBJPATH)
	@(\
		echo '\nBuilding objects...';\
		clang++ $(CFLAGS) $(OBJPATH) -o $@;\
	)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@(\
		printf '\r\033[2KCompiling $<...';\
		clang++ $(CFLAGS) -c $< -o $@\
	)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
