#ifndef INVENTORY_H
#define INVENTORY_H

#include "MainDish.h"
#include "Side.h"
#include "Drink.h"
#include <vector>
#include <string>

enum class DietaryTag {
    SPICY,
    VEGETARIAN,
    GLUTEN,
    SEAFOOD,
    DAIRY,
    NUTS,
    ALCOHOL,
    CAFFEINE,
    SUGAR
};

class Inventory {
private:
    std::vector<Product*> products;

public:
    // Constructor and destructor
    Inventory();
    ~Inventory();

    // 1. Modify stock
    bool modifyStock(int id, int amount);

    /* 2. Find and filter products */
    Product* findProduct(int id) const;

    // General filters
    std::vector<Product*> searchByName(const std::string& name) const;
    std::vector<Product*> filterByCategory(const std::string& category) const;
    std::vector<Product*> filterByType(const std::string& type) const;
    std::vector<Product*> filterByPrice(double min, double max) const;
    std::vector<Product*> filterLowStock() const;
    std::vector<Product*> filterOutOfStock() const;

    // Dietary filters
    std::vector<Product*> filterTag(DietaryTag tag, bool value) const;

    // 3. View all products
    std::vector<Product*> getAllProducts() const;

    // 4. Create product
    void createProduct(Product* product);

    /* 5. Edit product */
    bool updateName(int id, const std::string& newName);
    bool updatePrice(int id, double newPrice);
    bool updateThreshold(int id, int newThreshold);

    // Update product type using function overloading
    bool updateType(int id, MainType newType);
    bool updateType(int id, SideType newType);
    bool updateType(int id, DrinkType newType);

    // Update dietary tags
    bool updateTag(int id, DietaryTag tag, bool newValue);

    // 6. Create product
    bool deleteProduct(int id);

    // Automatic stock alerts
    void checkAllStock() const;

    // Statistics
    double getTotalValue() const;
    int getProductCount() const;

    // File operations
    void loadFromCSV();
    void saveToCSV() const;
};

#endif