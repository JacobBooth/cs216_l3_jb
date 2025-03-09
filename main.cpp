#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Constants
const int MAX_CREATURES = 100;

// Enum for menu options
enum MenuOptions { PRINT = 1, SORT, SEARCH, EXIT };
enum SortOptions { SORT_NAME = 1, SORT_TYPE, SORT_BACK };

// Creature Class
class Creature {
private:
    string name;
    string type;
    int health;
    int strength;

public:
    Creature(const string &n = "", const string &t = "", int h = 0, int s = 0)
        : name(n), type(t), health(h), strength(s) {}
    
    string getName() const { return name; }
    string getType() const { return type; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    
    static string toLower(const string &str) {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
    
    string toString() const {
        ostringstream out;
        out << left << setw(12) << name << setw(12) << type
            << right << setw(8) << health << setw(8) << strength;
        return out.str();
    }
};

// Army Class
class Army {
private:
    Creature* creatures[MAX_CREATURES];
    int count;

public:
    Army() : count(0) {
        for (int i = 0; i < MAX_CREATURES; ++i) {
            creatures[i] = nullptr;
        }
    }

    ~Army() {
        for (int i = 0; i < count; ++i) {
            delete creatures[i];
        }
    }

    void loadFromFile(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Cannot open file.\n";
            return;
        }

        string name, type;
        int health, strength;
        while (file >> name >> type >> health >> strength) {
            if (count < MAX_CREATURES) {
                creatures[count++] = new Creature(name, type, health, strength);
            }
        }
        file.close();
        cout << "Creatures loaded successfully.\n";
    }

    void printCreatures() const {
        cout << "\nName        Type        Health   Strength\n";
        cout << "------------------------------------------\n";
        for (int i = 0; i < count; ++i) {
            cout << creatures[i]->toString() << "\n";
        }
    }

    void bubbleSort(bool sortByType = false) {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (sortByType) {
                    if (creatures[j]->getType() < creatures[j + 1]->getType()) {
                        swap(creatures[j], creatures[j + 1]);
                    }
                } else {
                    if (creatures[j]->getName() < creatures[j + 1]->getName()) {
                        swap(creatures[j], creatures[j + 1]);
                    }
                }
            }
        }
    }

    void searchCreature(const string &query) const {
        string lowerQuery = Creature::toLower(query);
        bool found = false;
        cout << "\nSearch Results:\n";
        for (int i = 0; i < count; ++i) {
            if (Creature::toLower(creatures[i]->getName()).find(lowerQuery) != string::npos ||
                Creature::toLower(creatures[i]->getType()).find(lowerQuery) != string::npos) {
                cout << creatures[i]->toString() << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No matching creatures found.\n";
        }
    }
};

// Function to display menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Print Creatures\n";
    cout << "2. Sort Creatures\n";
    cout << "3. Search Creatures\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

// Function to display sorting submenu
void displaySortMenu() {
    cout << "\nSort by:\n";
    cout << "1. Name (Descending)\n";
    cout << "2. Type (Descending)\n";
    cout << "3. Back\n";
    cout << "Enter choice: ";
}
int main() {
    Army army;
    army.loadFromFile("creatures.txt");

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case PRINT:
                army.printCreatures();
                break;
            case SORT:
                int sortChoice;
                displaySortMenu();
                cin >> sortChoice;
                if (sortChoice == SORT_NAME || sortChoice == SORT_TYPE) {
                    army.bubbleSort(sortChoice == SORT_TYPE);
                    cout << "Creatures sorted successfully.\n";
                }
                break;
            case SEARCH:
                {
                    string query;
                    cout << "Enter name or type to search: ";
                    cin >> query;
                    army.searchCreature(query);
                }
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

/*
Creatures loaded successfully.

Menu:
1. Print Creatures
2. Sort Creatures
3. Search Creatures
4. Exit
Enter choice: 1

Name        Type        Health   Strength
------------------------------------------
Gandalf     Wizard           200     180
Aragorn     Ranger           150     140
Legolas     Archer           130     120
Gimli       Warrior          160     150
Frodo       Hobbit           100      60
Sauron      DarkLord         300     250
Saruman     Wizard           190     170
Nazgul      Wraith           180     160
Orc         Brute            120     100
Uruk-hai    Berserker        140     130
Balrog      Demon            250     230
Shelob      Beast            200     150
Elrond      Elf              170     140
Galadriel   Elf              180     150
Treebeard   Ent              220     160

Menu:
1. Print Creatures
2. Sort Creatures
3. Search Creatures
4. Exit
Enter choice: 2

Sort by:
1. Name (Descending)
2. Type (Descending)
3. Back
Enter choice: 1
Creatures sorted successfully.

Menu:
1. Print Creatures
2. Sort Creatures
3. Search Creatures
4. Exit
Enter choice: 1

Name        Type        Health   Strength
------------------------------------------
Uruk-hai    Berserker        140     130
Treebeard   Ent              220     160
Shelob      Beast            200     150
Sauron      DarkLord         300     250
Saruman     Wizard           190     170
Orc         Brute            120     100
Nazgul      Wraith           180     160
Legolas     Archer           130     120
Gimli       Warrior          160     150
Gandalf     Wizard           200     180
Galadriel   Elf              180     150
Frodo       Hobbit           100      60
Elrond      Elf              170     140
Balrog      Demon            250     230
Aragorn     Ranger           150     140

Menu:
1. Print Creatures
2. Sort Creatures
3. Search Creatures
4. Exit
Enter choice: 3
Enter name or type to search: elf 

Search Results:
Galadriel   Elf              180     150
Elrond      Elf              170     140

Menu:
1. Print Creatures
2. Sort Creatures
3. Search Creatures
4. Exit
Enter choice: 4
Exiting program.*/