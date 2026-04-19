#include "Inventory.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Destructor
Inventory::~Inventory() {
    for (Product* p : products) {
        delete p;
    }
}

// 1. Adjust stock
bool Inventory::adjustStock(int id, int amount) {
    Product* product = findProduct(id);
    if(!product) {
        return false;
    }

    product->adjustStock(amount);
    return true;
}

// 2. Find and filter products
Product* Inventory::findProduct(int id) const {
    for (Product* p : products) {
        if (p->getID() == id) {
            return p;
        }
    }
    return nullptr;
}

/* General filters */

std::vector<Product*> Inventory::searchByName(const std::string& name) const {
    std::vector<Product*> results;
    
    // Convert search term to lowercase
    std::string searchLower = name;
    std::transform(searchLower.begin(), searchLower.end, searchLower.begin(), [](unsigned char c) {return std::tolower(c)});
    for (Product* p : products) {
        if (p->getName == )
    }
}

std::vector<Product*> Inventory::filterByCategory(const std::string& category) const {

}

std::vector<Product*> Inventory::filterByType(const std::string& type) const {

}

std::vector<Product*> Inventory::filterByPrice(double min, double max) const {

}

std::vector<Product*> Inventory::filterLowStock() const {

}

std::vector<Product*> Inventory::filterOutOfStock() const {

}

// Dietary filters
std::vector<Product*> Inventory::filterTag(DietaryTag tag, bool value) const {

}

// 3. View all products
std::vector<Product*> Inventory::getAllProducts() const {

}

// 4. Create product
void Inventory::createProduct(Product* product) {

}

/* 5. Edit product */

bool Inventory::updateName(int id, const std::string& newName) {

}

bool Inventory::updatePrice(int id, double newPrice) {

}

bool Inventory::updateThreshold(int id, int newThreshold) {

}

/* Update product type using function overloading */

bool Inventory::updateType(int id, MainType newType) {

}

bool Inventory::updateType(int id, SideType newType) {

}

bool Inventory::updateType(int id, DrinkType newType) {

}

// Update dietary tags
bool Inventory::updateTag(int id, DietaryTag tag, bool newValue) {

}

// 6. Create product
bool Inventory::deleteProduct(int id) {

}

// Automatic stock alerts
void Inventory::checkAllStock() const {

}

/* Statistics */

double Inventory::getTotalValue() const {

}

int Inventory::getProductCount() const {

}

/* File operations */
void Inventory::loadFromCSV() {

}
void Inventory::saveToCSV() const {

}