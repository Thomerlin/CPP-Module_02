
FILES	=	main.cpp Fixed.cpp 

DIR		=	./

HEADERS	=	Fixed.hpp

OBJ_DIR	=	objects

SOURCES	=	$(addprefix $(DIR)/, $(FILES))

OBJECTS	=	$(SOURCES:$(DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME	=	fixed

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

RM		=	rm -rf

$(OBJ_DIR)/%.o:		$(DIR)/%.cpp $(HEADERS)
						$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME) 

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADERS)
						$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR):
						mkdir -p $(OBJ_DIR)
clean:
						$(RM) $(OBJ_DIR)

fclean:				clean
						$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re