epicentro:epicentro.pdf
	evince epicentro.pdf
	rm datos.dat

epicentro.pdf : grafica.py datos.dat
		python grafica.py
		rm a.out

datos.dat : a.out
	./a.out > datos.dat

a.out : epicentro.c
	gcc epicentro.c -lm




