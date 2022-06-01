/*

-> Dependências: sudo apt install gcc -y

-> Execução: gcc trabalho.c -o trabalho
->           ./trabalho

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    //system("cd /proc && ls -d *[1-9]*");
    
    //verificar se existe esse processo e matar
    printf("Digite o número o pid do processo: ");
    scanf("%s", processo);
    //printf("%s\n", processo);
    //pid = atoi(processo)
    sprintf(cmd1, "cd /proc && ls -d %s > /home/tiago.souza/pid.txt", processo);
    system(cmd1);
    
    arquivo_pid = fopen("/home/tiago.souza/pid.txt", "r");
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

/*void restart_tomcat(){

    char processo[10];    
    FILE *arquivo_pid;
    char num_processo;
    int pid;
    int i = 0;

    system("clear");
        
    system("ps -aux | grep tomcat | grep -v grep > /home/pid_tomcat.txt");

    arquivo_pid = fopen("/home/pid_tomcat.txt", "r");
    if (arquivo_pid == NULL){
        printf("Erro, não foi possível abrir o arquivo. \n");
    }else{
        while((num_processo=fgetc(arquivo_pid)) != EOF){ //EOF equivale a -1, aponta para o fim do arquivo, não terá mais nada para ler
            processo[i] = num_processo;
            i++;
        }
    fclose(arquivo_pid);
    }

    pid = atoi(processo);

    printf("pid do tomcat = %d \n", pid);

    system("/home/tomcat/bin/catalina.sh stop");

    system("pkill -F /home/pid_tomcat.txt"); //o parâmetro -F especifica um arquivo com os pids

    system("/home/tomcat/bin/catalina.sh start");

    printf("Feito! Aplicação reiniciada com sucesso \n");

    system("tail -f /home/tomcat/logs/catalina.out");
    
};

*/

int main(){

    //restart_tomcat();

    processos();

    return EXIT_SUCCESS;
    
};


    //Abaixo foram os testes

    //pid = system("pidof htop");

    //system("ps -aux | grep htop | grep -v grep");

    //system("pgrep -l htop");

    //pid = system("pgrep -f htop");
 
    /*system("ps -aux | grep htop | grep -v grep"); O segundo comando usa a -vopção de inverter o sentido 
    de correspondência, para selecionar linhas não correspondentes.*/
    
    /*A forma debaixo tb dá certo
    system("ps -aux | grep '[h]top' |"); Ele diz para encontrar o caractere 'p' seguido por 'erl', 
    ou seja, a expressão '[p]erl' corresponde apenas a 'perl' e não a '[p]erl', que é como o próprio comando 
    grep agora é mostrado na lista de processos.*/

    /*system("pidof htop  > /home/pid_tomcat.txt"); como o tomcat não tem nome de aplicação, temo que utilizar uma
    opcao que nos traga o caminho da aplicação no filtro*/