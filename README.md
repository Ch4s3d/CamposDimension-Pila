# Pila-Campos_de_dimension
Stack and dimension fields (Console)

The objective is to understand the use of files for storing information, to learn operations of the "Stack" method, such as push, pop, top. Also learn the method of dimension fields.

A stack is an ordinal list or data structure in which the mode of access to its elements is of type LIFO (Last In First Out, last in, first out) that allows to store and retrieve data. It is applied on many occasions in computing due to its simplicity and implicit ordering in the structure itself. Graphical representation of a stack
For data management there are two basic operations: stack (push), which places an object on the stack, and its inverse operation, remove (or unstack, pop), which removes the last stacked item.

It is the field that allows us to uniquely identify a specific record within a file, that is, without error to confuse the record. It is also known as the Primary Key and is said to be very important.

Problem to solve:
Design a computing solution that demonstrates the understanding and use of files for storage in secondary memory (with a stack-type insertion and deletion methodology), of more than one object of the same type, without the need to create a stack in main memory. The storage strategy is dimension fields.

The system must consider the storage of objects of a ClassA class, the objects of the ClassA class must have type attributes: string (string), integer (primary key) and an array of up to 10 objects of class B (stored objects NO modifiable) that contains string and boolean attributes, the ClassA object must also contain a counter for ClassB class objects. In the file, each record must contain only the ClassB objects that were requested.

Tools:
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
