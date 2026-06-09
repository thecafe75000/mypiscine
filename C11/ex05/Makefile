
TARGET = do-op
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
SOURCES = do_op.c calc.c ft_atoi.c
OBJECTS = $(SOURCES:%.c=$(SRCDIR)/%.o)

all: $(TARGET)

# $@ -> $(TARGET)
# $^ -> $(OBJECTS)
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# $< filename without .ext
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean
