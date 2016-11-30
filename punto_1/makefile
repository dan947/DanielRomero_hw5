epicentro:epicentro.pdf
	evince epicentro.pdf

epicentro.pdf : grafica.py a.dat
	python grafica.py

a.dat : a.out
	./a.out > a.dat

a.out : epicentro.c
	gcc epicentro.c -lm


