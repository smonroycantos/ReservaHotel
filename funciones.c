#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char tipo[40];
    int comp=0,x[3],j=0;
    printf("Ingrese el tamano de habitacion que desea buscar: \n");
    scanf("%s",tipo);
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("#\t\tTamano\t\tHotel\t\tPrecio\n");
            comp=1;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][1],tipo)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
            x[j]=i+1;
            j++;
        }
    }
    if (comp==1) {
        printf("Elija la habitacion que desea reservar: \n");
        scanf("%d",numHabitacion);        
        while (*numHabitacion!=x[0] && *numHabitacion!=x[1] && *numHabitacion!=x[2]){
            printf("Ingrese una habitacion valida\n");
            scanf("%d",numHabitacion);
        }
        
    } else {
        printf("No se ha encontrado ninguna habitacion de tipo %s\n",tipo);
    }
}

void buscarHotel(int *numHabitacion,char habitaciones[][3][40],double precios[]){
    char hotel[40];
    int j=0,x[3],comp=0;
    printf("Ingrese el hotel que desea buscar : \n");
    scanf("%s",hotel);
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][2],hotel)==0)
        {
            printf("#\t\tTamano\t\tHotel\t\tPrecio\n");
            comp=1;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (strcmp(habitaciones[i][2],hotel)==0)
        {
            printf("%s\t\t%s\t\t%s\t\t%lf\n",habitaciones[i][0],habitaciones[i][1],habitaciones[i][2],precios[i]);
            x[j]=i+1;
            j++;
        }
    }
    //printf("Validas: %d %d %d\n",x[0],x[1],x[2]);
    if (comp==1){
        printf("Elija la habitacion que desea reservar: \n");
        scanf("%d",numHabitacion);
        while (*numHabitacion!=x[0] && *numHabitacion!=x[1] && *numHabitacion!=x[2]){
            printf("Ingrese una habitacion valida\n");
            scanf("%d",numHabitacion);
        }
    } else {
        printf("No se ha encontrado el hotel %s\n",hotel);
    }
}

void realizarReserva(int numHabitacion,char habitaciones[][3][40],char clientes[][2][40],int reservas[][4],int *numClientes){
    int x=0,x1=0;
    if (numHabitacion==-1){
        printf("Busque primero una habitacion, ingrese 1 en el menu principal\n");
    } else {
        for (int i = 0; i < 9; i++)
        {
            if (reservas[i][1]==numHabitacion){
                printf("Ya existe una reserva de esta habitacion\n");
                x1=1;
            }
        }
        if (x1!=1)
        {
            char c[40];
            printf("\nIngrese el numero de cedula del cliente que realiza la reserva : \n");
            scanf("%s",c);
            for (int i = 0; i < 5; i++)
            {
                if (atoi(c)==reservas[i][0]){
                    printf("Ya hay una reserva con ese numero de cedula\n");
                    x=1;
                }
            }
            if (x!=1)
            {
                strcpy(clientes[*numClientes][1],c);
                printf("Ingrese el nombre del cliente que realiza la reserva : \n");
                scanf("%s",&clientes[*numClientes][0]);
                printf("De cuantos dias va a ser la estadia en el hotel : \n");
                scanf("%d",&reservas[*numClientes][2]);
                reservas[*numClientes][0]=atoi(clientes[*numClientes][1]);
                reservas[*numClientes][1]=numHabitacion;
                *numClientes+=1;
            }
        }
    }
}

void buscarReservaPorCedula(int *numReserva,int reservas[][4]){
    int cedula;
    printf("Ingrese el numero de cedula de la reserva : \n");
    scanf("%d",&cedula);
    for (int i = 0; i < 5; i++)
    {
        if (cedula==reservas[i][0]){
            *numReserva=i;
            break;
        }
    }
}

void imprimirReserva(int *numReserva,int reservas[][4],char habitaciones[][3][40],double precios[],int numHabitacion){
    //printf("%d\n",reservas[*numReserva][3]);
    char e[40];
    if (*numReserva==-1)
    {
        printf("Aun no se ha realizado ninguna reserva\n");
    } else {
        if (reservas[*numReserva][3]==0)
        {
            strcpy(e,"No");
        }
        else if (reservas[*numReserva][3]==1)
        {
            strcpy(e,"Si");
        }
        printf("Cedula: %d\nNumero de habitacion: %d\nTipo de habitacion: %s\nDuracion de su estadia (en dias): %d\nCancelado: %s\n",reservas[*numReserva][0],reservas[*numReserva][1],habitaciones[numHabitacion-1][1],reservas[*numReserva][2],e);
    }
}

void pagarReserva(int *numReserva,int reservas[][4],char habitaciones[][3][40],double precios[]){
    if (*numReserva==-1)
    {
        printf("Aun no se ha realizado ninguna reserva\n");
    }
    reservas[*numReserva][3]=1;
    //printf("%d\n",reservas[*numReserva][3]);
    printf("Reserva cancelada correctamente\n");
}