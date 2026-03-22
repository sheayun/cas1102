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
    double getBalance() const;
    int getDollars() const;
    int getCents() const;
    double getRate() const;

    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    void setRate(double newRate);

private:
  	int accountDollars;
  	int accountCents;
  	double rate;
    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;

    double fracion(double percent) const;
};


bool isLarger(const BankAccount &account1, const BankAccount &account2);

void welcome(const BankAccount & yourAccount);

int main()
{
    BankAccount account1(6543.21, 4.5), account2;
    welcome(account1);

    cout << "Enter data for account 2:\n";
    account2.input();
    if (isLarger(account1, account2))
        cout << "account 1 is larger.\n";
    else
        cout << "account 2 is at least as large as account 1.\n";

    return 0;
}

bool isLarger(const BankAccount &account1, const BankAccount &account2)
{
    return account1.getBalance() > account2.getBalance();
}

void welcome(const BankAccount & yourAccount)
{
    cout << "Welcome to our bank.\n"
         << "The status of your account is:\n";
    yourAccount.output();
}
