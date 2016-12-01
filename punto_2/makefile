gravitacion:gravitacion.pdf
	evince gravitacion.pdf
	rm a.dat

gravitacion.pdf : grafica.py a.dat
		python grafica.py
		rm a.out

a.dat : a.out
	./a.out > a.dat

a.out : gravedad.c
	gcc gravedad.c -lm
