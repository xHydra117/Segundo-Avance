#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <wchar.h>

using namespace std;

struct datos
{
    string nombre;
    string descripcion;
    int fecha;
};

int main()
{
    datos juegos[3];
    int opcion;
    do
    {
        printf("\t ***MENU DE OPCIONES*** \n");
        printf("1.-Alta \n");
        printf("2.-Modificacion \n");
        printf("3.-Baja \n");
        printf("4.-Lista \n");
        printf("5.-Limpiar Pantalla \n");
        printf("6.-Salir\n");
        scanf_s("%d", &opcion);

        switch (opcion)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                printf("Ingrese el nombre del juego \n");
                cin.ignore();
                getline(cin, juegos[i].nombre);
                printf("Ingrese una descripcion del juego \n");
                getline(cin, juegos[i].descripcion);
                printf("Ingrese el ano de lanzamiento \n");
                scanf_s("%d", &juegos[i].fecha);
            }

            break;
        case 2:
            break;

        case 3:
            break;

        case 4:
            printf("Lista de Videojuegos:\n");
            for (int i = 0; i < 3; i++)
            {
                printf("\n%s\n", juegos[i].nombre.c_str());
                printf("%s", juegos[i].descripcion.c_str());
                printf("\nAno de lanzamiento: %d\n", juegos[i].fecha);
            }
            system("pause");
            break;
        case 5:
            system("cls");
            break;
        case 6:
            exit(1);
            break;
        default:
            break;
        }
    } while (opcion != 6);
}
