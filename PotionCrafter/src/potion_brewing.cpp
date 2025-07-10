#include "potion_brewing.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cctype> // for tolower()

using namespace std;

PotionCrafting::PotionCrafting() {
    recipeMap["mushroom, snowflake"] = {
        "Ice-Shroom",
        "Creates an AOE ice explosion that inflicts the 'slowed' status...",
        "Especially effective to 'fire' type enemies!"
    };

    recipeMap["lizard_tail, mushroom"] = {
        "Steam Bomb",
        "Creates steam within a medium range that obstructs view.",
        "Use it to initiate surprise attacks or to flee!"
    };

    recipeMap["dragonfly_wings, snowflake"] = {
        "Mystic Brew",
        "Enhances magical abilities considerably for 10 minutes.",
        "Best used before initiating a fight!"
    };

    recipeMap["dragon_scale, mushroom"] = {
        "Pyro-Influence Potion",
        "Enables the user to unleash 'fire' type magic for 10 minutes.",
        "Better make use of it's utility!"
    };

    recipeMap["snowflake, unicorn_hair"] = {
        "Cryo-Influence Potion",
        "Enables the user to unleash 'ice' type magic for 10 minutes.",
        "Better make use of it's utility!"
    };

    recipeMap["dragonfly_wings, lizard_tail"] = {
        "Flying Potion",
        "Enables the user to fly for 10 minutes.",
        "Don't forget to keep track of the time!"
    };

    recipeMap["dragonfly_wings, unicorn_hair"] = {
        "Agility Potion", // Changed from duplicate "Mystic Brew"
        "Greatly enhances agility for 10 minutes.",
        "Best used before initiating an exploration quest!"
    };

    recipeMap["dragon_scale, lizard_tail"] = {
        "Stonewall Potion",
        "Greatly enhances defense for 10 minutes.",
        "Best used before initiating a fight!"
    };

    recipeMap["dragon_scale, unicorn_hair"] = {
        "Treasured Coin",
        "Flip the coin. If heads: summons a tiny unicorn...",
        "Best used before initiating a fight!"
    };
}

string PotionCrafting::normalizeIngredient(const string& input) {
    string result;

    for (char c : input) {
        if (c == ' ') {  // Fixed: == instead of =
            result += '_';
        } else {
            result += tolower(c);
        }
    }

    return result;
}

string PotionCrafting::createRecipeKey(const string& ingredient1, const string& ingredient2)
{
    string norm1 = normalizeIngredient(ingredient1);
    string norm2 = normalizeIngredient(ingredient2);

    vector<string> ingredients = {norm1, norm2};
    sort(ingredients.begin(), ingredients.end());
    return ingredients[0] + ", " + ingredients[1];
}

Potion* PotionCrafting::craftPotion(const string& ingredient1, const string& ingredient2) {
    string norm1 = normalizeIngredient(ingredient1);
    string norm2 = normalizeIngredient(ingredient2);

    // cout << "DEBUG: Normalized ingredients: " << norm1 << ", " << norm2 << endl;

    string key = createRecipeKey(ingredient1, ingredient2);
    // cout << "DEBUG: Looking for key: " << key << endl;

    auto it = recipeMap.find(key);
   /* if (it != recipeMap.end()) {
        cout << "DEBUG: Found recipe: " << it->second.name << endl;
    } */

    return (it != recipeMap.end()) ? &(it->second) : nullptr;
}


