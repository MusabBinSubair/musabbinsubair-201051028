#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
#include <assert.h>

void test_credit() {
Accno A={00,0000,05,0000,0,0};
assert(credit(A,1000)==0);
}
void test_debit() {
Accno A={00,0000,02,0000,0,15};
assert(debit(A,1200)==20);
}
void test_balance() {
Accno A={00,0000,05,00000,1000,7};
assert(balancenquiry(A)==1000);

}
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

int main()
{

test_credit();
test_debit();

return 0;
}
