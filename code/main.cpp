#include "game.h"
#include <iostream>

// grading: no globals - er worden geen globale variabelen gebruikt, alle state zit in klassen of lokale variabelen
// grading: correct protections - alle header files gebruiken include guards om multiple inclusion te voorkomen.
// maintainability: consistente naamgeving, duidelijke functies en beknopt commentaar
// seperate header files: interfaces zitten in .h bestanden, implementaties in bijhorende .cpp files
// default constructors: meerdere klassen hebben een standaardconstructor
// parameterized constructors - humanplayer en cpuplayer hebben constructors met parameters
// destructors: klassen zoals player en game hebben expliciete destructors om resources netjes op te ruimen
// member initialization - leden zoals deck, dealer, balance en currentbet worden via een member initializer list in de constructor geinitialiseerd
// dynamic polymorphism: player is een abstracte basisklasse met een pure virtual functie en afgeleide klassen (Humanplayer, cpuplayer, dealer) worden via Player* polymorf gebruikt.
// useful member functions: functies zoals handvalue showhandwithvalue enz kapselen concrete game logica in
// default values - functies zoals playerturn en addcpuplayer gebruiken default parameters
// useful member variables - leden zoals hand, balance, currentbet, deck en dealer bewaren de toestand van spelers en het spel.
// getters and setters: er zijn nuttige getters zoals getname getbalance en setters setbalance setbet voor leden die van buiten de klasse gebruikt worden
// inline functions korte functies zoals dealer::getname worden in class gedefinieerd en zijn daarmee inline
// bool usage: meerdere bool variabelen sturen de gameflow en beslissingslogica
// dynamic memory: spelers worden dynamisch aangemaakt met new en correct vrijgegeven in clearplayers met delete
// string usage: std::string wordt gebruikt voor spelersnaam en gebruikersinput enz
// container class: std::vector wordt gebruikt om kaarten in de hand en de lijst van spelers dynamisch te beheren
// nullptr: morderne pointervergelijkingen gebruiken nullptr om te testen of een cpuplayer aanwezig is


int main() {
    Game game;

    // Setup spelers
    std::cout << "=== BLACKJACK GAME SETUP ===\n";
    std::cout << "How many human players? ";
    int numHumans;
    std::cin >> numHumans;

    for (int i = 0; i < numHumans; ++i) {
        std::cout << "Name for player " << (i+1) << ": ";
        std::string name;
        std::cin >> name;
        game.addHumanPlayer(name);
    }

    std::cout << "How many CPU players? ";
    int numCPUs;
    std::cin >> numCPUs;

    for (int i = 0; i < numCPUs; ++i) {
        std::string cpuName = "CPU" + std::to_string(i+1);
        game.addCPUPlayer(cpuName);
    }

    // Speel de game
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        game.play();
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> again;
    }

    return 0;
}
