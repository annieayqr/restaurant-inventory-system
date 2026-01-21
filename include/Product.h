#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    int ID;             // Unique identifier for each product
    std::string name;
    double price;   
    int quantity;       // Number in stock
    int threshold;      // Quantity threshold for alerts, 0 turns off automated low-stock alerts
    static int nextID;  // Counter for auto-generating IDs
    
public:
    // Constructor and destructor
    Product(std::string name, double price, int quantity, int threshold = 5);
    virtual ~Product() = default;
    
    // Getters
    int getID() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    int getThreshold() const;

    // Setters
    void setName(std::string newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void setThreshold(int newThreshold);

    void operator*(double discountFactor);  // Apply discount and modify object (e.g. product * 0.8 = 20% off)

    // Restock and sell
    void adjustStock(int amount);       // Positive for restock, negative for sell

    void checkStock() const;                    // Alert if out of stock or low stock

    virtual std::string getFilename() const = 0;     // Get which CSV file to print to
    virtual std::string getCategory() const = 0;     // Get product category (Main Dish / Side / Drink)
    virtual std::string toCSV() const = 0;           // Convert to CSV format for saving
};

// Print product details using operator overloading
std::ostream& operator<<(std::ostream& os, const Product& product);  // Quick print product info

#endif