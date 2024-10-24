#include "SNIESController.h"

/*
Anotaciones para resolver issue #3
Acceder a la informacion necesaria sin importar la variacion de columnas

Verificar las columnas que necesito asumiendo que siempre van a variar
tener una variable que guarde el numero de columna que corresponde a esa informacion


NUEVA RAMA ACTUALIZADA POR ERROR DE ENCABEZADO



*/

SNIESController::SNIESController(string &nuevaRutaProgramasCSV, string &nuevaRutaAdmitidos, string &nuevaRutaGraduados, string &nuevaRutaInscritos, string &nuevaRutaMatriculadosc, string &nuevaRutaMatriculadosPrimerSemestre, string &nuevaRutaOutput)
{
    // FIXME quitar los parámetros de las rutas de los parametros del constructor, usar el archivo de settings.h para poner las constantes
    gestorCsvObj = GestorCsv();
    rutaProgramasCSV = nuevaRutaProgramasCSV;
    rutaAdmitidos = nuevaRutaAdmitidos;
    rutaGraduados = nuevaRutaGraduados;
    rutaInscritos = nuevaRutaInscritos;
    rutaMatriculados = nuevaRutaMatriculadosc;
    rutaMatriculadosPrimerSemestre = nuevaRutaMatriculadosPrimerSemestre;
    rutaOutput = nuevaRutaOutput;
}

SNIESController::~SNIESController()
{
    for (auto &pair : programasAcademicos)
    {
        ((pair).second)->~ProgramaAcademico();
        delete pair.second;
    }
}

