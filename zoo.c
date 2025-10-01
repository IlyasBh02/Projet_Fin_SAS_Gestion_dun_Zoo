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
    char choix = 'o';
    while (choix == 'o' || choix == 'O') {
        struct Animal a;
        a.id = total + 1;

        printf("Nom: ");
        scanf("%s", a.nom);

        printf("Espece: ");
        scanf("%s", a.espece);

        printf("Age: ");
        scanf("%d", &a.age);

        printf("Habitat: ");
        scanf("%s", a.habitat);

        printf("Poids: ");
        scanf("%f", &a.poids);

        zoo[total++] = a;
        printf("✅ Animal ajoute avec succes!\n");

        printf("Voulez-vous ajouter un autre animal? (o/n): ");
        scanf(" %c", &choix);
    }
}


void afficherAnimaux() {
    if (total == 0) {
        printf("Aucun animal enregistre!\n");
        return;
    }
    printf("\n--- Liste des animaux ---\n");
    for (int i = 0; i < total; i++) {
        printf("%d | %s | %s | %d ans | %s | %.2f kg\n",
               zoo[i].id, zoo[i].nom, zoo[i].espece,
               zoo[i].age, zoo[i].habitat, zoo[i].poids);
    }
}

void modifierAnimal() {
    int id;
    printf("Entrer l'ID a modifier: ");
    scanf("%d", &id);

    int choix;
    for (int i = 0; i < total; i++) {
        if (zoo[i].id == id) {
            break; 
        }
    }

    if (i == total) {
        printf("Animal non trouve!\n");
        return;
    }

    printf("1. Modifier habitat\n2. Modifier age\nVotre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Nouveau habitat: ");
        scanf("%s", zoo[i].habitat);
    } else if (choix == 2) {
        printf("Nouvel age: ");
        scanf("%d", &zoo[i].age);
    }

    printf("✅ Modification faite!\n");
}

void supprimerAnimal() {
    int id;
    printf("Entrer ID a supprimer: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < total; i++) {
        if (zoo[i].id == id) { found = i; break; }
    }
    if (found == -1) {
        printf("Animal non trouve!\n");
        return;
    }

    for (int i = found; i < total - 1; i++) {
        zoo[i] = zoo[i + 1];
        zoo[i].id = i + 1;
    }
    total--;
    printf("✅ Animal supprime!\n");
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