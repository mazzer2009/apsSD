#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>
#include <sys/types.h>
#include <unistd.h>
//97 ao 122 usa só letras minúsculas
//65 ao 90 usa só letras maiúsculas
//48 ao 57 usa só numeros
#define COMECO_CHAR 48
#define FIM_CHAR 122
#define MAX_SENHA 20

void Forca_Bruta_Inteligente(char *pass, int rank, int range, int size);
void Verifica_Senha(char *forca, char *pass);

int main(int argc, char *argv[])
{
    int rank, size, total = FIM_CHAR - COMECO_CHAR;
    char senha[MAX_SENHA] = "124Mor";
    char *recv;
    int i = 1;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int range = total/(size -1);

    
    if(rank != 0){
printf("rank proc %d\n", rank);
        Forca_Bruta_Inteligente(senha, rank, range, size);
}
    else
    {
        MPI_Recv(&recv, MAX_SENHA, MPI_CHAR, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	//MPI_Abort(MPI_COMM_WORLD,1);
	MPI_Finalize();
}

    return 0;
}


void Forca_Bruta_Inteligente(char *pass, int rank, int range, int size)
{
    char forca[MAX_SENHA];
    int tam = strlen(pass);
    int i;
    for (i = 0; i < MAX_SENHA; i++)
        forca[i] = '\0';

    int com, fim;
    com = COMECO_CHAR + ((rank-1) * range);

    if(rank == size)
        fim = FIM_CHAR;
    else
        fim = COMECO_CHAR + (rank * range);

  

    for (forca[0] = com ; forca[0] <= fim; forca[0]++)
    {
        if (tam <= 1)
        {
            if (tam == 1)
                Verifica_Senha( forca, pass);
    
        }
        else
            for (forca[1] = COMECO_CHAR; forca[1] <= FIM_CHAR; forca[1]++)
            {
                if (tam <= 2)
                {
                    if (tam == 2)
                        Verifica_Senha( forca, pass);

                }
                else
                    for (forca[2] = COMECO_CHAR; forca[2] <= FIM_CHAR; forca[2]++)
                    {
                        if (tam <= 3)
                        {
                            if (tam == 3)
                                Verifica_Senha( forca, pass);
                        }
                        else
                            for (forca[3] = COMECO_CHAR; forca[3] <= FIM_CHAR; forca[3]++)
                            {
                                if (tam <= 4)
                                {
                                    if (tam == 4)
                                        Verifica_Senha( forca, pass);
                                }
                                else
                                    for (forca[4] = COMECO_CHAR; forca[4] <= FIM_CHAR; forca[4]++)
                                    {
                                        if (tam <= 5)
                                        {
                                            if (tam == 5)
                                                Verifica_Senha( forca, pass);
                                        }
                                        else
                                            for (forca[5] = COMECO_CHAR; forca[5] <= FIM_CHAR; forca[5]++)
                                            {
                                                if (tam <= 6)
                                                {
                                                    if (tam == 6)
                                                        Verifica_Senha( forca, pass);
                                                }
                                                else
                                                    for (forca[6] = COMECO_CHAR; forca[6] <= FIM_CHAR; forca[6]++)
                                                    {
                                                        if (tam <= 7)
                                                        {
                                                            if (tam == 7)
                                                                Verifica_Senha( forca, pass);
                                                        }
                                                        else
                                                            for (forca[7] = COMECO_CHAR; forca[7] <= FIM_CHAR; forca[7]++)
                                                            {
                                                                if (tam <= 8)
                                                                {
                                                                    if (tam == 8)
                                                                        Verifica_Senha( forca, pass);
                                                                }
                                                                else
                                                                    for (forca[8] = COMECO_CHAR; forca[8] <= FIM_CHAR; forca[8]++)
                                                                    {
                                                                        if (tam <= 9)
                                                                        {
                                                                            if (tam == 9)
                                                                                Verifica_Senha( forca, pass);
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("\nSenha muito grande! > 9");
                                                                            exit(1);
                                                                        }
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                   }
            }
    }
}

void Verifica_Senha(char *forca, char *pass)
{
	int rank;
    if ( !strcmp(forca, pass) )
    {	
	
	printf("A senha correta: %s\n\n\n",forca);
        MPI_Send(&forca,strlen(forca),MPI_CHAR,0,0,MPI_COMM_WORLD);
        exit(1);
    }
    //else printf("%s",forca);
    //printf("\n%s erou", forca);

}
