#ifndef NOMBRES_H_INCLUDED
#define NOMBRES_H_INCLUDED

/*****************définition de la structure*********************/
typedef struct number_struct{
    double current;//élément actuel
    struct number_struct *next;//pointeur sur l'element suivant
}*number_struct, cell;


/***************déclaration des fonctions(prototypes)***********/
static cell *createCell(double data); //création d'une cellule

number_struct build();//construire et initialiser la liste

void showList(number_struct list);//afficher les éléments de la liste

int getListSize(number_struct list);//obtenir la taille de la liste

void addNumber();//afficher le menu d'ajout

void suppr();//afficher le menu de suppression

//Fonctions d'ajout
number_struct addAtHead(double newElement, number_struct list);//ajout en tête de liste

number_struct addAtEnd(double newElement, number_struct list);//ajout en fin de liste

number_struct addAtPosition(double newElement, int position, number_struct list);//ajout à une position

//Fonctions de suppression
number_struct supprAtHead(double newElement, number_struct list);//supprimer en tête de liste

number_struct supprAtEnd(double newElement, number_struct list);//supprimer en fin de liste

number_struct supprAtPosition(double newElement, int position, number_struct list);//supprimer à une position

int findNumber(double number, number_struct list);//recherche d'un élément

number_struct sortList(number_struct list);//trier une liste(ordre croissant)

number_struct addInSortList(double newElement, number_struct list);//ajout dans la liste triée

number_struct deleteSameNumber(number_struct list);//suppression des doublons

#endif
