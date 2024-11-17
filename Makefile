CC = gcc
CFLAGS = -Wall -g

BIN = bin
SRC = src

# Find all .c files in the src directory
SRCS = $(wildcard $(SRC)/*.c) main.c
# Generate corresponding .o files in the bin directory
OBJS = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS:main.c=$(BIN)/main.o))

# Ensure the bin directory exists
#$(BIN):
#	mkdir -p $(BIN)

all: $(BIN)/my_program

$(BIN)/my_program: $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Pattern rule for compiling .c files in src to .o files in bin
$(BIN)/%.o: $(SRC)/%.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling main.c in root to main.o in bin
$(BIN)/main.o: main.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)/my_program

clean:
	rm -f $(BIN)/my_program $(BIN)/*.o

# Debugging information
print-%:
	@echo $* = $($*)