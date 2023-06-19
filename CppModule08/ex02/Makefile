# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 10:51:09 by adpachec          #+#    #+#              #
#    Updated: 2023/06/19 13:57:51 by adpachec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME	=	mutant

#Sources 
SRCS	=	main.cpp

#Headers
HEADERS = MutantStack.hpp 
		  
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

$(OBJS_DIR)%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean