#ifndef POTION_BREWING_H
#define POTION_BREWING_H

#include <string>
#include <map>

struct Potion {
    std::string name;
    std::string description;
    std::string tip;
};

class PotionCrafting {
private:
    std::map<std::string, Potion> recipeMap;

public:
    PotionCrafting();  // Fixed capitalization (was potionCrafting)
    std::string normalizeIngredient(const std::string& input);
    std::string createRecipeKey(const std::string& ingredient1, const std::string& ingredient2);
    Potion* craftPotion(const std::string& ingredient1, const std::string& ingredient2);
};

#endif // POTION_BREWING_H
