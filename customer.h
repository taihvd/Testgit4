#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
class Customer
{
public:
    Customer();
    int getId() const;
    void setId(int value);


    QString getName() const;
    void setName(const QString &value);

private:
    int id;
    QString name;
};

#endif // CUSTOMER_H
