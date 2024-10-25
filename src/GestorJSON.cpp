#include "GestorJSON.h"

GestorJSON::GestorJSON()
{
}

#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

bool GestorJSON::crearArchivoJSON(string &ruta, map<int, ProgramaAcademico *> &mapadeProgramasAcademicos, vector<string> etiquetasColumnas, int ano1, int ano2)
{
    // Este bool nos ayudara a saber si se creo exitosamente el archivo
    bool estadoCreacion = false;
    string anoRango1 = to_string(ano1);
    string anoRango2 = to_string(ano2);
    string rangoAno = anoRango1 + "-" + anoRango2;

    // Definir la ruta del archivo JSON
    string rutaCompleta = ruta + "resultados" + rangoAno + ".json";

    ofstream archivoResultados(rutaCompleta);
    if (archivoResultados.is_open())
    {
        // Iniciar el archivo JSON
        archivoResultados << "{" << endl; // Inicio del objeto JSON

        map<int, ProgramaAcademico *>::iterator it;
        // Contador para controlar las comas en objetos JSON
        int programaCount = 0;

        // Leemos todos los programas del mapa para imprimirlos en el archivo
        for (it = mapadeProgramasAcademicos.begin(); it != mapadeProgramasAcademicos.end(); it++)
        {
            if (programaCount > 0)
            {
                archivoResultados << "," << endl; // Agregar coma entre programas
            }

            archivoResultados << "  \"" << it->first << "\": {" << endl; // Llave del programa

            // Añadir los atributos del programa
            archivoResultados << "    \"codigo_institucion\": \"" << (it->second)->getCodigoDeLaInstitucion() << "\"," << endl;
            archivoResultados << "    \"ies_padre\": \"" << (it->second)->getIesPadre() << "\"," << endl;
            archivoResultados << "    \"institucion_superior\": \"" << (it->second)->getInstitucionDeEducacionSuperiorIes() << "\"," << endl;
            archivoResultados << "    \"principal_o_seccional\": \"" << (it->second)->getPrincipalOSeccional() << "\"," << endl;
            // Añade aqui el resto de los atributos del programa como en el ejemplo anterior

            // Empezamos con los consolidados
            archivoResultados << "    \"consolidados\": [" << endl;

            for (int i = 0; i < 8; i++)
            {
                Consolidado *consolidadoActual = (it->second)->getConsolidado(i);
                archivoResultados << "      {" << endl;
                archivoResultados << "        \"id_sexo\": \"" << consolidadoActual->getIdSexo() << "\"," << endl;
                archivoResultados << "        \"sexo\": \"" << consolidadoActual->getSexo() << "\"," << endl;
                archivoResultados << "        \"ano\": " << consolidadoActual->getAno() << "," << endl;
                archivoResultados << "        \"semestre\": " << consolidadoActual->getSemestre() << "," << endl;
                archivoResultados << "        \"admitidos\": " << consolidadoActual->getAdmitidos() << "," << endl;
                archivoResultados << "        \"graduados\": " << consolidadoActual->getGraduados() << "," << endl;
                archivoResultados << "        \"inscritos\": " << consolidadoActual->getInscritos() << "," << endl;
                archivoResultados << "        \"matriculados\": " << consolidadoActual->getMatriculados() << "," << endl;
                archivoResultados << "        \"matriculados_primer_semestre\": " << consolidadoActual->getMatriculadosPrimerSemestre() << endl;

                if (i < 7)
                {
                    archivoResultados << "      }," << endl; // Agregar coma si no es el ultimo
                }
                else
                {
                    archivoResultados << "      }" << endl; // No agregar coma en el ultimo
                }
            }

            archivoResultados << "    ]" << endl; // Cerrar el array de consolidados

            archivoResultados << "  }"; // Cerrar el objeto de programa
            programaCount++;
        }

        archivoResultados << endl
                          << "}" << endl; // Cerrar el objeto JSON
        estadoCreacion = true;
        cout << "Archivo JSON Creado en: " << rutaCompleta << endl;
    }

    archivoResultados.close();
    return estadoCreacion;
}
