/*Automatização dos comandos start
e stop do serviço tomcat do ponto eletrônico

-> Tudo deve ser executado como root 

-> Dependências: sudo apt install gcc -y

-> Execução: gcc automatizacao_ponto.c -o automatizacao_ponto
->           ./automatizaca_ponto

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void restart_tomcat(){

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

int main(){

    restart_tomcat();

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