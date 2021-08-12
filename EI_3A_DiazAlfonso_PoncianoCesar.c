#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ********************STRUCT PRINCIPAL********************

struct registroAvion
{
    int idVuelo;
    char origen[50];
    char destino[50];
    char horario[25];
    int nAsientos;
};

struct ventaAsientos
{
    char nombre[50];
    char apellidos[50];
    int idVuelo;
    int idAsiento;
    //struct registroAvion vuelo;
};

// ********************STRUCT CAPTURAR VUELO********************

struct registroAvion capturarV();
struct registroAvion capturarV()
{

    struct registroAvion registroVuelo;

    FILE *ptrArchivo = NULL;

    printf("Introduce ID de vuelo: ");
    scanf("%d%*c", &registroVuelo.idVuelo);

    printf("Introduce el origen del vuelo: ");
    scanf("%[^\n]%*c", registroVuelo.origen);

    printf("Introduce el destino del vuelo: ");
    scanf("%[^\n]%*c", registroVuelo.destino);

    printf("Introduce el horario del vuelo: ");
    scanf("%[^\n]%*c", registroVuelo.horario);

    printf("Numero de asientos del vuelo: ");
    scanf("%d%*c", &registroVuelo.nAsientos);

    ptrArchivo = fopen("EI_prueba.dat", "ab");

    if (ptrArchivo != NULL)
    {
        printf("\nArchivo creado correctamente\n");

        fwrite(&registroVuelo, sizeof(registroVuelo), 1, ptrArchivo);
    }
    fclose(ptrArchivo);

    return (registroVuelo);
};

// *********************STRUCT MODIFICAR UN VUELO**********************

struct registroAvion modificarV();
struct registroAvion modificarV()
{

    struct registroAvion mVuelo;

    FILE *ptrArchivo = NULL;

    int codigo;
    int encontrar = 0, opcion;

