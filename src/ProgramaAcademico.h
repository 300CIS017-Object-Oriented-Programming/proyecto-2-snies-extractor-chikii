#ifndef PROGRAMA_ACADEMICO_H
#define PROGRAMA_ACADEMICO_H

#include <string>
#include <vector>
#include <iostream>
#include "Consolidado.h"
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

class ProgramaAcademico
{
    int codigoDeLaInstitucion;
    int iesPadre;
    string institucionDeEducacionSuperiorIes;
    string principalOSeccional;
    int idSectorIes;
    string sectorIes;
    int idCaracter;
    string caracterIes;
    int codigoDelDepartamentoIes;
    string departamentoDeDomicilioDeLaIes;
    int codigoDelMunicipioIes;
    string municipioDeDomicilioDeLaIes;
    int codigoSniesDelPrograma;
    string programaAcademico;
    int idNivelAcademico;
    string nivelAcademico;
    int idNivelDeFormacion;
    string nivelDeFormacion;
    int idMetodologia;
    string metodologia;
    int idArea;
    string areaDeConocimiento;
    int idNucleo;
    string nucleoBasicoDelConocimientoNbc;
    int idCineCampoAmplio;
    string descCineCampoAmplio;
    int idCineCampoEspecifico;
    string descCineCampoEspecifico;
    int idCineCodigoDetallado;
    string descCineCodigoDetallado;
    int codigoDelDepartamentoPrograma;
    string departamentoDeOfertaDelPrograma;
    int codigoDelMunicipioPrograma;
    string municipioDeOfertaDelPrograma;
    map<int, map<int, Consolidado *>> consolidadosAnio1;
    map<int, map<int, Consolidado *>> consolidadosAnio2;

public:
    ProgramaAcademico();

    // Métodos get y set codigo de la institucion
    void setCodigoDeLaInstitucion(int);
    int getCodigoDeLaInstitucion();

    // Métodos get y set Ies padre
    void setIesPadre(int);
    int getIesPadre();

    // Métodos get y set institucion educacio superior
    void setInstitucionDeEducacionSuperiorIes(string &);
    string getInstitucionDeEducacionSuperiorIes();

    // Métodos get y set Principal Seccional
    void setPrincipalOSeccional(string &);
    string getPrincipalOSeccional();

    // Métodos get y set ID sector Ies
    void setIdSectorIes(int);
    int getIdSectorIes();

    // Métodos get y set sector Ies
    void setSectorIes(string &);
    string getSectorIes();

    // Métodos get y set Id caracter
    void setIdCaracter(int);
    int getIdCaracter();

    // Métodos get y set caracter Ies
    void setCaracterIes(string &);
    string getCaracterIes();

    // Métodos get y set codigo departamento Ies
    void setCodigoDelDepartamentoIes(int);
    int getCodigoDelDepartamentoIes();

    // Métodos get y set departamento domicilio Ies
    void setDepartamentoDeDomicilioDeLaIes(string &);
    string getDepartamentoDeDomicilioDeLaIes();

    // Métodos get y set codigo municipios
    void setCodigoDelMunicipioIes(int);
    int getCodigoDelMunicipioIes();

    // Métodos get y set municipio domicilio Ies
    void setMunicipioDeDomicilioDeLaIes(string &);
    string getMunicipioDeDomicilioDeLaIes();

    // Métodos get y set codigo Snies programa
    void setCodigoSniesDelPrograma(int);
    int getCodigoSniesDelPrograma();

    // Métodos get y set programa academico
    void setProgramaAcademico(string &);
    string getProgramaAcademico();

    // Métodos get y set ID nivel academico
    void setIdNivelAcademico(int);
    int getIdNivelAcademico();

    // Métodos get y set nivel academico
    void setNivelAcademico(string &);
    string getNivelAcademico();

    // Métodos get y set ID nivel formacion
    void setIdNivelDeFormacion(int);
    int getIdNivelDeFormacion();

    // Métodos get y set nivel formacion
    void setNivelDeFormacion(string &);
    string getNivelDeFormacion();

    // Métodos get y set ID metodologia
    void setIdMetodologia(int);
    int getIdMetodologia();

    // Métodos get y set metodologia
    void setMetodologia(string &);
    string getMetodologia();

    // Métodos get y set ID area
    void setIdArea(int);
    int getIdArea();

    // Métodos get y set area conocimiento
    void setAreaDeConocimiento(string &);
    string getAreaDeConocimiento();

    // Métodos get y set ID nucleo
    void setIdNucleo(int);
    int getIdNucleo();

    // Métodos get y set nucleo basico de conocimiento
    void setNucleoBasicoDelConocimientoNbc(string &);
    string getNucleoBasicoDelConocimientoNbc();

    // Métodos get y set ID campo amplio
    void setIdCineCampoAmplio(int);
    int getIdCineCampoAmplio();

    // Métodos get y set campo amplio
    void setDescCineCampoAmplio(string &);
    string getDescCineCampoAmplio();

    // Métodos get y set ID campo especifico
    void setIdCineCampoEspecifico(int);
    int getIdCineCampoEspecifico();

    // Métodos get y set campo especifico
    void setDescCineCampoEspecifico(string &);
    string getDescCineCampoEspecifico();

    // Métodos get y set ID codigo detallado
    void setIdCineCodigoDetallado(int);
    int getIdCineCodigoDetallado();

    // Métodos get y set codigo detallado
    void setDescCineCodigoDetallado(string &);
    string getDescCineCodigoDetallado();

    // Métodos get y set codigo departamento programa
    void setCodigoDelDepartamentoPrograma(int);
    int getCodigoDelDepartamentoPrograma();

    // Métodos get y set Departamento De Oferta Del Programa
    void setDepartamentoDeOfertaDelPrograma(string &);
    string getDepartamentoDeOfertaDelPrograma();

    // Métodos get y set codigo municipio programa
    void setCodigoDelMunicipioPrograma(int);
    int getCodigoDelMunicipioPrograma();

    // Métodos get y set  municipio oferta programa
    void setMunicipioDeOfertaDelPrograma(string &);
    string getMunicipioDeOfertaDelPrograma();

    // Métodos get y set consolidado
    void setConsolidado(Consolidado *nuevoConsolidado, int, int, int);
    Consolidado *getConsolidado(int, int, int);

    // Destructor
    ~ProgramaAcademico();
};

#endif

// calidad bien