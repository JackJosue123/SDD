#include <stdio.h>
#include <stdlib.h>
#include "nombres.h"
#include "nombres.c"

int main()
{
    int choice_menu;
    int choice_sub_menu;
    int position;
    double new_element;

    printf("\t\t----------Manager----\n");
    printf("\t*-Gestionnaire de liste chaînée de nombres -*\n");
    //supposition d'une liste créée
    number_struct list = build();

    do{
        printf("Que voulez-vous faire ?\n");

        printf("\t1. Créer une liste chaînée\n");
        printf("\t2. Afficher la liste chaînée\n");
        printf("\t3. Calculer la longueur de la liste\n");
        printf("\t4. Ajouter un nombre dans la liste\n");
        printf("\t5. Supprimer un nombre de la liste\n");
        printf("\t6. Chercher un nombre dans la liste\n");
        printf("\t7. Trier la liste de nombre dans l'ordre croissant\n");
        printf("\t8. Ajouter un nombre dans la liste triée\n");
        printf("\t9. Eliminer les doublons\n");
        printf("\t10. Quitter\n");

        printf("Entrer le numéro de l'action à exécuter (ex: 4) : ");
        scanf("%d", &choice_menu);

        switch(choice_menu){
        case 1:
            if(!list){
                number_struct list = build();
            }
            printf("\n\tLa liste a bien été créée...\n");
            break;
        case 2:
            showList(list);
            break;
        case 3:
            printf("\n\tLa taille de la liste chaînée vaut: %d\n", getListSize(list));
            break;
        case 4:
            addNumber();
            printf("\t  Sélectionner une action: ");
            scanf("%d", &choice_sub_menu);
            break;
        case 5:
            suppr();
            printf("\t  Sélectionner une action: ");
            scanf("%d", &choice_sub_menu);
            break;
        case 6:
            double number;
            printf("Entrer la valeur à rechercher: ");
            scanf("%lf", &number);
            int position = findNumber(number, list);
            if (position == -1) {
                printf("\n\tLa valeur %.2f n'a pas été trouvée dans la liste chaînée.\n", number);
            } else {
                printf("\n\tLa valeur %.2f a été trouvée à la position %d dans la liste chaînée.\n", number, position);
            }
            break;
        case 7:
            sortList(list);
            showList(list);
            break;
        case 8:
            printf("Entrer la valeur à ajouter: ");
            scanf("%lf", &new_element);
            addInSortList(new_element, list);
            showList(list);
            break;
        case 9:
            deleteSameNumber(list);
            showList(list);
            break;
        default:
            /*code run here*/
        }

        switch(choice_sub_menu){
        case 0:
            /*run code here*/
            break;
        case 1:
            if(choice_menu == 4){
                printf("Entrer la valeur à ajouter: ");
                scanf("%lf", &new_element);
                list = addAtHead(new_element, list);
                showList(list);
            }else if(choice_menu == 5){
                printf("Entrer la valeur à supprimer: ");
                scanf("%lf", &new_element);
                list = supprAtHead(new_element, list);
                showList(list);
            }else{
                /*--run code here-*/
            }
            break;
        case 2:
            if(choice_menu == 4){
                printf("Entrer la valeur à ajouter: ");
                scanf("%lf", &new_element);
                list = addAtEnd(new_element, list);
                showList(list);
            }else if(choice_menu == 5){
                printf("Entrer la valeur à supprimer: ");
                scanf("%lf", &new_element);
                list = supprAtEnd(new_element, list);
                showList(list);
            }else{
                /*--run code here-*/
            }
            break;
        case 3:
            if(choice_menu == 4){
                printf("Entrer la valeur à ajouter: ");
                scanf("%lf", &new_element);
                printf("Entrer la position du nouveau élément: ");
                scanf("%d", &position);
                list = addAtPosition(new_element, position, list);
                showList(list);
            }else if(choice_menu == 5){
                printf("Entrer la valeur à ajouter: ");
                scanf("%lf", &new_element);
                printf("Entrer la position du nouveau élément: ");
                scanf("%d", &position);
                list = supprAtPosition(new_element, position, list);
                showList(list);
            }else{
                /*--run code here-*/
            }
            break;
        default:
            /*--run code here-*/
        }
        if(choice_menu == 10){
            break;
        }else{
            printf("\n");
        }
    }while(1);

    return 0;
}
