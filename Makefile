################################### VARIABLES ##################################
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
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
GLOBAL_SRCS = utils.c
#OBJECTS
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
GLOBAL_OBJS = $(GLOBAL_SRCS:.c=.o)
#COLORS
RED = \033[1;31m
LIGHT_GREEN = \033[0;32m
GREEN = \033[1;32m
BLUE = \033[0;34m
CUT = \033[0m

#################################### RULES #####################################
#COMPILING RULES
all: $(NAME)
$(NAME): make_libft make_printf make_server make_client
make_libft:
	@cd libft && make > /dev/null
	@echo "$(BLUE)LIBFT				$(CUT)$(GREEN)[OK]$(CUT)"
make_printf:
	@cd my_printf && make > /dev/null
	@echo "$(BLUE)FT_PRINTF			$(CUT)$(GREEN)[OK]$(CUT)"
make_server: $(SERVER_OBJS) $(GLOBAL_OBJS)
	@$(CC) $(SERVER_OBJS) $(GLOBAL_OBJS) $(LIBFT) $(PRINTF) -o server
	@echo "$(BLUE)SERVER				$(CUT)$(GREEN)[OK]$(CUT)"
make_client: $(CLIENT_OBJS) $(GLOBAL_OBJS)
	@$(CC) $(CLIENT_OBJS) $(GLOBAL_OBJS) $(LIBFT) $(PRINTF) -o client
	@echo "$(BLUE)CLIENT				$(CUT)$(GREEN)[OK]$(CUT)"
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#CLEANING RULES
fclean: clean
	@$(RM) client server
	@echo "$(BLUE)SERVER + CLIENT			$(CUT)$(RED)[DELETE]$(CUT)"
clean: clean_libft clean_printf clean_objects
clean_libft:
	@cd libft && make fclean > /dev/null
	@echo "$(BLUE)LIBFT				$(CUT)$(RED)[DELETE]$(CUT)"
clean_printf:
	@cd my_printf && make fclean > /dev/null
	@echo "$(BLUE)FT_PRINTF			$(CUT)$(RED)[DELETE]$(CUT)"
clean_objects:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(GLOBAL_OBJS)
	@echo "$(BLUE)OBJECTS				$(CUT)$(RED)[DELETE]$(CUT)"
re: fclean all