#ifndef SALE_H
#define SALE_H

namespace SaleCAS1102 {

class Sale
{
public:
    Sale();
    Sale(double thePrice);
    double getPrice() const;
    void setPrice(double newPrice);
    virtual double bill() const;
    // double bill() const;
    double savings(const Sale &other) const;
private:
    double price;
}; // end class Sale

bool operator <(const Sale &first, const Sale &second);

} // end namespace SaleCAS1102

#endif // SALE_H
