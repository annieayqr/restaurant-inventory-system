#include "Product.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>

int Product::nextID = 1;

const std::string OUT_OF_STOCK = " is out of stock.";
const std::string LOW_STOCK = " is low on stock. Qty: ";

// Constructor
Product::Product(std::string name, double price, int quantity, int threshold) 
    : name(name), price((price >= 0) ? price : 0), quantity ((quantity >= 0)? quantity : 0), 
      threshold((threshold >= 0)? threshold : 5){
    ID = nextID++;
}

// Getters
int Product::getID() const {return ID;}
std::string Product::getName() const {return name;}
double Product::getPrice() const {return price;}
int Product::getQuantity() const {return quantity;}
int Product::getThreshold() const {return threshold;}

/* Setters */

void Product::setName(std::string newName) {
    if (newName.empty()) throw std::invalid_argument("Name can't be empty.");
    name = newName;
}

void Product::setPrice(double newPrice) {
    if (newPrice < 0) throw std::invalid_argument("Price can't be negative.");
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    if (newQuantity < 0) throw std::invalid_argument("Qty can't be negative.");
    quantity = newQuantity;
}
void Product::setThreshold(int newThreshold) {
    if (newThreshold < 0) throw std::invalid_argument("Threshold can't be negative.");
    threshold = newThreshold;
}

// Apply discount
void Product::operator*(double discountFactor) {
    price *= discountFactor;
}

// Restock and sell
void Product::adjustStock(int amount) {
    if (amount == 0) {
        throw std::invalid_argument("Amount cannot be zero.");
    } else if (amount > 0) {
        quantity += amount;
    } else {
        int sellAmount = -amount;
        if (sellAmount > quantity) throw std::invalid_argument("Insufficient stock.");
        quantity -= sellAmount;
    }
}

// Alert if out of stock or low stock
void Product::checkStock() const { 
    if (quantity == 0)
        std::cout << name << OUT_OF_STOCK << std::endl;  // Alert if out of stock
    else if (quantity < threshold && threshold > 0) {
        std::cout << name << LOW_STOCK << quantity << std::endl;   // Alert if low stock alerts are on
    }
}

// Print product details
std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << std::fixed << std::setprecision(2) << "[ID: " << product.getID() << "] " << 
          product.getName() << " | $" << product.getPrice() << " | Qty:" 
          << product.getQuantity() << " | Threshold:" << product.getThreshold();
    return os;
}