#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Les variables globales
char    name[20];
int     choix;
int     shovel = 0;
int     light = 0;

// Les utilitaires
void    type_text(char *texte);
void    clear_screen(void);
void    death(void);
// Les scènes
void    in_house_intro(void);
void    ext_house(void);
void    in_house(void);
void    deep_forest_left(void);
void    deep_forest_right(void);
void    ending(void);

void    type_text(char *texte)
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

void    clear_screen(void)
{
    printf("\033[H\033[J");
}

void    death(void)
{
    clear_screen();
    type_text("Vous etes mort\n");
    type_text("Le jeu recommence dans 5 secondes\n");
    sleep(5);
    clear_screen();
    in_house_intro();
}

void    ext_house(void)
{
    type_text("Ok. Il va falloir bouger. Qu'est-ce que tu comptes faire ?\n");
    if (light == 1)
    {
        type_text("1 = Allumer la lampe\n2 = Avancer a l'aveugle\n");
        scanf("%d", &choix);
        if (choix == 1)
        {
            choix = 0;
            type_text("Tu allumes la lampe. Elle rayonne faiblement a travers la foret dense.\n");
            type_text("Tu avances entre les arbres. Quelle route vas-tu prendre ?\n");
            type_text("1 = gauche\n2 = droite\n");
            scanf("%d", &choix);
            if (choix == 1)
            {
                choix = 0;
                type_text("Tu t'enfonces dans les bois par la gauche\n");
                deep_forest_left();
            }
            else
            {
                choix = 0;
                type_text("Tu t'enfonces dans les bois par la droite\n");
                deep_forest_right();
            }
        }
        else
        {
            choix = 0;
            type_text("Il s'avere que ");
            type_text(name);
            type_text(" avait manifestement envie d'en finir...\n");
            type_text("Ou il est tres con\n");
            sleep(2);
            death();
        }
    }
    else
    {
        type_text("1 = S'aventurer dans les bois\n2 = Retourner dans la maison\n");
        scanf("%d", &choix);
        if (choix == 1)
        {
            type_text("Tu t'aventures dans les bois... Tu n'y vois absolument rien.\n");
            sleep(3);
            type_text("Un bruit. Tu leves les yeux.\n");
            sleep(2);
            type_text("Elle te regarde.\n");
            sleep(3);
            death();
        }
        if (choix == 2)
        {
            type_text("Tu retournes dans la maison\n");
            in_house();
        }
    }
}

void    in_house_intro(void)
{
    type_text("Une sensation etrange te parcourt. Tu emerges d'un coma qui semble\n");
    type_text("avoir dure des annees...\n");
    sleep(2);
    type_text("Tu ouvres les yeux. Rien, autour de toi, ne t'est familier.\n");
    type_text("Une cabane de bois. Deux ouvertures, seulement :\n");
    type_text("une fenetre a moitie brisee, et la porte, grande ouverte.\n");
    type_text("Qu'est-ce qui a bien pu se passer ici ?\n");
    type_text("1 = Sortir\n2 = Regarder a l'interieur de la maison\n");
    scanf("%d", &choix);

    if (choix == 1)
    {
        type_text("Tu sors de la maison.\n");
        sleep(2);
        type_text("\n");
        type_text("Tu regardes autour de toi. Rien que des arbres.\n");
        type_text("Des pins, surtout. Rien, ici, ne te dit quoi que ce soit...\n");
        type_text("En fait, tu ne te souviens de presque rien.\n");
        type_text("A part ton prenom : ");
        type_text(name);
        type_text("\n");
        sleep(2);
        ext_house();
    }
    else
    {
        type_text("Tu restes fouiller la cabane.\n");
        sleep(2);
        type_text("L'endroit est particulierement delabre.\n");
        type_text("Tu ne vois qu'une vieille armoire et un sommier sans matelas.\n");
        type_text("1 = Fouiller l'armoire\n2 = Investiguer le sommier\n");
        scanf("%d", &choix);

        if (choix == 1)
        {
            choix = 0;
            type_text("L'armoire est presque vide, a part une pelle\n");
            type_text("et quelques outils de jardinage.\n");
            sleep(2);
            shovel = 1;
            type_text("+1 pelle\n");
            sleep(2);
            in_house();
        } 
        else
        {
            choix = 0;
            type_text("Le sommier est completement casse. Parmi les planches brisees,\n");
            type_text("tu apercois une vieille lampe a huile.\n");
            sleep(2);
            light = 1;
            type_text("+1 lampe\n");
            sleep(2);
            in_house();
        }
    }
}

