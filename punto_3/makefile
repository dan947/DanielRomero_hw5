poblacion:poblacion.pdf
	evince poblacion.pdf
	rm poblacion.dat

poblacion.pdf : grafica.py poblacion.dat
		python grafica.py
		rm a.out

poblacion.dat : a.out
	./a.out > poblacion.dat

a.out : poblacion.c lotka_volterra_obs.dat
		gcc poblacion.c -lm


