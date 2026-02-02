#include <stdio.h>      // Provides input/output functions like printf
#include <string.h>     // Provides string handling functions like strcmp

/* ---------------- PRODUCT ADT ---------------- */
/* This structure represents a Product */
typedef struct {
    char category[30];  // Stores product category
    char name[30];      // Stores product name
    char seller[30];    // Stores seller name
    float price;        // Stores product price
    float rating;       // Stores product rating
} Product;

/* ---------------- INDIRECT ARRAY ADT ---------------- */
/* This structure stores indices of products */
typedef struct {
    int indices[50];    // Array to store indices of products
    int size;           // Number of products
} IndirectArray;

/* Initializes the IndirectArray with default indices */
void createIndirectArray(IndirectArray *ia, int size) {
    ia->size = size;                    // Set number of elements
    for (int i = 0; i < size; i++) {
        ia->indices[i] = i;             // Store original index positions
    }
}

/* Swaps two integer values */
void swap(int *a, int *b) {
    int temp = *a;                      // Store value of a
    *a = *b;                            // Assign value of b to a
    *b = temp;                          // Assign stored value to b
}

/* Sorts products by price in ascending order */
void sortProductsByPrice(IndirectArray *ia, Product products[]) {
    for (int i = 0; i < ia->size - 1; i++) {
        for (int j = 0; j < ia->size - i - 1; j++) {

            // Compare prices using indices
            if (products[ia->indices[j]].price >
                products[ia->indices[j + 1]].price) {

                // Swap only indices, not products
                swap(&ia->indices[j], &ia->indices[j + 1]);
            }
        }
    }
}

/* Sorts products by rating in descending order */
void sortProductsByRating(IndirectArray *ia, Product products[]) {
    for (int i = 0; i < ia->size - 1; i++) {
        for (int j = 0; j < ia->size - i - 1; j++) {

            // Higher rating comes first
            if (products[ia->indices[j]].rating <
                products[ia->indices[j + 1]].rating) {

                swap(&ia->indices[j], &ia->indices[j + 1]);
            }
        }
    }
}

/* Returns product at a given sorted position */
Product getProductAtIndex(int index, IndirectArray *ia, Product products[]) {
    return products[ia->indices[index]];   // Access product using sorted index
}

/* ---------------- MAIN FUNCTION (TESTING) ---------------- */
int main() {

    // Creating sample product data
    Product products[3] = {
        {"Electronics", "Laptop", "Dell", 60000, 4.5},
        {"Clothing", "T-Shirt", "Puma", 1500, 4.2},
        {"Electronics", "Mobile", "Samsung", 30000, 4.7}
    };

    IndirectArray ia;                       // Declare IndirectArray
    createIndirectArray(&ia, 3);            // Initialize IndirectArray

    sortProductsByPrice(&ia, products);     // Sort by price

    printf("Sorted by Price:\n");
    for (int i = 0; i < ia.size; i++) {
        Product p = getProductAtIndex(i, &ia, products);
        printf("%s %s %.2f\n", p.category, p.name, p.price);
    }

    return 0;                               // Program ends
}
