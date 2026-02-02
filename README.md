# IndirectArray ADT for Product Sorting (E-Commerce)

## 📌 Problem Statement
This project implements an **IndirectArray Abstract Data Type (ADT)** to sort product items on a single-page e-commerce website.

Instead of sorting the actual product objects, the system sorts **indices of products**, ensuring that:
- The original product array remains unchanged
- Multiple sorting criteria can be applied efficiently

This approach is commonly used in real-world e-commerce platforms.

---

## 🧠 Concept Used
- Abstract Data Type (ADT)
- Indirect Sorting
- Bubble Sort (for demonstration clarity)
- Data Structures and Algorithms

---

## 🧩 Product ADT
Each product contains the following attributes:

- Product Category
- Product Name
- Seller Name
- Price
- Rating

---

## 🗂 IndirectArray ADT Operations

| Operation | Description |
|---------|-------------|
| `createIndirectArray(size)` | Initializes an array of indices |
| `sortProductsByCategory()` | Sorts indices by product category |
| `sortProductsByName()` | Sorts indices by product name |
| `sortProductsBySeller()` | Sorts indices by seller name |
| `sortProductsByPrice()` | Sorts indices by price (ascending) |
| `sortProductsByRating()` | Sorts indices by rating (descending) |
| `getProductAtIndex()` | Retrieves product using sorted index |

---

## 🛠 Implementations
This ADT is implemented in the following languages:

- **C** → `C/1.c`
- **C++** → `CPP/1.cpp`
- **Java** → `Java/1.java`

Each implementation strictly follows the same ADT design.

---

## 🧪 Testing
Sample product data is used in each file to demonstrate:
- Correct sorting behavior
- Integrity of original product array
- Multiple sorting criteria support

---

## 🎯 Key Advantage of IndirectArray
- No modification of original data
- Efficient multi-criteria sorting
- Better performance for large objects
- Clean separation of data and sorting logic

---

## 👨‍🎓 Academic Use
This project was developed as part of a **Data Structures & Algorithms assignment**  
demonstrating the practical use of **IndirectArray ADT** in e-commerce systems.

---

## 📎 Author
**Kushal Batra**  
