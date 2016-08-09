#ifndef PRODUCT_H
#define PRODUCT_H

#include<QString>

class Product
{
public:
    Product();

    int getPrice() const;
    void setPrice(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    QString name;
    int price;
};

#endif // PRODUCT_H
