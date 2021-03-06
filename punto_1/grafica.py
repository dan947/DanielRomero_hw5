import numpy as np
import corner

datos=np.genfromtxt("a.dat")
figure = corner.corner(datos,labels=[r"$x$", r"$y$", r"$\Gamma \, [\mathrm{parsec}]$"],quantiles=[0.16, 0.5], show_titles=True ,title_kwargs={"fontsize": 12})

figure.savefig("epicentro.pdf")
