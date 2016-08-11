#ifndef VIPCUSTOMER_H
#define VIPCUSTOMER_H


class VIPCustomer: public customer
{
public:
    VIPCustomer();
    int getDiscount() const;
    void setDiscount(int value);

private:
    int discount;
    bool check;
};
#endif // VIPCUSTOMER_H
