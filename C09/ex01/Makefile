TARGET = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
SOURCES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJECTS = $(SOURCES:%.c=$(SRCDIR)/%.o)

all: $(TARGET)

# $@ -> $(TARGET)
# $^ -> $(OBJECTS)
$(TARGET): $(OBJECTS)
	ar rcs $@ $^

# $< filename without .ext
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	${CC} ${CFLAGS} -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re