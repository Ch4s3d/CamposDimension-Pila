#include "Admin.h"

int main()
{
    int op;
    Admin admin;

    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "0. Salir" << endl;
        cin >> op;

    }while (admin.menu(op));

    cout << "Listo!" << endl;
    return 0;
}
