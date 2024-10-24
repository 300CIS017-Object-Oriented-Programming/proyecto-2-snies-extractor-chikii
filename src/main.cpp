#include "View.h"

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        View menu;
        bool archivosParametrizados = menu.mostrarPantallaBienvenido();

        if (archivosParametrizados)
        {
            // menu.mostrarDatosExtra();
            menu.buscarPorPalabraClaveYFormacion();
        }

        menu.salir();
    }
    catch (const domain_error &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }

    return 0;
}
