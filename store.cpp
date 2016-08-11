#include "store.h"
#include <QString>
#include "customer.h"
#include "product.h"
#include "stock.h"
#include "string.h"
#include "QPair"
Store::Store()
{
}


int Store::createOrder(Customer nc, Stock np)
{
    bool flag;
    QPair<Customer, Stock> cp;
    cp.first = nc;
    cp.second = np;
    flag = false;

    for (int i = 0; i < Customers.count(); i++)
        if (Customers.at(i).getName() == nc.getName()) {
            flag = true;
        }

    if (flag == false) {
        Customers.push_back(nc);
    }

    flag = false;
    for (int i = 0; i < ProductStocks.count(); i++) {
        if (ProductStocks.at(i).getItems().getName() == np.getItems().getName()) {
            cp.second.getItems().setPrice(ProductStocks.at(i).getItems().getPrice());
            if (ProductStocks.at(i).getCout() == 0) {
                return 10;
            } else {
                Stock x;
                x.setCout(ProductStocks.at(i).getCout() - 1);
                x.setItems(ProductStocks.at(i).getItems());
                ProductStocks.replace(i, x);
                flag = true;
            }
        }
    }

    if (flag == false) {
        return 101;
    }
    listCustomerOrderByName.push_back(cp);
    return 0;
}

QString Store::getCustomersOrder(QString fname)
{
    QString t = "";
    QString num;
    int placeTake=0;
    for (int i = 0; i < listCustomerOrderByName.count(); i++) {
        if (listCustomerOrderByName.at(i).first.getName() == fname) {
            placeTake++;
            num = "Number:" + QString::number(placeTake) + " ";
            t += num;
            t += listCustomerOrderByName.at(i).second.getItems().getName();
            num = QString::number(listCustomerOrderByName.at(i).second.getCout());
            t += " " + num;
            num = QString::number(listCustomerOrderByName.at(i).second.getItems().getPrice());
            t += " " + num + "\n";
        }
    }

    return t;
}

bool Store::importStock(Product np, int sl)
{
    Stock x;
    x.setItems(np);
    x.setCout(sl);

    for (int i = 0; i < ProductStocks.count(); i++)
        if (ProductStocks.at(i).getItems().getName() == np.getName()) {
            x.setCout(x.getCout() + ProductStocks.at(i).getCout());
            ProductStocks.remove(i, 1);
        }

    ProductStocks.push_back(x);
    return true;
}

QVector<Stock> Store::getProductStocks() const
{
    return ProductStocks;
}

void Store::setProductStocks(const QVector<Stock> &value)
{
    ProductStocks = value;
}

QVector<Customer> Store::getCustomers() const
{
    return Customers;
}

void Store::setCustomers(const QVector<Customer> &value)
{
    Customers = value;
}
QVector<QPair<Customer, Stock> > Store::getListCustomerOrderByName() const
{
    return listCustomerOrderByName;
}

void Store::setListCustomerOrderByName(const QVector<QPair<Customer, Stock> > &value)
{
    listCustomerOrderByName = value;
}








