#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include "bank.h"


uint32_t credit(Accno a,uint32_t amount ) {
if(a.accountype==05)
{
    if(a.balance < amount)
    {
        return 0;
    }
    else
    {
        a.balance =a.balance-amount;
        a.transactions++;
    }
}
else
{
    if(a.balance<2000)
    {
        a.balance=a.balance-1000;
    }
    else
    {
        a.balance=a.balance-amount;
        a.transactions++;
    }
}
return a.balance;

}

uint32_t debit(Accno a,uint32_t amount) {

if(a.transactions<=10 && a.accountype==05)
{
    a.balance=a.balance+amount;
    a.transactions++;
}
else if(a.transactions<=5)
{
    a.balance=a.balance+amount;
    a.transactions++;
}
else {
    return 0;
}
return a.balance;

}
uint32_t balancenquiry(Accno a) {
return a.balance;

}
uint32_t countcredit(Accno a) {
return a.transactions;



}
