#################################### VARIABLES ####################################
#Aliases
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.
AR = ar rcs
RM = rm -rdf

#Files
NAME = libft.a
RAW_SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isblank.c \
		ft_iscntrl.c \
		ft_isdigit.c \
		ft_isgraph.c \
		ft_isprint.c \
		ft_ispunct.c \
		ft_isspace.c \
		ft_isxdigit.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_pow.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_print_address.c \
		ft_print_character.c \
		ft_print_hexa.c \
		ft_print_integer.c \
		ft_print_string.c \
		ft_print_unsigned.c \
		ft_printf.c \
		ft_split.c \
		ft_sqrt.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_toupper.c \
		ft_tolower.c
RAW_BONUS_SRCS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = $(addprefix srcs/, $(RAW_BONUS_SRCS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

####################################   RULES   ####################################
#Creative rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#Destructive rules
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

re: fclean all

#.PHONY
.PHONY: all bonus fclean clean re