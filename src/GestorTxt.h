#include "GestorCsv.h"

using namespace std;

class GestorTxt
{

public:
    GestorTxt();
    bool generarArchivoTxt(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas, int, int);
};