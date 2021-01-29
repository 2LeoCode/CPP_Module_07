# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 19:18:02 by lsuardi           #+#    #+#              #
#    Updated: 2021/01/29 18:33:42 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		Array

SRCDIR =	src
OBJDIR =	.obj
CLASSDIR =	class
INCDIR =	inc

CLASS =		
SRC =		main.cpp

OBJPATH =	$(addprefix $(OBJDIR)/, $(OBJ))
SRCPATH =	$(addprefix $(SRCDIR)/, $(SRC))

CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCDIR)\
			-I $(CLASSDIR)

CPP =		$(addprefix $(SRCDIR)/, $(SRC))\
			$(foreach i, $(CLASS), $(CLASSDIR)/$i/$i.class.cpp)

OBJ =		$(SRC:.cpp=.o)

all: $(NAME)
	@echo '$(NAME) is up to date'

$(OBJDIR):
	@mkdir $@

$(NAME): $(OBJDIR) $(OBJPATH)
	@(\
		echo '\nBuilding objects...';\
		clang++ $(CFLAGS) $(OBJPATH) $(foreach i, $(CLASS), $(OBJDIR)/$(i).class.o) -o $@;\
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
