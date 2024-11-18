CC = gcc
CFLAGS = -Wall -g -I$(SRC)/include

BIN = bin
SRC = src
UTIL = $(SRC)/util

# Find all .c files in the src and util directories
SRCS = $(wildcard $(SRC)/*.c) $(wildcard $(UTIL)/*.c)
# Generate corresponding .o files in the bin directory
OBJS = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(patsubst $(UTIL)/%.c, $(BIN)/%.o, $(SRCS)))

# Ensure the bin directory exists
#$(BIN):
#	@test -d $(BIN) || mkdir -p $(BIN)

all: $(BIN)/my_program

$(BIN)/my_program: $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Pattern rule for compiling .c files in src and util to .o files in bin
$(BIN)/%.o: $(SRC)/%.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%.o: $(UTIL)/%.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN)/my_program

clean:
	rm -f $(BIN)/my_program $(BIN)/*.o

# Debugging information
print-%:
	@echo $* = $($*)