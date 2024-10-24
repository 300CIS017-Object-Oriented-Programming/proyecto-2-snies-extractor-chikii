#include "ProgramaAcademico.h"

using namespace std;

/*
ProgramaAcademico::ProgramaAcademico()
{
    // Inicializa el vector con nullptrs para evitar punteros no inicializados
}
*/

// Métodos get y set codigo de la institucion
void ProgramaAcademico::setCodigoDeLaInstitucion(int nuevoCodigoDeLaInstitucion)
{
    codigoDeLaInstitucion = nuevoCodigoDeLaInstitucion;
}

int ProgramaAcademico::getCodigoDeLaInstitucion()
{
    return codigoDeLaInstitucion;
}

// Métodos get y set Ies padre
void ProgramaAcademico::setIesPadre(int nuevoIesPadre)
{
    iesPadre = nuevoIesPadre;
}

int ProgramaAcademico::getIesPadre()
{
    return iesPadre;
}

// Métodos get y set institucion educacio superior
void ProgramaAcademico::setInstitucionDeEducacionSuperiorIes(string &nuevoInstitucionDeEducacionSuperiorIes)
{
    institucionDeEducacionSuperiorIes = nuevoInstitucionDeEducacionSuperiorIes;
}
string ProgramaAcademico::getInstitucionDeEducacionSuperiorIes()
{
    return institucionDeEducacionSuperiorIes;
}

// Métodos get y set Principal Seccional
void ProgramaAcademico::setPrincipalOSeccional(string &nuevoPrincipalOSeccional)
{
    principalOSeccional = nuevoPrincipalOSeccional;
}

string ProgramaAcademico::getPrincipalOSeccional()
{
    return principalOSeccional;
}

// Métodos get y set ID sector Ies
void ProgramaAcademico::setIdSectorIes(int nuevoIdSectorIes)
{
    idSectorIes = nuevoIdSectorIes;
}

int ProgramaAcademico::getIdSectorIes()
{
    return idSectorIes;
}

// Métodos get y set sector Ies
void ProgramaAcademico::setSectorIes(string &nuevoSectorIes)
{
    sectorIes = nuevoSectorIes;
}

string ProgramaAcademico::getSectorIes()
{
    return sectorIes;
}
// Métodos get y set Id caracter
void ProgramaAcademico::setIdCaracter(int nuevoIdCaracter)
{
    idCaracter = nuevoIdCaracter;
}

int ProgramaAcademico::getIdCaracter()
{
    return idCaracter;
}

// Métodos get y set caracter Ies
void ProgramaAcademico::setCaracterIes(string &nuevoCaracterIes)
{
    caracterIes = nuevoCaracterIes;
}

string ProgramaAcademico::getCaracterIes()
{
    return caracterIes;
}

// Métodos get y set codigo departamento Ies
void ProgramaAcademico::setCodigoDelDepartamentoIes(int nuevoCodigoDelDepartamentoIes)
{
    codigoDelDepartamentoIes = nuevoCodigoDelDepartamentoIes;
}

int ProgramaAcademico::getCodigoDelDepartamentoIes()
{
    return codigoDelDepartamentoIes;
}

// Métodos get y set departamento domicilio Ies
void ProgramaAcademico::setDepartamentoDeDomicilioDeLaIes(string &nuevoDepartamentoDeDomicilioDeLaIes)
{
    departamentoDeDomicilioDeLaIes = nuevoDepartamentoDeDomicilioDeLaIes;
}

string ProgramaAcademico::getDepartamentoDeDomicilioDeLaIes()
{
    return departamentoDeDomicilioDeLaIes;
}

// Métodos get y set codigo municipios
void ProgramaAcademico::setCodigoDelMunicipioIes(int nuevoCodigoDelMunicipioIes)
{
    codigoDelMunicipioIes = nuevoCodigoDelMunicipioIes;
}

int ProgramaAcademico::getCodigoDelMunicipioIes()
{
    return codigoDelMunicipioIes;
}

// Métodos get y set municipio domicilio Ies
void ProgramaAcademico::setMunicipioDeDomicilioDeLaIes(string &nuevoMunicipioDeDomicilioDeLaIes)
{
    municipioDeDomicilioDeLaIes = nuevoMunicipioDeDomicilioDeLaIes;
}

