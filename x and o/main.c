#include <stdio.h>
#include <stdlib.h>
#include "../library/cs50/cs50.h"
#include <conio.h>
#include <string.h>

//la securiter
void Password()
{

    string password = "11032004";
    string p;
    int i=0;
    Debut:
        p=get_string("\t\t\t\tsaisir le mode passe ou tapper (9+enter) pour exit : ");
    if (strcmp(p, password) == 0)
    {
        printf("\t\t\t\t\t        Mot de passe correct.\n");
        printf("\t\t\t\t\t     tapper (enter) to continue .");
        getch();
        system("cls");
    }else if(strcmp(p,"9") == 0)
    {
        exit(1);
    }
    else
    {
        i++;
        printf("\t\t\t\t\tErreur,il vous reste %d tentatives.\n",3-i);
        if(i<3)
        {
            goto Debut;
        }else
        {
        exit(0);
        }
    }
}

//definition :
typedef struct {
string nom[2];
char outil[2];
}players;
players joueur;
char choie_play;
int x,y;
int conteur=0;
bool role =0;
int win=-1;
char p[7][10];

void play_with_robot()
{

}

void int_game()
{
    char default_values[7][10] = {
        {'3', ' ',' ','|', ' ', '|', ' ', '|', ' '},
        {' ', ' ',' ','|', '-', '+', '-', '+', '-'},
        {'2', ' ',' ','|', ' ', '|', ' ', '|', ' '},
        {' ', ' ',' ','|', '-', '+', '-', '+', '-'},
        {'1', ' ',' ','|', ' ', '|', ' ', '|', ' '},
        {' ', ' ',' ','|', '_', '_', '_', '_', '_'},
        {'y', '/','x','|', '1', ' ', '2', ' ', '3'},
    };
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10; j++) {
            p[i][j] = default_values[i][j];
        }
    }
    conteur=0;
    role=0;
    win=-1;
}
//choie de jeux et choie de l'outil
void menu()
{

    printf("    ------ menu ------\n");
    repeter:
    printf("1. play with your friend\n");
    printf("2. play with robot(n'est pas disponible)\n");
    printf("9. exit\n\n");
    choie_play = get_char("choisir votre choie : ");
    system("cls");
    switch(choie_play)
    {
        case '1' :
            {
                joueur.nom[0] = get_string("donnez le nom de player 1 : ");
                do{
                joueur.outil[0] = get_char("Dans quel outil veux-tu jouer (x/o)?") ;
                }while(joueur.outil[0]!='o' && joueur.outil[0]!='x');
                joueur.nom[1] = get_string("donnez le nom de player 2 : ");
                if(joueur.outil[0]=='o')
                {
                    printf("%s devra jouer avec x\n",joueur.nom[1]);
                    joueur.outil[1]='x';
                }else
                {
                    printf("%s devra jouer avec o\n",joueur.nom[1]);
                    joueur.outil[1]='o';
                }
                getch();
                system("cls");
                break;
            }
        case '2' :
            {
                printf("Il n'est pas disponible maintenant .\n");
                break;}
        case '9' :
            {
                exit(1);
            }
        default :
            {
                printf("Choie incorect .\n");
                goto repeter;
            }
    }
}

//addapter les position donner par uttilisateur et celui dans le program
void addapter()
{
    if(x==1)
    {
        x=4;
    }else
    if(x==2)
    {
        x=6;
    }else if(x==3)
    {
        x=8;
    }
    if(y==1)
    {
        y=4;
    }else
    if(y==2)
    {
        y=2;
    }else if(y==3)
    {
        y=0;
    }
}


