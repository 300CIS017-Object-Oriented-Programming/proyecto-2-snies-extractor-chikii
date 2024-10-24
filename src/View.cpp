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

void View::revisionAnios(string anio1)
{
    if (anio1 < "2021")
    {
        throw domain_error("El ano no se encuentra registrado, intente de nuevo.");
    }

    int ano1 = stoi(anio1);
    int anioConsecutivo = ano1 + 1;

    // Verificamos que el año consecutivo no exceda el año permitido
    if (anioConsecutivo > 2024)
    {
        throw domain_error("El segundo ano no se encuentra registrado, intente de nuevo.");
    }

    cout << "Ano Consecutivo: " << anioConsecutivo << endl;

    string anioConsecutivoStr = to_string(anioConsecutivo);
    cout << "Procesando datos ..." << endl;

    // Procesamos los datos con el controlador
    controlador.procesarDatosCsv(anio1, anioConsecutivoStr);

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
            string anio1;
            cout << "Escriba el primer ano de busqueda: " << endl;
            cin >> anio1;
            cout << endl;

            // Intentamos validar los años ingresados
            revisionAnios(anio1);

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

void View::mostrarDatosExtra(int anio1, int anio2)
{
    char opcionYN;
    cout << "A continuacion vamos a mostrar datos relevantes de los programas academicos seleccionados" << endl;
    // cout << endl;
    cout << "Desea Convertir los datos a un archivo CSV?(Y/N): " << endl;
    cin >> opcionYN;
    opcionYN = tolower(opcionYN);
    cout << "\n";
    // FIXME verificar que el usuario ingrese un valor igual al esperado, return true si es Y, false si es N, y no sale si no retorna un valor válido
    // Simplificar el código de acuerdo a ese ajuste
    if (opcionYN == 'y')
    {
        controlador.calcularDatosExtra(true, anio1, anio2);
    }

    else
    {
        controlador.calcularDatosExtra(false, anio1, anio2);
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
            cout << "Deseas convertir los datos del programa academico a un CSV, TXT O JSON?: " << endl;
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
            }

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