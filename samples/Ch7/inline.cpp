#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(double balance, double rate);
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();

    void update();
    void input();
    void output() const;

    double getBalance() const {
        return accountDollars + accountCents * 0.01;
    }
    int getDollars() const { return accountDollars; }
    int getCents() const { return accountCents; }
    double getRate() const { return rate; }

    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    void setRate(double newRate);

private:
    int accountDollars;
    int accountCents;
    double rate;

    int dollarsPart(double amount) const {
        return static_cast<int>(amount);
    }
    int centsPart(double amount) const;

    int round(double number) const {
        return static_cast<int>(floor(number + 0.5));
    }

    double fracion(double percent) const {
        return (percent / 100.0);
    }
};
