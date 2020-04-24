SRC = src/paula.cpp src/paulaMain.cpp src/gccMain.cpp src/dummyHeap.cpp
CC = g++
FLAGS = -std=c++14
TARGET_EXE = paula
DEBUG_FLAGS = -DPAULA_DEBUG -DOVERLOAD_NEW -fsanitize=leak
RELEASE_FLAGS = -Os -s

release: $(SRC)
	@echo --- Paula RELEASE ---
	$(CC) $(FLAGS) $(RELEASE_FLAGS) $(SRC) -o $(TARGET_EXE) 
	
debug: $(SRC)
	@echo --- Paula DEBUG ---
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(SRC) -o $(TARGET_EXE) 

clean:
	@echo --- Paula CLEAN ---
	rm $(TARGET_EXE)
