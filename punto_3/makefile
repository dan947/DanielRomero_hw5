poblacion:poblacion.pdf
	evince poblacion.pdf
poblacion.pdf: grafica.py poblacion.dat
		python grafica.py
poblacion.dat:poblacion.c lotka_volterra_obs.dat
	gcc poblacion.c -lm
	./a.out> poblacion.dat

