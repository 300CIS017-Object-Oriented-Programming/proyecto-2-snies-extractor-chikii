#include "GestorCsv.h"

using namespace std;

class GestorJSON
{

public:
    GestorJSON();
    bool crearArchivoJSON(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas, int, int);
};