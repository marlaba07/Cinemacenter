#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

void crearUsuario(int opcion)
{
    printf("---- [ REGISTRO ] ---- ");
    printf("\n");

    FILE * archivo;

    archivo = fopen("usuarios.bin","ab");

    if (archivo != NULL )
    {
        Usuario usuarioCreado = formularioUsuario(opcion);
        bool validarUsuario = validarUsername(usuarioCreado);

        if(!validarUsuario)
        {
            fwrite(&usuarioCreado,sizeof(Usuario),1,archivo);
            printf("\nEl usuario: %s fue registrado con exito!\n", usuarioCreado.nombreUsuario);
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

int iniciarSesion(int opcion)
{
    printf("---- [ Iniciar sesion ] ---- ");
    printf("\n");

    int flag = 0;
    char username[30] = "admin";
    char password[30] = "123";

    FILE * archivo;

    archivo = fopen("usuarios.bin","rb");

    if (archivo != NULL )
    {
        Usuario usuarioLogin = formularioUsuario(opcion);
        Usuario usuario;

        if((strcmp(usuarioLogin.nombreUsuario, username) == 0) && (strcmp(usuarioLogin.password, password) == 0))
        {
            flag = 2;
            return flag;
        }

        while(fread(&usuario,sizeof(Usuario),1,archivo)>0)
        {
            if((strcmp(usuarioLogin.nombreUsuario, usuario.nombreUsuario) == 0) && (strcmp(usuarioLogin.password, usuario.password) == 0))
            {
                flag = 1;
                return flag;
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

Usuario formularioUsuario(int opcion)
{
    Usuario usuario;
    char caracter;

    printf("\nIngresar nombre de usuario: ");
    fflush(stdin);
    scanf("%s", &usuario.nombreUsuario);

    printf("Ingresar contraseña: ");
    fflush(stdin);
    // scanf("%s", &usuario.password);

    int i=0;
    while(caracter =getch())   //cree un lector de caracteres y despues lo pase al arreglo de contraseña//
    {
        if(caracter==13)   //si caracter es igual a 13(tecla enter) deja de ingresar
        {
            usuario.password[i]='\0'; //ese caracter es NULL(no lo guarda)//
            break;
        }
        else if(caracter == 8) // validacion para poder borrar
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            printf("*");
            usuario.password[i]=caracter;
            i++;
        }

    }

    if(opcion == 1)
    {
        printf("\nIngresar ubicacion: ");
        fflush(stdin);
        gets(usuario.ubicacion);
    }

    return usuario;
}





