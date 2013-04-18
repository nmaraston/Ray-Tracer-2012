INC_DIR 	= include
SRC_DIR 	= src
BUILD_DIR 	= build
OBJ_DIR 	= $(BUILD_DIR)/obj

CC			= g++
CC_FLAGS	= -Wall

CPP_FILES 	:= $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES 	:= $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

ray-tracer: make_build_dir $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -o $(BUILD_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $^ -o $@

make_build_dir:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BUILD_DIR)