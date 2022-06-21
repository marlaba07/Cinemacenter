#include "login.h"

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



