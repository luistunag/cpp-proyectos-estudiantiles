# 🎢 Péndulo Doble Compuesto

Este proyecto simula numéricamente el movimiento de un péndulo doble compuesto usando métodos de integración numérica como Runge-Kutta de 4to orden (RK4) y Runge-Kutta-Fehlberg (RKF45), implementados en C++. También genera una animación cuadro por cuadro y un video en formato `.mp4` que muestra el comportamiento caótico del sistema.

> Trabajo realizado originalmente como parte de un curso de Simulación de Fenómenos Físicos en 2015.

---

## 🎯 Objetivo

Resolver las ecuaciones de movimiento del péndulo doble compuesto a partir del lagrangiano del sistema, analizar sus soluciones numéricas e ilustrar su comportamiento dinámico mediante animación.

---

## 📁 Estructura del Proyecto

```plaintext
pendulo-doble-compuesto/
├── src/                # Código fuente en C++
├── scripts/            # Script para animación con Gnuplot
├── data/               # Archivos de datos generados automáticamente
├── output/             # Imágenes y video de la animación
├── reporte/            # Reporte PDF del proyecto original
├── .gitignore
├── Makefile
└── README.md
```

---

## 🔧 Requisitos

- **g++**
- **gnuplot**
- **ffmpeg** (para generar el video)

Instalación en macOS:

```bash
brew install gnuplot ffmpeg
```

---

## ⚙️ Uso del Makefile

### 🛠️ Compilar todo

```bash
make
```

### ▶️ Ejecutar una simulación

```bash
make run-rk4     # Simulación con Runge-Kutta clásico
make run-rkf     # Simulación con Runge-Kutta-Fehlberg adaptativo
```

### 🎬 Generar animación completa (PNG + MP4)

```bash
make animacion
```

Esto genera:
- Imágenes `grafXXXXX.png` en `output/`
- El video `output/animacion.mp4`

### 🧹 Limpiar archivos generados

```bash
make clean
```

---

## 📂 Archivos relevantes
```
| Archivo                        | Descripción                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| `src/pendulo_rk4.cpp`         | Simulación usando RK4 con paso fijo                                        |
| `src/pendulo_rkf45.cpp`       | Simulación con RKF45 y control de error                                    |
| `src/pendulo_animacion.cpp`   | Genera archivo `animation.dat` para la animación                           |
| `scripts/generar_animacion.sh`| Script bash para generar PNGs con Gnuplot                                  |
| `reporte/reporte_proyecto.pdf`| Reporte original del proyecto con teoría, código y resultados              |
| `Makefile`                    | Automatiza compilación, simulación, animación y limpieza                   |
```
---

## 🧼 `.gitignore`

Se ignoran automáticamente los siguientes archivos:

```gitignore
*~
\#*\#
.DS_Store
*.dat
*.png
*.mp4
output/
data/
bin/
```

---

## 👤 Autor

**Luis Tun**  
Licenciado en Física Aplicada — USAC  
Científico de datos | Docente universitario | Fan de Emacs y la física computacional

---

## 📜 Licencia

Este proyecto se comparte con fines educativos y demostrativos. Puedes reutilizar el código con atribución.
