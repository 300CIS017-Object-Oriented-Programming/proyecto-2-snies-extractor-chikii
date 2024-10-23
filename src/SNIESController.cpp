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

void SNIESController::procesarDatosCsv(string &ano1, string &ano2)
{
    vector<int> codigosSnies;
    vector<vector<string>> programasAcademicosVector;
    int posicion;
    int columna;
    // Cambios realizados por el issue: 3-funcionamiento-de-rango-de-anios-en-proyecto
    int a, b, c, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, z, ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an, ar;
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
    }
    // a, b, c, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, x, y, z, ab, ac, ad, ae, af, ag, ah, ai, aj, ak, al, am, an
    posicionColumnas.push_back(a);
    posicionColumnas.push_back(b);
    posicionColumnas.push_back(ar);
    posicionColumnas.push_back(c);
    posicionColumnas.push_back(d);
    posicionColumnas.push_back(e);
    posicionColumnas.push_back(f);
    posicionColumnas.push_back(g);
    posicionColumnas.push_back(h);
    posicionColumnas.push_back(ii);
    posicionColumnas.push_back(j);
    posicionColumnas.push_back(k);
    posicionColumnas.push_back(l);
    posicionColumnas.push_back(m);
    posicionColumnas.push_back(n);
    posicionColumnas.push_back(o);
    posicionColumnas.push_back(p);
    posicionColumnas.push_back(q);
    posicionColumnas.push_back(r);
    posicionColumnas.push_back(s);
    posicionColumnas.push_back(t);
    posicionColumnas.push_back(u);
    posicionColumnas.push_back(v);
    posicionColumnas.push_back(x);
    posicionColumnas.push_back(y);
    posicionColumnas.push_back(z);
    posicionColumnas.push_back(ab);
    posicionColumnas.push_back(ac);
    posicionColumnas.push_back(ad);
    posicionColumnas.push_back(ae);
    posicionColumnas.push_back(af);
    posicionColumnas.push_back(ag);
    posicionColumnas.push_back(ah);
    posicionColumnas.push_back(ai);
    posicionColumnas.push_back(aj);
    posicionColumnas.push_back(ak);
    posicionColumnas.push_back(al);
    posicionColumnas.push_back(am);
    posicionColumnas.push_back(an);

    // vamos a hacer el ciclo para hallar las etiquetas

    for (int i = 1; i < programasAcademicosVector.size(); i += 4)
    {
        // aca es donde el valor de la columna tenemos que encontrarla para cada etiqueta asumiendo que es variable
        ProgramaAcademico *programaAcademico = new ProgramaAcademico();
        programaAcademico->setCodigoDeLaInstitucion(stoi(programasAcademicosVector[i][posicionColumnas[0]]));          // CÓDIGO DE LA INSTITUCIÓN
        programaAcademico->setIesPadre(stoi(programasAcademicosVector[i][posicionColumnas[1]]));                       // IES_PADRE
        programaAcademico->setInstitucionDeEducacionSuperiorIes(programasAcademicosVector[i][posicionColumnas[2]]);    // INSTITUCIÓN DE EDUCACIÓN SUPERIOR (IES)
        programaAcademico->setPrincipalOSeccional(programasAcademicosVector[i][posicionColumnas[3]]);                  // PRINCIPAL O SECCIONAL
        programaAcademico->setIdSectorIes(stoi(programasAcademicosVector[i][posicionColumnas[4]]));                    // ID SECTOR IES
        programaAcademico->setSectorIes(programasAcademicosVector[i][posicionColumnas[5]]);                            // SECTOR IES
        programaAcademico->setIdCaracter(stoi(programasAcademicosVector[i][posicionColumnas[6]]));                     // ID CARÁCTER
        programaAcademico->setCaracterIes(programasAcademicosVector[i][posicionColumnas[7]]);                          // CARACTER IES
        programaAcademico->setCodigoDelDepartamentoIes(stoi(programasAcademicosVector[i][posicionColumnas[8]]));       // CÓDIGO DEL DEPARTAMENTO (IES)
        programaAcademico->setDepartamentoDeDomicilioDeLaIes(programasAcademicosVector[i][posicionColumnas[9]]);       // DEPARTAMENTO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoDelMunicipioIes(stoi(programasAcademicosVector[i][posicionColumnas[10]]));         // CÓDIGO DEL MUNICIPIO IES
        programaAcademico->setMunicipioDeDomicilioDeLaIes(programasAcademicosVector[i][posicionColumnas[11]]);         // MUNICIPIO DE DOMICILIO DE LA IES
        programaAcademico->setCodigoSniesDelPrograma(stoi(programasAcademicosVector[i][posicionColumnas[12]]));        // CÓDIGO SNIES DEL PROGRAMA
        programaAcademico->setProgramaAcademico(programasAcademicosVector[i][posicionColumnas[13]]);                   // PROGRAMA ACADÉMICO
        programaAcademico->setIdNivelAcademico(stoi(programasAcademicosVector[i][posicionColumnas[14]]));              // ID NIVEL ACADÉMICO
        programaAcademico->setNivelAcademico(programasAcademicosVector[i][posicionColumnas[15]]);                      // NIVEL ACADÉMICO
        programaAcademico->setIdNivelDeFormacion(stoi(programasAcademicosVector[i][posicionColumnas[16]]));            // ID NIVEL DE FORMACIÓN
        programaAcademico->setNivelDeFormacion(programasAcademicosVector[i][posicionColumnas[17]]);                    // NIVEL DE FORMACIÓN
        programaAcademico->setIdMetodologia(stoi(programasAcademicosVector[i][posicionColumnas[18]]));                 // ID METODOLOGÍA
        programaAcademico->setMetodologia(programasAcademicosVector[i][posicionColumnas[19]]);                         // METODOLOGÍA
        programaAcademico->setIdArea(stoi(programasAcademicosVector[i][posicionColumnas[20]]));                        // ID ÁREA
        programaAcademico->setAreaDeConocimiento(programasAcademicosVector[i][posicionColumnas[21]]);                  // ÁREA DE CONOCIMIENTO
        programaAcademico->setIdNucleo(stoi(programasAcademicosVector[i][posicionColumnas[22]]));                      // ID NÚCLEO
        programaAcademico->setNucleoBasicoDelConocimientoNbc(programasAcademicosVector[i][posicionColumnas[23]]);      // NÚCLEO BÁSICO DEL CONOCIMIENTO (NBC)
        programaAcademico->setIdCineCampoAmplio(stoi(programasAcademicosVector[i][posicionColumnas[24]]));             // ID CINE CAMPO AMPLIO
        programaAcademico->setDescCineCampoAmplio(programasAcademicosVector[i][posicionColumnas[25]]);                 // DESC CINE CAMPO AMPLIO
        programaAcademico->setIdCineCampoEspecifico(stoi(programasAcademicosVector[i][posicionColumnas[26]]));         // ID CINE CAMPO ESPECÍFICO
        programaAcademico->setDescCineCampoEspecifico(programasAcademicosVector[i][posicionColumnas[27]]);             // DESC CINE CAMPO ESPECÍFICO
        programaAcademico->setIdCineCodigoDetallado(stoi(programasAcademicosVector[i][posicionColumnas[28]]));         // ID CINE CÓDIGO DETALLADO
        programaAcademico->setDescCineCodigoDetallado(programasAcademicosVector[i][posicionColumnas[29]]);             // DESC CINE CÓDIGO DETALLADO
        programaAcademico->setCodigoDelDepartamentoPrograma(stoi(programasAcademicosVector[i][posicionColumnas[30]])); // CÓDIGO DEL DEPARTAMENTO (PROGRAMA)
        programaAcademico->setDepartamentoDeOfertaDelPrograma(programasAcademicosVector[i][posicionColumnas[31]]);     // DEPARTAMENTO DE OFERTA DEL PROGRAMA
        programaAcademico->setCodigoDelMunicipioPrograma(stoi(programasAcademicosVector[i][posicionColumnas[32]]));    // CÓDIGO DEL MUNICIPIO (PROGRAMA)
        programaAcademico->setMunicipioDeOfertaDelPrograma(programasAcademicosVector[i][posicionColumnas[33]]);        // MUNICIPIO DE OFERTA DEL PROGRAMA
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
            int sexo = stoi(programasAcademicosVector[i + m][aj]);
            int semestre = stoi(programasAcademicosVector[i + m][am]);
            int anio = stoi(programasAcademicosVector[i + m][al]);
            programaAcademico->setConsolidado(consolidado[m], semestre, sexo, anio);
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
                consolidado[m]->setIdSexo(stoi(programasAcademicosVector[j + m][aj])); // encontre un error del fix 3, de una vez voy a ponerlo para cuando se le haga merge a este fix
                consolidado[m]->setSexo(programasAcademicosVector[j + m][ak]);
                consolidado[m]->setAno(stoi(programasAcademicosVector[j + m][al]));
                consolidado[m]->setSemestre(stoi(programasAcademicosVector[j + m][am]));
                consolidado[m]->setAdmitidos(stoi(programasAcademicosVector[j + m][an]));
                int semestre = stoi(programasAcademicosVector[j + m][am]);
                int sexo = stoi(programasAcademicosVector[j + m][aj]);
                int anio = stoi(programasAcademicosVector[j + m][al]);
                programa->setConsolidado(consolidado[m], semestre, sexo, anio);
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
                Consolidado *consolidado = programa->getConsolidado(m, sexo, anio1);
                consolidado->setGraduados(stoi(programasAcademicosVector[k + m][1]));
            }
        }

        programasAcademicosVector = gestorCsvObj.leerArchivo(rutaGraduados, ano2, codigosSnies, 13); // creeria que hay que tambien hallar la etiqueta de graduados

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

        bool archivoCreado;
        archivoCreado = gestorCsvObj.crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
        // cout << archivoCreado << endl;
        /*catch (const ios_base::failure &e)
        {
            cerr << "ERROR: " << e.what() << endl;
        }*/
    }
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