void SNIESController::procesarDatosCsv(string &ano1, string &ano2, int opcionOutput, int anoInicio, int anoFin)
{
    vector<int> codigosSnies;
    vector<vector<string>> programasAcademicosVector;
    int posicion;
    int columna;
    // Cambios realizados por el issue: 3-funcionamiento-de-rango-de-anios-en-proyecto
    int a, b, c, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, z, ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an, ao, ap, aq, ar;
    vector<int> posicionColumnas;
    // cout << "antes leer programas csv" << endl;
    codigosSnies = gestorCsvObj.leerProgramasCsv(rutaProgramasCSV);

    // cout << "despues leer programas csv" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivoPrimera(rutaAdmitidos, ano1, codigosSnies);
    // cout << "Esta es la ruta de admitidos " << rutaAdmitidos << endl;
    //  cout << "despues leer archivos Primera" << endl;
    etiquetasColumnas = programasAcademicosVector[0]; // Esta linea recibe todas las etiquetas para luego procesarlas una a una
                                                      // *** FIN DE CAMBIO ***
    /*
    try
    {
        // cout << "antes leer programas csv" << endl;
        codigosSnies = gestorCsvObj.leerProgramasCsv(rutaProgramasCSV);
        // cout << "despues leer programas csv" << endl;
        programasAcademicosVector = gestorCsvObj.leerArchivoPrimera(rutaAdmitidos, ano1, codigosSnies);
        // cout << "despues leer archivos Primera" << endl;
        etiquetasColumnas = programasAcademicosVector[0];
    }
    catch (const ios_base::failure &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    */

    for (int i = 0; i < etiquetasColumnas.size(); i++)
    {
        if (etiquetasColumnas[i] == "CÓDIGO DE LA INSTITUCIÓN")
        {
            a = i;
        }
        else if (etiquetasColumnas[i] == "IES_PADRE")
        {
            b = i;
        }
        else if (etiquetasColumnas[i] == "INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)")
        {
            ar = i;
        }
        else if (etiquetasColumnas[i] == "PRINCIPAL O SECCIONAL")
        {
            c = i;
        }
        else if (etiquetasColumnas[i] == "ID SECTOR IES")
        {
            d = i;
        }

        else if (etiquetasColumnas[i] == "SECTOR IES")
        {
            e = i;
        }
        else if (etiquetasColumnas[i] == "ID CARACTER")
        {
            f = i;
        }
        else if (etiquetasColumnas[i] == "CARACTER IES")
        {
            g = i;
        }
        else if (etiquetasColumnas[i] == "CÓDIGO DEL DEPARTAMENTO (IES)")
        {
            h = i;
        }
        else if (etiquetasColumnas[i] == "DEPARTAMENTO DE DOMICILIO DE LA IES")
        {
            ii = i;
        }
        else if (etiquetasColumnas[i] == "CÓDIGO DEL MUNICIPIO IES")
        {
            j = i;
        }
        else if (etiquetasColumnas[i] == "MUNICIPIO DE DOMICILIO DE LA IES")
        {
            k = i;
        }
        else if (etiquetasColumnas[i] == "CÓDIGO SNIES DEL PROGRAMA")
        {
            l = i;
        }
        else if (etiquetasColumnas[i] == "PROGRAMA ACADÉMICO")
        {
            m = i;
        }
        else if (etiquetasColumnas[i] == "ID NIVEL ACADÉMICO")
        {
            n = i;
        }
        else if (etiquetasColumnas[i] == "NIVEL ACADÉMICO")
        {
            o = i;
        }
        else if (etiquetasColumnas[i] == "ID NIVEL DE FORMACIÓN")
        {
            p = i;
        }
        else if (etiquetasColumnas[i] == "NIVEL DE FORMACIÓN")
        {
            q = i;
        }
        else if (etiquetasColumnas[i] == "ID METODOLOGÍA")
        {
            r = i;
        }
        else if (etiquetasColumnas[i] == "METODOLOGÍA")
        {
            s = i;
        }
        else if (etiquetasColumnas[i] == "ID ÁREA")
        {
            t = i;
        }
        else if (etiquetasColumnas[i] == "ÁREA DE CONOCIMIENTO")
        {
            u = i;
        }
        else if (etiquetasColumnas[i] == "ID NÚCLEO")
        {
            v = i;
        }
        else if (etiquetasColumnas[i] == "NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)")
        {
            x = i;
        }
        else if (etiquetasColumnas[i] == "ID CINE CAMPO AMPLIO")
        {
            y = i;
        }
        else if (etiquetasColumnas[i] == "DESC CINE CAMPO AMPLIO")
        {
            z = i;
        }
        else if (etiquetasColumnas[i] == "ID CINE CAMPO ESPECIFICO")
        {
            ab = i;
        }
        else if (etiquetasColumnas[i] == "DESC CINE CAMPO ESPECIFICO")
        {
            ac = i;
        }
        else if (etiquetasColumnas[i] == "ID CINE CODIGO DETALLADO")
        {
            ad = i;
        }
        else if (etiquetasColumnas[i] == "DESC CINE CODIGO DETALLADO")
        {
            ae = i;
        }
        else if (etiquetasColumnas[i] == "CÓDIGO DEL DEPARTAMENTO (PROGRAMA)")
        {
            af = i;
        }
        else if (etiquetasColumnas[i] == "DEPARTAMENTO DE OFERTA DEL PROGRAMA")
        {
            ag = i;
        }
        else if (etiquetasColumnas[i] == "CÓDIGO DEL MUNICIPIO (PROGRAMA)")
        {
            ah = i;
        }
        else if (etiquetasColumnas[i] == "MUNICIPIO DE OFERTA DEL PROGRAMA")
        {
            ai = i;
        }
        else if (etiquetasColumnas[i] == "ID SEXO")
        {
            aj = i;
        }
        else if (etiquetasColumnas[i] == "SEXO")
        {
            ak = i;
        }
        else if (etiquetasColumnas[i] == "AÑO")
        {
            al = i;
        }
        else if (etiquetasColumnas[i] == "SEMESTRE")
        {
            am = i;
        }
        else if (etiquetasColumnas[i] == "ADMITIDOS")
        {
            an = i;
        }
        else if (etiquetasColumnas[i] == "ID ÁREA")
        {
            ao = i;
        }
        else if (etiquetasColumnas[i] == "ID ÁREA")
        {
            ap = i;
        }
        else if (etiquetasColumnas[i] == "ID ÁREA")
        {
            aq = i;
        }
    }

    // vamos a hacer el ciclo para hallar las etiquetas

    for (int i = 1; i < programasAcademicosVector.size(); i += 4)
    {
        // aca es donde el valor de la columna tenemos que encontrarla para cada etiqueta asumiendo que es variable
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();
        programaAcademico->setCodigoDeLaInstitucion(stoi(programasAcademicosVector[i][a]));          // CÓDIGO DE LA INSTITUCIÓN
        programaAcademico->setIesPadre(stoi(programasAcademicosVector[i][b]));                       // IES_PADRE
        programaAcademico->setInstitucionDeEducacionSuperiorIes(programasAcademicosVector[i][ar]);   // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
        programaAcademico->setPrincipalOSeccional(programasAcademicosVector[i][c]);                  // PRINCIPAL O SECCIONAL
        programaAcademico->setIdSectorIes(stoi(programasAcademicosVector[i][d]));                    // ID SECTOR IES
        programaAcademico->setSectorIes(programasAcademicosVector[i][e]);                            // SECTOR IES
        programaAcademico->setIdCaracter(stoi(programasAcademicosVector[i][f]));                     // ID CARÁCTER
        programaAcademico->setCaracterIes(programasAcademicosVector[i][g]);                          // CARACTER IES
        programaAcademico->setCodigoDelDepartamentoIes(stoi(programasAcademicosVector[i][h]));       // CÓDIGO DEL DEPARTAMENTO (IES)
        programaAcademico->setDepartamentoDeDomicilioDeLaIes(programasAcademicosVector[i][ii]);      // DEPARTAMENTO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoDelMunicipioIes(stoi(programasAcademicosVector[i][j]));          // CÓDIGO DEL MUNICIPIO IES
        programaAcademico->setMunicipioDeDomicilioDeLaIes(programasAcademicosVector[i][k]);          // MUNICIPIO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoSniesDelPrograma(stoi(programasAcademicosVector[i][l]));         // CÓDIGO SNIES DEL PROGRAMA
        programaAcademico->setProgramaAcademico(programasAcademicosVector[i][m]);                    // PROGRAMA ACADÉMICO
        programaAcademico->setIdNivelAcademico(stoi(programasAcademicosVector[i][n]));               // ID NIVEL ACADÉMICO
        programaAcademico->setNivelAcademico(programasAcademicosVector[i][o]);                       // NIVEL ACADÉMICO
        programaAcademico->setIdNivelDeFormacion(stoi(programasAcademicosVector[i][p]));             // ID NIVEL DE FORMACIÓN
        programaAcademico->setNivelDeFormacion(programasAcademicosVector[i][q]);                     // NIVEL DE FORMACIÓN
        programaAcademico->setIdMetodologia(stoi(programasAcademicosVector[i][r]));                  // ID METODOLOGÍA
        programaAcademico->setMetodologia(programasAcademicosVector[i][s]);                          // METODOLOGÍA
        programaAcademico->setIdArea(stoi(programasAcademicosVector[i][t]));                         // ID ÁREA
        programaAcademico->setAreaDeConocimiento(programasAcademicosVector[i][u]);                   // ÁREA DE CONOCIMIENTO
        programaAcademico->setIdNucleo(stoi(programasAcademicosVector[i][v]));                       // ID NÚCLEO
        programaAcademico->setNucleoBasicoDelConocimientoNbc(programasAcademicosVector[i][x]);       // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
        programaAcademico->setIdCineCampoAmplio(stoi(programasAcademicosVector[i][y]));              // ID CINE CAMPO AMPLIO
        programaAcademico->setDescCineCampoAmplio(programasAcademicosVector[i][z]);                  // DESC CINE CAMPO AMPLIO
        programaAcademico->setIdCineCampoEspecifico(stoi(programasAcademicosVector[i][ab]));         // ID CINE CAMPO ESPECÍFICO
        programaAcademico->setDescCineCampoEspecifico(programasAcademicosVector[i][ac]);             // DESC CINE CAMPO ESPECÍFICO
        programaAcademico->setIdCineCodigoDetallado(stoi(programasAcademicosVector[i][ad]));         // ID CINE CÓDIGO DETALLADO
        programaAcademico->setDescCineCodigoDetallado(programasAcademicosVector[i][ae]);             // DESC CINE CÓDIGO DETALLADO
        programaAcademico->setCodigoDelDepartamentoPrograma(stoi(programasAcademicosVector[i][af])); // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
        programaAcademico->setDepartamentoDeOfertaDelPrograma(programasAcademicosVector[i][ag]);     // DEPARTAMENTO DE OFERTA DEL PROGRAMA
        programaAcademico->setCodigoDelMunicipioPrograma(stoi(programasAcademicosVector[i][ah]));    // CÓDIGO DEL MUNICIPIO (PROGRAMA)
        programaAcademico->setMunicipioDeOfertaDelPrograma(programasAcademicosVector[i][ai]);        // MUNICIPIO DE OFERTA DEL PROGRAMA
        Consolidado *consolidado[4];
        // falta corregir las columnas
        for (int m = 0; m < 4; ++m)
        {

            consolidado[m] = new Consolidado();
            consolidado[m]->setIdSexo(stoi(programasAcademicosVector[i + m][aj]));
            consolidado[m]->setSexo(programasAcademicosVector[i + m][ak]);
            consolidado[m]->setAno(stoi(programasAcademicosVector[i + m][al]));
            consolidado[m]->setSemestre(stoi(programasAcademicosVector[i + m][am]));
            consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[i + m][an]));
            programaAcademico->setConsolidado(consolidado[m], m);
        }
        programasAcademicos.emplace(programaAcademico->getCodigoSniesDelPrograma(), programaAcademico);
    }
    // cout << "despues crear programas academicos" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivoSegunda(rutaAdmitidos, ano2, codigosSnies);
    // cout << "despues leer archivos segunda" << endl;
    for (int j = 0; j < programasAcademicosVector.size(); j += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[j][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            Consolidado *consolidado[4];
            for (int m = 0; m < 4; ++m)
            {
                consolidado[m] = new Consolidado();
                consolidado[m]->setIdSexo(stoi(programasAcademicosVector[j + m][1]));
                consolidado[m]->setSexo(programasAcademicosVector[j + m][2]);
                consolidado[m]->setAno(stoi(programasAcademicosVector[j + m][3]));
                consolidado[m]->setSemestre(stoi(programasAcademicosVector[j + m][4]));
                consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[j + m][5]));
                programa->setConsolidado(consolidado[m], m + 4);
            }
        }
    }
    // cout << "despues crear todos los consolidados" << endl;
    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaGraduados, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaGraduados, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaInscritos, ano1, codigosSnies, 12);
    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    if (ano2 == "2022")
    {
        columna = 12;
    }
    else
    {
        columna = 13;
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaInscritos, ano2, codigosSnies, columna);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setInscritos(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculados, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setMatriculados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculados, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setMatriculados(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculadosPrimerSemestre, ano1, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m);
                consolidado->setMatriculadosPrimerSemestre(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }

    programasAcademicosVector = gestorCsvObj.leerArchivo(rutaMatriculadosPrimerSemestre, ano2, codigosSnies, 13);

    for (int k = 0; k < programasAcademicosVector.size(); k += 4)
    {
        map<int, ProgramaAcademico *>::iterator it = programasAcademicos.find(stoi(programasAcademicosVector[k][0]));
        if (it != programasAcademicos.end())
        {
            ProgramaAcademico *programa = it->second;

            for (int m = 0; m < 4; ++m)
            {
                Consolidado *consolidado = programa->getConsolidado(m + 4);
                consolidado->setMatriculadosPrimerSemestre(stoi(programasAcademicosVector[k + m][1]));
            }
        }
    }
    int anoActual = stoi(ano1);
    int anoSiguiente = stoi(ano2);

    bool archivoCreado = procesarTipoOutput(opcionOutput, rutaOutput, programasAcademicos, etiquetasColumnas, gestorCsvObj, anoActual, anoSiguiente /*,gestorTxtObj, gestorJSONObj*/);

    if (!archivoCreado)
    {
        cout << "No se pudo crear el archivo de salida." << endl;
    }
    else
    {
        cout << "Archivo de salida creado exitosamente." << endl;
    }
}

