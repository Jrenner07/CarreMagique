#include <stdio.h>
#include <stdlib.h>
#define TAILLE 7

typedef struct Coord{

    int x;      //Vertical
    int y;      //Horizontal

}Coord;

void init(int tab[][TAILLE]);     // Initialisation de toutes les valeurs du tableau a 0
void affiche(int tab[][TAILLE]);  //Affiche le carré
void remplissage(int tab[][TAILLE], Coord mCoord); // Appel les fonctions up / right / left pour remplire le tableau
int up (Coord mCoord); // Fonction poour deplacer le coordonne X
int Right (Coord mCoord);   // Fonction poour deplacer le coordonne y vers la droite
int Left(Coord mCoord); // Fonction poour deplacer le coordonne y vers la gauche



int main()
{
/*
BUT : Afficher un carre magique dont la taille est saisie en constante
Entree : Rien
Sortie : L'affichage du carre magique
*/


    int tab[TAILLE][TAILLE];    // Tableau 2 dim

    Coord mCoord;


    init(tab);  // Initialisation de toutes les valeurs du tableau a 0

    tab[TAILLE/2-1][TAILLE/2] = 1;      //Placement du premier chiffre sur la case supérieure du centre
    mCoord.x = TAILLE/2-1;
    mCoord.y = TAILLE/2;        //Positionnement des Coordonnés

    remplissage(tab, mCoord);   // Appel de remplissage
    affiche(tab);   //Affiche le carré


    return 0;
}


void init(int tab[][TAILLE]){       // Initialisation de toutes les valeurs du tableau a 0
/*
BUT : Initialiser les valeurs du tableau a 0
Entree : Le tableau tab
Sortie : Valeurs du tableau a 0
*/



    int i = 0;
    int j = 0;

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            tab[i][j] = 0;
        }
    }
}


void remplissage(int tab[][TAILLE], Coord mCoord){  // Appel les fonctions up / right / left pour remplire le tableau

/*
BUT : Remplire le tableau avec les valeurs du carre magique
Entree : Le tableau et notre variable mCoord de type Coord
Sortie : Le tableau assigner avec les valeurs du carre magique
*/


    int fin =0;     //Booleen
    int compteur = 2;   //Compteur qui permet de connaitre quel nombre seras placer

    while (fin != 1){

        mCoord.x = up(mCoord);
        mCoord.y = Right(mCoord);

        if(tab[mCoord.x][mCoord.y] == 0){   // Si la valeur des coordonne x et y sont egals a 0 dans la tableau alors
            tab[mCoord.x][mCoord.y] = compteur; // on entre le chiffre compteur
            compteur++;
        } else {
            mCoord.x = up(mCoord);  // Si la valeur des coordonne x et y ne sont pas egals a 0 dans la tableau alors
            mCoord.y = Left(mCoord);    // on appel up et left

            if(tab[mCoord.x][mCoord.y] == 0){   // Si la valeur des coordonne x et y sont egals a 0 dans la tableau alors
                tab[mCoord.x][mCoord.y] = compteur; // on entre le chiffre compteur
                compteur++;
            }
        }

        if(compteur == TAILLE*TAILLE+1){    // Si le compteur est egals a taille * taille +1 alors on sort de la boucle While
            fin = 1;
        }
    }
}

void affiche(int tab[][TAILLE]){    //Affichage du tableau

/*
BUT : Afficher le tableau ( le carre magique )
Entree : Le tableau
Sortie : Le carre magiqu avec une mis en page
*/

    int i = 0;
    int j = 0;

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){      //Boucle d'affichage du tableau
                printf("  %i  |",tab[i][j]);
        }
    printf("\n");
    printf("________________________________________________");        //Petite mise en page
    printf("\n\n");
    }
}

int up(Coord mCoord){   // Fonction poour deplacer le coordonne X

/*
BUT : Deplacer la coordonne x vers le haut
Entree : mCoord de type Coord
Sortie : mCoord.x assigner avec la valeur
*/

    if(mCoord.x-1 >= 0){  //Si la coordonne -1 est dans le tableau on l'assigne
        return mCoord.x-1;
    } else return TAILLE-1; //Si la coordonne -1 sort de la taille du tableau on l'assigne a Taille-1
}

int Right(Coord mCoord){    // Fonction poour deplacer le coordonne y vers la droite

/*
BUT : Deplacer la coordonne y vers la droite
Entree : mCoord de type Coord
Sortie : mCoord.y assigner avec la valeur
*/

    if(mCoord.y+1 <=TAILLE-1){
        return mCoord.y+1;  //Si la coordonne +1 est dans le tableau on l'assigne
    }else return 0; //Si la coordonne +1 sort de la taille du tableau on l'assigne a 0
}

int Left(Coord mCoord){      // Fonction poour deplacer le coordonne y vers la gauche

/*
BUT : Deplacer la coordonne y vers la gauche
Entree : mCoord de type Coord
Sortie : mCoord.y assigner avec la valeur
*/

    return mCoord.y-1;      //On assigne -1 a la coordonner
}
