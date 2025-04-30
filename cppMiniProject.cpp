#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // For fixed and setprecision

using namespace std;

// Base class for Property
class Property {
protected:
    string name;
    double price;
    double area;  // Area of the property in square feet

public:
    // Constructor
    Property(string n, double p, double a) : name(n), price(p), area(a) {}

    // Virtual function to display property details
    virtual void display() const = 0;

    // Getter functions for price and area
    double getPrice() const { return price; }
    double getArea() const { return area; }

    // Virtual function to get property type
    virtual string getType() const = 0;

    // Virtual destructor
    virtual ~Property() {}
};

// Derived class for Residential Property
class ResidentialProperty : public Property {
public:
    ResidentialProperty(string n, double p, double a) : Property(n, p, a) {}

    void display() const override {
        // Display without scientific notation and formatted as integers
        cout << "Residential Property: " << name << ", Price: " << fixed << setprecision(0) << price << ", Area: " << area << " sq ft" << endl;
    }

    string getType() const override {
        return "Residential";
    }
};

// Derived class for Commercial Property
class CommercialProperty : public Property {
public:
    CommercialProperty(string n, double p, double a) : Property(n, p, a) {}

    void display() const override {
        cout << "Commercial Property: " << name << ", Price: " << fixed << setprecision(0) << price << ", Area: " << area << " sq ft" << endl;
    }

    string getType() const override {
        return "Commercial";
    }
};

// Derived class for Land Property
class LandProperty : public Property {
public:
    LandProperty(string n, double p, double a) : Property(n, p, a) {}

    void display() const override {
        cout << "Land Property: " << name << ", Price: " << fixed << setprecision(0) << price << ", Area: " << area << " sq ft" << endl;
    }

    string getType() const override {
        return "Land";
    }
};

// Template class to manage properties
template <typename T>
class PropertyManager {
    vector<T*> properties;

public:
    void addProperty(T* property) {
        properties.push_back(property);
    }

    void removeProperty(int index) {
        if (index >= 0 && index < properties.size()) {
            delete properties[index];
            properties.erase(properties.begin() + index);
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void displayProperties() const {
        if (properties.empty()) {
            cout << "No properties to display!" << endl;
            return;
        }

        for (size_t i = 0; i < properties.size(); ++i) {
            properties[i]->display();
        }
    }

    double calculateTotalPrice() const {
        double total = 0;
        for (size_t i = 0; i < properties.size(); ++i) {
            total += properties[i]->getPrice();
        }
        return total;
    }

    void searchByPrice(double minPrice, double maxPrice) const {
        bool found = false;
        for (size_t i = 0; i < properties.size(); ++i) {
            if (properties[i]->getPrice() >= minPrice && properties[i]->getPrice() <= maxPrice) {
                properties[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No properties found in the given price range!" << endl;
        }
    }

    void searchByType(const string& type) const {
        bool found = false;
        for (size_t i = 0; i < properties.size(); ++i) {
            if (properties[i]->getType() == type) {
                properties[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No properties found of type: " << type << endl;
        }
    }

    ~PropertyManager() {
        for (size_t i = 0; i < properties.size(); ++i) {
            delete properties[i];
        }
    }
};

int main() {
    // Create a property manager object
    PropertyManager<Property> manager;

    // Add properties
    ResidentialProperty* house1 = new ResidentialProperty("House 1", 5000000, 2000);   // 50 lakh
    CommercialProperty* shop1 = new CommercialProperty("Shop 1", 10000000, 1500);      // 1 crore
    LandProperty* land1 = new LandProperty("Land 1", 2500000, 5000);                   // 25 lakh

    manager.addProperty(house1);
    manager.addProperty(shop1);
    manager.addProperty(land1);

    // Display all properties
    cout << "All Properties:\n";
    manager.displayProperties();

    // Calculate total price of properties
    cout << "\nTotal Price of Properties: " << fixed << setprecision(0) << manager.calculateTotalPrice() << endl;

    // Search properties by price range
    cout << "\nSearching properties between 4000000 and 10000000:\n";
    manager.searchByPrice(4000000, 10000000);

    // Search properties by type
    cout << "\nSearching for Residential Properties:\n";
    manager.searchByType("Residential");

    // Remove a property and display again
    manager.removeProperty(1);  // Remove the second property (Shop 1)
    cout << "\nUpdated Property List:\n";
    manager.displayProperties();

    return 0;
}

