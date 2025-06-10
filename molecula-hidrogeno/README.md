# Simulación y Animación de una Molécula de Agua (H₂O)

Este proyecto implementa una simulación dinámica de una molécula de agua basada en el método de Runge-Kutta de cuarto orden (RK4) y genera una animación visual en formato MP4 usando Python y MoviePy con Gizeh.

## 🧪 Descripción

El modelo simula las interacciones entre los tres átomos de la molécula de agua: dos átomos de hidrógeno y uno de oxígeno. La dinámica considera:

- Fuerzas armónicas tipo resorte entre el oxígeno y cada hidrógeno.
- Una fuerza angular para mantener el ángulo típico entre los enlaces.
- La integración numérica se realiza mediante RK4 en C++.

La animación visualiza el movimiento de cada átomo y resalta información clave sobre posiciones y velocidades iniciales.

## 📁 Estructura del Proyecto

molecula-hidrogeno/
├── bin/                      # Contiene el ejecutable de la simulación
├── data/                     # Almacena los datos generados por la simulación (molecula.dat)
├── output/                   # Carpeta de salida con el video generado (molecula_animacion.mp4)
├── scripts/
│   └── animacion_vpython.py # Script que genera el video MP4 usando Gizeh + MoviePy
├── simulacion_molecula.cpp  # Código fuente de la simulación en C++
├── Makefile                 # Automatización de compilación y animación
└── README.md                # Este archivo

## ⚙️ Requisitos

### Python (instalar dentro de un entorno virtual):

```bash
pip install numpy moviepy gizeh
```

Nota: gizeh requiere Cairo. En macOS, instalarlo con: brew install cairo

### Compilador C++

Necesitas g++ o equivalente. En macOS:

```bash
brew install gcc
```

## 🧩 Cómo ejecutar

	1. Clonar el repositorio (o descargar los archivos)
	2. Activar el entorno virtual 
	3. Ejecutar:
	
	```bash
    make animacion
    ```

## 📹 Resultado

El video generado muestra la evolución temporal de la molécula de agua, con una visualización clara de los enlaces y átomos, además de comentarios informativos durante los primeros segundos del video.

## 🧠 Créditos

Simulación basada en un modelo físico clásico. Proyecto desarrollado por Luis Tun, físico aplicado y científico de datos, como ejercicio educativo de física computacional.
