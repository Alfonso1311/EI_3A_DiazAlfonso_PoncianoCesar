#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ********************STRUCT PRINCIPAL********************

struct registroMercancia
{
    int id;
    char nombre [50];
    char marca [40];
    char Umedida [30];
    int existencia;
    float pCompra;
    float pVenta;
};

// ********************STRUCT CAPTURAR********************

struct registroMercancia capturar();
struct registroMercancia capturar(){

    struct registroMercancia registroProducto;
    
    FILE *ptrArchivo = NULL;
    
    printf("Introduce ID de producto: ");
    scanf("%d%*c", &registroProducto.id);
        
    printf("Introduce nombre del producto: ");
    scanf("%[^\n]%*c", registroProducto.nombre);

    printf("Introduce marca del producto: ");
    scanf("%[^\n]%*c", registroProducto.marca);

    printf("Introduce unidad de medida del producto: ");
    scanf("%[^\n]%*c", registroProducto.Umedida);
    
    printf("Introduce el numero de existencias del producto: ");
    scanf("%d%*c", &registroProducto.existencia);
    
    printf("Introduce el precio de compra: ");
    scanf("%f%*c", &registroProducto.pCompra);
    
    printf("Introduce el precio de venta: ");
    scanf("%f%*c", &registroProducto.pVenta);
    
    ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "ab");

    if(ptrArchivo != NULL)
    {
        printf("\nArchivo creado correctamente\n");

        fwrite(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
        
    }
    fclose(ptrArchivo);
    
    return (registroProducto);

};

// ********************STRUCT ELIMINAR********************


struct registroMercancia eliminar();
struct registroMercancia eliminar(){
    
    struct registroMercancia registroProducto, otroProducto;

    FILE *ptrArchivo = NULL, *ptrEscribir = NULL;
    
    long posicion;
    int leerMas = 1;
    int opcion, idConsulta;
    
    

    printf(" ***************************\n");
    printf(" * 1-. De forma física     *\n");
    printf(" * 2-. De forma lógica     *\n");
    printf(" ***************************\n\n");
    printf("¿De que forma desea eliminar?: ");
    scanf("%d", &opcion);
    printf("\nEscribe el ID del producto: ");
    scanf("%d", &idConsulta);
    
    switch(opcion){
        case 1:
            ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb");
            if(ptrArchivo != NULL)
            {
                fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                while( !feof(ptrArchivo) && leerMas == 1)
                {
                    if(registroProducto.id == idConsulta)
                    {
                        posicion = ftell(ptrArchivo)-sizeof(registroProducto);
                        leerMas = 0;
                    }
                    else
                    {
                        fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                    }
                }
                
                if(leerMas == 0)
                {
                    ptrEscribir = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb+");
                    if(ptrEscribir != NULL)
                    {
                        fseek(ptrEscribir, posicion, SEEK_SET);
                        fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                        while(!feof(ptrArchivo)){
                            otroProducto = registroProducto;
                            fwrite(&otroProducto, sizeof(otroProducto), 1, ptrEscribir);
                            fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                        }
                        fclose(ptrEscribir);
                    }
                }
                fclose(ptrArchivo);
                
                printf("\nProducto eliminado correctamente\n");
            }
        
        break;
        
        case 2:
        
        ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb");
            if(ptrArchivo != NULL)
            {
                fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                while( !feof(ptrArchivo) && leerMas == 1)
                {
                    if(registroProducto.id == idConsulta)
                    {
                        posicion = ftell(ptrArchivo)-sizeof(registroProducto);
                        leerMas = 0;
                    }
                    else
                    {
                        fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                    }
                }
                
                if(leerMas == 0)
                {
                    ptrEscribir = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb+");
                    if(ptrEscribir != NULL)
                    {
                        fseek(ptrEscribir, posicion, SEEK_SET);
                        fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                        while(!feof(ptrArchivo)){
                            otroProducto = registroProducto;
                            fwrite(&otroProducto, sizeof(otroProducto), 1, ptrEscribir);
                            fread(&registroProducto, sizeof(registroProducto), 1, ptrArchivo);
                        }
                        fclose(ptrEscribir);
                    }
                }
                fclose(ptrArchivo);
                
                printf("\nProducto eliminado correctamente\n");
            }
        
        break;
    }

};


// ********************STRUCT MODIFICAR UN REGISTRO********************

struct registroMercancia modificarR();
struct registroMercancia modificarR(){
    
struct registroMercancia mRegistro;

    
    FILE *ptrArchivo = NULL;
    
    int codigo;
    int encontrar=0, opcion;
    