string ProgramaAcademico::getMunicipioDeDomicilioDeLaIes()
{
    return municipioDeDomicilioDeLaIes;
}

// Métodos get y set codigo Snies programa
void ProgramaAcademico::setCodigoSniesDelPrograma(int nuevoCodigoSniesDelPrograma)
{
    codigoSniesDelPrograma = nuevoCodigoSniesDelPrograma;
}

int ProgramaAcademico::getCodigoSniesDelPrograma()
{
    return codigoSniesDelPrograma;
}

// Métodos get y set programa academico
void ProgramaAcademico::setProgramaAcademico(string &nuevoProgramaAcademico)
{
    programaAcademico = nuevoProgramaAcademico;
}

string ProgramaAcademico::getProgramaAcademico()
{
    return programaAcademico;
}

// Métodos get y set ID nivel academico
void ProgramaAcademico::setIdNivelAcademico(int nuevoIdNivelAcademico)
{
    idNivelAcademico = nuevoIdNivelAcademico;
}

int ProgramaAcademico::getIdNivelAcademico()
{
    return idNivelAcademico;
}

// Métodos get y set nivel academico
void ProgramaAcademico::setNivelAcademico(string &nuevoNivelAcademico)
{
    nivelAcademico = nuevoNivelAcademico;
}

string ProgramaAcademico::getNivelAcademico()
{
    return nivelAcademico;
}

// Métodos get y set ID nivel formacion
void ProgramaAcademico::setIdNivelDeFormacion(int nuevoIdNivelDeFormacion)
{
    idNivelDeFormacion = nuevoIdNivelDeFormacion;
}

int ProgramaAcademico::getIdNivelDeFormacion()
{
    return idNivelDeFormacion;
}

// Métodos get y set nivel formacion
void ProgramaAcademico::setNivelDeFormacion(string &nuevoNivelDeFormacion)
{
    nivelDeFormacion = nuevoNivelDeFormacion;
}

string ProgramaAcademico::getNivelDeFormacion()
{
    return nivelDeFormacion;
}

// Métodos get y set ID metodologia
void ProgramaAcademico::setIdMetodologia(int nuevoIdMetodologia)
{
    idMetodologia = nuevoIdMetodologia;
}

int ProgramaAcademico::getIdMetodologia()
{
    return idMetodologia;
}

// Métodos get y set metodologia
void ProgramaAcademico::setMetodologia(string &nuevaMetodologia)
{
    metodologia = nuevaMetodologia;
}

string ProgramaAcademico::getMetodologia()
{
    return metodologia;
}

// Métodos get y set ID area
void ProgramaAcademico::setIdArea(int nuevoIdArea)
{
    idArea = nuevoIdArea;
}

int ProgramaAcademico::getIdArea()
{
    return idArea;
}

// Métodos get y set area conocimiento
void ProgramaAcademico::setAreaDeConocimiento(string &areaConocimiento)
{
    areaDeConocimiento = areaConocimiento;
}
string ProgramaAcademico::getAreaDeConocimiento()
{
    return areaDeConocimiento;
}

// Métodos get y set ID nucleo
void ProgramaAcademico::setIdNucleo(int nuevoIdNucleo)
{
    idNucleo = nuevoIdNucleo;
}
int ProgramaAcademico::getIdNucleo()
{
    return idNucleo;
}

// Métodos get y set nucleo basico de conocimiento
void ProgramaAcademico::setNucleoBasicoDelConocimientoNbc(string &nuevoNucleoBasicoDelConocimientoNbc)
{
    nucleoBasicoDelConocimientoNbc = nuevoNucleoBasicoDelConocimientoNbc;
}
string ProgramaAcademico::getNucleoBasicoDelConocimientoNbc()
{
    return nucleoBasicoDelConocimientoNbc;
}

// Métodos get y set ID campo amplio
void ProgramaAcademico::setIdCineCampoAmplio(int nuevoIdCineCampoAmplio)
{
    idCineCampoAmplio = nuevoIdCineCampoAmplio;
}
int ProgramaAcademico::getIdCineCampoAmplio()
{
    return idCineCampoAmplio;
}

