#include "MainDish.h"
#include <sstream>
#include <iomanip>

// Constructor 
MainDish::MainDish(std::string name, double price, int quantity, int threshold, MainType type, 
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
MainType MainDish::getType() const {return type;}
bool MainDish::getIsSpicy() const {return isSpicy;}
bool MainDish::getIsVegetarian() const {return isVegetarian;}
bool MainDish::getHasGluten() const {return hasGluten;}
bool MainDish::getHasSeafood() const {return hasSeafood;}
bool MainDish::getHasDairy() const {return hasDairy;}
bool MainDish::getHasNuts() const {return hasNuts;}

// Setters 
void MainDish::setType(MainType newType) {type = newType;}
void MainDish::setIsSpicy(bool spicy) {isSpicy = spicy;}
void MainDish::setIsVegetarian(bool vegetarian) {isVegetarian = vegetarian;}
void MainDish::setHasGluten(bool gluten) {hasGluten = gluten;}
void MainDish::setHasSeafood(bool seafood) {hasSeafood = seafood;}
void MainDish::setHasDairy(bool dairy) {hasDairy = dairy;}
void MainDish::setHasNuts(bool nuts) {hasNuts = nuts;}
    
std::string MainDish::getFilename() const {return "data/main_dish.csv";}
std::string MainDish::getCategory() const {return "Main";}

std::string MainDish::toCSV() const {
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

std::string MainDish::typeToString(MainType type) {
    switch(type) {
        case MainType::BURGER: return "BURGER";
        case MainType::MEAT: return "MEAT";
        case MainType::PASTA: return "PASTA";
        case MainType::RICE: return "RICE";
        case MainType::OTHER: return "OTHER";
        default: return "OTHER";
    }
}

MainType MainDish::stringToType(const std::string& str) {
    if (str == "BURGER") return MainType::BURGER;
    if (str == "MEAT") return MainType::MEAT;
    if (str == "PASTA") return MainType::PASTA;
    if (str == "RICE") return MainType::RICE;
    if (str == "OTHER") return MainType::OTHER;

    return MainType::OTHER; 
}