Backend-2#include <string>
#include <iostream>
using namespace std;

class Product;

class Item {
    Product* product;
    int quantity;

public:
    Item(Product* p, int q) : product(p), quantity(q) {}

    int getItemPrice() {
        return quantity * product->price;
    }

    string getItemInfo() {
        return to_string(quantity) + " x " + product->name + " Rs " + to_string(quantity * product->price) + "\n";
    }
};

class Product {
    int id;
    string name;
    int price;

public:
    Product(int u_id, string name, int price) {
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName() {
        return name + " : Rs " + to_string(price) + "\n";
    }

    string getShortName() {
        return name.substr(0, 1);
    }

    friend class Item;
};

class Cart {   
    unordered_map<int, Item> items;

    public:

    void addProduct (Product product){
        if(items.count(product.id)==0){
            Item newitem(product,1);
            items[product.id]=newItem;
        }
    }

};