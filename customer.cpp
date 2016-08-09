#include "customer.h"
#include "string.h"
#include <QString>

Customer::Customer()
{

}
int Customer::getId() const
{
    return id;
}

void Customer::setId(int value)
{
    id = value;
}
QString Customer::getName() const
{
    return name;
}

void Customer::setName(const QString &value)
{
    name = value;
}







