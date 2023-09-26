#include <iostream>
#include <vector>
#include <string>

struct Client {
    std::string nom;
    double solde;
};

int main() {
    // Liste des clients
    std::vector<Client> clients = {
        {"Jean Dupont", 120000.0},
        {"Marie Martin", 50000.0},
        {"Paul Durand", 150000.0},
        {"Alice Leroy", 30000.0},
        {"Claire Petit", 95000.0}
    };

    // Affichage des clients ayant un solde supérieur à 100 000 euros
    std::cout << "Clients avec un solde > 100 000 euros:" << std::endl;
    for (const Client& client : clients) {
        if (client.solde > 100000.0) {
            std::cout << client.nom << " : " << client.solde << " euros" << std::endl;
        }
    }

    return 0;
}