    do
    {
        //

        ptrArchivo = fopen("EI_prueba.dat", "r+b");

        if (ptrArchivo != NULL)
        {

            //for(codigo=0;codigo<1;codigo++){

            printf("\nIngrese la clave del vuelo a modificar: ");
            scanf("%d", &codigo);

            fread(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
            while (!feof(ptrArchivo) && encontrar == 0)
            {

                if (codigo == mVuelo.idVuelo)
                {
                    printf("\n***********************************************\n");
                    printf("\t ID: %d\n", mVuelo.idVuelo);
                    printf("\t ORIGEN: %s\n", mVuelo.origen);
                    printf("\t DESTINO: %s\n", mVuelo.destino);
                    printf("\t HORARIO: %s\n", mVuelo.horario);
                    printf("\t ASIENTOS: %d\n", mVuelo.nAsientos);
                    printf("***********************************************\n\n");

                    printf(" ***************************\n");
                    printf(" * 1-. Todos los registros *\n");
                    printf(" * 2-. Origen              *\n");
                    printf(" * 3-. Destino             *\n");
                    printf(" * 4-. Horario             *\n");
                    printf(" * 5-. N. Asientos         *\n");
                    printf(" ***************************\n\n");
                    printf("Que registro desea modificar?: ");
                    scanf("%d", &opcion);

                    if (opcion > 0 && opcion < 8)
                    {

                        switch (opcion)
                        {

                        case 1:

                            printf("Modificar todos los registros del vuelo\n\n");

                            printf("ID: %d\n", mVuelo.idVuelo);

                            printf("Origen: ");
                            scanf("%s%*c", mVuelo.origen);

                            printf("Destino: ");
                            scanf("%s%*c", mVuelo.destino);

                            printf("Horario: ");
                            scanf("%s%*c", mVuelo.horario);

                            printf("N. Asientos: ");
                            scanf("%d%*c", &mVuelo.nAsientos);

                            long pos = ftell(ptrArchivo) - sizeof(mVuelo);
                            fseek(ptrArchivo, pos, SEEK_SET);
                            fwrite(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 2:

                            printf("Modificar registro de vuelo\n\n");

                            printf("ID: %d\n", mVuelo.idVuelo);

                            printf("Origen: ");
                            scanf("%s%*c", mVuelo.origen);

                            long pos1 = ftell(ptrArchivo) - sizeof(mVuelo);
                            fseek(ptrArchivo, pos1, SEEK_SET);
                            fwrite(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 3:

                            printf("Modificar registro de vuelo\n\n");

                            printf("ID: %d\n", mVuelo.idVuelo);

                            printf("Destino: ");
                            scanf("%s%*c", mVuelo.destino);

                            long pos2 = ftell(ptrArchivo) - sizeof(mVuelo);
                            fseek(ptrArchivo, pos2, SEEK_SET);
                            fwrite(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 4:

                            printf("Modificar registro vuelo\n\n");

                            printf("ID: %d\n", mVuelo.idVuelo);

                            printf("Horario: ");
                            scanf("%s%*c", mVuelo.horario);

                            long pos3 = ftell(ptrArchivo) - sizeof(mVuelo);
                            fseek(ptrArchivo, pos3, SEEK_SET);
                            fwrite(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 5:

                            printf("Modificar registro vuelo\n\n");

                            printf("ID: %d\n", mVuelo.idVuelo);

                            printf("N. Asientos: ");
                            scanf("%d%*c", &mVuelo.nAsientos);

                            long pos4 = ftell(ptrArchivo) - sizeof(mVuelo);
                            fseek(ptrArchivo, pos4, SEEK_SET);
                            fwrite(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;
                        }
                    }
                    else
                    {
                        printf("\nLa opcion no existe, intentelo de nuevo\n\n");
                    }
                }
                else //(encontrar == 0)
                {
                    printf("\nNo existe ningun vuelo con esta clave\n");
                    encontrar = 0;
                }

                fread(&mVuelo, sizeof(mVuelo), 1, ptrArchivo);
            }

            //}while(encontrar==);
        }

        fclose(ptrArchivo);

    } while (encontrar == 0); //(opcion <= 0 || opcion >= 10);
};

// ********************STRUCT CAPTURAR VENTA ASIENTOS********************

struct ventaAsientos capturarA();
struct ventaAsientos capturarA()
{

    struct ventaAsientos registroAsiento;
    //struct registroAvion Vuelo;

    FILE *ptrArchivo = NULL;

    printf("Introduce ID de asiento: ");
    scanf("%d%*c", &registroAsiento.idAsiento);

    printf("Introduce el nombre del pasajero: ");
    scanf("%[^\n]%*c", registroAsiento.nombre);

    printf("Introduce apellido del pasajero: ");
    scanf("%[^\n]%*c", registroAsiento.apellidos);

    printf("Introduce ID de vuelo: ");
    scanf("%d%*c", &registroAsiento.idVuelo);

    ptrArchivo = fopen("EI_pruebaPasajeros.dat", "ab");

    if (ptrArchivo != NULL)
    {
        printf("\nArchivo creado correctamente\n");

        fwrite(&registroAsiento, sizeof(registroAsiento), 1, ptrArchivo);
    }
    fclose(ptrArchivo);

    return (registroAsiento);
};

// *********************STRUCT MODIFICAR UNA VENTA DE ASIENTO**********************

struct ventaAsientos modificarA();
struct ventaAsientos modificarA()
{

    struct ventaAsientos mAsiento;

    FILE *ptrArchivo = NULL;

    int codigo, codigo2;
    int encontrar = 0, opcion;

    do
    {
        //

        ptrArchivo = fopen("EI_pruebaPasajeros.dat", "r+b");

        if (ptrArchivo != NULL)
        {

            //for(codigo=0;codigo<1;codigo++){

            printf("\nIngrese la clave del asiento a modificar: ");
            scanf("%d", &codigo);

            printf("\nIngrese la clave del vuelo a modificar: ");
            scanf("%d", &codigo2);

            fread(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
            while (!feof(ptrArchivo) && encontrar == 0)
            {

                if ((codigo == mAsiento.idAsiento) && (codigo2 == mAsiento.idVuelo))
                {
                    printf("\n***********************************************\n");
                    printf("\t ID ASIENTO: %d\n", mAsiento.idAsiento);
                    printf("\t NOMBRE: %s\n", mAsiento.nombre);
                    printf("\t APELLIDO: %s\n", mAsiento.apellidos);
                    printf("\t ID VUELO: %d\n", mAsiento.idVuelo);
                    printf("***********************************************\n\n");

                    printf(" ***************************\n");
                    printf(" * 1-. Todos los registros *\n");
                    printf(" * 2-. Nombre              *\n");
                    printf(" * 3-. Apellido            *\n");
                    printf(" * 4-. ID vuelo            *\n");
                    printf(" * 5-. Salir               *\n");
                    printf(" ***************************\n\n");
                    printf("Que registro desea modificar?: ");
                    scanf("%d", &opcion);

                    if (opcion > 0 && opcion < 8)
                    {

                        switch (opcion)
                        {

                        case 1:

                            printf("Modificar todos los registros del asiento\n\n");

                            printf("ID asiento: %d\n", mAsiento.idAsiento);

                            printf("Nombre: ");
                            scanf("%s%*c", mAsiento.nombre);

                            printf("Apellido: ");
                            scanf("%s%*c", mAsiento.apellidos);

                            printf("ID vuelo: ");
                            scanf("%d%*c", &mAsiento.idVuelo);

                            long pos = ftell(ptrArchivo) - sizeof(mAsiento);
                            fseek(ptrArchivo, pos, SEEK_SET);
                            fwrite(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 2:

                            printf("Modificar registro de vuelo\n\n");

                            printf("ID: %d\n", mAsiento.idAsiento);

                            printf("Nombre: ");
                            scanf("%s%*c", mAsiento.nombre);

                            long pos1 = ftell(ptrArchivo) - sizeof(mAsiento);
                            fseek(ptrArchivo, pos1, SEEK_SET);
                            fwrite(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 3:

                            printf("Modificar registro de vuelo\n\n");

                            printf("ID: %d\n", mAsiento.idAsiento);

                            printf("Apellido: ");
                            scanf("%s%*c", mAsiento.apellidos);

                            long pos2 = ftell(ptrArchivo) - sizeof(mAsiento);
                            fseek(ptrArchivo, pos2, SEEK_SET);
                            fwrite(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;

                        case 4:

                            printf("Modificar registro vuelo\n\n");

                            printf("ID: %d\n", mAsiento.idAsiento);

                            printf("ID vuelo: ");
                            scanf("%d%*c", &mAsiento.idVuelo);

                            long pos4 = ftell(ptrArchivo) - sizeof(mAsiento);
                            fseek(ptrArchivo, pos4, SEEK_SET);
                            fwrite(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
                            printf("\nDatos actualizados correctamente\n\n");

                            encontrar = 1;

                            break;
                        }
                    }
                    else
                    {
                        printf("\nLa opcion no existe, intentelo de nuevo\n\n");
                    }
                }
                else //(encontrar == 0)
                {
                    printf("\nNo existe ningun vuelo con esta clave\n");
                    encontrar = 0;
                }

                fread(&mAsiento, sizeof(mAsiento), 1, ptrArchivo);
            }

            //}while(encontrar==);
        }

        fclose(ptrArchivo);

    } while (encontrar == 0); //(opcion <= 0 || opcion >= 10);
};

// ********************STRUCT CONSULTAR UN ASIENTO VENDIDO********************

struct ventaAsientos consultarA();
struct ventaAsientos consultarA()
{

    struct ventaAsientos cAsiento;

    FILE *ptrArchivo = NULL;

    int codigo;
    int encontrar = 0;

    ptrArchivo = fopen("EI_pruebaPasajeros.dat", "rb");

    if (ptrArchivo != NULL)
    {
        printf("Ingrese la clave del asiento: ");
        scanf("%d%*c", &codigo);

        fread(&cAsiento, sizeof(cAsiento), 1, ptrArchivo);
        while (!feof(ptrArchivo))
        {
            if (codigo == cAsiento.idAsiento)
            {
                printf("\n***********************************************\n");
                printf("\t ID ASIENTO: %d\n", cAsiento.idAsiento);
                printf("\t NOMBRE: %s\n", cAsiento.nombre);
                printf("\t APELLIDO: %s\n", cAsiento.apellidos);
                printf("\t ID VUELO: %d\n", cAsiento.idVuelo);
                printf("***********************************************\n\n");

                encontrar = 1;
            }

            fread(&cAsiento, sizeof(cAsiento), 1, ptrArchivo);
        }

        if (encontrar == 0)
        {
            printf("No existe ningun asiento con esta clave");
        }
    }

    fclose(ptrArchivo);
};

// ********************STRUCT CONSULTAR VUELO DISPONIBLE********************

struct registroAvion consultarV();
struct registroAvion consultarV(){
    
struct registroAvion cVuelo;

    FILE *ptrArchivo = NULL;
    
    
    
    ptrArchivo = fopen("EI_prueba.dat", "rb");
        if(ptrArchivo != NULL)
        {
            fread(&cVuelo, sizeof(cVuelo), 1, ptrArchivo);
            while( !feof(ptrArchivo) && cVuelo.nAsientos > 0 )
            {
                printf("\n***********************************************\n");
                printf("\t ID: %d\n", cVuelo.idVuelo);
                printf("\t ORIGEN: %s\n", cVuelo.origen);
                printf("\t DESTINO: %s\n", cVuelo.destino);
                printf("\t HORARIO: %s\n", cVuelo.horario);
                printf("\t ASIENTOS: %d\n", cVuelo.nAsientos);
                printf("***********************************************\n\n");
                fread(&cVuelo, sizeof(cVuelo), 1, ptrArchivo);
            }
        }
    
        fclose(ptrArchivo);

};

// ********************MAIN DONDE SE EJECUTAN LOS STRUCTS********************

int main()
{
    int opcion;
    char seguir;
    do
    {
        printf(" \n");
        printf(" **********************************************************\n");
        printf(" * Autores:                                               *\n");
        printf(" * -Diaz Celito Alfonso                                   *\n");
        printf(" * -Ponciano Velasquez Cesar Ivan                         *\n");
        printf(" **********************************************************\n");
        printf(" *                MENU                                    *\n");
        printf(" **********************************************************\n");
        printf(" * INSTRUCCIONES:                                         *\n");
        printf(" * Selecciona una opcion escribiendo                      *\n");
        printf(" * el numero de la operacion.                             *\n");
        printf(" **********************************************************\n");
        printf(" * 1-. Agregar vuelo                                      *\n");
        printf(" * 2-. Modificar vuelo                                    *\n");
        printf(" * 3-. Venta de asientos                                  *\n");
        printf(" * 4-. Modificar venta se asiento                         *\n");
        printf(" * 5-. Consultar asiento vendido                          *\n");
        printf(" * 6-. Consultar vuelo disponible                         *\n");
        printf(" * 7-. Consultar asientos disponibles en todos los vuelos *\n");
        printf(" * 8-. Salir del programa                                 *\n");
        printf(" **********************************************************\n\n");
        printf("Introduce la opcion que deseas ejecutar: ");
        scanf("%d", &opcion);

        printf("\n");

        switch (opcion)
        {

        case 1:

            printf("\n************************************************\n");
            printf("************** REGISTRO DE VUELO ***************\n");
            printf("************************************************\n\n");

            capturarV();

            break;

        case 2:

            printf("\n************************************************\n");
            printf("************** MODIFICAR VUELO *****************\n");
            printf("************************************************\n\n");

            modificarV();

            break;

        case 3:

            printf("\n\n************************************************\n");
            printf("*************  VENTA DE ASIENTOS ***************\n");
            printf("************************************************\n\n");

            capturarA();

            break;

        case 4:

            printf("\n************************************************\n");
            printf("*********** MODIFICAR VENTA DE ASIENTO *********\n");
            printf("************************************************\n\n");

            modificarA();

            break;

        case 5:

            printf("\n\n************************************************\n");
            printf("********** CONSULTAR ASIENTO VENDIDO  **********\n");
            printf("************************************************\n\n");

            consultarA();

            break;

        case 6:

            printf("\n************************************************\n");
            printf("******** CONSULTAR VUELO DISPONIBLE  ***********\n");
            printf("************************************************\n\n");

            consultarV();
            
            break;

        case 7:

            printf("\n************************************************\n");
            printf("**** CONSULTAR ASIENTO DISPONIBLE EN VUELO  ****\n");
            printf("************************************************\n\n");

            break;

        case 8:
            return 1;

            break;

        default:

            printf("\nLa opcion seleccionada no existe, intente nuevamente\n");

            break;
        }

    } while (seguir != 'n'/*opcion<=0 || opcion>=9*/);
}
