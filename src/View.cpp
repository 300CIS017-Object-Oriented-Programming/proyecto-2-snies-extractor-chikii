#include "View.h"

View::View()
{

    try
    {
        string ruta1 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/programas.csv");
        string ruta2 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/admitidos");
        string ruta3 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/graduados");
        string ruta4 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/inscritos");
        string ruta5 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/matriculados");
        string ruta6 = string("C:/proyecto-2-snies-extractor-chikii/docs/inputs/matriculadosPrimerSemestre");
        string ruta7 = string("C:/proyecto-2-snies-extractor-chikii/docs/outputs/");

        controlador = SNIESController(ruta1, ruta2, ruta3, ruta4, ruta5, ruta6, ruta7);
    }
    catch (const ios_base::failure &e)
    {
        cerr << "ERROR: " << e.what() << std::endl;
        throw;
    }
}

View::~View()
{
    controlador.~SNIESController();
}

void View::revisionAniosRango(string anoRango1, string anoRango2)
{
    int anoInicio = stoi(anoRango1);
    int anoFin = stoi(anoRango2);

    if (anoInicio < 2021 || anoFin > 2024 || anoInicio >= anoFin)
    {
        throw domain_error("El rango de anos no es valido, intente de nuevo.");
    }

    cout << "Procesando el rango de anos..." << endl;

    int output = preguntarFormatoOutputResultado();

    for (int anoActual = anoInicio; anoActual < anoFin; ++anoActual)
    {
        int anoSiguiente = anoActual + 1;
        cout << endl;
        cout << "Procesando datos para el ano: " << anoActual << " - " << anoSiguiente << endl;

        string anoActualStr = to_string(anoActual);
        string anoSiguienteStr = to_string(anoSiguiente);

        // int output = preguntarFormatoOutputResultado();

        controlador.procesarDatosCsv(anoActualStr, anoSiguienteStr, output, anoInicio, anoFin);
    }

    cout << "Datos procesados con exito!" << endl;
}

