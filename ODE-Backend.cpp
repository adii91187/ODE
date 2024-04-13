Backend-1



#include <iostream>
#include <vector>
#include "Datamodel.h" 
using namespace std;

vector<Product> allProducts = {
    Product(1, "Apple", 40),
    Product(2, "Orange", 30),
    Product(3, "Banana", 20),
    Product(6, "Juice", 120),
    Product(7, "Milk", 100),
    Product(8, "Bread", 50)
};

Product* chooseProduct() {
    string productList;
    cout << "Available products: " << endl;

    for (auto& product : allProducts) {
        productList += product.getDisplayName() + "\n"; 
    }
    cout << productList << endl;

    cout << "__________ " << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++) {
        if (allProducts[i].getShortName() == choice) {
            return &allProducts[i];
        }
    }
    cout << "Product Not Found!!" << endl;

    return nullptr; // Using nullptr instead of NULL
}

int main() {
    char action;
    while (true) {
        cout << "Select an action: (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;

        if (action == 'a') {
            Product* product = chooseProduct();
            if (product != nullptr) {
                cout << "Added To The Cart " << product->getDisplayName() << endl;
            }
        }
        else if (action == 'v') {
            // View cart functionality
        }
        else if (action == 'c') {
            // Checkout functionality
        }
    }
    return 0;
}