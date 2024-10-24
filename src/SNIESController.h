#ifndef SNIES_CONTROLLER_H
#define SNIES_CONTROLLER_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include "ProgramaAcademico.h"
#include "Consolidado.h"
#include "GestorCsv.h"

using namespace std;

class SNIESController
{

private:
    map<int, ProgramaAcademico *> programasAcademicos;
    GestorCsv gestorCsvObj;
    vector<string> etiquetasColumnas;
    string rutaProgramasCSV;
    string rutaAdmitidos;
    string rutaGraduados;
    string rutaInscritos;
    string rutaMatriculados;
    string rutaMatriculadosPrimerSemestre;
    string rutaOutput;

public:
    SNIESController() = default;
    SNIESController(string &, string &, string &, string &, string &, string &, string &);
    ~SNIESController();
    void procesarDatosCsv(string &, string &, int, int, int);
    void calcularDatosExtra(bool);
    void buscarProgramas(bool, string &, int);
    bool procesarTipoOutput(int, string, map<int, ProgramaAcademico *> &, vector<string> &, GestorCsv &, int, int /*,GestorTXT& gestorTxtObj, GestorJSON& gestorJSONObj*/);
};

#endif