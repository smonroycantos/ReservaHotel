#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include "funciones.h"
#include<conio.h>

int main (int argc, char *argv[]) {

    char clientes[5][2][40]={{"",""},
                             {"",""},
                             {"",""},
                             {"",""},
                             {"",""}};    

    char habitaciones[9][3][40]={{"1","simple","Dan Carlton"},
                                  {"2","doble","Dan Carlton"},
                                  {"3","triple","Dan Carlton"},
                                  {"4","simple","Swissotel"},
                                  {"5","doble","Swissotel"},
                                  {"6","triple","Swissotel"},
                                  {"7","simple","Sheraton"},
                                  {"8","doble","Sheraton"},
                                  {"9","triple","Sheraton"}};

    double precios[9]={90,120,160,65,100,140,85,110,150};

    int reservas[10][4]={{-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0},
                         {-1,-1,-1,0}};
                         
    bool reservaRealizada=false, reservaPagada=false;
    int lineas=0;//contadores
    char l;
    FILE *fReservas, *fClientes, *lectura, *temporal;
    //crearArchivos(fReservas,fClientes);
    fReservas=fopen("reservas.txt","a+");
    if (fReservas==NULL){
        fReservas=fopen("reservas.txt","w");
        fclose(fReservas);
        fReservas=fopen("reservas.txt","a+");
    } else{
        //printf("CORRECTO\n");
        lectura=fopen("reservas.txt","r");
        if (lectura!=NULL)
        {
            while ((l=fgetc(lectura))!=EOF)
            {
                //printf("CORRECTO\n");
                //printf("%c\n",l);
                if (l=='\n')
                {
                    lineas++;
                    //printf("LINEAS: %d\n",lineas);                    
                }
            }
            /*if (lineas>=1)
                {
                    lineas++;
                }*/              
            //printf("??????");
            //getch();
            fclose(lectura);
            //printf("LINEAS: %d\n",lineas);  
        }
        lectura=fopen("reservas.txt","r");
        for (int i = 0; i < lineas; i++)
        {
            //for (int j = 0; j < 4; i++)
            //{
                fscanf(lectura,"%d %d %d %d",&reservas[i][0],&reservas[i][1],&reservas[i][2],&reservas[i][3]);
            //}
        }
        fclose(lectura);
    }
    //fprintf(fReservas,"\n");
    fClientes=fopen("clientes.txt","a+");
    if (fClientes==NULL){
        fClientes=fopen("clientes.txt","w");
        fclose(fClientes);
        fClientes=fopen("clientes.txt","a+");
    } else{
        //fprintf(fClientes,"\n");
        lectura=fopen("clientes.txt","r");
        if (lectura!=NULL)
        {
            for (int i = 0; i < lineas; i++)
            {
                fscanf(lectura,"%s %s",clientes[i][0],clientes[i][1]);
            }    
        }
        
        
    }

    int opcion,numHabitacion=-1,numReserva=-1,numClientes=lineas, r=lineas, c=lineas;

    do
    {   //printf("%d\n",lineas);
        printf("Escoja una opcion:\n1.Buscar Habitacion\n2.Realizar reserva\n3.Ver reservas\n4.Pagar Reserva\n>>");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            printf("1.Por tamano\n2.Por Hotel\n>>");
            scanf("%d",&opcion);
            switch (opcion)
            {
            case 1:
                buscarPorTamano(&numHabitacion,habitaciones,precios);
                break;
            case 2:
                buscarHotel(&numHabitacion,habitaciones,precios);      
            default:
                break;
            }
            break;
        case 2:
            realizarReserva(numHabitacion,habitaciones,clientes,reservas,&numClientes,&reservaRealizada);
            if (reservaRealizada)
            {
                fprintf(fReservas,"%d %d %d %d\n",reservas[r][0],reservas[r][1],reservas[r][2],reservas[r][3]);
                //printf("%s %s\n",clientes[c][0],clientes[c][1]);
                fprintf(fClientes,"%s %s\n",clientes[c][0],clientes[c][1]);
                r++;
                c++;
                reservaRealizada=false;
            }
            break;
        case 3:
            buscarReservaPorCedula(&numReserva,reservas);
            imprimirReserva(&numReserva,reservas,habitaciones,precios);
            break;
        case 4:
            buscarReservaPorCedula(&numReserva,reservas);
            pagarReserva(&numReserva,reservas,habitaciones,precios,&reservaPagada);
            if(reservaPagada){
                //modificar reservas
                temporal=fopen("temporal.txt","w");
                int i=0;
                while (reservas[i][0]!=-1)
                {
                    fprintf(temporal,"%d %d %d %d\n",reservas[i][0],reservas[i][1],reservas[i][2],reservas[i][3]);
                    i++;
                }
            fclose(fReservas);
            fclose(temporal);
            if(remove("reservas.txt")==0){//printf("Eliminado");}
            }
            if(rename("temporal.txt","reservas.txt")==0){//printf("Renombrado");}
            }
            fReservas=fopen("reservas.txt","a+");

            }

            break;
        default:
            break;
        }
        printf("Desea continuar?\n1: Continuar\t2: Salir\n");
        scanf("%d",&opcion);
    } while (opcion==1);
    
    fclose(fReservas);
    fclose(fClientes);
    return 0;
}