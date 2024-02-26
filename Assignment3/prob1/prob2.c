#include "prob1.h"

// NewCustomer function creates a new customer with the given name, address, and email
struct Customer NewCustomer(int id, const char *name, const char *address, const char *email) {
    struct Customer new_customer;

    // Each SetX method accesses the values of each field of the struct.
    SetCustomerID(&new_customer, id);
    SetCustomerName(&new_customer, name);
    SetCustomerAddress(&new_customer, address);
    SetCustomerEmail(&new_customer, email);

    return new_customer;  // Return the newly created customer
}

// PrintCustomer function prints the details of the given customer
void PrintCustomer(struct Customer customer) {
    printf("\n");
    printf("Customer Profile: \n");
    printf("ID: %d\n", customer.ID);
    printf("Name: %s\n", customer.Name);
    printf("Address: %s\n", customer.Address);
    printf("Email: %s\n\n", customer.Email);
}


// NewProduct function creates a new product with the given details
struct Product NewProduct(int id, const char *name, double price, int quantity) {
    struct Product new_product;

    SetProductID(&new_product, id);
    SetProductName(&new_product, name);
    SetProductPrice(&new_product, price);
    SetProductQuantity(&new_product, quantity);

    return new_product;  // Return the newly created product
}


// PrintProduct prints the details of the given product
void PrintProduct(struct Product product) {
    printf("\n");
    printf("Product Details: \n");
    printf("ID: %d\n", product.ID);
    printf("Name: %s\n", product.Name);
    printf("Price: %.2f\n", product.Price);
    printf("Quantity: %d\n\n", product.Quantity);
}

// NewSale function creates a new sale with the given details
struct Sale NewSale(int customerID, int productID, double amount) {
    struct Sale new_sale;

    SetSaleCustomerID(&new_sale, customerID);
    SetSaleProductID(&new_sale, productID);
    SetSaleAmount(&new_sale, amount);

    return new_sale;  // Return the newly created sale
}


// PrintSale prints the details of the given sale
void PrintSale(struct Sale sale) {
    printf("\n");
    printf("Sale Details: \n");
    printf("Customer ID: %d\n", sale.CustomerID);
    printf("Product ID: %d\n", sale.ProductID);
    printf("Amount: %.2f\n\n", sale.Amount);
}

// This program creates and appropriately accesses each struct: Customer, Product, and Sale structs.
// The syntax that I chose is influenced by my experience with the Go Programming Language and its use of structs.
int main() {
    // Creating and accessing the fields of the Customer struct as requested.
    struct Customer customer = NewCustomer(1, "John Doe", "123 Main St, Anytown, USA", "john.doe@example.com");
    PrintCustomer(customer);

    // Creating and accessing the fields of the Product struct as requested.
    struct Product product = NewProduct(1, "Product A", 10.99, 100);
    PrintProduct(product);

    // Creating and accessing the fields of the Sale struct as requested.
    struct Sale sale = NewSale(1234, 1, 1099.00);
    PrintSale(sale);


    // Now we will appropriately modify and print each one with its modifications.
    // This could have also been made to separate functions but I will instead keep them here
    // to show that we are modifying our data within the main function explicitly.
    SetCustomerID(&customer, 2);
    SetCustomerName(&customer, "Alice Smith");
    SetCustomerAddress(&customer, "456 Oak St, Smalltown, USA");
    SetCustomerEmail(&customer, "alice.smith@example.com");
    PrintCustomer(customer);

    SetProductID(&product, 2);
    SetProductName(&product, "Product B");
    SetProductPrice(&product, 9.99);
    SetProductQuantity(&product, 50);
    PrintProduct(product);

    SetSaleCustomerID(&sale, 101);
    SetSaleProductID(&sale, 2);
    SetSaleAmount(&sale, 99.95);
    PrintSale(sale);
}
