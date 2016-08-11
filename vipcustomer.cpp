#include "vipcustomer.h"
#include "customer.h"
VIPCustomer::VIPCustomer()
{

}
int VIPCustomer::getDiscount() const
{
    return discount;
}

void VIPCustomer::setDiscount(int value)
{
    discount = value;
    //da get set
}
bool VIPCustomer::getCheck() const
{
    return check;
}

void VIPCustomer::setCheck(bool value)
{
    check = value;
}



