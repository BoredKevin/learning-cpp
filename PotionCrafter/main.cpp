#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>
#include "log_message.h"
#include "inventory_display.h"
#include "potion_brewing.h"

using namespace std;

// Function to trim whitespace
string trim(const string& text)
{
    size_t first = text.find_first_not_of(" \t");
    if (string::npos == first) return "";
    size_t last = text.find_last_not_of(" \t");
    return text.substr(first, (last - first + 1));
}

int main()
{
    // WELCOME MESSAGE
    log_message(LOG, "Welcome to Potion Crafter 3000!");
    inventory_display();

    PotionCrafting crafting;

    //GAME LOOP
    bool keepBrewing = true;

    while (keepBrewing)
    {
        string ing1, ing2;

        // USER INPUT
        log_message(DISPLAY, "Choose two ingredients to combine (or 'quit' to exit): ");
        log_message(INPUT, "First Ingredient:");
        cout << ">> ";
        getline(cin, ing1);
        ing1 = trim(ing1);

        if ("quit" == ing1)
        {
            keepBrewing = false;
            continue;
        }

        log_message(INPUT, "Second Ingredient:");
        cout << ">> ";
        getline(cin, ing2);
        ing2 = trim(ing2);

        if ("quit" == ing2)
        {
            keepBrewing = false;
            continue;
        }

        // POTION BREWING
        Potion* result = crafting.craftPotion(ing1, ing2);

        if (result) {
            cout << "\nSuccessfully crafted: " << result->name << endl;
            cout << "Description: " << result->description << endl;
            cout << "Tip: " << result->tip << endl;
        } else {
            cout << "\nYou created a Mystery Goo!\n" << endl;
        }

        // Game loop
        string command;

        log_message(INPUT, "Press enter to continue brewing...");
        cout << ">> ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    log_message(LOG, "Goodbye, young wizard!");

    return 0;
}
