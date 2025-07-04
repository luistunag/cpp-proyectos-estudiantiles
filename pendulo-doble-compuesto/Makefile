# === Variables ===
CXX = g++
CXXFLAGS = -O2 -Wall -lm
SRC_DIR = src
BIN_DIR = bin
DATA_DIR = data
SCRIPT_DIR = scripts

# === Source files ===
RK4_SRC = $(SRC_DIR)/pendulo_rk4.cpp
RKF_SRC = $(SRC_DIR)/pendulo_rkf45.cpp
ANIM_SRC = $(SRC_DIR)/pendulo_animacion.cpp

# === Executables ===
RK4_EXE = $(BIN_DIR)/rk4
RKF_EXE = $(BIN_DIR)/rkf45
ANIM_EXE = $(BIN_DIR)/animar

# === Rules ===
all: $(RK4_EXE) $(RKF_EXE) $(ANIM_EXE)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(RK4_EXE): $(RK4_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(RKF_EXE): $(RKF_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

$(ANIM_EXE): $(ANIM_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# === Execute simulations ===
run-rk4: $(RK4_EXE)
	$(RK4_EXE)
	mv rk4.dat $(DATA_DIR)/

run-rkf: $(RKF_EXE)
	$(RKF_EXE)

run-anim: $(ANIM_EXE)
	$(ANIM_EXE)
	mv animation.dat $(DATA_DIR)/

# === Animation ===
animacion: run-anim
	bash $(SCRIPT_DIR)/generar_animacion.sh
	ffmpeg -framerate 25 -start_number 10000 -i output/graf%05d.png -c:v libx264 -pix_fmt yuv420p output/animacion.mp4

# === Cleaning ===
clean:
	rm -rf $(BIN_DIR) $(DATA_DIR)/animation.dat output/graf*.png
