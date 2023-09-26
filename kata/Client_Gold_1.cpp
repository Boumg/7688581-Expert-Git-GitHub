#include <stdio.h>

// Définition de la structure Client
typedef struct {
    char nom[50];
    double solde;
} Client;

int main() {
    // Tableau statique des clients
    Client clients[] = {
        {"Jean Dupont", 120000.0},
        {"Marie Martin", 50000.0},
        {"Paul Durand", 150000.0},
        {"Alice Leroy", 30000.0},
        {"Claire Petit", 95000.0}
    };

    int taille = sizeof(clients) / sizeof(Client);

    // Affichage des clients ayant un solde supérieur à 100 000 euros
    printf("Clients avec un solde > 100 000 euros:\n");
    for (int i = 0; i < taille; i++) {
        if (clients[i].solde > 100000.0) {
            printf("%s : %.2f euros\n", clients[i].nom, clients[i].solde);
        }
    }

    return 0;
}
