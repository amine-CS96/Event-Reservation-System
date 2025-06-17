#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED
typedef struct Date{
int jour ;
int mois ;
int annee ;
}Date ;
typedef struct event{
char nom[77];
Date date ;
int place_dispo ;
int place_total ;
int place_reserv ;
}event ;
typedef struct admin{
char nom_event[77];
char nom_complet[77];
char id[50];
int plac_reserv ;
}admin;


extern int i;
extern int c;
extern int k;
extern admin *tb ;
extern event  * cree_Event(event * tab ) ;
extern event * reservation_place(event * tab) ;
extern event* annulation_reservation (event * tab) ;
extern void  Affichage_event(event* tab) ;
extern void  Affichage_reservateur() ;
extern int recherche_event(event * tab) ;
extern void sauvegarde_event(char *f_event,event *tab ) ;
extern void Charge_event(char *f_event) ;
extern void sauvegarde_reservateur(char *f_reserv ) ;
extern void Charge_reservateur(char *f_reserv ) ;
#endif // RESERVATION_H_INCLUDED
