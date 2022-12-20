#ifndef ADMIN_H
#define ADMIN_H
#include "ClassA.h"

class Admin
{
private:
    bool push(ClassA a)
    {
        ofstream fout("archivo.bin", ios::app|ios::binary);

        if (!fout.good())
            return false;

        char* s;
        int size = a.serialize(&s);

        fout.write(s,size);
        fout.close();


        return true;

    }
    ClassA pop()
    {
        ifstream fin("archivo.bin", ios::binary);
        ofstream fout("auxiliar.bin", ios::app|ios::binary);

        int tamObjRecuperado;
        fin.read((char*)&tamObjRecuperado,4);
        char sRecuperado[tamObjRecuperado];
        fin.read(sRecuperado,tamObjRecuperado);

        ClassA objRecuperado(sRecuperado);

        return objRecuperado;

    }
    ClassA top()
    {
        ifstream fin("archivo.bin", ios::binary);

        int tamObjRecuperado;
        fin.read((char*)&tamObjRecuperado,4);
        char sRecuperado[tamObjRecuperado];
        fin.read(sRecuperado,tamObjRecuperado);

        ClassA objRecuperado(sRecuperado);

        return objRecuperado;
    }

    ClassA crear()
    {
        int entero, contClassB;
        string cadena, cadenaB;
        bool booleanB;

        cout << "Entero (main key): ";
        cin >> entero;

        cout << "Cadena: ";
        cin >> cadena;

        cout << "Numero de ClassBs: ";
        cin >> contClassB;

        ClassB* arregloB = new ClassB[contClassB];

        for (int i=0 ; i<contClassB ; i++)
        {
            cout << "ClassB " << i+1 << endl;
            cout << "Cadena: ";
            cin >> cadenaB;
            arregloB[i].setcad(cadenaB);

            cout << "Booleano: ";
            cin >> booleanB;
            arregloB[i].setBooleano(booleanB);
        }

        ClassA nuevo = *new ClassA(entero, cadena, contClassB, arregloB);
        return nuevo;
    }

public:
    Admin(){}
    bool menu(int op)
    {
        switch(op)
        {
        case 0:
            return false;
        case 1:
            if (push(crear()))
                cout << "Insertado con exito..." << endl;
            else cout << "Error de insersión" << endl;
            return true;
        case 2:
            cout<<pop().toString()<<endl;
            return true;
        case 3:
            top();
            return true;
        default:
            return true;
        }
    }
};

#endif // ADMIN_H
