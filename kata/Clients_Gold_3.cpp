#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>  // Pour std::function

struct Euro {
    double montant;

    bool operator>(const Euro& other) const {
        return montant > other.montant;
    }
};

Euro operator "" _euro(long double montant) {
    return { static_cast<double>(montant) };
}

struct Client {
    std::string nom;
    std::string statut;
    Euro solde;
};

// La fonction Superieure retourne une fonction
std::function<bool(const Client&)> Superieure(Euro montant) {
    return [montant](const Client& client) {
        return client.solde > montant;
    };
}

std::vector<Client> operator&(const std::vector<Client>& clients, const std::function<bool(const Client&)>& pred) {
    std::vector<Client> result;
    
    std::copy_if(clients.begin(), clients.end(), std::back_inserter(result), pred);
    
    return result;
}

int main() {
    std::vector<Client> clients = {
        {"Jean Dupont", "gold", 1200000_euro},
        {"Marie Martin", "silver", 500000_euro},
        {"Paul Durand", "gold", 1500000_euro},
        {"Alice Leroy", "bronze", 300000_euro},
        {"Claire Petit", "gold", 950000_euro}
    };

    auto Gold = Superieure(1000000_euro);
    for (const Client& client : clients & Gold) {
        std::cout << client.nom << " : " << client.solde.montant << " euros" << std::endl;
    }

    return 0;
}