// Métodos get y set campo amplio
void ProgramaAcademico::setDescCineCampoAmplio(string &nuevoDescCineCampoAmplio)
{
    descCineCampoAmplio = nuevoDescCineCampoAmplio;
}
string ProgramaAcademico::getDescCineCampoAmplio()
{
    return descCineCampoAmplio;
}

// Métodos get y set ID campo especifico
void ProgramaAcademico::setIdCineCampoEspecifico(int nuevoIdCineCampoEspecifico)
{
    idCineCampoEspecifico = nuevoIdCineCampoEspecifico;
}
int ProgramaAcademico::getIdCineCampoEspecifico()
{
    return idCineCampoEspecifico;
}

// Métodos get y set campo especifico
void ProgramaAcademico::setDescCineCampoEspecifico(string &nuevoDescCineCampoEspecifico)
{
    descCineCampoEspecifico = nuevoDescCineCampoEspecifico;
}

string ProgramaAcademico::getDescCineCampoEspecifico()
{
    return descCineCampoEspecifico;
}

// Métodos get y set ID codigo detallado
void ProgramaAcademico::setIdCineCodigoDetallado(int nuevoIdCineCodigoDetallado)
{
    idCineCodigoDetallado = nuevoIdCineCodigoDetallado;
}
int ProgramaAcademico::getIdCineCodigoDetallado()
{
    return idCineCodigoDetallado;
}

// Métodos get y set codigo detallado
void ProgramaAcademico::setDescCineCodigoDetallado(string &nuevoDescCineCodigoDetallado)
{
    descCineCodigoDetallado = nuevoDescCineCodigoDetallado;
}
string ProgramaAcademico::getDescCineCodigoDetallado()
{
    return descCineCodigoDetallado;
}

// Métodos get y set codigo departamento programa
void ProgramaAcademico::setCodigoDelDepartamentoPrograma(int nuevoCodigoDelDepartamentoPrograma)
{
    codigoDelDepartamentoPrograma = nuevoCodigoDelDepartamentoPrograma;
}
int ProgramaAcademico::getCodigoDelDepartamentoPrograma()
{
    return codigoDelDepartamentoPrograma;
}

// Métodos get y set Departamento De Oferta Del Programa
void ProgramaAcademico::setDepartamentoDeOfertaDelPrograma(string &nuevoDepartamentoDeOfertaDelPrograma)
{
    departamentoDeOfertaDelPrograma = nuevoDepartamentoDeOfertaDelPrograma;
}
string ProgramaAcademico::getDepartamentoDeOfertaDelPrograma()
{
    return departamentoDeOfertaDelPrograma;
}

// Métodos get y set codigo municipio programa
void ProgramaAcademico::setCodigoDelMunicipioPrograma(int nuevoCodigoDelMunicipioPrograma)
{
    codigoDelMunicipioPrograma = nuevoCodigoDelMunicipioPrograma;
}
int ProgramaAcademico::getCodigoDelMunicipioPrograma()
{
    return codigoDelMunicipioPrograma;
}

// Métodos get y set  municipio oferta programa
void ProgramaAcademico::setMunicipioDeOfertaDelPrograma(string &nuevoMunicipioDeOfertaDelPrograma)
{
    municipioDeOfertaDelPrograma = nuevoMunicipioDeOfertaDelPrograma;
}
string ProgramaAcademico::getMunicipioDeOfertaDelPrograma()
{
    return municipioDeOfertaDelPrograma;
}

// Métodos get y set consolidado

void ProgramaAcademico::setConsolidado(Consolidado *nuevoConsolidado, int anio)
{
    consolidadosPorAnio[anio].push_back(nuevoConsolidado);
}

Consolidado *ProgramaAcademico::getConsolidado(int m, int anio)
{
    int index = 0;
    for (const auto &consolidado : consolidadosPorAnio[anio])
    {
        if (index == m)
        {
            return consolidado;
        }
        index++;
    }
}

// Destructor

// reconstruccion del destructor para adaptacion de mapa
ProgramaAcademico::~ProgramaAcademico()
{
    for (const auto &anio : consolidadosPorAnio)
    {
        for (const auto &consolidado : anio.second)
        {
            delete consolidado;
        }
    }
}
