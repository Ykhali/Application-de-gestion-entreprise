#include <stdio.h>
#include <stdlib.h>
#include "gestionEN.h"
#include "gestion.c"
#include <string.h>
#include <conio.h>

int main() {
    liste L = { NULL,NULL,0,"comdata",2222,"admin" };
    int c = connexion(L);
    int choix = 0;
    char CIN[20], sp[50];

    printf("%d\n", c);
    if (c == 1) {
        do {
            choix = menu();
            switch (choix) {
            case 1:
                ajout_emp(&L);
                getchar();
                break;
            case 2:
                printf("CIN: ");
                scanf("%s", CIN);
                supp_empl(&L, CIN);
                getchar();
                break;
            case 3:
                printf("CIN: ");
                scanf("%s", CIN);
                modifie_empl(&L,CIN);
                getchar();
                break;
            case 4:
                printf("Specialite: ");
                scanf("%s", sp);
                aff_emp_par_dep(&L, sp);
                getchar();
                break;
            }
        } while (choix != 0);
    }
    else {
        printf("Erreur de connexion\n");
    }
    return 0;
}
