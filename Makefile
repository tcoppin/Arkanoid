# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:44:19 by tcoppin           #+#    #+#              #
#    Updated: 2015/05/03 22:48:49 by tcoppin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= arkanoid

DEBUG 		= no
ifeq ($(DEBUG),no)
    FLAGS	= -Wall -Werror -Wextra -Wno-deprecated
else
    FLAGS	= -g
endif
SRC 		= main.c ball.c collision.c content_win.c draw.c error.c init.c \
			  keyhook.c misc.c parse.c ship.c map.c

OBJ 		= $(SRC:.c=.o)
INC 		= arkanoid.h
LIBFLAGS 	= -L./libft/ -lft
SRCDIR  	= ./srcs/
OBJDIR  	= ./obj/
INCDIRLIB	= ./libft/includes/
INCDIR		= ./includes/
GLFWINC		= ./glfw/include/
GLFWLIBDIR	= ./glfw/src/
GLFWFLAGS	=  -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework GLUT
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))

.SILENT:

all : 		$(NAME)

$(NAME) :
ifeq ($(DEBUG),yes)
		echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
		echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
			git submodule init
			git submodule update
			cd glfw ; ~/.brew/bin/cmake .
			make -C glfw/
			Make -C libft/
			gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INCDIRLIB) -I $(GLFWINC)
			echo "\\033[1;34mCompiling $(NAME)...\\033[0;39m"
			mkdir -p $(OBJDIR)
			mv $(OBJ) $(OBJDIR)
			gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS) $(GLFWFLAGS) -L$(GLFWLIBDIR)
			echo "\\033[1;34m$(NAME) has been created !\\033[0;39m"

.PHONY: 	clean fclean re

clean : 
			Make -C ./libft/ clean
			rm -rf $(OBJS)
			rm -rf $(OBJDIR)
			echo "\\033[1;31mobjects files has been removed !\\033[0;39m"

fclean :	clean
			Make -C ./libft/ fclean
			rm -rf $(NAME)
			echo "\\033[1;31m$(NAME) has been removed !\\033[0;39m"

re		: 	fclean all


git :
			git add .
			echo "Enter Your Commit : "
			read root_path ; git commit -m "$$root_path"
			git push