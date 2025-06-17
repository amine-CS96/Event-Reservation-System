#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/reservation.h"

int i=0 ;
int k=0;
int c=0 ;
admin *tb ;
event * cree_Event(event * tab ){
if(i==0)
    tab=malloc(sizeof(event));

tab=realloc(tab,(i+1)*sizeof(event)) ;
     printf("\n -----------------------------<...(^_^) : Saisir les  informations de nouvel evenement : ...>--------------------------\n");
     printf("\n--> Nom de l'evenement : ");
     scanf(" %[^\n]s",&tab[i].nom);

     printf("\n--> Date de l'evenement : \n");
     printf("   -> Jour : ") ;
     scanf(" %d",&tab[i].date.jour);
     printf("   -> Mois : ") ;
     scanf(" %d",&tab[i].date.mois);
     printf("   -> Annee : ") ;
     scanf(" %d",&tab[i].date.annee);

       printf("\n--> Nombre de place disponible  de l'evenement : ");
     scanf(" %d",&tab[i].place_dispo);
     tab[i].place_total=tab[i].place_dispo ;
     tab[i].place_reserv=0;
     printf("\n");
i++ ;
return tab;
}


event * reservation_place(event * tab){

int nbr ;
int j;
char nom[77];
char nom_comp[77];
if(i==0){
     printf("\n\n -------------<...(-_-): Aucunne evenement existe pour la reservation   : ....>---------------\n",i+1);
  return tab ;
}
      printf("\n\n (^-^)-->Veuillez saisir nom de l'evenement a reservee : ");
      scanf(" %[^\n]s",nom) ;
      for(j=0;j<i ;j++){
        if(strcmp(tab[j].nom,nom)==0) {

            if(tab[j].place_dispo>0){
    printf("\n\n (^-^)-->veuillez saisir votre nom complet (nom et prenom) : ");
    scanf(" %[^\n]s",&nom_comp) ;
    printf("\n\n (^-^)-->veuillez saisir nombre de place a reservee  de l'evenement ' %s ' : ",nom);
    scanf("%d",&nbr) ;
    while(nbr>(tab[j].place_dispo) || nbr<= 0 ){
     printf("\n\n (-_-) !! Chiox invalide,ce nombre de place n'est pas disponible !! \n\n -->veuillez saisir un  nombre de place a reservee  compris entre '1' et '%d' : ",tab[j].place_dispo);
    scanf("%d",&nbr) ;
    }
    tab[j].place_reserv+=nbr ;
    tab[j].place_dispo-=nbr;
       if(k==0)
    tb=malloc(sizeof(admin));
    tb=realloc(tb,(k+1)*sizeof(admin)) ;
      sprintf(tb[k].nom_event,nom );
     sprintf(tb[k].nom_complet,nom_comp);
      tb[k].plac_reserv=nbr;

     sprintf(tb[k].id,"A00%d",c+1);


      printf("\n\n \t (^_^)--> Reservation avec success de %d places ,voici votre code de reservation : ( %s )  . \n\n",nbr,tb[k].id);
    k++ ;
    c++ ;
      }
      else
           printf("\n\n -----------<...(-_-) : !! Chiox invalide !! --> aucunne place est  disponible a reservee pour l'evenement ' %s '  ...>-------------------\n",nom);

           break ;
      }

        }
    if(j==i)
    printf("\n\n--------------<...(-_-):!! Chiox invalide !! --> Ce evenement  n'existe pas ...>-----------------\n");


return tab;
}
event * annulation_reservation (event * tab){
int nbr ,l;
int j ;
char nom[77];
char nom_comp[77];
char id[50] ;
if(k==0){
  printf("\n\n -------------<...(-_-): Aucunne reservation existe pour l'annulation  : ....>---------------\n");
 return tab ;
}
       printf("\n\n (^-^)-->Veuillez saisir votre nom complet (nom et prenom) : ");
      scanf(" %[^\n]s",&nom_comp) ;
      printf("\n\n (^-^)-->Veuillez saisir le code de reservation : ");
      scanf(" %s",id) ;
      printf("\n\n (^-^)-->Veuillez saisir nom de l'evenement qui vous avez reservee : ");
      scanf(" %[^\n]s",&nom) ;
for(l=0;l<i;l++){
if(strcmp(tab[l].nom,nom)==0){
  for(j=0;j<k ;j++){
    if(strcmp(tb[j].id,id)==0 && strcmp(tb[j].nom_complet,nom_comp)==0){
        if(strcmp(tb[j].nom_event,nom)==0) {

            if(tb[j].plac_reserv>0){
    printf("\n\n -->veuillez saisir nombre de place a annullee leurs reservation de l'evenement ' %s ' : ",nom);
    scanf("%d",&nbr) ;
    while(nbr>(tb[j].plac_reserv) || nbr< 0 ){
     printf("\n\n (-_-) !! Chiox invalide,ce nombre de place n'est pas reservee !! \n\n -->veuillez saisir un  nombre de place a annullee  compris entre '0' et '%d' : ",tb[j].plac_reserv);
    scanf("%d",&nbr) ;
    }
    tb[j].plac_reserv-=nbr ;
    tab[l].place_reserv-=nbr ;
    tab[l].place_dispo+=nbr ;
    if(tb[j].plac_reserv==0){
      for(int p=j;p<k-1;p++)
        tb[p]=tb[p+1] ;

       k-- ;
     tb=realloc(tb,k*sizeof(admin));
     printf("\n\n \t (^_^)--> Annullation  avec success de tous les places a reservee ( %d ) \n\t   ,c-a-d : vous etes ignoree de la liste des reservateurs de l'evenement ' %s ' . \n\n",nbr,nom);
   return tab ;
       }

      printf("\n\n \t (^_^)--> Annullation  avec success de reservation de %d places  . \n\n",nbr);
     return tab ;
      }


      }
       else
           printf("\n\n (-_-) : !! Chiox invalide !! --> Ce evenement n'est pas reservee en fonction ce code de reservation (%s) et en fonction de ce nom ' %s ',\n\t\t--> l'evenement reservee pour ce code de reservation et ce nom  est ' %s ' .\n",tb[j].id,tb[j].nom_complet,tb[j].nom_event);
     break ;
           }

            }

            if(j==k)
      printf("\n\n -----<...(-_-) : !! Chiox invalide !! --> Le Code de reservation (%s) ou Votre Nom ('%s') n'est pas correct (ou bien les deux  ) ! ...>------\n",id,nom_comp);
break ;
}

  }

        if(l==i)
           printf("\n\n --------<...(-_-) : !! Chiox invalide !! --> Ce evenement '%s' n'existe pas dans la liste des evenements ! ...>---------\n",nom);
return tab ;
  }


