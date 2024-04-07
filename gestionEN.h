#ifndef GESTIONEN_H_INCLUDED
#define GESTIONEN_H_INCLUDED

struct departement{
int ID ;
char specialite[50];
int nbr_emp;
};

typedef struct EMPLOYE{
char nom[100];
char prenom[100];
char addresse[100];
char matricule[100];
char post[100];
char CIN[100];
int compteB ;
float salaire;
struct departement DEP ;
}employe;


typedef struct Element{
 employe V;
 struct Element *suiv;
 struct Element *prec;

}element;


typedef struct liste{
    element *tete;
    element *fin;
    int nbr_emplo;
    char nom_EN[100];
    int ID;
    char mdp[100];
}liste;



void ajout_emp(liste *L);
void supp_deb(liste *L);
void supp_fin(liste *L);
void supp_mil(liste *L,int p);
void supp_empl(liste *L,char CIN[20]);
void modifie_empl(liste *L,char CIN[20]);
void aff_emp_par_dep(liste *L,char specialite[30]);
int menu(void);
int connexion(liste L);












#endif // GESTIONEN_H_INCLUDED