void    in_house(void)
{
    type_text("Tu es dans la maison\n");
    sleep(2);
    type_text("Il y a une armoire, un sommier vide, et la sortie\n");
    type_text("1 = Fouiller l'armoire\n2 = Inspecter le sommier\n3 = Sortir de la maison\n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        choix = 0;
        type_text("L'armoire est presque vide, a part une pelle\n");
        type_text("et quelques outils de jardinage.\n");
        sleep(2);
        shovel = 1;
        type_text("+1 pelle\n");
        sleep(2);
        in_house();
    }
    else if (choix == 2)
    {
        choix = 0;
        type_text("Le sommier est completement casse. Parmi les planches brisees,\n");
        type_text("tu apercois une vieille lampe a huile.\n");
        sleep(2);
        light = 1;
        type_text("+1 lampe\n");
        sleep(2);
        in_house();
    }
    else
    {
        ext_house();
    }
}

void    deep_forest_left(void)
{
    clear_screen();
    type_text("Tu t'enfonces au coeur de la foret. Ta lampe n'emet qu'une lueur fragile.\n");
    type_text("Tu ne distingues presque rien. Mais au loin, une autre lumiere.\n");
    type_text("Celle-ci est plus... pure.\n");
    sleep(3);
    type_text(name);
    sleep(3);
    type_text("\nTu te sens observe.\n");
    type_text("Et tu la vois.\n");
    sleep(1);
    type_text(name);
    type_text("1 = Utiliser la pelle\n2 = Fuir\n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        choix = 0;
        type_text("Elle est la, devant toi. Ses yeux livides percent ton ame.\n");
        type_text("Tes mains sont couvertes de terre, tes yeux rougis par la douleur.\n");
        type_text("La lumiere se pose sur toi. Tu baignes dans une clarte rouge.\n");
        ending();
    }
    else 
    {
        choix = 0;
        type_text("Tes jambes sont comme prises dans la glace. Tu n'arrives pas\n");
        type_text("a bouger.\n");
        type_text("1 = Utiliser pelle\n");
        scanf("%d", &choix);
        if (choix != 1)
        {
            sleep(3);
            type_text("Assume les consequences de tes actes\n");
            death();
        }
        else
        {
            type_text("Ton sang se mele a la terre et a son corps, tandis que tu brises\n");
            type_text("ce qu'il reste de toi.\n\n");
            sleep(2);
            type_text("Tu tombes. Enfin. Repose-toi.\n\n");
            sleep(2);
            type_text("Vous etes magnifique, sous ce clair de lune.\n");
            sleep(2);
            exit(0);
        }
    }
}

void    deep_forest_right(void)
{
    type_text("Tu apercois la lisiere de la foret.\n");
    sleep(2);
    type_text("Tu passes de l'autre cote. La douce lumiere d'un lever de soleil\n");
    sleep(2);
    type_text("t'eclaire alors que tu t'eloignes dans les collines.\n");
    type_text("1 = Oublier\n2 = Revenir\n");
    scanf("%d", &choix);
    if (choix == 1)
    {
        type_text("Quelques jours de marche plus tard, tu atteins les abords\n");
        type_text("d'une petite ville. Les habitants t'ignorent.\n");
        sleep(1);
        type_text("Comme si tu n'existais plus.\n");
        sleep(1);
        type_text(name);
        sleep(1);
        type_text("Øı Œª∫|‚ Í/*  */Ó/* */∑");
        death();
    }
    else
    {
        in_house();
    }
}

void    ending(void)
{
    type_text("Bien joué !! Je sais que le jeu est mal foutu et que l'histoire\n");
    type_text("a des enormes defauts mais faut pas m'en vouloir j'etais au college\n");
    type_text("Bref, Merci d'avoir jouer\n");
    sleep(3);
    type_text("Aussi oui le message cryptique a la fin du chemin de droite a un sens");
    exit(0);
}

int main(void)
{
    clear_screen();
    type_text("Bonjour, est ce que je pourrais avoir ton prenom s'il te plait ?\n");
    scanf("%19s", name);
    printf("\n");
    type_text("Parfait, ");
    type_text(name);
    type_text(", on va jouer a un jeu rapide que je fais parce que j'ai\n");
    type_text("le seum d'avoir rate mon concours pour une ecole de code.\n");
    printf("\n");
    sleep(1);
    type_text("C'est un petit jeu base sur un projet Scratch que j'avais fait au\n");
    type_text("college quand je me faisais chier en cours de SES\n");
    printf("\n");
    sleep(2);
    type_text("BON, on va commencer le tuto\n");
    type_text("On va faire simple : tout se joue avec ton clavier\n");
    type_text("Tu vas devoir faire des choix entre plusieurs options. VOILA\n");
    sleep(1);
    type_text("Tu as compris ");
    type_text(name);
    type_text(" ?\n");
    printf("1 = oui\n2 = non\n");
    scanf("%d", &choix);

    if (choix == 1)
        type_text("Bah parfait t'as compris !\n");
    else
    {
        type_text("Bon on va dire que tu as juste appuye sur le mauvais bouton...\n");
        sleep(1);
        type_text("Ou tu es juste con\n");
    } 
    sleep(1);
    type_text("On va commencer notre jolie petite aventure ");
    type_text(name);
    type_text("\n");
    type_text("Ca va etre marrant");
    sleep(3);
    clear_screen();
    sleep(3);
    in_house_intro();
    return (0);
}