#ifndef VIEW_H
#define VIEW_H
#include "SNIESController.h"
/*Todo el codigo va entre estas guardas*/
#include "SNIESController.h"
#include <cctype>

using namespace std;

class View
{
private:
    SNIESController controlador;

public:
    View();
    ~View();
    bool mostrarPantallaBienvenido();
    void mostrarDatosExtra(int, int);
    void buscarPorPalabraClaveYFormacion();
    void salir();
    bool isConvetibleToInt(const string &);
    void revisionAnios(string);
};

#endif