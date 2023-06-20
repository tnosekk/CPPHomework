#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class negative_balance_exception : public std::out_of_range 
{
public:
    negative_balance_exception(const std::string& message, double deficit)
        :std::out_of_range(message), deficit(deficit) {}

    double getDeficit() const {
        return deficit;
    }

private:
    double deficit;
};

class account_info 
{
public:
    account_info(const std::string& accountNum, const std::string& ownerName, double balance)
        :accountNum(accountNum), ownerName(ownerName), balance(balance) {}

    double getBalance() const {
        return balance;
    }

private:
    std::string accountNum;
    std::string ownerName;
    double balance;
};

int main() {

    std::vector<account_info> accounts{
        account_info("123456789", "Franciszek", 1390.5),
        account_info("987654321", "Magdalena", -538.0),
        account_info("555555555", "Ala", 3040.4)
    };

    for (const account_info& account : accounts) {
        try {
            if (account.getBalance() < 0) {
                throw negative_balance_exception("Negative balance detected.", -account.getBalance());
            }
            std::cout << "Account balance: " << account.getBalance() << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << " Deficit: " << dynamic_cast<const negative_balance_exception&>(ex).getDeficit() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}