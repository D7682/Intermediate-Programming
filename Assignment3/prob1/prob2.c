#include "prob1.h"

// ANSI escape codes for colored text
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"
#define CLEAR "\033[2J"
#define SECTION printf("------------------------------------------------------------------------------\n");

int main() {
    // Clear the screen
    printf(CLEAR);

    // Initialization of variables and print initial values (as requested explicitly by our assignment)
    /*
        In this section:
        1. Variables are initialized with dummy values for each struct type.
        2. Initial values of each type are printed in the terminal.
        3. A SECTION separator is defined to distinguish initial values from the modified ones.
    */
    Customer customer = NewCustomer(1, "John Doe", "123 Main St, Anytown, USA", "john.doe@example.com");
    Product product = NewProduct(1, "Product A", 10.99, 100);
    Sale sale = NewSale(1, 1234, 1099.00);

    PrintCustomer(customer); // Printing initial customer details
    PrintProduct(product);   // Printing initial product details
    PrintSale(sale);         // Printing initial sale details

    SECTION; // Printing a section separator for clarity
    
    // Modification of initial values (as requested by our assignment)
    /*
        Here:
        1. Initial values of each struct are changed to new dummy variables.
        2. Modified values are printed as requested.
    */
    customer.ID = 2; // Change customer ID
    strcpy(customer.Name, "Alice Smith"); // Change customer name
    strcpy(customer.Address, "456 Oak St, Smalltown, USA"); // Change customer address
    strcpy(customer.Email, "alice.smith@example.com"); // Change customer email

    product.ID = 2; // Change product ID
    product.Price = 9.99; // Change product price
    product.Quantity = 50; // Change product quantity
    strcpy(product.Name, "Product B"); // Change product name

    sale.CustomerID = 101; // Change sale's customer ID
    sale.ProductID = 2; // Change sale's product ID
    sale.Amount = 99.95; // Change sale amount

    // Print the modified values
    PrintCustomer(customer); // Printing modified customer details
    PrintProduct(product);   // Printing modified product details
    PrintSale(sale);         // Printing modified sale details
    
    return 0;
}