void  Affichage_event(event* tab){
    if(i==0){
   printf("\n\n -------------<...(-_-): la liste des evenements est vide  : ....>---------------\n");
   return ;
    }
 printf("\n\n ---------------<...(^_^): Affichage des evenements  : ....>----------------\n");
for (int j=0 ;j<i ;j++){

    printf("\n-----> L'evenement %d : \n",j+1);
    printf(" --> Nom de l'evenement  : %s \n",tab[j].nom);
    printf(" --> Date (JJ/MM/AA) : %d/%d/%d \n",tab[j].date.jour,tab[j].date.mois,tab[j].date.annee);
    printf(" --> Nombre de places total a reservees  : %d \n",tab[j].place_reserv);
     printf(" --> Nombre de places disponibles  %d : \n",tab[j].place_dispo);

}
printf("\n -----------------------------------<...(^_^)...>------------------------------------\n\n");
}

void  Affichage_reservateur(){
    if(k==0){
  printf("\n\n -------------<...(-_-): la liste de reservations des utilisateurs est vide  : ....>---------------\n");
  return ;
    }
 printf("\n\n -------------<...(^_^): Affichage des reservateurs  : ....>---------------\n");
for (int j=0 ;j<k ;j++){

    printf("\n-----> Le reservateur %d : \n",j+1);
    printf(" --> Nom de reservateur  : %s \n",tb[j].nom_complet);
    printf(" --> Nom de l'evenement a reservee  : %s \n",tb[j].nom_event);
    printf(" --> Code de reservation  : %s \n",tb[j].id);
    printf(" --> Nombre de places a reservees  : %d \n",tb[j].plac_reserv);

}
printf("\n -----------------------------------<...(^_^)...>------------------------------------\n\n");
}
int recherche_event(event * tab){
char nom[77];

 printf("\n\n (^-^)-->Veuillez saisir nom de l'evenement a recherchee : ");
      scanf(" %[^\n]s",&nom) ;
      for(int j=0;j<i ;j++){
        if(strcmp(tab[j].nom,nom)==0) {
         return j ;
        }
      }
 return -1 ;
}

