#include <stdio.h>
#include <string.h>

#define MAX 200

struct Animal {
    int id;
    char nom[50];
    char espece[30];
    int age; 
    char habitat[30];
    float poids;
};

struct Animal zoo[MAX] = {
    {1, "Lion", "Panthera", 5, "Savannah", 180.5},
    {2, "Elephant", "Loxodonta", 10, "Forest", 5400.0},
    {3, "Tiger", "Panthera", 6, "Jungle", 220.0},
    {4, "Giraffe", "Giraffa", 7, "Savannah", 800.0},
    {5, "Zebra", "Equus", 4, "Savannah", 350.0},
    {6, "Kangaroo", "Macropus", 3, "Outback", 85.0},
    {7, "Penguin", "Aptenodytes", 8, "Antarctica", 40.0},
    {8, "Panda", "Ailuropoda", 12, "Forest", 95.0},
    {9, "Monkey", "Cercopithecidae", 5, "Jungle", 25.0},
    {10, "Bear", "Ursus", 9, "Forest", 600.0},
    {11, "Wolf", "Canis", 6, "Woodland", 45.0},
    {12, "Cheetah", "Acinonyx", 4, "Savannah", 70.0},
    {13, "Leopard", "Panthera", 7, "Savannah", 60.0},
    {14, "Flamingo", "Phoenicopterus", 5, "Wetlands", 3.5},
    {15, "Gorilla", "Gorilla", 15, "Jungle", 150.0},
    {16, "Koala", "Phascolarctos", 3, "Forest", 15.0},
    {17, "Sloth", "Folivora", 10, "Rainforest", 8.0},
    {18, "Rhino", "Rhinocerotidae", 12, "Savannah", 2200.0},
    {19, "Crocodile", "Crocodylus", 20, "Swamp", 1000.0},
    {20, "Ostrich", "Struthio", 4, "Desert", 130.0}
};
int total = 20;

void afficherUnAnimal(struct Animal a) {
    printf("%d | %s | %s | %d ans | %s | %.2f kg\n",
           a.id, a.nom, a.espece, a.age, a.habitat, a.poids);
}

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
        printf("❌ Aucun animal enregistre!\n");
        return;
    }
    int choix;
    printf("\n--- Menu Affichage ---\n");
    printf("1. Liste complete\n");
    printf("2. Trier par nom\n");
    printf("3. Trier par age\n");
    printf("4. Afficher par habitat\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
        for (int i = 0; i < total; i++) afficherUnAnimal(zoo[i]);
    }
    else if (choix == 2) {
        struct Animal tmp[MAX];
        for (int i = 0; i < total; i++) tmp[i] = zoo[i];
        for (int i = 0; i < total-1; i++)
            for (int j = 0; j < total-i-1; j++)
                if (strcmp(tmp[j].nom, tmp[j+1].nom) > 0) {
                    struct Animal t = tmp[j]; tmp[j] = tmp[j+1]; tmp[j+1] = t;
                }
        for (int i = 0; i < total; i++) 
        afficherUnAnimal(tmp[i]);
    }
    else if (choix == 3) {
        struct Animal tmp[MAX];
        for (int i = 0; i < total; i++) tmp[i] = zoo[i];
        for (int i = 0; i < total-1; i++)
            for (int j = 0; j < total-i-1; j++)
                if (tmp[j].age > tmp[j+1].age) {
                    struct Animal t = tmp[j]; tmp[j] = tmp[j+1]; tmp[j+1] = t;
                }
        for (int i = 0; i < total; i++) afficherUnAnimal(tmp[i]);
    }
    else if (choix == 4) {
        char hab[30]; int found = 0;
        printf("Habitat: "); scanf("%s", hab);
        for (int i = 0; i < total; i++)
            if (strcmp(zoo[i].habitat, hab) == 0) {
                afficherUnAnimal(zoo[i]); found = 1;
            }
        if (!found) 
        printf("❌ Aucun animal dans cet habitat!\n");
    }
}

