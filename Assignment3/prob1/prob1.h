#include <stdio.h>
#include <string.h> // for strcpy

struct Customer {
    int ID;
    char Name[50];
    char Address[100];
    char Email[40];
};

struct Sale {
    int CustomerID;
    int ProductID;
    double Amount;
};

struct Product {
    int ID;
    char Name[50];
    double Price;
    int Quantity;
};

// Set functions for Product
void SetProductID(struct Product *p, int id) {
    p->ID = id;
}

void SetProductName(struct Product *p, const char *name) {
    strncpy(p->Name, name, sizeof(p->Name)-1);
    p->Name[sizeof(p->Name)-1] = '0'; 
}

void SetProductPrice(struct Product *p, double price) {
    p->Price = price;
}

void SetProductQuantity(struct Product *p, int quantity) {
    p->Quantity = quantity;
}

// Set functions for Customer
void SetCustomerID(struct Customer *c, int id) {
    c->ID = id;
}

void SetCustomerName(struct Customer *c, const char *name) {
    strncpy(c->Name, name, sizeof(c->Name)-1);
    c->Name[sizeof(c->Name)-1] = '0';
}

void SetCustomerAddress(struct Customer *c, const char *address) {
    strncpy(c->Address, address, sizeof(c->Address)-1);
    c->Address[sizeof(c->Address)-1] = '0';
}

void SetCustomerEmail(struct Customer *c, const char *email) {
    strncpy(c->Email, email, sizeof(c->Email)-1);
    c->Email[sizeof(c->Email)-1] = '0';
}

// Set functions for Sale
void SetSaleCustomerID(struct Sale *s, int customerID) {
    s->CustomerID = customerID;
}

void SetSaleProductID(struct Sale *s, int productID) {
    s->ProductID = productID;
}

void SetSaleAmount(struct Sale *s, double amount) {
    s->Amount = amount;
}

// Constructor functions
struct Product NewProduct(int id, const char *name, double price, int quantity) {
    struct Product product;
    product.ID = id;
    strcpy(product.Name, name);
    product.Price = price;
    product.Quantity = quantity;
    return product;
}

struct Customer NewCustomer(int id, const char *name, const char *address, const char *email) {
    struct Customer customer;
    customer.ID = id;
    strcpy(customer.Address, address);
    strcpy(customer.Email, email);
    strcpy(customer.Name, name);
    return customer;
    
}

struct Sale NewSale(int productID, int customerID, double amount) {
    struct Sale sale;
    sale.CustomerID = customerID;
    sale.ProductID = productID;
    sale.Amount = amount;
    return sale;
}


// Set the print functions that take in a struct and format the output into the terminal.

// PrintCustomer function prints the details of the given customer
void PrintCustomer(struct Customer customer) {
    printf("Customer Profile: \n");
    printf("ID: %d\n", customer.ID);
    printf("Name: %s\n", customer.Name);
    printf("Address: %s\n", customer.Address);
    printf("Email: %s\n\n", customer.Email);
}

// PrintProduct prints the details of the given product
void PrintProduct(struct Product product) {
    printf("Product Details: \n");
    printf("ID: %d\n", product.ID);
    printf("Name: %s\n", product.Name);
    printf("Price: %.2f\n", product.Price);
    printf("Quantity: %d\n\n", product.Quantity);
}

// PrintSale prints the details of the given sale
void PrintSale(struct Sale sale) {
    printf("\n");
    printf("Sale Details: \n");
    printf("Product ID: %d\n", sale.ProductID);
    printf("Customer ID: %d\n", sale.CustomerID);
    printf("Amount: %.2f\n\n", sale.Amount);
}