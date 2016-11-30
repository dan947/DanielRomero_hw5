import numpy as np
import corner

datos=np.genfromtxt("poblacion.dat")
figure = corner.corner(datos,labels=[r"$betta$", r"$alpha$", r"$\delta$",r"$\gamma$", r"$\Gamma \, [\mathrm{parsec}]$"],quantiles=[0.16, 0.5], show_titles=True ,title_kwargs={"fontsize": 12})

figure.savefig("poblacion.pdf")
