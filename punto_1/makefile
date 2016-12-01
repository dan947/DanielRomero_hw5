epicentro:epicentro.pdf
	evince epicentro.pdf

epicentro.pdf : grafica.py datos.dat
		python grafica.py

datos.dat : a.out
	./a.out > datos.dat

a.out : epicentro.c
	gcc epicentro.c -lm



.PHONY: clean
clean:
	rm -f a.out datos.dat



