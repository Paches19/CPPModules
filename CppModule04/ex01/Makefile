# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 10:51:09 by adpachec          #+#    #+#              #
#    Updated: 2023/07/06 13:47:50 by adpachec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	=	brain

#Sources 
SRCS	=	Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			Brain.cpp \
			main.cpp

#Headers
HEADERS = Animal.hpp \
		  Cat.hpp \
		  Dog.hpp

#Objects
OBJS	= $(SRCS:.cpp=.o)

#Flags
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98 

#Folders
OBJS_DIR = ./obj/
 
#Paths
OBJ = $(addprefix $(OBJS_DIR), $(OBJS))

all: create_dir $(NAME)

$(NAME): Makefile $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

create_dir:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean