#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initialisation(char tab[6][7])
{
int i;
int j;
printf("  0 1 2 3 4 5 6\n");
for(i=0;i<6;i++)
{
    printf("%d ",i);
	for(j=0;j<7;j++)
	{
		tab[i][j]='.';
		printf("%c ",tab[i][j]);
	}
	printf("\n");
}
}

void AffTab(char tab[6][7])
{
int i;
printf("  0 1 2 3 4 5 6\n");
for(i=0;i<6;i++)
{
    printf("%d ",i);
    printf("%c " "%c " "%c " "%c " "%c " "%c " "%c \n",tab[i][0],tab[i][1],tab[i][2],tab[i][3],tab[i][4],tab[i][5],tab[i][6]);
}
printf("Quelle colonne ? : \n");
}

int Victoire(char tab[6][7])
{
    int i=NULL;
    int j=NULL;
        for(i=0;i<6;i++)
        {
            for(j=0;j<7;j++)
            {
                if(tab[i][j]!='.')
                {
                if(tab[i][j]==tab[i+1][j] && tab[i+2][j]==tab[i+3][j] && tab[i+3][j]==tab[i][j] && tab[i][j]=='X')
                {
                    return 1;
                }
                else if(tab[i][j]==tab[i][j+1] && tab[i][j+2]==tab[i][j+3] && tab[i][j+3]==tab[i][j] && tab[i][j]=='X')
                {
                    return 1;
                }
                else if(tab[i][j]==tab[i+1][j+1] && tab[i+2][j+2]==tab[i+3][j+3] && tab[i+3][j+3]==tab[i][j] && tab[i][j]=='X')
                {
                    return 1;
                }

                if(tab[i][j]!='.')
                {
                if(tab[i][j]==tab[i+1][j] && tab[i+2][j]==tab[i+3][j] && tab[i+3][j]==tab[i][j] && tab[i][j]=='O')
                {
                    return 1;
                }
                else if(tab[i][j]==tab[i][j+1] && tab[i][j+2]==tab[i][j+3] && tab[i][j+3]==tab[i][j] && tab[i][j]=='O')
                {
                    return 1;
                }
                else if(tab[i][j]==tab[i+1][j+1] && tab[i+2][j+2]==tab[i+3][j+3] && tab[i+3][j+3]==tab[i][j] && tab[i][j]=='O')
                {
                    return 1;
                }
            }
        }
    }
}
}


void Jouer(char tab[6][7])
{
    int booleen=0;
    int i;
    int j;
    int t;
    int test=0;
    int compteur=0;
    int reponse=NULL;
    printf("Tapez 0 pour que le joueur 1 commence, tapez 1 pour que le joueur 2 commence : ");
    scanf("%d",&reponse);
    while(reponse<0 || reponse>1)
    {
        printf("Erreur de saisie, recommencez : \n");
        scanf("%d",&reponse);
    }
    while(booleen!=1)
    {
        while(reponse%2==0)
        {
            AffTab(tab);
            printf("Au tour du joueur 1 : ");
            scanf("%d",&j);
            while(j<0 || j>6)
            {
                printf("Colonne invalide, recommencez : \n");
                scanf("%d",&j);
            }
            if(tab[5][j]=='.')
            {
                tab[5][j]='X';
            }
            else
            {
                while(tab[5-compteur][j]!='.')
                {
                    compteur++;
                }
                tab[5-compteur][j]='X';
                compteur=0;
            }
            for(i=5;i<0;i--)
            {
                if(tab[i][j]!='.' && i<0)
                {
                    printf("Colonne remplie !\n");
                }
            }
            reponse++;
            booleen=Victoire(tab);
            if(booleen==1)
            {
                AffTab(tab);
                printf("Le joueur 1 a gagne ! \n");
            }
        }
        while(reponse%2==1 & booleen!=1)
        {
            AffTab(tab);
            printf("Au tour du joueur 2 : ");
            scanf("%d",&t);
            while(t<0 || t>6)
            {
            printf("Erreur de saisie, recommencez :\n");
            scanf("%d",&t);
            }
            if(tab[5][t]=='.')
            {
            tab[5][t]='O';
            }
            else
            {
                while(tab[5-test][t]!='.')
                {
                    test++;
                }
                tab[5-test][t]='O';
                test=0;
            }
        reponse++;
        booleen=Victoire(tab);
        if(booleen==1)
            {
                AffTab(tab);
                printf("Le joueur 2 a gagne ! \n");
            }
        }
    }
}

int main()
{
    srand(time(NULL));
	char plateau[6][7];
	Initialisation(plateau);
	Jouer(plateau);
    return 0;
}
