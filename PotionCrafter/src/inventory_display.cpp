#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "inventory_display.h"
#include "log_message.h"

using namespace std;

struct Ingredient
{
    string common;
    string rare;
    string epic;
};

void print_centered(string text, int width)
{
    int padding = (width - text.length()) / 2;
    cout << setw(padding + text.length()) << text << setw(padding) << "";
}

void inventory_display()
{
    log_message(LOG, "Displaying your inventory...");
    log_message(DISPLAY, "Here are the list of ingredients that you can use:");

    vector<Ingredient> ingredients =
    {
        {"Mushroom", "Lizard Tail", "Unicorn Hair"},
        {"Snowflake", "Dragonfly Wings", "Dragon Scale"}
    };

    // Print header
    cout << setfill('-') << setw(60) << "" << endl;
    cout << setfill(' ');
    print_centered("COMMON", 15);
    print_centered("RARE", 25);
    print_centered("EPIC", 15);
    cout << endl;
    cout << setfill('-') << setw(60) << "" << endl;
    cout << setfill(' ');

    // Print data
    for (const auto& ingredient : ingredients)
    {
        cout << left << setw(20) << ingredient.common
                << setw(20) << ingredient.rare
                << setw(20) << ingredient.epic << endl;
    }
    cout << setfill('-') << setw(60) << "" << endl;
    cout << setfill(' ');
}
