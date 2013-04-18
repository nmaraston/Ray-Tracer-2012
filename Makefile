INC_DIR 	= include
SRC_DIR 	= src
BUILD_DIR 	= build
OBJ_DIR 	= $(BUILD_DIR)/obj

CC			= g++
CC_FLAGS	= -Wall 

CPP_FILES 	:= $(wildcard $(SRC_DIR)/*.cpp)
H_FILES		:= $(wildcard $(INC_DIR)/*.h)
OBJ_FILES 	:= $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

ray-tracer: make_build_dir $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -o $(BUILD_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_FILES)
	$(CC) $(CC_FLAGS) -c $< -I$(INC_DIR) -o $@

make_build_dir:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(BUILD_DIR)