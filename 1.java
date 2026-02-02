/* ---------------- PRODUCT ADT ---------------- */
class Product {
    String category;     // Product category
    String name;         // Product name
    String seller;       // Seller name
    double price;        // Product price
    double rating;       // Product rating

    // Constructor initializes product data
    Product(String c, String n, String s, double p, double r) {
        category = c;
        name = n;
        seller = s;
        price = p;
        rating = r;
    }
}

/* ---------------- INDIRECT ARRAY ADT ---------------- */
class IndirectArray {
    int[] indices;       // Array storing indices
    int size;            // Number of products

    // Constructor
    IndirectArray(int n) {
        size = n;
        indices = new int[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;   // Store original index
        }
    }

    // Swap helper
    void swap(int i, int j) {
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    // Sort by price (ascending)
    void sortByPrice(Product[] products) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (products[indices[j]].price >
                    products[indices[j + 1]].price) {

                    swap(j, j + 1);
                }
            }
        }
    }

    // Sort by rating (descending)
    void sortByRating(Product[] products) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (products[indices[j]].rating <
                    products[indices[j + 1]].rating) {

                    swap(j, j + 1);
                }
            }
        }
    }

    // Get product using sorted index
    Product getProductAtIndex(int i, Product[] products) {
        return products[indices[i]];
    }
}

/* ---------------- MAIN CLASS ---------------- */
public class Main {
    public static void main(String[] args) {

        // Sample product data
        Product[] products = {
            new Product("Electronics", "Laptop", "Dell", 60000, 4.5),
            new Product("Clothing", "T-Shirt", "Puma", 1500, 4.2),
            new Product("Electronics", "Mobile", "Samsung", 30000, 4.7)
        };

        IndirectArray ia = new IndirectArray(3);  // Create IndirectArray
        ia.sortByPrice(products);                 // Sort by price

        System.out.println("Sorted by Price:");
        for (int i = 0; i < 3; i++) {
            Product p = ia.getProductAtIndex(i, products);
            System.out.println(p.name + " " + p.price);
        }
    }
}
