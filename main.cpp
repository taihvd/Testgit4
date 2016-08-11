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
    int newPrice, newCout;
    int effectShow;
    int totalPriceShow,totalDiscount;
    int static idNumber=0;

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
        cout << "4.CheckOut the Store" << endl;
        cout << "5.Exit" << endl;

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

                char askKey;

                do
                {
                    cout << "Product name:" ;
                    cin >> newName;

                    cout << "Number of items:";
                    cin >> newCout;

                    idNumber++;

                    nnewName = QString::fromStdString(newName);
                    newCustomer.setName(cqName);
                    newCustomer.setId(idNumber);

                    newProduct.setName(nnewName);

                    newStock.setItems(newProduct);
                    newStock.setCout(newCout);

                    effectShow = superMarket.createOrder(newCustomer, newStock);

                    if (effectShow == 101) {
                        cout << "We don't have that product!" << endl;
                    } else if (effectShow == 10) {
                        cout << "Out of stuff!" << endl;
                    }

                    cout << "Do u want buy something else?(Y/N): ";
                    cin >> askKey;
                    if (askKey == 'N' || askKey == 'n') break;
                    //ne
                 }
                while (theChoose == 2);
                break;

            case 3:
                cout << "Customer name:";
                cin >> cName;

                infoOrder = "";
                infoOrder = superMarket.getCustomersOrder(QString::fromStdString(cName)).toStdString();

                if (infoOrder == "") {
                    cout << "Cannot find the customer!";
                } else {
                    cout << "                     "<<cName<< "                               "<<endl;
                    cout << "No.        Product         Numbers       Price       Totals  "<<endl;
                    cout << infoOrder << endl;
                }

                cout << endl;
                break;
            case 4:
                cout << "Customer name:";
                cin >> cName;

                newCustomer.setName(QString::fromStdString(cName));

                totalPriceShow = superMarket.checkOut(newCustomer);

                if (totalPriceShow == 0) {
                    cout << "Cannot find the customer!" << endl;
                } else {
                    totalDiscount = superMarket.discountCaculate(totalPriceShow , QString::fromStdString(cName));
                    cout << endl << "Discount: " << totalDiscount << endl;
                    totalPriceShow -= totalDiscount;
                    cout << endl << "Totals: " << totalPriceShow << endl;
                }

        }
    } while (theChoose != 5);

    return 0;
}
