#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include<stddef.h>
#include<stdlib.h>
#include<stdint.h>
#include<uchar.h>
typedef struct _accountno_ Accno;
struct _accountno_ {
uint32_t bankcode;
uint32_t areacode;
uint32_t accountype;
uint32_t accountnumbr;
uint32_t balance;
uint32_t transactions;
};

typedef struct _customerdetails_ Customer;
struct _customerdetails_ {
char32_t name1;
char32_t name2;
int16_t age;
uint32_t panno;
uint32_t accounttype;
uint32_t initialdeposit;
uint32_t phoneno;
};

uint32_t credit(Accno a,uint32_t amount );
uint32_t debit(Accno a,uint32_t amount);
uint32_t balancenquiry(Accno a);
uint32_t countcredit(Accno a);
uint32_t counts();

#endif // BANK_H_INCLUDED
