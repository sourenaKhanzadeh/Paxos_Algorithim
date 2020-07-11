TARGET = main 

SRC = ./src
INC = ./inc 
BIN = ./bin

LIB =  -lsfml-graphics -lsfml-system -lsfml-window

################
#    COLORS    #
RED = \033[1;31m
GREEN = \033[1;32m
BLUE  = \033[1;34m
YELLOW  = \033[1;33m
NC  = \033[1;0m
################

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.cpp=.o)))

CC = g++ -c  

$(BIN)/$(TARGET): $(OBJECT)
	@echo "\n$(RED) Linking...$(NC)"
	g++ -o $@ $^ $(LIB)
	@echo "Finished!"

$(BIN)/%.o: $(SRC)/%.cpp 
	@echo "\n$(GREEN) Compiling...$(NC)"
	g++ -c $< -o $@ $(LIB)
	@echo "Finished!"

.PHONY: help run 

run: $(BIN)/$(TARGET)
	@echo "\n$(YELLOW) Running...$(NC)"
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECT) $(BIN)/$(TARGET)

help:
	@echo "src: $(SOURCE)"
	echo "obj: $(OBJECT)"
