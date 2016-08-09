#ifndef STOCK_H
#define STOCK_H
#include<product.h>

class Stock
{
public:
    Stock();

    int getCout() const;
    void setCout(int value);

    Product getItems() const;
    void setItems(Product value);

private:
    Product items;
    int cout;
};

#endif // STOCK_H
