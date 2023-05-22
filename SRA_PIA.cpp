#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct datos
{
    int  fecha,  total;
    string nombre,  status,  clasificacion,  descripcion,  genero, consola;
    float precio,  iva;
};
int contador, alta;
datos *PIA;
void Alta();
void listas();
void archivos();
void eliminar();
void modificar();

int main()
{
    int opc;
    printf("1.-Alta \n2.-Lista \n3.-Limpiar pantalla \n4.-Modificar registro \n5.-Eliminar registro \n6.-Salir \n");
    scanf_s("%d", &opc);

    switch (opc)
    {
    case 1:
        Alta();
        return main();
        break;

    case 2:
        listas();
        return main();
        break;

    case 3:
        system("cls");
        return main();
        break;

    case 4:
        modificar();
        return main();
        break;

    case 5:
        eliminar();
        return main();
        break;

    case 6:
        archivos();
        break;
    }

    return 0;
}

void Alta()
{
    printf("Digite el n%cmero de art%cculos que desea dar de alta: ", 163, 161);
    scanf_s("%d", &alta);
    PIA = new datos[alta];

    for (int i = 0; i < alta; i++)
    {
        cin.ignore();
        printf("Ingrese el nombre del videojuego %d: ", i+1);
        getline(cin, PIA[i].nombre);
        cin.ignore();
        printf("Ingrese una descripci%cn del juego %d: ", 162, i+1);
        getline(cin, PIA[i].descripcion);
        printf("Ingrese el a%co de lanzamiento del juego %d: ", 164, i+1);
        scanf_s("%d", &PIA[i].fecha);
        cin.ignore();
        printf("Ingrese la clasificaci%cn del juego %d: ", 162, i+1);
        getline(cin, PIA[i].clasificacion);
        cin.ignore();
        printf("Ingrese el g%cnero del juego %d: ", 130, i+1);
        getline(cin, PIA[i].genero);
        cin.ignore();
        printf("Ingrese la consola del juego %d: ", i + 1);
        getline(cin, PIA[i].consola);
        printf("Ingrese el precio del juego %d: ", i+1);
        scanf_s("%f", &PIA[i].precio);

        PIA[i].iva = PIA[i].precio * 1.16;
    }
}

void listas()
{
    for (int i = 0; i < alta; i++)
    {
        if (PIA[i].status == "ELIMINADO")
        {
            printf("REGISTRO %d ELIMINADO\n", i + 1);
        }
        else
        {
            printf("Registro %d\n", i + 1);
            printf("%s\n", PIA[i].nombre.c_str());
            printf("%s\n", PIA[i].descripcion.c_str());
            printf("A%co de lanzamiento: %d\n", 164, PIA[i].fecha);
            printf("Clasificaci%cn: %s\n", 162, PIA[i].clasificacion.c_str());
            printf("G%cnero: %s\n", 130, PIA[i].genero.c_str());
            printf("Consola: %s\n", PIA[i].consola.c_str());
            printf("Precio: $%f\n", PIA[i].precio);
            printf("Precio Total (IVA 16%c): %f\n", 37, PIA[i].iva);
        }
    }
}

void archivos()
{
    ofstream archivo;
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "Videojuegosymas.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        printf("ERROR: NO SE PUDO CREAR EL ARCHIVO\n");
        exit(1);
    }

    archivo << "NOMBRE" << "\t";
    archivo << "DESCRIP." << "\t";
    archivo << "FECHA" << "\t";
    archivo << "CLASIF." << "\t";
    archivo << "GENERO" << "\t";
    archivo << "CONSOLA" << "\t";
    archivo << "PRECIO" << "\t";
    archivo << "PRECIO TOTAL" << "\n";

    for (int i = 0; i < alta; i++)
    {
        if (PIA[i].status == "ELIMINADO")
        {
            texto2 = "REGISTRO ELIMINADO: ";
            texto = i+1;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto2 = PIA[i].nombre;
            archivo << texto2 << "\t";
            texto2 = PIA[i].descripcion;
            archivo << texto2 << "\t";
            texto = PIA[i].fecha;
            archivo << texto << "\t";
            texto2 = PIA[i].clasificacion;
            archivo << texto2 << "\t";
            texto2 = PIA[i].genero;
            archivo << texto2 << "\t";
            texto2 = PIA[i].consola;
            archivo << texto2 << "\t";
            texto = PIA[i].precio;
            archivo << texto << "\t";
            texto = PIA[i].iva;
            archivo << texto << "\n";
        }
    }

    archivo.close();
}

void eliminar()
{
    int j;
    printf("Ingrese el registro a eliminar: ");
    scanf_s("%d", &j);

    j = j - 1;

    for (int i = j; i == j; i++)
    {
        printf("Eliminando registro %d\n", j + 1);
        PIA[i].status = "ELIMINADO";
    }
}

void modificar()
{
    int j, opcion, op2;

    do
    {
        printf("Ingrese el n%cmero de registro a modificar: ", 163);
        scanf_s("%d", &j);
        j = j - 1;

        for (int i = j; i == j; i++)
        {
            if (PIA[i].status == "ELIMINADO")
            {
                printf("REGISTRO %d ELIMINADO\n", i + 1);
                printf("Ingrese un registro v%clido\n", 160);
                op2 = 1;
            }
            else
            {
                op2 = 2;
            }
        }
    } while (op2 == 1);

    printf("Ingrese que desea modificar: 1.- Nombre del videojuego, 2.- Descripcion, 3.- A%co de lanzamiento, 4.- Clasificaci%cn, 5.- G%cnero, 6.- Consola, 7.- Precio\n", 164, 162, 130);
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese el nuevo nombre del videojuego: ");
            getline(cin, PIA[i].nombre);
        }
        break;

    case 2:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingrese la descripci%cn nueva: ", 162);
            getline(cin, PIA[i].descripcion);
        }
        break;

    case 3:
        for (int i = j; i == j; i++)
        {
            printf("Ingrese el a%co nuevo: ", 164);
            scanf_s("%d", &PIA[i].fecha);
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingresa la nueva clasificaci%cn: ", 162);
            getline(cin, PIA[i].clasificacion);
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingresa el nuevo g%cnero: ", 130);
            getline(cin, PIA[i].genero);
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            cin.ignore();
            printf("Ingresa la consola a modificar: ");
            getline(cin, PIA[i].consola);
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            printf("Ingrese el nuevo precio: ");
            scanf_s("%f", &PIA[i].precio);
            PIA[i].iva = PIA[i].precio * 1.16;
        }
        break;
    }
}
