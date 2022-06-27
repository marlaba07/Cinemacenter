#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

void crearUsuario()
{
    printf("---- [ REGISTRO ] ---- ");
    printf("\n");

    FILE * archivo;

    archivo = fopen("usuarios.bin","ab");

    if (archivo != NULL )
    {
        Usuario usuarioCreado = formularioUsuario();
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

Usuario iniciarSesion(Usuario usuarioInicial)
{
    printf("---- [ Iniciar sesion ] ---- ");
    printf("\n");

    int flag = 0;
    Usuario admin = {.id = 0,
                     .nombreUsuario = "admin",
                     .password = "123",
                     .ubicacion = "",
                    };
    Usuario usuario;

    FILE * archivo;

    archivo = fopen("usuarios.bin","rb");

    if (archivo != NULL )
    {
        Usuario usuarioLogin = formularioLogin();

        if((strcmp(usuarioLogin.nombreUsuario, admin.nombreUsuario) == 0) && (strcmp(usuarioLogin.password, admin.password) == 0))
        {
            return admin;
        }

        while(fread(&usuario,sizeof(Usuario),1,archivo)>0)
        {
            if((strcmp(usuarioLogin.nombreUsuario, usuario.nombreUsuario) == 0) && (strcmp(usuarioLogin.password, usuario.password) == 0))
            {
                return usuario;
            }
        }
    }

    fclose(archivo);

    return usuarioInicial;
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
            printf("ID: %d\n", a.id);
            printf("Nombre de usuario: %s\n", a.nombreUsuario);
            printf("Contraseña: %s\n", a.password);
            printf("Ubicacion: %s\n", a.ubicacion);

            printf("\n");
        }
    }
}

Usuario formularioLogin()
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

    return usuario;
}


Usuario formularioUsuario()
{
    Usuario usuario;
    char caracter;

    usuario.id = contarRegistroUsuario("usuarios.bin") + 1;

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

    printf("\nIngresar ubicacion: ");
    fflush(stdin);
    gets(usuario.ubicacion);


    return usuario;
}

int contarRegistroUsuario(char nombre[50])
{
    int cantidad = 0;
    long tam = 0;

    FILE * archi = fopen(nombre,"rb");
    if (archi !=NULL)
    {
        fseek(archi,0,SEEK_END);
        tam = ftell(archi);
        cantidad = tam / sizeof(Usuario);
    }

    fclose(archi);
    return cantidad;
}



