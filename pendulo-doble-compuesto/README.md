# Péndulo Doble Compuesto

Este proyecto simula numéricamente el movimiento de un péndulo doble compuesto usando métodos de integración numérica como Runge-Kutta de 4to orden (RK4) y Runge-Kutta-Fehlberg (RKF45), implementado en C++.

> Trabajo realizado originalmente como parte de un curso de Simulación de Fenómenos Físicos en 2015.

---

## 🎯 Objetivo

Resolver las ecuaciones de movimiento del péndulo doble compuesto a partir del lagrangiano del sistema, y visualizar la evolución temporal de sus ángulos y coordenadas.

---

## 📂 Archivos principales

| Archivo                 | Descripción                                                               |
|-------------------------|---------------------------------------------------------------------------|
| `pendulo_rk4.cpp`       | Simulación principal usando RK4 con paso fijo                             |
| `pendulo_animacion.cpp` | Generación de datos para animación cuadro por cuadro                      |
| `pendulo_rkf45.cpp`     | Ejecución del método RKF45 con control de error adaptativo                |
| `generar_animacion.sh`  | Script Bash que genera animación con Gnuplot                              |
| `reporte_proyecto.pdf`  | Reporte académico original con teoría, gráficas y discusión de resultados |
| `odeint.h`              | Funciones del integrador adaptativo                            |

---

## ⚙️ Compilación

Este proyecto requiere un compilador C++ y Gnuplot:

```bash
g++ pendulo_rk4.cpp -o pendulo_rk4 -lm
./pendulo_rk