    do{
    
        printf(" ***************************\n");
        printf(" * 1-. Todos los registros *\n");
        printf(" * 2-. Nombre              *\n");
        printf(" * 3-. Marca               *\n");
        printf(" * 4-. Unidad de medida    *\n");
        printf(" * 5-. Existencia          *\n");
        printf(" * 6-. Precio de compra    *\n");
        printf(" * 7-. Precio de venta     *\n");
        printf(" ***************************\n\n");
        printf("¿Qué registro desea modificar?: ");
        scanf("%d", &opcion);
        
        if(opcion>0 && opcion<8){
        
            ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "r+b");
            
                if(ptrArchivo != NULL)
                {
                    
                    do{
                    
                        printf("\nIngrese la clave del producto a modificar: ");
                                scanf("%d", &codigo);
                        
                        fread(&mRegistro, sizeof(mRegistro),1,ptrArchivo);
                        while( !feof(ptrArchivo) )
                        {
                                
                            if(codigo == mRegistro.id){
                                printf("\n***********************************************\n");
                                printf("\t ID: %d\n", mRegistro.id);
                                printf("\t NOMBRE: %s\n", mRegistro.nombre);
                                printf("\t MARCA: %s\n", mRegistro.marca);
                                printf("\t UNIDAD DE MEDIDA: %s\n", mRegistro.Umedida);
                                printf("\t EXISTENCIA: %d\n", mRegistro.existencia);
                                printf("\t PRECIO DE COMPRA: %f\n", mRegistro.pCompra);
                                printf("\t PRECIO DE VENTA: %f\n", mRegistro.pVenta);
                                printf("***********************************************\n\n");
                                
                                
                                switch(opcion){
                    
                                    case 1:
                                    
                                        printf("Modificar todos los registros\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Nombre: ");
                                        scanf("%s%*c", mRegistro.nombre);
                                    
                                        printf("Marca: ");
                                        scanf("%s%*c", mRegistro.marca);
                                    
                                        printf("Unidad de medida: ");
                                        scanf("%s%*c", mRegistro.Umedida);
                                        
                                        printf("Existencia: ");
                                        scanf("%d%*c", &mRegistro.existencia);
                                        
                                        printf("Precio de compra: ");
                                        scanf("%f%*c", &mRegistro.pCompra);
                                        
                                        printf("Precio de venta: ");
                                        scanf("%f%*c", &mRegistro.pVenta);
                                        
                                        long pos = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 2:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Nombre: ");
                                        scanf("%s%*c", mRegistro.nombre);
                                        
                                        long pos1 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos1, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 3:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Marca: ");
                                        scanf("%s%*c", mRegistro.marca);
                                        
                                        long pos2 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos2, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 4:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Unidad de medida: ");
                                        scanf("%s%*c", mRegistro.Umedida);
                                        
                                        long pos3 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos3, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 5:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Existencia: ");
                                        scanf("%d%*c", &mRegistro.existencia);
                                        
                                        long pos4 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos4, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 6:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Precio de compra: ");
                                        scanf("%f%*c", &mRegistro.pCompra);
                                        
                                        long pos5 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos5, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                    case 7:
                                    
                                        printf("Modificar registro\n\n");
                                        
                                        printf("ID: %d\n", mRegistro.id);
                                        
                                        printf("Precio de venta: ");
                                        scanf("%f%*c", &mRegistro.pVenta);
                                        
                                        long pos6 = ftell(ptrArchivo)-sizeof(mRegistro);
                                        fseek(ptrArchivo, pos6, SEEK_SET);
                                        fwrite(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                        printf("\nDatos actualizados correctamente\n\n");
                                        
                                        encontrar=1;
                                        
                                        break;
                                        
                                }   
                                
                            }
                            
                            fread(&mRegistro, sizeof(mRegistro), 1, ptrArchivo);
                                
                        }
                        
                        if(encontrar==0){
                            printf("\nNo existe ningun producto con esta clave\n");
                        }
                        
                    }while(encontrar==0);
                }
        
            fclose(ptrArchivo);
            
        }else{
            printf("\nLa opcion no existe, intentelo de nuevo\n\n");
        }
        
    }while(opcion<=0 || opcion>=10);

};


// ********************STRUCT CONSULTAR UN PRODUCTO********************

struct registroMercancia consultarP();
struct registroMercancia consultarP(){
    
struct registroMercancia cProducto;

    
    FILE *ptrArchivo = NULL;
    
    int codigo;
    int encontrar=0;
    
    ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb");
    
        if(ptrArchivo != NULL)
        {
            printf("Ingrese la clave del producto: ");
            scanf("%d%*c", &codigo);
            
            fread(&cProducto, sizeof(cProducto),1,ptrArchivo);
            while( !feof(ptrArchivo) )
            {
                if(codigo == cProducto.id){
                    printf("\n***********************************************\n");
                    printf("\t ID: %d\n", cProducto.id);
                    printf("\t NOMBRE: %s\n", cProducto.nombre);
                    printf("\t MARCA: %s\n", cProducto.marca);
                    printf("\t UNIDAD DE MEDIDA: %s\n", cProducto.Umedida);
                    printf("\t EXISTENCIA: %d\n", cProducto.existencia);
                    printf("\t PRECIO DE COMPRA: %f\n", cProducto.pCompra);
                    printf("\t PRECIO DE VENTA: %f\n", cProducto.pVenta);
                    printf("***********************************************\n\n");
                    
                    encontrar=1;
                }
                
                fread(&cProducto, sizeof(cProducto), 1, ptrArchivo);
            }
            
            if(encontrar==0){
                printf("No existe ningun producto con esta clave");
            }
        }
    
