void buscarPorTamano(int *numHabitacion,char habitaciones[][3][40],double precios[]);
void buscarHotel(int *numHabitacion,char habitaciones[][3][40],double precios[]);
void realizarReserva(int numHabitacion,char habitaciones[][3][40],char clientes[][2][40],int reservas[][4],int *numClientes);
void buscarReservaPorCedula(int *numReserva,int reservas[][4]);
void imprimirReserva(int *numReserva,int reservas[][4],char habitaciones[][3][40],double precios[]);
void pagarReserva(int *numReserva,int reservas[][4],char habitaciones[][3][40],double precios[]);