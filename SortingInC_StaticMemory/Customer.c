//
//  Customer.c
//  SortingInC
//
//  Created by Panayotis Matsinopoulos on 10/7/21.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Customer.h"

Customer CreateCustomer(const char *iFirstName, const char *iLastName) {
  assert(iFirstName);
  assert(iLastName);

  Customer result;
  
  unsigned long sizeOfBuffer = 0;
  if (iFirstName) {
    sizeOfBuffer = sizeof(char) * (strlen(iFirstName) + 1);
    result.firstName = malloc(sizeOfBuffer);
    memset(result.firstName, 0, sizeOfBuffer);
    strcpy(result.firstName, iFirstName);
  }
  else {
    result.firstName = NULL;
  }
  
  if (iLastName) {
    sizeOfBuffer = sizeof(char) * (strlen(iLastName) + 1);
    result.lastName = malloc(sizeOfBuffer);
    memset(result.lastName, 0, sizeOfBuffer);
    strcpy(result.lastName, iLastName);
  }
  else {
    result.lastName = NULL;
  }
  return result;
}

void DestroyCustomer(Customer *oCustomer) {
  assert(oCustomer);
  
  if (oCustomer->firstName) {
    free(oCustomer->firstName);
    oCustomer->firstName = NULL;
  }
  if (oCustomer->lastName) {
    free(oCustomer->lastName);
    oCustomer->lastName = NULL;
  }
}

char *CustomerFullNameCString(Customer iCustomer) {
  size_t bufferSize = (strlen(iCustomer.lastName) + 1 + strlen(iCustomer.firstName) + 1) * sizeof(char);
  char *result = malloc(bufferSize);
  memset((void *)result, 0, bufferSize);
  
  sprintf((char *)result, "%s %s", iCustomer.lastName, iCustomer.firstName);
  
  return result;
}

// follows the prototype that "qsort()" prescribes for the comparison function
int CustomerComparison(const void *aCustomer, const void *bCustomer) {
  Customer a = *(Customer *)aCustomer;
  Customer b = *(Customer *)bCustomer;

  int lastNameComparison = strcmp(a.lastName, b.lastName);
  if (lastNameComparison) {
    return lastNameComparison;
  }
  
  return strcmp(a.firstName, a.lastName);
}

void PrintCustomers(Customer customers[], size_t numberOfCustomers) {
  for(size_t i = 0; i < numberOfCustomers; i++) {
    char *fullName = CustomerFullNameCString(customers[i]);
    printf("Customer %lu: %s\n", i, fullName);
    free(fullName);
  }
}

