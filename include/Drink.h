#ifndef DRINK_H
#define DRINK_H

#include "Product.h"

enum class DrinkType {
    ALCOHOL,
    COFFEE,
    JUICE,
    SODA,
    TEA,
    OTHER
};

class Drink : public Product {
private:
    DrinkType type;
    bool hasAlcohol;
    bool hasCaffeine;
    bool hasDairy;
    bool hasSugar;

public:
    // Constructor with defaults 
    Drink(std::string name, double price, int quantity, int threshold = 5, DrinkType type,
          bool hasAlcohol = false,
          bool hasCaffeine = false,
          bool hasDairy = false,
          bool hasSugar = false);

    // Destructor
    virtual ~Drink() = default;

    // Getters
    DrinkType getType() const;
    bool getHasAlcohol() const;
    bool getHasCaffeine() const;
    bool getHasDairy() const;
    bool getHasSugar() const;

    // Setters
    void setType(DrinkType newType);
    void setHasAlcohol(bool alcohol);
    void setHasCaffeine(bool caffeine);
    void setHasDairy(bool dairy);
    void setHasSugar(bool sugar);

    // Required virtual overrides
    std::string getFilename() const override;
    std::string getCategory() const override;
    std::string toCSV() const override;
    
    static std::string typeToString(DrinkType type);
    static DrinkType stringToType(const std::string& str);
};

#endif