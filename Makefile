NAME = minitalk
C_NAME = client
S_NAME = server
C_SRC = client.c
S_SRC    = server.c
LIB = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = -I ./includes
RM = rm -f

$(NAME) : $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJ) $(LIB) $(PRINTF)
	$(CC) $(CFLAGS) $(C_OBJ) $(LIB) $(PRINTF) -o $(C_NAME)

$(S_NAME): $(S_OBJ) $(LIB) $(PRINTF)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIB) $(PRINTF) -o $(S_NAME)

$(LIB):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./printf

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./printf
	$(RM) $(C_OBJ) $(S_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./printf
	$(RM) $(C_NAME) $(S_NAME)

re : fclean all

.PHONEY : all clean fclean re