bool SNIESController::procesarTipoOutput(int opcion, string rutaOutput, map<int, ProgramaAcademico *> &programasAcademicos, vector<string> &etiquetasColumnas, GestorCsv &gestorCsvObj, int anoInicio, int anoFin /*, GestorTxt &gestorTxtObj, GestorJSON &gestorJSONObj*/)
{
    bool archivoCreado = false;

    try
    {
        switch (opcion)
        {
        case 1: // CSV
            cout << "Exportando archivo resultado.csv..." << endl;
            archivoCreado = gestorCsvObj.crearArchivoCsv(rutaOutput, programasAcademicos, etiquetasColumnas, anoInicio, anoFin);
            break;
        case 2: // TXT
            cout << "Exportando archivo resultado.txt..." << endl;
            // archivoCreado = gestorTxtObj.crearArchivoTxt(rutaOutput, programasAcademicos, etiquetasColumnas, anoInicio, anoFin);
            break;
        case 3: // JSON
            cout << "Exportando archivo resultado.json..." << endl;
            // archivoCreado = gestorJSONObj.crearArchivoJSON(rutaOutput, programasAcademicos, etiquetasColumnas);
            break;
        case 4: // Ninguna
            cout << "No se ha creado ningun archivo." << endl;
            break;
        default: // Manejar entradas fuera del rango esperado
            throw out_of_range("Opción inválida. Debe ingresar un valor entre 1 y 4.");
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Error de entrada/salida: " << e.what() << endl;
    }

    return archivoCreado;
}

void SNIESController::buscarProgramas(bool flag, string &palabraClave, int idComparacion)
{
    list<ProgramaAcademico *> listaProgramas;
    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        ProgramaAcademico *programa = it->second;
        string nombre = programa->getProgramaAcademico();
        int id = programa->getIdNivelDeFormacion();
        if (nombre.find(palabraClave) != string::npos && id == idComparacion)
        {
            listaProgramas.push_back(programa);
            // codigo SNIES, nombre del programa, codigo de la institucion, nombre de la institucion y metodología
            cout << programa->getCodigoSniesDelPrograma() << ";" << programa->getProgramaAcademico() << ";" << programa->getCodigoDeLaInstitucion() << ";" << programa->getInstitucionDeEducacionSuperiorIes() << ";" << programa->getMetodologia() << endl;
        }
    }

    if (flag)
    {
        bool creado;
        creado = gestorCsvObj.crearArchivoBuscados(rutaOutput, listaProgramas, etiquetasColumnas);
    }
}