bool View::mostrarPantallaBienvenido()
{
    bool parametrizacionBool = false;
    bool inputValido = false;

    cout << endl;
    cout << " -------------- SNIES-Extractor --------------------" << endl;
    cout << endl;
    cout << "NOTA: Para el funcionamiento correcto del programa tuvo que haber parametrizado" << endl;
    cout << "la carpeta SNIES_EXTRACTOR en el disco duro, incluyendo los archivos CSV del SNIES." << endl;

    while (!inputValido)
    {
        try
        {
            // Solicitamos el año de busqueda
            string anioRango1, anioRango2;
            cout << "Escriba el primer ano del rango de busqueda: " << endl;
            cin >> anioRango1;
            cout << "Escriba el segundo ano del rango de busqueda: " << endl;
            cin >> anioRango2;
            cout << endl;

            revisionAniosRango(anioRango1, anioRango2);

            // Si llegamos aqui sin excepciones, la parametrizacion es correcta
            inputValido = true;
            parametrizacionBool = true;
        }

        catch (const ios_base::failure &e)
        {
            cerr << "Error de entrada/salida: " << e.what() << endl;
        }
        catch (const domain_error &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    return parametrizacionBool;
}

void View::salir()
{
    cout << "Cerrando programa..." << endl;
    // cout << "Recuerde revisar la carpeta de outputs para los archivos .csv exportados" << endl;
    //  cout << "Programa Cerrado con exito!" << endl;
}

int View::preguntarFormatoOutputResultado()
{
    int opcion;
    bool inputValido = false;

    cout << "--------------------------------------------" << endl;
    cout << "Como desea exportar el archivo de resultados?" << endl;
    cout << "1) CSV" << endl;
    cout << "2) TXT" << endl;
    cout << "3) JSON" << endl;

    while (!inputValido)
    {
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            // cout << "Exportando archivo resultado.csv..." << endl;
            cout << endl;
            return opcion = 1;
            break;

        case 2: // TXT
            // cout << "Exportando archivo resultado.txt..." << endl;
            cout << endl;
            return opcion = 2;
            break;

        case 3: // JSON
            // cout << "Exportando archivo resultado.json..." << endl;
            cout << endl;
            return opcion = 3;
            break;

        default: // Entrada inválida
            throw out_of_range("Opcion invalida. Debe ingresar un valor entre 1 y 3.");
        }
    }
    return opcion;
}

int View::preguntarFormatoOutputExtra()
{
    int opcionYN;

    cout << "--------------------------------------------" << endl;
    cout << "Como desea exportar el archivo de extra?" << endl;
    cout << "1) CSV" << endl;
    cout << "2) TXT" << endl;
    cout << "3) JSON" << endl;

    try
    {
        cin >> opcionYN;
        cout << "\n";

        switch (opcionYN)
        {
        case 1: // CSV
            cout << "Exportando archivo extra.csv..." << endl;
            // controlador.calcularDatosExtra(true);
            break;

        case 2: // TXT
            cout << "Exportando archivo extra.txt..." << endl;
            // archivoCreado = gestorTxtObj.crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
            break;

        case 3: // JSON
            cout << "Exportando archivo extra.json..." << endl;
            // archivoCreado = gestorJSONObj.crearArchivo(rutaOutput, programasAcademicos, etiquetasColumnas);
            break;

        default: // Entrada inválida
            throw out_of_range("Opcion invalida. Debe ingresar un valor entre 1 y 3.");
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "ERROR: " << e.what() << endl;
        cin.clear();
    }
    catch (const out_of_range &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Error de entrada/salida: " << e.what() << endl;
    }
}

void View::mostrarDatosExtra()
{
    try
    {
        int opcionExtra;
        cout << endl;
        cout << "A continuacion escoge cual de los dos archivos deseas exportar con datos relevantes de los programas academicos seleccionados:" << endl;
        cout << "1) " << endl;
        cout << " - Consolidado de estudiantes por ano en programas presenciales o virtuales" << endl;
        cout << " - Diferencia porcentual anual entre la cantidad de nuevos matriculados durante los anos de busqueda por programa" << endl;
        cout << " - Lista de programas sin nuevos matriculados en 3 semestres consecutivos" << endl;
        cout << "2) Resultado de busqueda por clave y formacion" << endl;
        cout << "3) No deseo exportar ningun extra" << endl;
        cout << endl;
        cout << "Que opcion desea exportar?" << endl;
        cin >> opcionExtra;

        cout << "\n";
        int formatoOutput;
        switch (opcionExtra)
        {
        case 1:
            cout << "Creando archivo con requisitos 1a,1b y 1c..." << endl;
            formatoOutput = preguntarFormatoOutputExtra();
            // ....
            break;
        case 2: // csv
            cout << "Creando archivo resultado de busqueda por clave y formacion..." << endl;
            formatoOutput = preguntarFormatoOutputExtra();
            controlador.calcularDatosExtra(true);
            break;
        case 3: // ningun
            controlador.calcularDatosExtra(false);
            break;
        default: // Manejar entradas fuera del rango esperado
            throw out_of_range("Opcion invalida. Debe ingresar un valor entre 1 y 3.");
        }
    }
    catch (const invalid_argument &e)
    {
        cerr << "ERROR: " << e.what() << endl;
        cin.clear();
    }
    catch (const out_of_range &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Error de entrada/salida: " << e.what() << endl;
    }
}

void View::buscarPorPalabraClaveYFormacion()
{
    char opcionYN = 'y', opcionOutput;
    string palabraClave;
    bool convertirCSV;
    int idFormacionAcademica;

    while (opcionYN == 'y')
    {
        cout << "Desea hacer una busqueda por palabra clave del nombre del programa(Y/N): " << endl;
        cin >> opcionYN;
        cout << "\n";
        opcionYN = tolower(opcionYN);

        if (opcionYN == 'y')
        {
            /*cout << "Deseas convertir los datos del programa academico a un CSV, TXT O JSON?: " << endl;
            cin >> opcionOutput;
            cout << "\n";
            opcionOutput = tolower(opcionOutput);

            if (opcionOutput == 'y')
            {
                convertirCSV = true;
            }

            else
            {
                convertirCSV = false;
            }*/

            cout << "Escriba la palabra clave para buscar los programas por nombre:" << endl;
            cin >> palabraClave;
            cout << endl;

            cout << "Seleccione un nivel de formacion para filtrar: \n 1->Especializacion Universitaria\n 2->Maestria\n 3->Doctorado\n 4->Formacion Tecnica Profesional \n 5->Tecnologico\n 6->Universitario\n 7->Especializacion Tecnico Profesional\n 8->Especializacion Tecnologica\n 10->Especializacion Medico Quirurgica\n " << endl;
            cin >> idFormacionAcademica;
            cout << "\n";
            while ((idFormacionAcademica > 10) || (idFormacionAcademica == 9) || (idFormacionAcademica < 1))
            {
                cout << "Seleccione una opcion entre 1-10 excluyendo el 9\n"
                     << endl;
                cin >> idFormacionAcademica;
            }

            controlador.buscarProgramas(convertirCSV, palabraClave, idFormacionAcademica);
        }
    }
}

bool View::isConvetibleToInt(const string &str)
{
    try
    {
        std::size_t pos;
        int num = std::stoi(str, &pos);

        // Verificamos si se ha convertido toda la cadena
        return pos == str.length();
    }
    catch (const std::invalid_argument &)
    {
        // No se pudo convertir: la cadena no es un número válido
        return false;
    }
    catch (const std::out_of_range &)
    {
        // No se pudo convertir: el número está fuera del rango de int
        return false;
    }
}