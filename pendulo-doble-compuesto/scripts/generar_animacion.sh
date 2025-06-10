#!/bin/bash

for(( i=10000; i<=15000; i=i+1 ))
do

cat > tmp <<EOF
set term pngcairo enhanced font 'Verdana,12'
set encoding utf8
set output "output/graf$i.png"
set title "Animación Péndulo Doble Compuesto"
set style fill   pattern 2 border lt 1
set label 1 "θ₁(0)=π/4, p₁(0)=0" at -0.30,-0.43
set label 2 "θ₂(0)=π/2, p₂(0)=0" at -0.30,-0.47
#set style line 1 lt 2 lc rgb "red" lw 3
#set style fill solid noborder
set object  5 rect from -0.500000, 0.200000, 0.00000 to 0.500000, 0.000000, 0.00000
set object  5 back clip lw 1.0 fc  rgb "black"  fillstyle   pattern 1 border lt -1
set grid
set size square
set xrange [-0.35:0.35]
set yrange [-0.5:0.2]

tiempo = (($i-10000)/100.0)
set label 3 sprintf("t=%3.4f s",tiempo) at 0.1,-0.47 font "verdana"
plot 'data/animation.dat' u (\$2):(\$6==tiempo? \$3 : 1/0) w l lt 4 lw 6 lc rgb "red"  t '', \
'' u (\$4):(\$6==tiempo? \$5 : 1/0) w l lt 4 lw 6 lc rgb "red" t '', \
'' u (\$2):(\$6==tiempo ? \$3 : 1/0)  pt 7 ps 1 lc rgb "white" t '', \
#'' u (\$4):(\$1==$i ? \$5 : 1/0) w circle lc rgb "red" t ''
EOF

gnuplot tmp

echo "Cuadro $i generado"

done

rm -f tmp
