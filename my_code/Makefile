TEST_DIR:=test
BUILD_DIR:=build
DIR=lexer token utils tree
MAIN_DIR=main
TEST_DIR=test

SRC:= $(notdir $(wildcard $(foreach dir, $(DIR), $(dir)/*.c)))
TEST_SRC:= $(notdir $(wildcard $(TEST_DIR)/*.c))
MAIN_SRC:= $(notdir $(wildcard $(MAIN_DIR)/*.c))
OBJ_SRC:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))
OBJ_TEST:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(TEST_SRC))
OBJ_MAIN:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(MAIN_SRC))

CFLAGS=-Wall -Werror -O3
LDFLAGS=-L/usr/local/lib -lcheck

run: $(OBJ_MAIN) $(OBJ_SRC) | $(BUILD_DIR)
	cc -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

test: $(OBJ_TEST) $(OBJ_SRC) | $(BUILD_DIR)
	cc -o $(BUILD_DIR)/$@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	cc $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean

clean:
	rm -r $(BUILD_DIR)

vpath %.c $(DIR) $(MAIN_DIR) $(TEST_DIR)
