#include <stdio.h>
#ifndef PROB1_H
#define PROB1_H

struct Product {
    int ID;
    char Name[50];
    double Price;
    int Quantity;
};

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

// SetX method for struct Product
void SetProductID(struct Product *product, int id) {
    product->ID = id;
}

void SetProductName(struct Product *product, const char *name) {
    int i = 0;
    while (i < sizeof(product->Name) - 1 && name[i] != '\0') {
        product->Name[i] = name[i];
        i++;
    }
    product->Name[i] = '\0'; // Ensure null terminator
}

void SetProductPrice(struct Product *product, double price) {
    product->Price = price;
}

void SetProductQuantity(struct Product *product, int quantity) {
    product->Quantity = quantity;
}

// SetX method for struct Customer
void SetCustomerID(struct Customer *customer, int id) {
    customer->ID = id;
}

void SetCustomerName(struct Customer *customer, const char *name) {
    int i = 0;
    while (i < sizeof(customer->Name) - 1 && name[i] != '\0') {
        customer->Name[i] = name[i];
        i++;
    }
    customer->Name[i] = '\0'; // Ensure null terminator
}

void SetCustomerAddress(struct Customer *customer, const char *address) {
    int i = 0;
    while (i < sizeof(customer->Address) - 1 && address[i] != '\0') {
        customer->Address[i] = address[i];
        i++;
    }
    customer->Address[i] = '\0'; // Ensure null terminator
}

void SetCustomerEmail(struct Customer *customer, const char *email) {
    int i = 0;
    while (i < sizeof(customer->Email) - 1 && email[i] != '\0') {
        customer->Email[i] = email[i];
        i++;
    }
    customer->Email[i] = '\0'; // Ensure null terminator
}

// SetX method for struct Sale
void SetSaleCustomerID(struct Sale *sale, int customerID) {
    sale->CustomerID = customerID;
}

void SetSaleProductID(struct Sale *sale, int productID) {
    sale->ProductID = productID;
}

void SetSaleAmount(struct Sale *sale, double amount) {
    sale->Amount = amount;
}
#endif /* PROB1_H */