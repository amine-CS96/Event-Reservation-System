#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/reservation.h"
int main()
{
    int rt;
char nom_file[50] ;
event *tab;
    int x ;
    while(1){
            if(x!=2 && x!=3 && x!=6 && x!=5){
        printf("\n\n-----------------------------------------MENU:------------------------------------------------\n");
printf("\n\t  1. Ajouter un nouveau evenement dans la liste des evenements .\n");
printf("\n\t  2. Reserver des billets pour un evenement .\n");
printf("\n\t  3. Annulation de reservation d'un nombre specifique de billets . \n");
printf("\n\t  4. Affichage des evenements disponibles  .\n");
printf("\n\t  5. Affichage des reservation des utilisateurs  .\n");
printf("\n\t  6. Recherche d'evenements par nom .\n");
printf("\n\t  7. Sauvegarde les evenements disponibles dans un fichier  .\n");
printf("\n\t  8. Sauvegarde les reservation des utilisateurs dans un fichier  .\n");
printf("\n\t  9. Chargement de evenements disponibles a partir d'un fichier  .\n");
printf("\n\t 10. Chargement de reservation des utilisateurs a partir d'un fichier  .\n");
printf("\n\t 11. Quitter . \n");
printf("----------------------------------------------------------------------------------------------------\n\n");
            }
 printf("\n\n-->Veuillez saisir un numero a partir de MENU (1,2,...,10,11) :");
 scanf("%d",&x);
 printf("\n\n");
  switch(x){
    case 1:
        tab=cree_Event(tab);
               printf("--------------<...(^_^) : L'evenement a ete ajoutee avec sucess ...>---------------\n\n");
       break ;
    case 2:
    tab=reservation_place(tab) ;
    break;
    case 3:
   tab=annulation_reservation(tab) ;
        break;
    case 4:
     Affichage_event(tab);
    break;
    case 5:
    Affichage_reservateur() ;
    break;
    case 6:
        if(i==0){
         printf("\n\n -----<...(-_-): Aucunne evenement existe dans la liste des evenements, pour le recherchee  : ....>------\n");
          continue;
            }
         rt =recherche_event(tab);
      if(rt!=-1)
             printf("\n\n \t (^_^)--> l'evenement ' %s ' est existe dans la liste des evenements .",tab[rt].nom);
             else
            printf("\n\n \t (-_-)--> l'evenement a recherchee n'existe pas dans la liste des evenements .");

    break;

    case 7:
        if(i==0){
             printf("\n\n -----<...(-_-): la liste des evenements est vide : ....>---------\n");
           continue ;
  }
      printf("\n\n (^-^)-->Veuillez saisir le nom de fichier pour le sauvegardement des evenements : ");
      scanf(" %[^\n]s",nom_file);
      sauvegarde_event(nom_file,tab)  ;

    break;

    case 8:
        if(k==0){
             printf("\n\n ---------<...(-_-): la liste de reservations des utilisateurs est vide   : ....>-----------\n");
           continue ;
  }
       printf("\n\n (^-^)-->Veuillez saisir le nom de fichier pour le sauvegardement de reservations : ");
      scanf(" %[^\n]s",nom_file);
      printf("\n") ;
      sauvegarde_reservateur(nom_file)  ;
    break;
    case 9:
       printf("\n\n (^-^)-->Veuillez saisir le nom de fichier pour le chargement des evenements : ");
      scanf(" %[^\n]s",nom_file);
      printf("\n\n") ;
      Charge_event(nom_file) ;
    break;
    case 10:
       printf("\n\n (^-^)-->Veuillez saisir le nom de fichier pour le chargement de reservations : ");
      scanf(" %[^\n]s",nom_file);
      printf("\n\n") ;
      Charge_reservateur(nom_file)  ;
    break;
    case 11:printf("\n ------------------------<...(^_^) : Au Revoir ! ...>----------------------------\n") ;
                return 0;
    break;
    default :printf("\n (-_-)-->Ce numero n'existe pas dans le MENU \n\n") ;
  }

}
    return 0;
}
