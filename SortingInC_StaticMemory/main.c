//
//  main.c
//  SortingInC_StaticMemory
//
//  Created by Panayotis Matsinopoulos on 11/7/21.
//
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

int main(int argc, const char * argv[]) {
  const int numberOfCustomers = 3;
  
  Customer customers[numberOfCustomers];
  customers[0] = CreateCustomer("Peter", "Pan");
  customers[1] = CreateCustomer("Mary", "Foo");
  customers[2] = CreateCustomer("John", "Woo");

  PrintCustomers(customers, numberOfCustomers);
  
  qsort(customers, numberOfCustomers, sizeof(Customer), CustomerComparison);
  
  printf("After sorting:\n");
  
  PrintCustomers(customers, numberOfCustomers);
  
  for(int i = 0; i < numberOfCustomers; i++) {
    DestroyCustomer(&customers[i]);
  }
  
  printf("Bye!\n");
  
  return 0;
}
