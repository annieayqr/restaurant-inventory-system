#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    int id;             // Unique identifier for each product
    string name;
    double price;   
    int quantity;       // Number in stock
    int threshold;      // Quantity threshold for alerts
    static int nextID;  // Counter for auto-generating IDs
    
public:
    // Constructor and destructor
    Product(string name, double price, int quantity, int threshold = 5);
    virtual ~Product() = default;
    
    // Getters
    int getID() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    int getThreshold() const;

    // Setters
    void setName(string newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void setThreshold(int newThreshold);

    // Useful operators
    Product& operator()(int amount);            // Quick restock / sell 
    string operator[](int index) const;         // Print variable by index
    Product& operator*(double discountFactor);  // Apply discount and modify object (e.g. product * 0.8 = 20% off)
    friend ostream& operator<<(ostream& os, const Product& product);  // Quick print product info

    // Restock and sell
    void restock(int amount);
    void sell(int amount);

    bool isLowStock() const;                    // Check if product is low on stock

    virtual void display() const = 0;           // Print product info
    virtual string getCategory() const = 0;     // Get product category (Main Dish / Side / Drink)
    virtual string toCSV() const = 0;           // Convert to CSV format for saving
};

#endif
