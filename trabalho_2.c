/*
-> Dependências: sudo apt install gcc -y
-> Execução: gcc trabalho_2.c -o trabalho_2
->           ./trabalho_2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <math.h>
#include <sys/resource.h>
#include <sched.h>
#include <sys/time.h>

void criar_processo()
{
    pid_t pid;

    pid = fork();

    switch(pid)
    {
        case -1:
            exit(-1);
        case 0:
            printf("Processo nº %d criado\n", getpid());
    }
};

void matar_processo()
{
    int pid;

    printf("Digite o PID do processo que deve morrer: ");
    scanf("%d", &pid);

    kill(pid, SIGKILL);
    printf("Processo finalizado!!!\n");
};

void parar_processo()
{
    int pid;

    printf("Digite o PID do processo que deve parar: ");
    scanf("%d", &pid);

    kill(pid, SIGSTOP);
    printf("Processo parado!!!\n");
};

void continuar_processo()
{
    int pid;

    printf("Digite o PID do processo que deve continuar: ");
    scanf("%d", &pid);

    kill(pid, SIGCONT);
    printf("Processo continuado!!!\n");
};

void buscar_processo_pelo_nome()
{
    char pid_nome[100];
    char cmd[200];

    printf("Digite o nome do processo: ");
    scanf("%s", &pid_nome);

    sprintf(cmd, "ps -aux | grep %s", pid_nome);
    system(cmd);
};

void buscar_processo_pelo_pid()
{
    int pid;
    char cmd[200];

    printf("Digite o nome do processo: ");
    scanf("%d", &pid);

    sprintf(cmd, "ps -aux | grep %d", pid);
    system(cmd);
};

void listar_todos_os_processos()
{
    //filtro pedido pelo professor
    system("ps -eo pcpu,pid,ppid,pri,s");

    //todos os processos existentes na máquina
    system("cd /proc && ls -d *[1-9]*");
    //ou
    system("ps -aux");
};

void processo_escolha_cpu()
{
    int pid, cpu, ncpu;
    cpu_set_t mask;

    printf("Este computador possui %d CPU's, começando em 0\n", ncpu);
    printf("Digite o pid do processo para alocação de CPU: ");
    scanf("%d", pid);
    printf("Digite em qual CPU o processo de pid %d deverá executar: ", pid);
    scanf("%d", cpu);

    CPU_SET(cpu, &mask);

    int result = sched_setaffinity(pid, sizeo(mask), &mask);
};
    
void muda_prioridade_cpu()
{
    int pid, prioridade;

    printf("Digite o pid do processo que será alterada a prioridade: ");
    scanf("%d", pid);
    printf("Digite uma prioridade para alterar a do processo: ",pid);
    scanf("%d", prioridade);

    setpriority(PRIO_PROCESS, pid, prioridade);

    //também dá certo com o fator nice()

};

int main(){

    int op;

    printf("Escolha uma opção abaixo\nCriar Processo -> 1\nMatar Processo -> 2\nParar Processo -> 3\nContinuar Processo -> 4
    \nBuscar Processo pelo Nome -> 5\nBuscar Processo pelo PID -> 6\nListar Todos os Processos -> 7\nProcesso CPU -> 8\n
    Mudar Prioridade da CPU -> 9\n");

    printf("Digite uma opção válida: ");
    scanf("%d", op);

    if (op == 1) {
        criar_processo();
    }
    if (op == 2) {
        matar_processo();
    }
    if (op == 3) {
        parar_processo();
    }
    if (op == 4) {
        continuar_processo();
    }
    if (op == 5) {
        buscar_processo_pelo_nome();
    }
    if (op == 6) {
        buscar_processo_pelo_pid();
    }
    if (op == 7) {
        listar_todos_os_processos();
    }
    if (op == 8) {
        processo_escolha_cpu();
    }
    if (op == 9) {
        muda_prioridade_cpu();
    }

    /*a função abaixo foi uma abordagem diferente que eu fiz, 
    mas foi apenas para conhecimento*/
    //processos();

    return EXIT_SUCCESS;
    
};

/*
void processos()
{
    char processo[6];
    char pid[6];
    char cmd[1024];
    char cmd1[512];
    FILE *arquivo_pid;
    char num_processo;
    int i = 0;
    //int pid;
    //listar todos os processos da máquina
    system("cd /proc && ls -d *[1-9]*");
    
    //verificar se existe esse processo e matar
    printf("Digite o número o pid do processo: ");
    scanf("%s", processo);
    //printf("%s\n", processo);
    //pid = atoi(processo)
    sprintf(cmd1, "cd /proc && ls -d %s > /home/tiago/pid.txt", processo);
    system(cmd1);
    
    arquivo_pid = fopen("/home/tiago/pid.txt", "r");
    if (arquivo_pid == NULL){
        printf("Erro, não foi possível abrir o arquivo.\n");
    }else{
        while((num_processo=fgetc(arquivo_pid)) != EOF){ //EOF equivale a -1, aponta para o fim do arquivo, não terá mais nada para ler
            pid[i] = num_processo;
            i++;
        }
    fclose(arquivo_pid);
    }
    if (pid == processo)
    {
        //sprintf(cmd, "ps -aux | grep %s | grep -v grep && kill -9 %s\n", processo, processo);
        sprintf(cmd, "kill -9 %s\n", processo);
        system(cmd);
        printf("Processo terminado\n");
    }else{
        printf("O número do pid não existe\n");
    }
}; 
*/