void sauvegarde_event(char *f_event,event *tab ){
FILE *fw2;
fw2= fopen(f_event,"w");

if(fw2==NULL){
   printf(" (-_-)!!--> Erreur d'ouverture de fichier '%s' !",f_event);
   return ;
}

for(int j=0;j<i;j++){

  fprintf(fw2,"----------------------------<...Les informations de l'evenement  %d : ...>-----------------------------\n",j+1);
    fprintf(fw2,"\n --> Nom de l'evenement  : %s \n",tab[j].nom);
    fprintf(fw2," --> Date (JJ/MM/AA) : %d/%d/%d \n",tab[j].date.jour,tab[j].date.mois,tab[j].date.annee);
    fprintf(fw2," --> Nombre de places total a reservees  : %d \n",tab[j].place_reserv);
    fprintf(fw2," --> Nombre de places disponibles  %d : \n",tab[j].place_dispo);
  fprintf(fw2,"\n------------------------------------------<.......>-------------------------------------------------\n\n");

}
printf("\n   (^_^) : --> Sauvegarde des evenements dans le fichier ' %s ' avec success .\n",f_event) ;
  fclose(fw2);
}
void Charge_event(char *f_event){
FILE *pr;
char aff_event[777];
pr= fopen(f_event, "r");

  if(pr==NULL){
   printf("\n (-_-)--> Erreur d'ouverture de fichier '%s'  !",f_event);
   return ;
  }
     while(fscanf(pr," %[^\n]s",aff_event)==1 ) {
         printf(" %s \n\n",aff_event);
     }

    fclose(pr);
}
void sauvegarde_reservateur(char *f_reserv ){
FILE *fw2;
fw2= fopen(f_reserv,"w");

if(fw2==NULL){
   printf(" (-_-)!!--> Erreur d'ouverture de fichier '%s' !",f_reserv);
   return ;
}

for(int j=0;j<k;j++){

  fprintf(fw2,"----------------------------<...Les informations de reservateur %d : ...>-----------------------------\n\n",j+1);
    fprintf(fw2," --> Nom de reservateur  : %s \n",tb[j].nom_complet);
    fprintf(fw2," --> Nom de l'evenement a reservee  : %s \n",tb[j].nom_event);
    fprintf(fw2," --> Code de reservation  : %s \n",tb[j].id);
    fprintf(fw2," --> Nombre de places a reservees  : %d \n",tb[j].plac_reserv);
  fprintf(fw2,"\n\n------------------------------------------<.......>-------------------------------------------------\n\n");

}
printf("\n   (^_^) : --> Sauvegarde de reservateurs dans le fichier ' %s ' avec success .\n",f_reserv) ;
  fclose(fw2);
}
void Charge_reservateur(char *f_reserv){
FILE *pr;
char aff_reserv[777];
pr= fopen(f_reserv, "r");

  if(pr==NULL){
   printf("\n (-_-)--> Erreur d'ouverture de fichier '%s'  !",f_reserv);
   return ;
  }
     while(fscanf(pr," %[^\n]s",aff_reserv)==1 ) {
         printf(" %s \n\n",aff_reserv);
     }

    fclose(pr);
}
