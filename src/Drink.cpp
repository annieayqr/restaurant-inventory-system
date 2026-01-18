#include "Drink.h"
#include <sstream>
#include <iomanip>

// Constructor 
Drink::Drink(std::string name, double price, int quantity, int threshold, DrinkType type,
             bool hasAlcohol,
             bool hasCaffeine,
             bool hasDairy,
             bool hasSugar)
      : Product(name, price, quantity, threshold), type(type),
        hasAlcohol(hasAlcohol),
        hasCaffeine(hasCaffeine),
        hasDairy(hasDairy),
        hasSugar(hasSugar) {
}

// Getters
DrinkType Drink::getType() const {return type;}
bool Drink::getHasAlcohol() const {return hasAlcohol;}
bool Drink::getHasCaffeine() const {return hasCaffeine;}
bool Drink::getHasDairy() const {return hasDairy;}
bool Drink::getHasSugar() const {return hasSugar;}

// Setters
void Drink::setType(DrinkType newType) {type = newType;}
void Drink::setHasAlcohol(bool alcohol) {hasAlcohol = alcohol;}
void Drink::setHasCaffeine(bool caffeine) {hasCaffeine = caffeine;}
void Drink::setHasDairy(bool dairy) {hasDairy = dairy;}
void Drink::setHasSugar(bool sugar) {hasSugar = sugar;}

std::string Drink::getFilename() const {return "data/drink.csv";}
std::string Drink::getCategory() const {return "Drink";}
std::string Drink::toCSV() const {
    std::ostringstream oss;
    oss << getID() << ","
        << getName() << ","
        << std::fixed << std::setprecision(2) << getPrice() << ","
        << getQuantity() << ","
        << getThreshold() << ","
        << typeToString(type) << ","
        << (hasAlcohol ? "1" : "0") << ","
        << (hasCaffeine ? "1" : "0") << ","
        << (hasDairy ? "1" : "0") << ","
        << (hasSugar ? "1" : "0");
    return oss.str();
}

std::string Drink::typeToString(DrinkType type) {
    switch(type) {
        case DrinkType::ALCOHOL: return "ALCOHOL";
        case DrinkType::COFFEE: return "COFFEE";
        case DrinkType::JUICE: return "JUICE";
        case DrinkType::SODA: return "SODA";
        case DrinkType::TEA: return "TEA";
        case DrinkType::OTHER: return "OTHER";
        default: return "OTHER";
    }
}

DrinkType Drink::stringToType(const std::string& str) {
    if (str == "ALCOHOL") return DrinkType::ALCOHOL;
    if (str == "COFFEE") return DrinkType::COFFEE;
    if (str == "JUICE") return DrinkType::JUICE;
    if (str == "SODA") return DrinkType::SODA;
    if (str == "TEA") return DrinkType::TEA;
    if (str == "OTHER") return DrinkType::OTHER;
    
    return DrinkType::OTHER;
}