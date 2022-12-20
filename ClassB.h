#ifndef CLASSB_H
#define CLASSB_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class ClassB
{
    friend class ClassA;
    string cad;
    bool booleano;

public:

    ClassB()
    {
        this->cad = "";
        this->booleano = NULL;
    }

    ClassB(char *s)
    {
        int tamCad;
        int k = 0;
        for (int i = 0; i<sizeof(int); i++, k++)
            ((char*)&tamCad)[i] = s[k];

        char sAux[tamCad];
        for (int i = 0; i<sizeof(char)*tamCad; i++, k++)
            sAux[i] = s[k];

        for (int i = 0; i<sizeof(float); i++, k++)
            ((char*)&booleano)[i] = s[k];

        this->cad = sAux;

    }

    string toString()
    {
        stringstream ss;
        ss<<cad<<", "<<booleano;
        return ss.str();
    }
    string getcad() const;
    void setcad(const string &value);
    bool getBooleano() const;
    void setBooleano(bool value);
};

#endif // CLASSB_H

bool ClassB::getBooleano() const
{
    return booleano;
}

void ClassB::setBooleano(bool value)
{
    booleano = value;
}

string ClassB::getcad() const
{
    return cad;
}

void ClassB::setcad(const string &value)
{
    cad = value;
}
