#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void Initialisation(char tab[3][3]){
int i;
int j;
printf("  0 1 2\n");
for(i=0;i<3;i++)
{
    printf("%d ",i);
	for(j=0;j<3;j++)
	{
		tab[i][j]='.';
		printf("%c ",tab[i][j]);
	}
	printf("\n");
}
}
void AffTab(char tab[3][3]){
int i;
printf("  0 1 2\n");
for(i=0;i<3;i++)
{
    printf("%d ",i);
    printf("%c " "%c " "%c \n",tab[i][0],tab[i][1],tab[i][2]);
}
}

int Victoire(char tab[3][3])
{
        if(tab[0][0]==tab[1][0] && tab[2][0]==tab[1][0] && tab[0][0]!='.')
        {
            return 1;
        }
        else if(tab[0][0]==tab[0][1] && tab[0][2]==tab[0][0] && tab[0][0]!='.')
        {
            return 1;
        }
        else if(tab[0][0]==tab[1][1] && tab[2][2]==tab[0][0] && tab[0][0]!='.' )
        {
            return 1;
        }
        else if(tab[1][0]==tab[1][1] && tab[1][2]==tab[1][0] && tab[1][0]!='.')
        {
            return 1;
        }
        else if(tab[2][0]==tab[2][1] && tab[2][2]==tab[2][0] && tab[2][0]!='.')
        {
            return 1;
        }
        else if(tab[0][1]==tab[1][1] && tab[2][1]==tab[0][1] && tab[0][1]!='.')
        {
            return 1;
        }
        else if(tab[0][2]==tab[1][1] && tab[2][0]==tab[0][2] && tab[0][2]!='.')
        {
            return 1;
        }
        else if(tab[0][2]==tab[1][2] && tab[2][2]==tab[0][2] && tab[0][2]!='.')
        {
            return 1;
        }
}

int Jouer(char tab[3][3])
{
int i;
int j;
int tour=0;
int reponse=0;
int booleen=0;
int victory=NULL;
int test=0;
printf("Voulez-vous commencer? Tapez 0 pour oui, 1 pour non: ");
scanf("%d",&reponse);
while(booleen!=1)
{
    while(reponse%2==0)
    {
        tour++;
        test=test+1;
        Sleep(250);
        printf("C'est a X de jouer\n");
        printf("Choisis ta ligne: ");
        scanf("%d",&i);
        printf("Choisis ta colonne: ");
        scanf("%d",&j);
        while(i<0 || i>2 || j<0 || j>2 )
            {
            printf("Erreur de saisie, les nombres sont trop grands recommencez !\n");
            printf("Choisis ta ligne: ");
            scanf("%d",&i);
            printf("Choisis ta colonne: ");
            scanf("%d",&j);
            }
        AffTab(tab);
        if(tab[i][j]!='.')
        {
         printf("Espace deja occupe !\n");
            continue;
        }
        tab[i][j]='X';
        system("cls");
		reponse++;
		if(test>3)
        {
            booleen=Victoire(tab);
            if(booleen==1)
            {
                AffTab(tab);
                printf("Tu es le gagnant !\n");
            }
        }
    }
    printf("Tour : %d\n",tour);
    while(reponse%2==1 & booleen!=1) //Booleen!=1 car sinon ça m'affiche pas le bon gagnant ( car test n'est pas encore >3 )
        {
            Sleep(250);
            srand(time(NULL));
            i=rand()%3;
            j=rand()%3;
            if(tab[i][j]!='.')
            {
            continue;
            }
                tab[i][j]='O';
                printf("C'est au bot de jouer\n");
                tour++;
                AffTab(tab);
                printf("Tour : %d\n",tour);
                test=test+1;
                reponse++;
            if(test>3)
            {
                booleen=Victoire(tab);
                if(booleen==1 & tab[0][0]!='.')
                {
                    system("cls");
                    AffTab(tab);
                    printf("Tu as perdu !\n");
                    printf("Tour : %d\n",tour);
                }
            }
        }
            if(tour==9 & booleen!=1)
            {
                booleen=1;
                printf("Partie nulle !\n");
            }
}
}

int main()
{
    int reponse2=NULL;
	char plateau[3][3];
	Initialisation(plateau);
	Jouer(plateau);
	printf("Voulez-vous recommencer? Tapez 0 pour oui, 1 pour non : \n");
	scanf("%d",&reponse2);
	while(reponse2<0 || reponse2>1)
    {
        printf("Voulez-vous recommencer? Tapez 0 pour oui, 1 pour non : \n");
        scanf("%d",&reponse2);
    }
	{
	    if(reponse2==0)
        main();
        else
        exit(0);
	}
    return 0;
}