        fclose(ptrArchivo);

};


// ********************STRUCT CONSULTAR TODOS LOS PRODUCTOS********************

struct registroMercancia consultarT();
struct registroMercancia consultarT(){
    
struct registroMercancia cListado;

    FILE *ptrArchivo = NULL;
    
    
    
    ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb");
        if(ptrArchivo != NULL)
        {
            fread(&cListado, sizeof(cListado), 1, ptrArchivo);
            while( !feof(ptrArchivo) )
            {
                printf("\n***********************************************\n");
                printf("\t ID: %d\n", cListado.id);
                printf("\t NOMBRE: %s\n", cListado.nombre);
                printf("\t MARCA: %s\n", cListado.marca);
                printf("\t UNIDAD DE MEDIDA: %s\n", cListado.Umedida);
                printf("\t EXISTENCIA: %d\n", cListado.existencia);
                printf("\t PRECIO DE COMPRA: %f\n", cListado.pCompra);
                printf("\t PRECIO DE VENTA: %f\n", cListado.pVenta);
                printf("***********************************************\n\n");
                fread(&cListado, sizeof(cListado), 1, ptrArchivo);
            }
        }
    
        fclose(ptrArchivo);

};

// ********************STRUCT CONSULTAR PRODUCTOS CON SU EXISTENCIA********************

struct registroMercancia consultarE();
struct registroMercancia consultarE(){
    
struct registroMercancia cExistencia;

    FILE *ptrArchivo = NULL;
    
    
    
    ptrArchivo = fopen("EP3_3A_DíazAlfonso_PoncianoCesar.dat", "rb");
        if(ptrArchivo != NULL)
        {
            fread(&cExistencia, sizeof(cExistencia), 1, ptrArchivo);
            while( !feof(ptrArchivo) )
            {
                printf("***********************************************\n");
                printf("\t ID: %d\n", cExistencia.id);
                printf("\t NOMBRE: %s\n", cExistencia.nombre);
                printf("\t EXISTENCIA: %d\n", cExistencia.existencia);
                printf("***********************************************\n\n");
                fread(&cExistencia, sizeof(cExistencia), 1, ptrArchivo);
            }
        }
    
        fclose(ptrArchivo);

};

// ********************MAIN DONDE SE EJECUTAN LOS STRUCTS********************

int main()
{
    int opcion;
    char seguir;
    do{
    printf(" \n");
        printf(" **************************************\n");
        printf(" * Autores:                           *\n");
        printf(" * -Diaz Celito Alfonso               *\n");
        printf(" * -Ponciano Velasquez Cesar Ivan     *\n");
        printf(" **************************************\n");
        printf(" *                MENU                *\n");
        printf(" **************************************\n");
        printf(" * INSTRUCCIONES:                     *\n");
        printf(" * Selecciona una opcion escribiendo  *\n");
        printf(" * el número de la operación.         *\n");
        printf(" **************************************\n");
        printf(" * 1-. Agregar                        *\n");
        printf(" * 2-. Eliminar                       *\n");
        printf(" * 3-. Modificar                      *\n");
        printf(" * 4-. Consultar un producto          *\n");
        printf(" * 5-. Consultar todos los productos  *\n");
        printf(" * 6-. Consultar existencia           *\n");
        printf(" * 7-. Salir del programa             *\n");
        printf(" **************************************\n\n");
        printf("Introduce la opcion que deseas ejecutar: ");
        scanf("%d", &opcion);
        
        printf("\n");
        
        switch(opcion){
            
            case 1:
            
                printf("\n************************************************\n");
                printf("************ REGISTRO DE PRODUCTOS *************\n");
                printf("************************************************\n\n");
                
                capturar();
        
                break;
                
            case 2:
            
                printf("\n************************************************\n");
                printf("************* ELIMINAR PRODUCTOS ***************\n");
                printf("************************************************\n\n");
                
                eliminar();
                
                break;
                
            case 3:
            
                printf("\n\n************************************************\n");
                printf("*************  MODIFICAR PRODUCTO **************\n");
                printf("************************************************\n\n");
                
                modificarR();
                
                break;
                
            case 4:
                
                printf("\n************************************************\n");
                printf("************* CONSULTAR UN PRODUCTO ************\n");
                printf("************************************************\n\n");
                
                consultarP();
                
                break;
                
            case 5:
                
                printf("\n\n************************************************\n");
                printf("******** CONSULTAR TODOS LOS PRODUCTOS  ********\n");
                printf("************************************************\n\n");
                
                consultarT();
                
                break;
                
            case 6:  
                
                printf("\n************************************************\n");
                printf("***** CONSULTAR EXISTENCIA DE PRODUCTO  ********\n");
                printf("************************************************\n\n");
                
                consultarE();
                
                break;
                
            case 7:   
                return 1;
                
                break;
            
            default:
            
                printf("\nLa opcion seleccionada no existe");
        
        }

    }while(seguir!='n');

    return 0;
}
