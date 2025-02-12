TEST_DIR:=test
BUILD_DIR:=build
DIR=token lexer test

SRC:= $(notdir $(wildcard $(foreach dir, $(DIR), $(dir)/*.c)))
OBJ:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

CFLAGS=-Wall -Werror
LDFLAGS=-L/usr/local/lib -lcheck

compiler: $(OBJ) | $(BUILD_DIR)
	cc -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	cc $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean

clean:
	rm -r $(BUILD_DIR)

vpath %.c $(DIR)
