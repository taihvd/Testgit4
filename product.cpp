#include "product.h"
#include <QString>
Product::Product()
{

}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int value)
{
    price = value;
}
QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}




