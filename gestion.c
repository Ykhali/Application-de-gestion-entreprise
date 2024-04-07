#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gestionEN.h"
#include <string.h>

void ajout_emp(liste* L) {
    element* E = malloc(sizeof(element));
    fflush(stdin);
    printf("nom: ");
    gets(E->V.nom);
    printf("prenom: ");
    gets(E->V.prenom);
    printf("addresse: ");
    gets(E->V.addresse);
    printf("matricule: ");
    gets(E->V.matricule);
    printf("CIN: ");
    gets(E->V.CIN);
    printf("compteB: ");
    scanf("%d", &(E->V.compteB));
    fflush(stdin);
    printf("salaire: ");
    scanf("%f", &(E->V.salaire));
    fflush(stdin);
    printf("poste: ");
    gets(E->V.post);
    printf("ID du departement: ");
    scanf("%d", &(E->V.DEP.ID));
    printf("nombre d'employes: ");
    scanf("%d", &(E->V.DEP.nbr_emp));
    fflush(stdin);
    printf("spécialite: ");
    gets(E->V.DEP.specialite);

    if (L->tete == NULL) {
        L->tete = L->fin = E;
        E->suiv = E->prec = NULL;
    }
    else {
        E->suiv = L->tete;
        L->tete->prec = E;
        L->tete = E;
        E->prec = NULL;
    }
    L->nbr_emplo++;
}

void supp_deb(liste* L) {
    if (L->tete->suiv == NULL) {
        free(L->tete);
        L->tete = L->fin = NULL;
    }
    else {
        L->tete = L->tete->suiv;
        free(L->tete->prec);
        L->tete->prec = NULL;
    }
    L->nbr_emplo--;
}

void supp_fin(liste* L) {
    if (L->nbr_emplo == 1) {
        free(L->tete);
        L->tete = L->fin = NULL;
    }
    else {
        L->fin = L->fin->prec;
        free(L->fin->suiv);
        L->fin->suiv = NULL;
    }
    L->nbr_emplo--;
}

void supp_mil(liste* L, int p) {
    element* tmp = L->tete;
    int cpt = 1;
    if (p > 1 && p < L->nbr_emplo) {
        while (cpt != p) {
            tmp = tmp->suiv;
            cpt++;
        }
        tmp->prec->suiv = tmp->suiv;
        tmp->suiv->prec = tmp->prec;
        free(tmp);
        L->nbr_emplo--;
    }
    else {
        printf("erreur");
    }
}

void supp_empl(liste* L, char CIN[20]) {
    int ptr_pos = 1;
    element* ptr = L->tete;
    while (ptr != NULL) {
        if (strcmp(CIN, ptr->V.CIN) == 0) {
            if (ptr == L->tete) {
                supp_deb(L);
            }
            else if (ptr == L->fin) {
                supp_fin(L);
            }
            else {
                supp_mil(L, ptr_pos);
            }
            break;
        }
        ptr = ptr->suiv;
        ptr_pos++;
    }
}

void modifie_empl(liste* L,char CIN[20]) {
    element* ptr = L->tete;
    char* nouveau_nom = malloc(sizeof(char) * 20);
    char* nouveau_pren = malloc(sizeof(char) * 20);

    while (ptr != NULL) {
        if (strcmp(CIN, ptr->V.CIN) == 0) {
            printf("Nouveau nom:");
            fgets(nouveau_nom, 20, stdin);
            printf("Nouveau prenom:");
            fgets(nouveau_pren, 20, stdin);
            strcpy(ptr->V.nom, nouveau_nom);
            strcpy(ptr->V.prenom, nouveau_pren);
            break;
        }
        ptr = ptr->suiv;
    }

    free(nouveau_nom);
    free(nouveau_pren);
}

void aff_emp_par_dep(liste* L, char specialite[30]) {
    element* ptr = L->tete;
    if (L->nbr_emplo == 0) {
        printf("Liste vide\n");

    }
    else {
        while (ptr != NULL) {
            if (strcmp(ptr->V.DEP.specialite, specialite) == 0) {
                printf("Nom: %s\n", ptr->V.nom);
                printf("Prenom: %s\n", ptr->V.prenom);
                printf("Adresse: %s\n", ptr->V.addresse);
                printf("CIN: %s\n", ptr->V.CIN);
                printf("Matricule: %s\n", ptr->V.matricule);
                printf("Salaire: %.2f\n", ptr->V.salaire);
                printf("Poste: %s\n", ptr->V.post);
                printf("CompteB: %d\n", ptr->V.compteB);
                printf("Specialite: %s\n", ptr->V.DEP.specialite);
                printf("ID departement: %d\n", ptr->V.DEP.ID);
                printf("Nombre d'employes dans le departement: %d\n", ptr->V.DEP.nbr_emp);
                printf("\n");
            }
            ptr = ptr->suiv;
        }

    }
    printf("appuyez sur une touche pour quitter...");
    getchar();
}

int menu(void) {
    int choix;
    system("cls");
    printf("\t\tGestion d'entreprise\n\n");
    printf("0) Fin\n");
    printf("1) Ajouter employe\n");
    printf("2) Supprimer employe\n");
    printf("3) Modifier un employe\n");
    printf("4) Afficher les employes par departement\n");
    printf("\t\tVotre choix : ");
    scanf("%d", &choix);
    system("cls");
    return choix;
}

int connexion(liste L) {
    int id, i;
    char* M;
    M = malloc(strlen(L.mdp) + 1);
    for (i = 0; i < 3; i++) {
        scanf("%d", &id);
        fgets(M, strlen(L.mdp) + 1, stdin);
        if (id == L.ID && strcmp(M, L.mdp) == 0) {
            free(M);
            return 1;
        }

    }
    free(M);
    return 0;
}
