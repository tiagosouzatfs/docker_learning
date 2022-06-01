
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    
    printf("htop vai morrer em outro terminal...vou chamar o htop e o terminal! \n");

    system("gnome-terminal"); //Abrindo outro terminal

    system("htop & > /dev/pts/2");

    for (int j=5; j>0 ; j--){
        printf("%d\n", j);
        sleep(1);
    }

    system("echo htop vai morrer... > /dev/pts/2");

    system("pkill htop > /dev/pts/2"); //escrevendo os comandos no outro terminal, para ver o outro terminal digite o comando tty

    system("echo Feito! htop morreu :/ > /dev/pts/2");

    printf("Feito \n");

    return EXIT_SUCCESS;
    
};