#include <iostream>
#include <array>

// Fonction constexpr pour obtenir le message de bienvenue
constexpr const char* GetWelcomeMessage(const char* role) {
    return role;  // Dans cet exemple simplifié, nous retournons juste le rôle.
                  // Une vraie fonction constexpr de formatage serait plus complexe.
}

int main() {
    constexpr std::array<const char*, 1> roles = {"Bonjour les développeurs SCRUM!"};

    for (const auto& role : roles) {
        std::cout << GetWelcomeMessage(role) << std::endl;
    }

    return 0;
}
