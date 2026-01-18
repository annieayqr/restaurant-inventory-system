#include "Side.h"
#include <sstream>
#include <iomanip>

// Constructor 
Side::Side(std::string name, double price, int quantity, int threshold, SideType type,
        bool isSpicy,
        bool isVegetarian,
        bool hasGluten,
        bool hasSeafood,
        bool hasDairy,
        bool hasNuts)
    : Product(name, price, quantity, threshold), type(type),
      isSpicy(isSpicy),
      isVegetarian(isVegetarian),
      hasGluten(hasGluten),
      hasSeafood(hasSeafood),
      hasDairy(hasDairy),
      hasNuts(hasNuts) {
}

// Getters
SideType Side::getType() const {return type;}
bool Side::getIsSpicy() const {return isSpicy;}
bool Side::getIsVegetarian() const {return isVegetarian;}
bool Side::getHasGluten() const {return hasGluten;}
bool Side::getHasSeafood() const {return hasSeafood;}
bool Side::getHasDairy() const {return hasDairy;}
bool Side::getHasNuts() const {return hasNuts;}

// Setters 
void Side::setType(SideType newType) {type = newType;}
void Side::setIsSpicy(bool spicy) {isSpicy = spicy;}
void Side::setIsVegetarian(bool vegetarian) {isVegetarian = vegetarian;}
void Side::setHasGluten(bool gluten) {hasGluten = gluten;}
void Side::setHasSeafood(bool seafood) {hasSeafood = seafood;}
void Side::setHasDairy(bool dairy) {hasDairy = dairy;}
void Side::setHasNuts(bool nuts) {hasNuts = nuts;}

std::string Side::getFilename() const {return "data/side.csv";}
std::string Side::getCategory() const {return "Side";}

std::string Side::toCSV() const {
    std::ostringstream oss;
    oss << getID() << "," 
        << getName() << ","
        << std::fixed << std::setprecision(2) << getPrice() << ","
        << getQuantity() << ","
        << getThreshold() << ","
        << typeToString(type) << ","
        << (isSpicy ? "1" : "0") << ","
        << (isVegetarian ? "1" : "0") << ","
        << (hasGluten ? "1" : "0") << ","
        << (hasSeafood ? "1" : "0") << ","
        << (hasDairy ? "1" : "0") << ","
        << (hasNuts ? "1" : "0");
    return oss.str();
} 

std::string Side::typeToString(SideType type) {
    switch(type) {
        case SideType::APPETIZER: return "APPETIZER";
        case SideType::BREAD: return "BREAD";
        case SideType::DESSERT: return "DESSERT";
        case SideType::POTATO: return "POTATO";
        case SideType::SALAD: return "SALAD";
        case SideType::SOUP: return "SOUP";
        case SideType::VEGETABLES: return "VEGETABLES"; 
        case SideType::OTHER: return "OTHER";         
        default: return "OTHER";
    }
}

SideType Side::stringToType(const std::string& str) {
    if (str == "APPETIZER") return SideType::APPETIZER;
    if (str == "BREAD") return SideType::BREAD;
    if (str == "DESSERT") return SideType::DESSERT;
    if (str == "POTATO") return SideType::POTATO;
    if (str == "SALAD") return SideType::SALAD;
    if (str == "SOUP") return SideType::SOUP;
    if (str == "VEGETABLES") return SideType::VEGETABLES;
    if (str == "OTHER") return SideType::OTHER;

    return SideType::OTHER; 
}