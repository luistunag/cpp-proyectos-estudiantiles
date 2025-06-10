# === Configuración ===
CXX = g++
CXXFLAGS = -O2 -Wall
SRC_DIR = src
DATA_DIR = data
SCRIPT_DIR = scripts
BIN_DIR = bin
OUTPUT_DIR = output

SIM_SRC = $(SRC_DIR)/simulacion_molecula.cpp
SIM_EXE = $(BIN_DIR)/simulacion_molecula
DATA_FILE = $(DATA_DIR)/molecula.dat
ANIM_SCRIPT = $(SCRIPT_DIR)/animacion_vpython.py

# === Targets ===
.PHONY: all run animacion clean

all: $(SIM_EXE)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(SIM_EXE): $(SIM_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(SIM_EXE)
	./$(SIM_EXE)
	mkdir -p $(DATA_DIR)
	mv molecula.dat $(DATA_FILE)

animacion: run
	python3 $(ANIM_SCRIPT)

clean:
	rm -rf $(BIN_DIR) $(DATA_FILE) $(OUTPUT_DIR)/capturas
