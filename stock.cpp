#include "stock.h"

Stock::Stock()
{

}
int Stock::getCout() const
{
    return cout;
}

void Stock::setCout(int value)
{
    cout = value;
}
Product Stock::getItems() const
{
    return items;
}

void Stock::setItems(Product value)
{
    items = value;
}






