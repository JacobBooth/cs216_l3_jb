#include <iostream>
#include <iomanip>
#include <cstdlib>  
#include <ctime>    
#include <string>
#include <algorithm> // for transform()

using namespace std;

// Define menu options using enum
enum MenuOptions { PRINT = 1, UPDATE, PRINT_DAMAGE, EXIT };

// Main function
int main() {
    srand(time(0));  // Seed for random numbers
    Creature creature; 
    initializeCreature(creature);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case PRINT:
                printCreature(creature);
                break;
            case UPDATE:
                initializeCreature(creature);
                cout << "Creature updated successfully!\n";
                break;
            case PRINT_DAMAGE:
                printDamageReport(creature);
                break;
            case EXIT:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}

// Define the Creature class
class Creature {
private:
    string name;
    string type; // New attribute for creature type
    int health;
    int strength;

public:
    // Mutator function to set creature attributes
    void setCreature(string newName, string newType, int newHealth, int newStrength) {
        transform(newName.begin(), newName.end(), newName.begin(), ::tolower); // Store lowercase
        transform(newType.begin(), newType.end(), newType.begin(), ::tolower);
        name = newName;
        type = newType;
        health = newHealth;
        strength = newStrength;
    }

    // Accessor functions
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    string getName() const { return name; }
    string getType() const { return type; }
    
    // Compute damage as a random value up to strength
    int getDamage() const { return (rand() % strength) + 1; }

    // Format the creature’s attributes as a string
    string to_String() const {
        return name + "\t" + type + "\t" + to_string(health) + "\t" + to_string(strength);
    }
};

// Function to load a random creature name and type
pair<string, string> loadCreatureAttributes() {
    string names[] = {"Dragon", "Centaur", "Griffin", "Troll", "Phoenix"};
    string types[] = {"Fire", "Water", "Earth", "Air"};
    return {names[rand() % 5], types[rand() % 4]};
}

// Function to initialize a creature with random health and strength
void initializeCreature(Creature &creature) {
    pair<string, string> attributes = loadCreatureAttributes();
    int health = rand() % 176 + 75; // Random health between 75 and 250
    int strength = rand() % 151 + 50; // Random strength between 50 and 200
    creature.setCreature(attributes.first, attributes.second, health, strength);
}

// Function to print the creature's details
void printCreature(const Creature &creature) {
    cout << "\nName\tType\tHealth\tStrength\n";
    cout << "--------------------------------\n";
    cout << creature.to_String() << "\n";
}

// Function to print the creature's damage report
void printDamageReport(const Creature &creature) {
    cout << "\nName\tType\tHealth\tStrength\tDamage\n";
    cout << "----------------------------------------------\n";
    cout << creature.to_String() << "\t" << creature.getDamage() << "\n";
}

// Function to display menu options
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Print Creature\n";
    cout << "2. Update Creature\n";
    cout << "3. Print Damage Report\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

