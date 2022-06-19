#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include <conio.h>
#include <stdbool.h>


// ------------------ | PROTOTIPADO | ------------------ \\

typedef struct
{
    char nombreUsuario[50];
    char password[50];
    char ubicacion[50];

} Usuario;

int menu();
int welcome();
Usuario formulario(int opcion);
bool iniciarSesion();

void leerUsuario();


// ------------------ | MAIN | ------------------ \\

int main()
{
    int opcion = welcome();
    validarDatos(opcion);

    leerUsuario();

    return 0;
}

// ------------------ | FUNCIONES | ------------------ \\

int welcome ()
{
    printf("---- [ Bienvenidos a CINEMACENTER ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- Opcion 1 [Registrarme]");
    printf("\n[2] ---- Opcion 2 [Iniciar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void validarDatos(int opcion)
{
    if(opcion == 1)
    {
        crearUsuario(opcion);
    }

    if(opcion == 2)
    {
        bool sesion = iniciarSesion();
    }
}


void crearUsuario(int opcion)
{
    printf("---- [ REGISTRO ] ---- ");
    printf("\n");

    FILE * archivo;

    archivo = fopen("usuarios.bin","ab");

    if (archivo != NULL )
    {
        Usuario usuarioCreado = formulario(opcion);

        fwrite(&usuarioCreado,sizeof(Usuario),1,archivo);
    }

    fclose(archivo);

}

void leerUsuario()
{
    Usuario a;
    FILE * archivo;

    archivo = fopen("usuarios.bin", "rb");
    if(archivo != NULL)
    {
        while(fread(&a,sizeof(Usuario),1,archivo)>0)
        {
            /* if(a.nombreUsuario == usuario.nombreUsuario && a.password == usuario.password)
            {

            } */
            printf("Nombre de usuario: %s\n", a.nombreUsuario);
            printf("Contraseña: %s\n", a.password);
            printf("Ubicacion: %s\n", a.ubicacion);

            printf("\n");
        }
    }
}

Usuario formulario(int opcion)
{
    Usuario usuario;

    printf("Ingresar nombre de usuario: ");
    scanf("%s", &usuario.nombreUsuario);

    printf("Ingresar contraseña: ");
    scanf("%s", &usuario.password);

    if(opcion == 1)
    {
        printf("Ingresar ubicacion: ");
        scanf("%s", &usuario.ubicacion);
    }

    return usuario;
}

bool iniciarSesion()
{
    bool flag = false;

    return flag;
}

int menu ()
{
    int opcion;

    printf("\n[1] ---- Opcion 1 [Ver peliculas disponibles]");
    printf("\n[2] ---- Opcion 2 [Ver mi carrito]");
    printf("\n[3] ---- Opcion 3 [Ver supercombos cinemacenter]");
    printf("\n[0] ---- Salir");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    system("cls");

    return opcion;
}
