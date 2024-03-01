#include <stdio.h>
#include <string.h> // Include for strcpy()

typedef struct {
    int ID;
    char Name[50];
    double Price;
    int Quantity;
} Product;

typedef struct {
    int ID;
    char Name[50];
    char Address[100];
    char Email[40];
} Customer;

typedef struct {
    int CustomerID;
    int ProductID;
    double Amount;
} Sale;


// Constructor functions and "methods" for each type.
Product NewProduct(int id, char *name, double price, int quantity) {
    Product product = {
        .ID = id,
        .Price = price,
        .Quantity = quantity
    };
    
    // Copy name
    if (name != NULL) {
        strncpy(product.Name, name, 49);
        product.Name[49] = '\0'; // Ensure null-terminated
    }

    return product;
}


void PrintProduct(Product product) {
    printf("Product Details: \n");
    printf("ID: %d\n", product.ID);
    printf("Name: %s\n", product.Name);
    printf("Price: %.2f\n", product.Price);
    printf("Quantity: %d\n\n", product.Quantity);
}

Customer NewCustomer(int id, char *name, char *address, char *email) {
    Customer customer = {
        .ID = id
    };

    // Copy name
    if (name != NULL) {
        strncpy(customer.Name, name, 49);
        customer.Name[49] = '\0'; // Ensure null-terminated
    }

    // Copy address
    if (address != NULL) {
        strncpy(customer.Address, address, 99);
        customer.Address[99] = '\0'; // Ensure null-terminated
    }

    // Copy email
    if (email != NULL) {
        strncpy(customer.Email, email, 39);
        customer.Email[39] = '\0'; // Ensure null-terminated
    }

    return customer;
}

void PrintCustomer(Customer customer) {
    printf("Customer Profile: \n");
    printf("ID: %d\n", customer.ID);
    printf("Name: %s\n", customer.Name);
    printf("Address: %s\n", customer.Address);
    printf("Email: %s\n\n", customer.Email);
}

Sale NewSale(int productID, int customerID, double amount) {
    Sale sale = {
        .CustomerID = customerID,
        .ProductID = productID,
        .Amount = amount
    };
    return sale;
}

void PrintSale(Sale sale) {
    printf("\n");
    printf("Sale Details: \n");
    printf("Product ID: %d\n", sale.ProductID);
    printf("Customer ID: %d\n", sale.CustomerID);
    printf("Amount: %.2f\n\n", sale.Amount);
}