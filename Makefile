############### VARIABLES ###############
### COMPILING ###
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes
### PROGRAMS ###
NAME = minitalk
CLIENT = client
SERVER = server
### COMMANDS ###
RM = rm -rdf

################# FILES #################
SRCS_DIR = srcs

### CLIENT ###
CLIENT_RAWS = client.c
CLIENT_SRCS = $(addprefix $(SRCS_DIR)/, $(CLIENT_RAWS))
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

### SERVER ###
SERVER_RAWS = server.c
SERVER_SRCS = $(addprefix $(SRCS_DIR)/, $(SERVER_RAWS))
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

################# RULES #################
### COMPILING ###
all: $(NAME)

$(NAME): libft $(CLIENT) $(SERVER)

libft:
	cd libft && make

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $@

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

### CLEANING ###
fclean: clean
	$(RM) $(CLIENT) $(SERVER)

clean:
	$(RM) $(CLIENT_OBJS)
	$(RM) $(SERVER_OBJS)
	$(RM) $(GLOBAL_OBJS)
	cd libft && make fclean

re: fclean all

.PHONY: all libft fclean clean re