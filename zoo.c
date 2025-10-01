#include<stdio.h>


struct Animal {
    int id;
    char nom[50];
    char espece[30];
    int age; 
    char habitat[30];
    float poids;
};

void ajouterAnimal() {
    struct Animal a;
    a.id = total + 1;

    printf("Nom : ");
    scanf("%s", a.nom);

    printf("Espece : ");
    scanf("%s", a.espece);

    printf("Age : ");
    scanf("%d", &a.age);

    printf("Habitat : ");
    scanf("%s", a.habitat);

    printf("Poids : ");
    scanf("%f", &a.poids);

    zoo[total++] = a;
    printf("✅ Animal ajouté avec succès!\n");
}

int main() {
    int choix;
    do {
        printf("\n===== MENU ZOO =====\n");
        printf("1. Ajouter un animal\n");
        printf("2. Afficher les animaux\n");
        printf("3. Modifier un animal\n");
        printf("4. Supprimer un animal\n");
        printf("5. Rechercher un animal\n");
        printf("6. Statistiques\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterAnimal(); break;

            case 2: afficherAnimaux(); break;

            case 3: modifierAnimal(); break;

            case 4: supprimerAnimal(); break;

            case 5: rechercherAnimal(); break;

            case 6: statistiques(); break;
            
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide!\n");
        }
    } while(choix != 0);

    return 0;
}