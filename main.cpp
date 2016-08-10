#include <iostream>
#include "string.h"
#include <string>

#include "customer.h"
#include "product.h"
#include "store.h"
#include "stock.h"

using namespace std;

int main()
{
    Store superMarket;
    Stock newStock;
    Product newProduct;
    Customer newCustomer;

    int theChoose;
    int newPrice, newCout, customerId;
    int effectShow;

    string newName;
    string infoOrder;
    string cName;

    QString cqName;
    QString nnewName;

    do {
        cout << "What do you want?" << endl;

        cout << "1.Import Stock" << endl;
        cout << "2.Create Order" << endl;
        cout << "3.List Customer" << endl;
        cout << "4.Exit" << endl;

        cout << "And you want(number):";
        cin >> theChoose;

        switch (theChoose) {
            case 1:
                cout << "IMPORT STOCK" << endl;

                cout << "Product name:" ;
                cin >> newName;

                cout << "How much?:" ;
                cin >> newPrice;

                cout << "How many?:" ;
                cin >> newCout;

                nnewName = QString::fromStdString(newName);
                newProduct.setName(nnewName);
                newProduct.setPrice(newPrice);

                superMarket.importStock(newProduct, newCout);

                cout << "OK!" << endl << endl;

                break;

            case 2:
                cout << "Customer name:" ;
                cin >> cName;
                cqName = QString::fromStdString(cName);

                cout << "Customer id:" ;
                cin >> customerId;

                cout << "Product name:" ;
                cin >> newName;

                cout << "Number of items:";
                cin >> newCout;

                nnewName = QString::fromStdString(newName);
                newCustomer.setName(cqName);
                newCustomer.setId(customerId);

                newProduct.setName(nnewName);

                newStock.setItems(newProduct);
                newStock.setCout(newCout);

                effectShow = superMarket.createOrder(newCustomer, newProduct);

                if (effectShow == 101) {
                    cout << "We don't have that product!" << endl;
                } else if (effectShow == 10) {
                    cout << "Out of stuff!" << endl;
                }

                break;

            case 3:
                cout << "Customer name:";
                cin >> cName;

                infoOrder = "";
                infoOrder = superMarket.getCustomersOrder(QString::fromStdString(cName)).toStdString();

                if (infoOrder == "") {
                    cout << "Cannot find the customer!";
                } else {
                    cout << "Customer buy: " << infoOrder << endl;
                }

                cout << endl;
                break;
        }
    } while (theChoose != 4);

    return 0;
}