void choie_friend()
{
    do{
            if(!role)
            {
                printf("%s :\n",joueur.nom[0]);
            }else
            {
                printf("%s :\n",joueur.nom[1]);
            }
        do{
            x = get_int("donnez position x ou tapper(9+enter) pour exit : ");
            if(x==9)
            {
                exit(1);
            }
        }while(x>=4 || x<=0);
        do{
            y = get_int("donnez position y ou tapper(9+enter) pour exit : ");
            if(x==9)
            {
                exit(1);
            }
        }while(y>=4 || y<=0);


    addapter();

    if(p[y][x]==' ')
    {
        if(!role){
            p[y][x]=joueur.outil[0];
            role=1;
            conteur++;
        }else
        {
            p[y][x]=joueur.outil[1];
            role=0;
            conteur++;
        }
    }
    else
    {
        printf("imposible! repeter le choie.\n");
    }

    }while(p[y][x]==' ');
    system("cls");
}
void affichege_borde()
{
    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            printf("%c",p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
bool bord_fin()
{
    for(int i=1;i<=5;i+=2)
    {
        for(int j=4;j<=8;j+=2)
        {
            if(p[i][j]!=' ')
            {
                return 1;
            }
        }
    }
    return 0;
}
//x=4 6 8
//y=0 2 4
void player_win()
{
    if(conteur>=4)
    {
        if((p[0][4]==joueur.outil[0] && p[2][6]==joueur.outil[0] && p[4][8]==joueur.outil[0]) ||
           (p[4][4]==joueur.outil[0] && p[2][6]==joueur.outil[0] && p[0][8]==joueur.outil[0]))
           {
               win=0;
            }else
        if((p[0][4]==joueur.outil[1] && p[2][6]==joueur.outil[1] && p[4][8]==joueur.outil[1]) ||
           (p[4][4]==joueur.outil[1] && p[2][6]==joueur.outil[1] && p[0][8]==joueur.outil[1]))
           {
               win=1;
            }else
               {
               for(int i=0;i<=4;i+=2)
                {
                    if((p[i][4]==joueur.outil[0] && p[i][6]==joueur.outil[0] && p[i][8]==joueur.outil[0]))
                       {
                           win=0;
                       }
                    if((p[i][4]==joueur.outil[1] && p[i][6]==joueur.outil[1] && p[i][8]==joueur.outil[1]))
                       {
                           win=1;
                        }
                }
                for(int i=4;i<=8;i+=2)
                {
                    if((p[0][i]==joueur.outil[0] && p[2][i]==joueur.outil[0] && p[4][i]==joueur.outil[0]))
                       {
                           win=0;
                       }
                    if((p[0][i]==joueur.outil[1] && p[2][i]==joueur.outil[1] && p[4][i]==joueur.outil[1]))
                       {
                           win=1;
                        }
                }

            {

            }
        }
        if(win==0)
        {
            affichege_borde();
            printf("%s est win.\n",joueur.nom[0]);
            printf("press (enter) to continue : ");
            getch();
            system("cls");

        }else if(win==1)
        {
            affichege_borde();
            printf("%s est win.\n",joueur.nom[1]);
            printf("tapper (enter) to continue : ");
            getch();
            system("cls");
        }
    }
}
void play_with_friend()
{
    rejouer:
    int_game();
    do{
        affichege_borde();
        choie_friend();
        player_win();
    }while(bord_fin() && win==-1);
    repeter:
    printf("1. Rejouer\n");
    printf("2. menu\n");
    printf("3. exit\n");
    int n = get_char("\ndonnez votre choie : ");
    switch(n)
    {
    case '1' :
        {
            system("cls");
            goto rejouer;
        }
    case '2' :
        {
            system("cls");
            menu();
            goto rejouer;
        }
    case '3' :
        {
            exit(1);
        }
    default :
        {
            printf("Choie incorect .\n");
            goto repeter;
        }
    }
}

void play_with_robo()
{

}

int main()
{

   Password();
    menu();
    switch(choie_play)
    {
    case '1' :
        {
            play_with_friend();
            break;
        }
    case '2' :
        {
            play_with_robot();
            break;
        }
    }
    getch();
    return 0;
}
