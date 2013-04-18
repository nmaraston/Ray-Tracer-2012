INC_DIR 	= include
SRC_DIR 	= src
BIN_DIR 	= bin
OBJ_DIR 	= $(BIN_DIR)/obj

CC			= g++
CC_FLAGS	= -Wall

CPP_FILES 	:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES 	:= $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

ray-tracer: make_build_dir $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $^ -o $@

make_build_dir:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BIN_DIR)