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
void welcome();

Usuario formulario(int opcion);
bool iniciarSesion(int opcion);

void leerUsuario();

bool validarUsername(Usuario usuarioCreado);


// ------------------ | MAIN | ------------------ \\

int main()
{
    leerUsuario();

    welcome();

    return 0;
}

// ------------------ | FUNCIONES | ------------------ \\

void welcome()
{
    printf("---- [ Bienvenidos a CINEMACENTER ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- Opcion 1 [Registrarme]");
    printf("\n[2] ---- Opcion 2 [Iniciar sesion]");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    system("cls");

    bool sesion = false;

    switch(opcion)
    {
    case 1:
        crearUsuario(opcion);
        printf("Redireccionando al menu principal...");
        sleep(3);
        system("cls");
        welcome();
        break;
    case 2:
        sesion = iniciarSesion(opcion);
        if(sesion)
        {
            menuPrincipal();
        }
        break;
    default:
        puts("Error");
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
        bool validarUsuario = validarUsername(usuarioCreado);

        if(!validarUsuario)
        {
            fwrite(&usuarioCreado,sizeof(Usuario),1,archivo);
            printf("\nEl usuario: %s  fue registrado con exito!\n", usuarioCreado.nombreUsuario);
        }
        else
        {
            printf("El usuario ingresado ya existe. \n");
        }

    }

    fclose(archivo);

}

bool validarUsername(Usuario usuarioCreado)
{

    FILE * archivo;
    bool flag = false;
    archivo = fopen("usuarios.bin","rb");

    if (archivo != NULL )
    {
        Usuario usuario;

        while(fread(&usuario,sizeof(Usuario),1,archivo)>0)
        {
            if(strcmp(usuarioCreado.nombreUsuario, usuario.nombreUsuario) == 0)
            {
                flag = true;
                break;
            }
        }
    }
    fclose(archivo);
    return flag;
}

bool iniciarSesion(int opcion)
{
    printf("---- [ Iniciar sesion ] ---- ");
    printf("\n");

    bool flag = false;

    FILE * archivo;

    archivo = fopen("usuarios.bin","rb");

    if (archivo != NULL )
    {
        Usuario usuarioLogin = formulario(opcion);
        Usuario usuario;

        while(fread(&usuario,sizeof(Usuario),1,archivo)>0)
        {
            if((strcmp(usuarioLogin.nombreUsuario, usuario.nombreUsuario) == 0) && (strcmp(usuarioLogin.password, usuario.password) == 0))
            {
                flag = true;

                break;
            }
        }
    }

    fclose(archivo);

    system("cls");

    return flag;
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

    printf("\nIngresar nombre de usuario: ");
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


void menuPrincipal()
{
    printf("---- [ Opciones ] ---- ");
    printf("\n");

    int opcion;

    printf("\n[1] ---- Opcion 1 [Ver peliculas disponibles]");
    printf("\n[2] ---- Opcion 2 [Ver mi carrito]");
    printf("\n[3] ---- Opcion 3 [Ver supercombos cinemacenter]");
    printf("\n[4] ---- Cerrar sesion");

    printf("\n\nOpcion = ");
    fflush(stdin);
    scanf("%d", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        puts("Se ha pulsado una a.");
        break;
    case 2:
        puts("Se ha pulsado una a.");
        break;
    case 3:
        puts("Se ha pulsado una a.");
        break;
    case 4:
        welcome();
        break;
    default:
        puts("Error");
    }
}
