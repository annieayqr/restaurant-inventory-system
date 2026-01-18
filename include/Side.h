#ifndef SIDE_H
#define SIDE_H

#include "Product.h"

enum class SideType {
    APPETIZER,   // Wings, nachos, mozzarella sticks
    BREAD,       // Garlic bread, rolls, naan, biscuits
    DESSERT,     // Cakes, pies, ice cream, pudding
    POTATO,      // Fries and bashed, baked, roasted potatoes
    SALAD,       // Vegetable, fruit and pasta salads
    SOUP,        
    VEGETABLES,   // Fried, steamed and grilled vegetables
    OTHER
};

class Side : public Product {
private:
    SideType type;
    
    bool isSpicy;
    bool isVegetarian;
    bool hasGluten;
    bool hasSeafood;
    bool hasDairy;
    bool hasNuts;

public:
    // Constructor with defaults
    Side(std::string name, double price, int quantity, int threshold = 5, SideType type,
         bool isSpicy = false,
         bool isVegetarian = false,
         bool hasGluten = false,
         bool hasSeafood = false,
         bool hasDairy = false,
         bool hasNuts = false);
    
    virtual ~Side() = default;

    // Getters
    SideType getType() const;
    bool getIsSpicy() const;
    bool getIsVegetarian() const;
    bool getHasGluten() const;
    bool getHasSeafood() const;
    bool getHasDairy() const;
    bool getHasNuts() const;

    // Setters
    void setType(SideType newType);
    void setIsSpicy(bool spicy);
    void setIsVegetarian(bool vegetarian);
    void setHasGluten(bool gluten);
    void setHasSeafood(bool seafood);
    void setHasDairy(bool dairy);
    void setHasNuts(bool nuts);

    // Required virtual overrides
    std::string getFilename() const override;
    std::string getCategory() const override;
    std::string toCSV() const override;
    
    static std::string typeToString(SideType type);
    static SideType stringToType(const std::string& str);
};

#endif