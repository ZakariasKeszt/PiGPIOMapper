CC = gcc
CFLAGS = -Wall -Wextra -std=c11 $(INCLUDES)

INCLUDES = -I./src/internal -I./include

SRCS = $(wildcard src/hw/*.c) $(wildcard src/core/*.c)

OBJS = $(SRCS:.c=.o)

TARGET = pigpiomapper.a

# --- Recipes ---

# The default 'target' when you just type 'make'
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	install -D -m 644 include/PiGPIOMapper.h /usr/local/include/PiGPIOMapper.h
	install -D -m 644 $(TARGET) /usr/local/lib/$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
