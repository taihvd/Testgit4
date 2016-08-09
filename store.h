#ifndef STORE_H
#define STORE_H
#include "customer.h"
#include "product.h"
#include "QString"
#include "QVector"
#include "stock.h"
#include "QPair"

class Store
{
public:
    Store();
    bool importStock(Product np,int sl);
    int createOrder(Customer nc,Product np);
    QString getCustomersorder(QString fname);

    QVector<Stock> getProductStocks() const;
    void setProductStocks(const QVector<Stock> &value);

    QVector<Customer> getCustomers() const;
    void setCustomers(const QVector<Customer> &value);

    QVector<QPair<Customer, Product> > getListCustomerOrderByName() const;
    void setListCustomerOrderByName(const QVector<QPair<Customer, Product> > &value);

private:
    QVector<Customer> Customers;
    QVector<Stock> ProductStocks;
    QVector<QPair<Customer,Product> > listCustomerOrderByName;
};

#endif // STORE_H
