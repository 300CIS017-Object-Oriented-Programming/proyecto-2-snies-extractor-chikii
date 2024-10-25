#include "Consolidado.h"

Consolidado::Consolidado() = default;

Consolidado::Consolidado(int idSexo, string sexo, int ano, int semestre, int inscritos, int admitidos, int primeraMatricula, int totalMatriculados, int graduados)
    : idSexo(idSexo), sexo(sexo), ano(ano), semestre(semestre), inscritos(inscritos), admitidos(admitidos), matriculados(primeraMatricula), matriculadosPrimerSemestre(totalMatriculados), graduados(graduados) {}

// Getter y Setter de idSexo
int Consolidado::getIdSexo()
{
    return idSexo;
}

void Consolidado::setIdSexo(int idSexo)
{
    this->idSexo = idSexo;
}

// Getter y Setter de sexo
const string Consolidado::getSexo()
{
    return sexo;
}

void Consolidado::setSexo(const string &sexo)
{
    this->sexo = sexo;
}

// Getter y Setter de año
int Consolidado::getAno()
{
    return ano;
}

void Consolidado::setAno(int ano)
{
    this->ano = ano;
}

// Getter y Setter de semestre
int Consolidado::getSemestre()
{
    return semestre;
}
void Consolidado::setSemestre(int semestre)
{
    this->semestre = semestre;
}

// Getter y Setter de inscritos
int Consolidado::getInscritos()
{
    return inscritos;
}

void Consolidado::setInscritos(int inscritos)
{
    this->inscritos = inscritos;
}

// Getter y Setter de admitidos
int Consolidado::getAdmitidos()
{
    return admitidos;
}

void Consolidado::setAdmitidos(int admitidos)
{
    this->admitidos = admitidos;
}

// Getter y Setter de matriculados
int Consolidado::getMatriculados()
{
    return matriculados;
}

void Consolidado::setMatriculados(int matriculados)
{
    this->matriculados = matriculados;
}

// Getter y Setter de matriculadosPrimerSemestre
int Consolidado::getMatriculadosPrimerSemestre()
{
    return matriculadosPrimerSemestre;
}

void Consolidado::setMatriculadosPrimerSemestre(int matriculadosPrimerSemestre)
{
    this->matriculadosPrimerSemestre = matriculadosPrimerSemestre;
}

// Getter y Setter de graduados
int Consolidado::getGraduados()
{
    return graduados;
}

void Consolidado::setGraduados(int graduados)
{
    this->graduados = graduados;
}

// calidad bien