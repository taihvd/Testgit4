#include "vipcustomer.h"

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


