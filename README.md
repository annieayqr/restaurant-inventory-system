![C++](https://img.shields.io/badge/C++-11-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-in%20development-yellow.svg)
![Platform](https://img.shields.io/badge/platform-macOS%20%7C%20Linux%20%7C%20Windows-lightgrey.svg)

# Restaurant Inventory System in C++

A comprehensive C++ inventory management system for restaurants with allergy-aware filtering and real-time stock tracking.

## Current Implementation
- **Product Base Class** - Product class with core inventory logic
- **MainDish Derived Class** - MainDish implementations
- **Inventory Management** - Restock, sell, and track quantities with configurable low-stock alerts
- **Allergy & Dietary Tracking** - Tags for nuts, dairy, seafood, gluten, eggs, vegetarian, spicy, alcohol
- **Auto-incrementing IDs** - Unique product identification system

## To Be Implemented
- **Derived Classes** - Side, Drink implementations
- **Smart Filtering System** - Lambda-based filters for price ranges, stock levels, and dietary constraints
- **CSV Serialization** - File persistence for products

### **Separated CSV Files by Product Type**
- `data/main_dish.csv` - Main dish inventory
- `data/sides.csv` - Side dish inventory  
- `data/drink.csv` - Beverage inventory

## Advanced C++ Features
- C++11 lambdas for flexible filtering
- Strongly-typed enum classes
- Operator overloading for natural syntax
- Exception handling for robust error management
- STL containers and algorithms