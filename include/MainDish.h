#ifndef MAINDISH_H
#define MAINDISH_H

#include "Product.h"

enum class MainType {
    BURGER,
    MEAT,
    PASTA,
    RICE,
    OTHER
};

class MainDish : public Product {
private:
    MainType type;

    bool isSpicy;
    bool isVegetarian;
    bool hasGluten;
    bool hasSeafood;
    bool hasDairy;
    bool hasNuts;

public:
    // Constructor with defaults
    MainDish(std::string name, double price, int quantity, int threshold, MainType type, 
                   bool isSpicy = false, 
                   bool isVegetarian = false, 
                   bool hasGluten = false,
                   bool hasSeafood = false, 
                   bool hasDairy = false, 
                   bool hasNuts = false);
    
    // Destructor
    virtual ~MainDish() = default;

    // Getters
    MainType getType() const;
    bool getIsSpicy() const;
    bool getIsVegetarian() const;
    bool getHasGluten() const;
    bool getHasSeafood() const;
    bool getHasDairy() const;
    bool getHasNuts() const;

    // Setters
    void setType(MainType newType);
    void setIsSpicy(bool spicy);
    void setIsVegetarian(bool vegetarian);
    void setHasGluten(bool gluten);
    void setHasSeafood(bool seafood);
    void setHasDairy(bool dairy);
    void setHasNuts(bool nuts);

    std::string getFilename() const override;
    std::string getCategory() const override;
    std::string toCSV() const override;
    
    static std::string typeToString(MainType type);
    static MainType stringToType(const std::string& str);
};

#endif