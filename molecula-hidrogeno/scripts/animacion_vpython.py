#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import gizeh as gz
import numpy as np
import time
from moviepy import VideoClip

# Configuración general
W, H = 1024, 768  # Ancho y alto del video
D = 25            # Duración en segundos
nball = 3
FPS = 20 # Cuadros por segundo
DATA_FILE = "data/molecula.dat"

# Gradientes para átomos
gradient1 = gz.ColorGradient(type="radial",
                            stops_colors =[(0,(1,1,0)),(1,(0.1,0.1,0))],
                            xy1=[0.3,-0.3], xy2=[0,0], xy3 =[0,1.4])
gradient2 = gz.ColorGradient(type="radial",
                            stops_colors =[(0,(1,1,0)),(1,(0.1,0.1,0))],
                             xy1=[0.3,-0.3], xy2=[0,0], xy3 =[0,1.4])
gradient3 = gz.ColorGradient(type="radial",
                             stops_colors =[(0,(1,0,0)),(1,(0.1,0,0))],
                             xy1=[0.3,-0.3], xy2=[0,0], xy3 =[0,1.4])

# Cargar datos
data = np.loadtxt(DATA_FILE)

def make_frame(t):
    i = min(int(200 * t), len(data) - 1)
    frame_data = data[i]
    
    # Coordenadas escaladas
    xO, yO = frame_data[9] * 160, frame_data[10] * 160
    xH1, yH1 = frame_data[1] * 160, frame_data[2] * 160
    xH2, yH2 = frame_data[5] * 160, frame_data[6] * 160

    Angstrom = "\u00C5"
    surface = gz.Surface(W, H, bg_color=(0.8, 0.8, 0.8))

    shadow_gradient = gz.ColorGradient(
        type="radial",
        stops_colors=[(0, (0, 0, 0, .7 / 5)), (1, (0, 0, 0, 0))],
        xy1=[0, 0], xy2=[0, 0], xy3=[0, 1.4]
    )

    def draw_text_cond(condition, text, xy):
        if condition:
            gz.text(text, "Amiri", fontsize=20, xy=xy, fontweight='bold').draw(surface)

    def draw_atom(x, y, r, gradient, label):
        gz.circle(r=r, fill=gradient).scale(50).translate((x - 500, y - 600)).draw(surface)
        gz.circle(r=r, fill=shadow_gradient).scale(50, 25).translate((x - 600, y - 500)).draw(surface)
        gz.text(label, fontfamily="Amiri", fontsize=40, xy=(x - 500, y - 600), fontweight='bold').draw(surface)

    # Textos informativos por tiempo
    draw_text_cond(8 >= t >= 1,  "Condiciones iniciales: Hidrógeno 1",         (750, 140))
    draw_text_cond(8 >= t >= 2,  f"posición inicial en x H1 =2.9 {Angstrom}", (750, 180))
    draw_text_cond(8 >= t >= 3,  f"posición inicial en y H1 =3.9 {Angstrom}", (750, 220))
    draw_text_cond(8 >= t >= 4,  f"velocidad inicial en x H1 =2.0 {Angstrom}/s", (750, 260))
    draw_text_cond(8 >= t >= 5,  f"velocidad inicial en y H1 =2.0 {Angstrom}/s", (750, 300))

    draw_text_cond(15 >= t >= 8,  "Condiciones iniciales: Hidrógeno 2",         (250, 440))
    draw_text_cond(15 >= t >= 9,  f"posición inicial en x H2 =3.9 {Angstrom}", (250, 480))
    draw_text_cond(15 >= t >= 10, f"posición inicial en y H2 =2.8 {Angstrom}", (250, 520))
    draw_text_cond(15 >= t >= 11, f"velocidad inicial en x H2 =1.0 {Angstrom}/s", (250, 560))
    draw_text_cond(15 >= t >= 12, f"velocidad inicial en y H2 =2.0 {Angstrom}/s", (250, 600))

    draw_text_cond(24 >= t >= 15, "Condiciones iniciales: Oxígeno",            (250, 140))
    draw_text_cond(24 >= t >= 16, f"posición inicial en x O =3.0 {Angstrom}", (250, 180))
    draw_text_cond(24 >= t >= 17, f"posición inicial en y O =3.0 {Angstrom}", (250, 220))
    draw_text_cond(24 >= t >= 18, f"velocidad inicial en x O =0.0 {Angstrom}/s", (250, 260))
    draw_text_cond(24 >= t >= 19, f"velocidad inicial en y O =0.0 {Angstrom}/s", (250, 300))

    # Título y tiempo
    gz.text("Molécula de Agua", "Amiri", fontsize=40, xy=(500, 50), fontweight='bold').draw(surface)
    gz.text(f"t={t:.4f} s", "Amiri", fontsize=20, xy=(450, 100), fontweight='bold').draw(surface)

    # Enlaces moleculares
    gz.polyline(points=[
        (xH1 - 500, yH1 - 600),
        (xO  - 500, yO  - 600),
        (xH2 - 500, yH2 - 600),
        (xO  - 500, yO  - 600)
    ], stroke_width=5, fill=(1, 0, 0)).draw(surface)

    # Átomos y sombras
    draw_atom(xH1, yH1, 0.9, gradient1, "H")
    draw_atom(xH2, yH2, 0.9, gradient2, "H")
    draw_atom(xO,  yO,  1.5, gradient3, "O")

    return surface.get_npimage()

# Crear clip y exportar
clip = VideoClip(make_frame, duration=D)
clip.write_videofile("output/molecula_animacion.mp4", fps=FPS)
