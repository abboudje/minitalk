# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Project name
NAME_CLIENT = client
NAME_SERVER = server 

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include

# Source files and obj files
CLIENT_SRC =	client.c core.c
SERVER_SRC =	server.c core.c

CLIENT_OBJS = $(addprefix $(OBJ_DIR), $(CLIENT_SRC:.c=.o))
SERVER_OBJS = $(addprefix $(OBJ_DIR), $(SERVER_SRC:.c=.o))

# Header files
HEADERS = -I$(INC_DIR)

# Rules
all: $(OBJ_DIR) $(NAME_CLIENT) $(NAME_SERVER)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME_CLIENT) : $(CLIENT_OBJS) 
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(SERVER_OBJS) 
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(NAME_SERVER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re