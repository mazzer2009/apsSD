Aps Sistemas Distribuidos

Para a execução do código:
-Ter MPI Instalado

Compilação:
mpicc forcas.c -o "arquivo"

Executando:
mpiexec "arquivo"

executando com vários processos: mpiexec -np X "arquivo";
onde X é o numero de processos desejados

Executando em vários hosts: mpiexec -host "ip1,ip2,...ipn" -np X "arquivo"

