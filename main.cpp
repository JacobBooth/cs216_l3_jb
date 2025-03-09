#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Constants
const int MAX_CREATURES = 100;

// Enum for menu options
enum MenuOptions { PRINT = 1, SORT, SEARCH, EXIT };
enum SortOptions { SORT_NAME = 1, SORT_TYPE, SORT_BACK };

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

    // Function to display menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Print Creatures\n";
    cout << "2. Sort Creatures\n";
    cout << "3. Search Creatures\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}