#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, tag = 0,i;
    char msg[20];
    MPI_Status status;

    //Iniciando entorno MPI
    MPI_Init(&argc, &argv);

    // Obtener el nivel del proceso
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Obtener el numero de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Obtener el nombre del proceso
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

	for(i=1;i< 5;i++){
	if (rank == 0){
        strcpy(msg, "Hola ");
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, (i),tag, MPI_COMM_WORLD);
	
    	}else if (rank == i){
 
        //printf("Antes de recibir: %s\n", mensage);
        MPI_Recv(msg , 20 , MPI_CHAR , 0 , tag ,MPI_COMM_WORLD , &status);
        printf("Mensaje recibido: %s, %s procesador\n",msg, processor_name);
    
        }
    }
	
    //cerrar entorno MPI
    MPI_Finalize();
}
