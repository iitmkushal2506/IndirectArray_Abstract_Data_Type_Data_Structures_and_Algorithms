#include <iostream>     // For input/output
#include <string>       // For string class
using namespace std;

/* ---------------- PRODUCT ADT ---------------- */
struct Product {
    string category;    // Product category
    string name;        // Product name
    string seller;      // Seller name
    float price;        // Product price
    float rating;       // Product rating
};

/* ---------------- INDIRECT ARRAY ADT ---------------- */
class IndirectArray {
    int *indices;       // Dynamic array of indices
    int size;           // Number of products

public:
    // Constructor initializes indices
    IndirectArray(int n) {
        size = n;
        indices = new int[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;   // Store original positions
        }
    }

    // Swap helper function
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Sort products by price (ascending)
    void sortByPrice(Product products[]) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (products[indices[j]].price >
                    products[indices[j + 1]].price) {

                    swap(indices[j], indices[j + 1]);
                }
            }
        }
    }

    // Sort products by rating (descending)
    void sortByRating(Product products[]) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (products[indices[j]].rating <
                    products[indices[j + 1]].rating) {

                    swap(indices[j], indices[j + 1]);
                }
            }
        }
    }

    // Get product using sorted index
    Product getProductAtIndex(int i, Product products[]) {
        return products[indices[i]];
    }
};

/* ---------------- MAIN FUNCTION ---------------- */
int main() {

    // Sample product data
    Product products[3] = {
        {"Electronics", "Laptop", "Dell", 60000, 4.5},
        {"Clothing", "T-Shirt", "Puma", 1500, 4.2},
        {"Electronics", "Mobile", "Samsung", 30000, 4.7}
    };

    IndirectArray ia(3);         // Create IndirectArray
    ia.sortByRating(products);  // Sort by rating

    cout << "Sorted by Rating:\n";
    for (int i = 0; i < 3; i++) {
        Product p = ia.getProductAtIndex(i, products);
        cout << p.name << " " << p.rating << endl;
    }

    return 0;                   // Program ends
}
