NAME = libftprintf.a
CFLAGS    = -Wall -Wextra -Werror
OBJS    = $(SOURCES:.c=.o)
OBJDIR = ./
SRCDIR = ./
INCDIR  = ./ft_printf.h
FILES = ft_printf.c char.c hexlower.c hexupper.c integer.c output_handler.c percent.c pointer.c string.c unsigned.c utils.c
SOURCES = $(addprefix $(SRCDIR)/, $(FILES))

.c.o: $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re