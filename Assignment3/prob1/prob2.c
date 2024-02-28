#include "prob1.h"

#define YELLOW "\033[0;93m"
#define RESET "\033[0m"
#define CLEAR "\033[2J"
#define SECTION printf("------------------------------------------------------------------------------\n");

int main() {
    // Clear the screen
    printf(CLEAR);

    // This code does what was requested, but I moved the process of initializing and reassigning
    // the structs themselves to separate functions appropriately to make the code easier to read.
    // I used the Go Programming Language to generate some dummy data that I could use in this program.
    struct Customer customer = NewCustomer(1, "John Doe", "123 Main St, Anytown, USA", "john.doe@example.com");
    struct Product product = NewProduct(1, "Product A", 10.99, 100);
    struct Sale sale = NewSale(1, 1234, 1099.00);

    PrintCustomer(customer);
    PrintProduct(product);
    PrintSale(sale);

    SECTION;
    
    // Modify the values of the structs.
    SetCustomerID(&customer, 2);
    SetCustomerName(&customer, "Alice Smith");
    SetCustomerAddress(&customer, "456 Oak St, Smalltown, USA");
    SetCustomerEmail(&customer, "alice.smith@example.com");

    SetProductID(&product, 2);
    SetProductName(&product, "Product B");
    SetProductPrice(&product, 9.99);
    SetProductQuantity(&product, 50);

    SetSaleCustomerID(&sale, 101);
    SetSaleProductID(&sale, 2);
    SetSaleAmount(&sale, 99.95);

    // Print the modified values like it was requested.
    PrintCustomer(customer);
    PrintProduct(product);
    PrintSale(sale);
    
    return 0;

}