void SNIESController::calcularDatosExtra(bool flag)
{
    vector<vector<string>> matrizFinal;
    vector<vector<string>> matrizEtiquetas1;
    vector<vector<string>> matrizEtiquetas2;
    vector<vector<string>> matrizEtiquetas3;
    vector<string> etiquetas1 = {"Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual) Primer año", "Suma Estudiantes Matriculados de Programas Seleccionados (Presencial o Virtual)"};
    matrizEtiquetas1.push_back(etiquetas1);
    vector<string> etiquetas2 = {"Codigo Snies", "Nombre del Programa", "Nombre del Institucion", "Diferencial porcentual anual de NEOS"};
    matrizEtiquetas2.push_back(etiquetas2);
    vector<string> etiquetas3 = {"Codigo Snies", " Nombre del Programa sin NEOS en los ultimos 3 semestres"};
    matrizEtiquetas3.push_back(etiquetas3);
    vector<string> datosEtiquetas1;
    vector<string> datosEtiquetas2;
    int sumaPrimerAno = 0;
    int sumaSegundoAno = 0;

    for (map<int, ProgramaAcademico *>::iterator it = programasAcademicos.begin(); it != programasAcademicos.end(); ++it)
    {
        int neosPrimerAno = 0;
        int neosSegundoAno = 0;
        int diferenciaNeos = 0;
        ProgramaAcademico *programa = it->second;
        int idMetodologiaBuscada = programa->getIdMetodologia();
        if (idMetodologiaBuscada == 1 || idMetodologiaBuscada == 3)
        {
            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i);
                int matriculados = consolidado->getMatriculados();
                sumaPrimerAno += matriculados;
            }

            for (int i = 0; i < 4; ++i)
            {
                Consolidado *consolidado = programa->getConsolidado(i + 4);
                int matriculados = consolidado->getMatriculados();
                sumaSegundoAno += matriculados;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosPrimerAno += numNeos;
        }

        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidado = programa->getConsolidado(i + 4);
            int numNeos = consolidado->getMatriculadosPrimerSemestre();
            neosSegundoAno += numNeos;
        }

        if (neosPrimerAno != 0)
        {
            diferenciaNeos = ((neosSegundoAno - neosPrimerAno) * 100) / neosPrimerAno;
        }
        else
        {
            diferenciaNeos = 0;
        }
        datosEtiquetas2 = {to_string(programa->getCodigoSniesDelPrograma()), programa->getProgramaAcademico(), programa->getInstitucionDeEducacionSuperiorIes(), to_string(diferenciaNeos)};
        matrizEtiquetas2.push_back(datosEtiquetas2);
        int SumaNeosPrimerSemestre;
        int SumaNeosSegundoSemestre;
        int SumaNeosTercerSemestre;
        int SumaNeosCuartoSemestre;
        for (int i = 0; i < 4; ++i)
        {
            Consolidado *consolidados[8];
            if (i == 0)
            {
                consolidados[0] = programa->getConsolidado(i);
                consolidados[1] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[0]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[1]->getMatriculadosPrimerSemestre();
                SumaNeosPrimerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 1)
            {
                consolidados[2] = programa->getConsolidado(i);
                consolidados[3] = programa->getConsolidado(i + 2);
                int neosHombres = consolidados[2]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[3]->getMatriculadosPrimerSemestre();
                SumaNeosSegundoSemestre = neosHombres + neosMujeres;
            }
            else if (i == 2)
            {
                consolidados[4] = programa->getConsolidado(i + 2);
                consolidados[5] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[4]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[5]->getMatriculadosPrimerSemestre();
                SumaNeosTercerSemestre = neosHombres + neosMujeres;
            }
            else if (i == 3)
            {
                consolidados[6] = programa->getConsolidado(i + 2);
                consolidados[7] = programa->getConsolidado(i + 4);
                int neosHombres = consolidados[6]->getMatriculadosPrimerSemestre();
                int neosMujeres = consolidados[7]->getMatriculadosPrimerSemestre();
                SumaNeosCuartoSemestre = neosHombres + neosMujeres;
            }
        }

        if ((SumaNeosPrimerSemestre == 0 && SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0) || (SumaNeosSegundoSemestre == 0 && SumaNeosTercerSemestre == 0 && SumaNeosCuartoSemestre == 0))
        {
            etiquetas3 = {to_string(programa->getCodigoSniesDelPrograma()),
                          programa->getProgramaAcademico()};
        }
    }
    etiquetas1 = {to_string(sumaPrimerAno), to_string(sumaSegundoAno)};
    matrizEtiquetas1.push_back(etiquetas1);
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas1.begin(), matrizEtiquetas1.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas2.begin(), matrizEtiquetas2.end());
    matrizFinal.insert(matrizFinal.end(), matrizEtiquetas3.begin(), matrizEtiquetas3.end());

    for (const auto &fila : matrizFinal)
    {
        for (size_t i = 0; i < fila.size(); ++i)
        {
            cout << fila[i];
            if (i < fila.size() - 1)
            {
                cout << ";";
            }
        }
        cout << endl;
    }

    if (flag)
    {
        bool creado;
        creado = gestorCsvObj.crearArchivoExtra(rutaOutput, matrizFinal);
    }
}