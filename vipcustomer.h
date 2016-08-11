#ifndef VIPCUSTOMER_H
#define VIPCUSTOMER_H
#include "customer.h"

class VIPCustomer: public Customer
{
public:
    VIPCustomer();
    int getDiscount() const;
    void setDiscount(int value);

    bool getCheck() const;
    void setCheck(bool value);

private:
    int discount;
    bool check;
};
#endif // VIPCUSTOMER_H