void modifierAnimal() {
    int id, choix, i;
    printf("ID a modifier: "); scanf("%d", &id);
    for (i = 0; i < total; i++) if (zoo[i].id == id) break;
    if (i == total) { printf("❌ Animal non trouve!\n"); return; }

    printf("1. Modifier habitat\n2. Modifier age\nVotre choix: ");
    scanf("%d", &choix);
    if (choix == 1) { printf("Nouveau habitat: "); scanf("%s", zoo[i].habitat); }
    else if (choix == 2) { printf("Nouvel age: "); scanf("%d", &zoo[i].age); }
    printf("✅ Modification faite!\n");
}

void supprimerAnimal() {
    int id, found=-1;

    printf("ID a supprimer: "); scanf("%d", &id);

    for (int i = 0; i < total; i++) 
    if (zoo[i].id == id) { 
        found=i; break; }

    if (found == -1) { printf("❌ Animal non trouve!\n"); 
        return; 
    }

    for (int i = found; i < total-1; i++) {
        zoo[i] = zoo[i+1]; 
        /*zoo[i].id = i+1;*/
    }
    total--;
    printf("✅ Animal supprime!\n");
}

void rechercherAnimal() {

    int choix; 
    
    printf("1. Par ID\n2. Par nom\n3. Par espece\nVotre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {

        int id; 
        
        printf("ID: "); 
        scanf("%d", &id);
        
        for (int i=0;i<total;i++) if(zoo[i].id==id){ 
            afficherUnAnimal(zoo[i]); 
            return; 
        }
        printf("❌ Animal non trouve!\n");
    }

    else if (choix == 2) {

        char nom[50]; 
        int found=0;
        
        printf("Nom: "); 
        scanf("%s", nom);
        
        for (int i=0;i<total;i++) 
        if(strcmp(zoo[i].nom,nom)==0){ 
            afficherUnAnimal(zoo[i]); found=1; 
        }
        if (!found) 
        printf("❌ Animal non trouve!\n");
    }

    else if (choix == 3) {
        char esp[30]; 
        int found=0;
        
        printf("Espece: "); 
        scanf("%s", esp);
        
        for (int i=0;i<total;i++) 
        if(strcmp(zoo[i].espece,esp)==0){ afficherUnAnimal(zoo[i]); found=1; }
        if (!found) 
        printf("❌ Aucun animal avec cette espece!\n");
    }
}

void statistiques() {
    if (total==0){ 
        printf("❌ Zoo vide!\n"); 
        return; 
    }

    int somme=0, maxAge=zoo[0].age, minAge=zoo[0].age;
    char vieux[50], jeune[50];

    strcpy(vieux,zoo[0].nom); 
    strcpy(jeune,zoo[0].nom);

    for (int i=0;i<total;i++) {
        somme += zoo[i].age;
        if (zoo[i].age > maxAge) { 
            maxAge=zoo[i].age; 
            strcpy(vieux,zoo[i].nom); 
        }

        if (zoo[i].age < minAge) { 
            minAge=zoo[i].age; 
            strcpy(jeune,zoo[i].nom); 
        }
    }

    printf("Nombre total: %d\n", total);
    printf("Age moyen: %.2f\n", (float)somme/total);
    printf("Plus vieux: %s (%d ans)\n", vieux, maxAge);
    printf("Plus jeune: %s (%d ans)\n", jeune, minAge);


    int maxCount=0; 
    char espMax[30];

    for (int i=0;i<total;i++) {
        int count=0;

        for (int j=0;j<total;j++) 
        if(strcmp(zoo[i].espece,zoo[j].espece)==0) 
        count++;

        if (count > maxCount) { 
            maxCount = count; 
            strcpy(espMax,zoo[i].espece); }
    }
    printf("Espece la plus representee: %s (%d)\n", espMax, maxCount);
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
