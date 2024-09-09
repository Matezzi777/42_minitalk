#==============================================================================
#COMPILING
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Ilibft -Imy_printf
RM = rm -rf
NAME = minitalk
#LIBRARIES
LIBFT = -Llibft -l:libft.a
PRINTF = -Lmy_printf -l:libftprintf.a
#SOURCES
SERVER_SRCS = server_main.c
CLIENT_SRCS = client_main.c
#OBJECTS
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
#COLORS
RED = \033[1;31m
LIGHT_GREEN = \033[0;32m
GREEN = \033[1;32m
BLUE = \033[0;34m
CUT = \033[0m

#==============================================================================
all: $(NAME)

$(NAME): make_libft make_printf make_server make_client

make_libft:
	@cd libft && make > /dev/null
	@echo "$(BLUE)libft ready !$(CUT)"

make_printf:
	@cd my_printf && make > /dev/null
	@echo "$(BLUE)ft_printf ready !$(CUT)"

make_server: $(SERVER_OBJS)
	@$(CC) $(SERVER_OBJS) $(LIBFT) $(PRINTF) -o server
	@echo "$(LIGHT_GREEN)server ready !$(CUT)"

make_client: $(CLIENT_OBJS)
	@$(CC) $(CLIENT_OBJS) $(LIBFT) $(PRINTF) -o client
	@echo "$(LIGHT_GREEN)client ready !$(CUT)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)$@ $(GREEN)compiled$(CUT)"

#==============================================================================
fclean: clean
	@$(RM) client server
	@echo "$(LIGHT_GREEN)client & server $(RED)removed$(CUT)"

clean: clean_libft clean_printf clean_server_obj clean_client_obj

clean_libft:
	@cd libft && make fclean > /dev/null
	@echo "$(BLUE)libft $(RED)removed$(CUT)"

clean_printf:
	@cd my_printf && make fclean > /dev/null
	@echo "$(BLUE)ft_printf $(RED)removed$(CUT)"

clean_server_obj:
	@$(RM) $(SERVER_OBJS)
	@echo "$(BLUE)server objects $(RED)removed$(CUT)"

clean_client_obj:
	@$(RM) $(CLIENT_OBJS)
	@echo "$(BLUE)client objects $(RED)removed$(CUT)"

re: fclean all