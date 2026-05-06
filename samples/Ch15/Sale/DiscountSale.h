#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H

#include "Sale.h"

namespace SaleCAS1102 {

class DiscountSale : public Sale
{
public:
    DiscountSale();
    DiscountSale(double thePrice, double theDiscount);
    double getDiscount() const;
    void setDiscount(double newDiscount);
    double bill() const;
private:
    double discount;
}; // end class DiscountSale

} // end namespace SaleCAS1102

#endif // DISCOUNTSALE_H