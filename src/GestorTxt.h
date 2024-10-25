#include "GestorCsv.h"

using namespace std;

class GestorTxt
{

public:
    GestorTxt();
    bool crearArchivoTxt(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas, int, int);
};