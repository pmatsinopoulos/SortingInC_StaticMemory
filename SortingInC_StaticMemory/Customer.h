//
//  Customer.h
//  SortingInC
//
//  Created by Panayotis Matsinopoulos on 10/7/21.
//

#ifndef Customer_h
#define Customer_h

typedef struct {
  char *firstName;
  char *lastName;
} Customer;

Customer CreateCustomer(const char *iFirstName, const char *iLastName);
void DestroyCustomer(Customer *oCustomer);
int CustomerComparison(const void *aCustomer, const void *bCustomer);
char *CustomerFullNameCString(Customer iCustomer);
void PrintCustomers(Customer customers[], size_t numberOfCustomers);
#endif /* Customer_h */
