#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Variables

int choix;
char    name[20];
int state;

// Utilitaires
void    text(char *texte);

// Lieux

void    text(char *texte)
{
    int i = 0;

    while (texte[i] != '\0')
    {
        putchar(texte[i]);
        fflush(stdout);
        usleep(40000);
        i++;
    }
}

int main(void)
{
    text("WOW, encore un mini jeu ?? Mais comment fait-elle ?\n");
    sleep(2);
    text("Bon un peu de serieux, comment t'appeles-tu ?\n");
    scanf("%19s", name);
    text("Enchanté ! Moi c'est Satyne. Bon on va faire un petit tuto ok ");
    text(name);
    text(" ?\n");
    text("Pour faire simple, tu joues avec con clavier, tu dois séléctioné tes actions\n");
    text("1 = Compris\n2 = Hein ?\n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        choix = 0;
        text("Bien ! Alors on va pouvoir commencer, ah et aussi\n");
        text("Il y a un systeme d'état dans ce jeu la, amuse toi bien !");
        //first_zone(void);
    }
    else
    {
        choix = 0;
        text("Ah\n");
        sleep(2);
        text("Tu finiras bien par comprendre\n");
        //first_zone(void);
    }
}