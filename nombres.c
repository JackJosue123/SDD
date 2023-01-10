#include <stdio.h>
#include <stdlib.h>
#include "nombres.h"

/*-Créer une cellule pour notre liste chaînée-*/
static cell *createCell(double data){
    cell *cell = malloc(sizeof(cell));
    if(!cell){
        return NULL;
    }
    cell->current = data;
    cell->next = NULL;
    return cell;
}

/*--Voir si une liste est vide ou pas--*/
int isEmptyList(number_struct L){
    return L == NULL;
}

/*--construire et initialiser la liste--*/
number_struct build(){
    return NULL;
}

/*--afficher les éléments de la liste--*/
void showList(number_struct list){
    if(list == NULL){
        printf("\n\tLa liste est vide. Rien à afficher !!!\n");
    }else{
        printf("\n");
        while(!isEmptyList(list)){
            printf("| %.2lf | ==> ", list->current);
            list = list->next;
            if(list == NULL){
                printf("NULL");
            }
        }
        printf("\n");
    }
}

/*--ajout en tête de liste--*/
number_struct addAtHead(double newElement, number_struct list){
    cell *cell = createCell(newElement);
    cell->next = list;
    return cell;
}

/*--ajout en fin de liste--*/
number_struct addAtEnd(double newElement, number_struct list){

}

/*--ajout à une position donnée--*/
number_struct addAtPosition(double newElement, int position, number_struct list){
    if (position < 0){
        printf("La position doit être supérieure ou égale à 0.\n");
        return;
    }
    cell *cell = createCell(newElement);
    if (position == 0 || isEmptyList(list)) {
        cell->next = list;
        return cell;
    }
    int i = 0;
    number_struct *prec = list;
    number_struct *curr = list;
    while (i < position) {
        i++;
        prec = curr;
        //curr = curr->next;
    }
    //prec->next = cell;
    //cell->next = curr;
    return list;
}

/*--supprimer en tête de liste--*/
number_struct supprAtHead(double newElement, number_struct list){
    int position = findNumber(newElement, list);
    // Vérifie si la position est valide
    if (position < 0) {
        printf("La position doit être supérieure ou égale à 0.\n");
        return;
    }
    if (position == 0) {
        number_struct temp = list;
        list = list->next;
        free(temp);
    }
    return list;
}

/*--supprimer en fin de liste--*/
number_struct supprAtEnd(double newElement, number_struct list){
    int position = findNumber(newElement, list);
    // Vérifie si la position est valide
    if (position < 0) {
        printf("La position doit être supérieure ou égale à 0.\n");
        return;
    }
}

/*--supprimer à une position--*/
number_struct supprAtPosition(double newElement, int position, number_struct list){
    position = findNumber(newElement, list);
    // Vérifie si la position est valide
    if (position < 0) {
        printf("La position doit être supérieure ou égale à 0.\n");
        return;
    }
    number_struct current = list;
    for (int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("La position spécifiée est hors limites.\n");
            return;
        }
        current = current->next;
    }
    free(current);
    return list;
}

//obtenir la taille de la liste
int getListSize(number_struct list){
    int size = 0;
    number_struct current = list;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

/*--recherche d'un élément--*/
int findNumber(double number, number_struct list){
    int position = 0;
    number_struct current = list;
    while (current != NULL) {
        if (current->current == number) {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;
}

/*--trier une liste(ordre croissant)--*/
number_struct sortList(number_struct list){
    int swapped;
    number_struct current;
    number_struct last = NULL;
    do {
        swapped = 0;
        current = list;
        while (current->next != last) {
            if (current->current > current->next->current) {
                double temp = current->current;
                current->current = current->next->current;
                current->next->current = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
    return list;
}

/*--ajout dans la liste triée--*/
number_struct addInSortList(double newElement, number_struct list){
    //Tri pré-alable
    list = sortList(list);
    number_struct new_node = (number_struct) malloc(sizeof(number_struct));
    new_node->current = newElement;
    new_node->next = NULL;
    if (list == NULL || list->current >= newElement) {
        new_node->next = list;
        list = new_node;
        return;
    }
    number_struct current = list;
    while (current->next != NULL && current->next->current < newElement) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return list;
}

/*--suppression des doublons--*/
number_struct deleteSameNumber(number_struct list){
    number_struct current = list;
    while (current != NULL && current->next != NULL) {
        if (current->current == current->next->current) {
            number_struct* next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

/*--afficher le menu d'ajout--*/
void addNumber(){
    printf("\t1. Ajout en tête de liste\n");
    printf("\t2. Ajout en fin de liste\n");
    printf("\t3. Ajout à une position donnée\n");
}

/*-afficher le menu de suppression-*/
void suppr(){
    printf("\t1. Suppression en tête de liste\n");
    printf("\t2. Suppression en fin de liste\n");
    printf("\t3. Suppression à une position donnée\n");
}
