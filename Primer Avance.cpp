#include <iostream>

using namespace std;

int main()
{
    int op, des;

    char vj1[20];
    char vj2[20];
    char vj3[20];

    cout << "**MENU DE OPCIONES**" << endl;
    cout << "1.- Dar productos de alta" << endl;
    cout << "2.- Limpiar pantalla" << endl;
    cout << "3.- Salir" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Ingrese el nombre de los articulos para agregar a la lista" << endl;
        cin >> vj1 >> vj2 >> vj3;
        cout << "Desea regresar al menu? 1.- Si, 2.- No" << endl;
        cin >> des;
        if (des == 1)
        {
            return main();
        }
        break;
    case 2:
        system("cls");
        return main();
        break;
    case 3:
        exit(1);
        break;
    default:
        return main();
        break;
    }
    system("pause");
}
