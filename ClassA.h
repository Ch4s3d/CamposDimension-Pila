#ifndef CLASSA_H
#define CLASSA_H
#include "ClassB.h"

class ClassA
{
    int entero;
    string cad;
    ClassB* arreglo;

    int contClassB;

public:

    ClassA(int entero, string cad, int contClassB, ClassB* arreglo )
    {
        this->entero = entero;
        this->cad = cad;
        this->contClassB = contClassB;
        this->arreglo = arreglo;
    }
    ClassA(char* s)
    {
        int tamCad;
        int k = 0;
        for (int i = 0; i<sizeof(int); i++, k++)
            ((char*)&entero)[i] = s[k];
        for (int i = 0; i<sizeof(int); i++, k++)
            ((char*)&tamCad)[i] = s[k];

        char sAux[tamCad];
        for (int i = 0; i<sizeof(char)*tamCad; i++, k++)
            sAux[i] = s[k];

        for (int i = 0; i<sizeof(int); i++, k++)
            ((char*)&contClassB)[i] = s[k];

        for (int i = 0; i<sizeof(int)*contClassB; i++, k++)
            ((char*)arreglo)[i] = s[k];

        this->cad = sAux;
    }

    string toString(){

        stringstream ss;
        ss<<entero<<cad<<", [ ";
        if (contClassB)
        {
            for (int i = 0; i<contClassB-1; i++)
                ss<<arreglo[i].toString()<<", ";
            ss<<arreglo[contClassB-1].toString();
        }
        ss<<" ]";
        return ss.str();
    }
    int serialize(char** s){
        int tamCad = cad.length();
        int tamObj = sizeof(int)+sizeof(int)+tamCad*sizeof(char)+sizeof(int)+contClassB*sizeof(ClassB);
        *s = new char[tamObj];
        int k = 0;
        for (int i = 0; i<sizeof(int); i++, k++)
            *(s[k]) = *(((char*)&tamObj)+i);

        for (int i = 0; i<sizeof(int); i++, k++)
            *(s[k]) = *(((char*)&entero)+i);

        for (int i = 0; i<sizeof(int); i++, k++)
            *(s[k]) = *(((char*)&tamCad)+i);

        char cadAux[tamCad];
        cad.copy(cadAux,tamCad);
        for (int i = 0; i<sizeof(char)*tamCad; i++, k++)
            *(s[k]) = cadAux[i];

        for (int i = 0; i<sizeof(int); i++, k++)
            *(s[k]) = *(((char*)&contClassB)+i);

        for (int i = 0; i<sizeof(int)*contClassB; i++, k++)
        {

           int tamCad = cad.length();
           int tamObj = sizeof(int)+sizeof(int)+tamCad*sizeof(char)+sizeof(bool);
           *s = new char[tamObj];
           int k = 0;
           for (int i = 0; i<sizeof(int); i++, k++)
               *(s[k]) = *(((char*)&tamObj)+i);

           for (int i = 0; i<sizeof(int); i++, k++)
               *(s[k]) = *(((char*)&tamCad)+i);

           char cadAux[tamCad];
           arreglo[i].cad.copy(cadAux,tamCad);
           for (int i = 0; i<sizeof(char)*tamCad; i++, k++)
               *(s[k]) = cadAux[i];

           for (int i = 0; i<sizeof(bool); i++, k++)
               *(s[k]) = *(((char*)&arreglo[i].booleano)+i);
        }

        return tamObj;

    }
    int getEntero() const;
    void setEntero(int value);
    string getcad() const;
    void setcad(const string &value);
    ClassB getArreglo(int num);
    void setArreglo(ClassB b);
    int getContClassB() const;
    void setContClassB(int value);
};

#endif // CLASSA_H

string ClassA::getcad() const
{
    return cad;
}

void ClassA::setcad(const string &value)
{
    cad = value;
}

ClassB ClassA::getArreglo(int num)
{
    return arreglo[num];
}

void ClassA::setArreglo(ClassB b)
{
    arreglo[contClassB++] = b;
}

int ClassA::getContClassB() const
{
return contClassB;
}

void ClassA::setContClassB(int value)
{
contClassB = value;
}

int ClassA::getEntero() const
{
    return entero;
}

void ClassA::setEntero(int value)
{
    entero = value;
}
