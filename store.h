#ifndef STORE_H
#define STORE_H

#include "stock.h"
#include "product.h"
#include "customer.h"
#include "vipcustomer.h"

#include "QString"
#include "QVector"
#include "QPair"

class Store
{
public:
    Store();

    bool importStock(Product np,int sl);
    int createOrder(Customer nc,Stock np);
    long long checkOut(Customer nc);
    long long discountCaculate(long long totalPrice, QString customerName);

    VIPCustomer changeToVip(Customer oldCustomer);

    QString getCustomersOrder(QString fname);

    QVector<Stock> getProductStocks() const;
    void setProductStocks(const QVector<Stock> &value);

    QVector<Customer *> getCustomers() const;
    void setCustomers(const QVector<Customer *> &value);

    QVector<QPair<Customer, Stock> > getListCustomerOrderByName() const;
    void setListCustomerOrderByName(const QVector<QPair<Customer, Stock> > &value);

    QVector<VIPCustomer> getVipCustomers() const;
    void setVipCustomers(const QVector<VIPCustomer> &value);

private:
    QVector<Customer *> Customers;
    QVector<Stock> ProductStocks;
    QVector<QPair<Customer,Stock> > listCustomerOrderByName;
    QVector<VIPCustomer> VipCustomers;
};
#endif // STORE_H
