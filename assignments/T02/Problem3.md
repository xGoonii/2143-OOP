## Solution for problem 3

```cpp
class BankAcc{
    private:
        string name;
        double amount;
        string account;
    public:
        BankAcc();
        BankAcc(string n, double money);
        BankAcc(string n);
        BankAcc(double money);
        void setAccountNumber(string acc);
        string getAccountNumber();
        double getBalance();
        void deposit(double n);
        void withdraw(double n);
        void transfer(string acc, string acc2, double money);
};

int main(){

}

        BankAcc::BankAcc(){
            name = "";
            amount = 0;
            account = "";
        }
        BankAcc::BankAcc(string n, double money){
            name = n;
            amount = money;
            account = "";
        }
        BankAcc::BankAcc(string n){
            name = n;
            amount = 0;
            account = "";
        }
        BankAcc::BankAcc(double money){
            name = "";
            amount = money;
            account = "";
        }
        void BankAcc::setAccountNumber(string acc){
            account = acc;
        }
        string BankAcc::getAccountNumber(){
            return account;
        }
        double BankAcc::getBalance(){
            return amount;
        }
        void BankAcc::deposit(double n){
            amount += n;
        }
        void BankAcc::withdraw(double n){
            amount -= n;
        }

        // looked up logic for function. I overcomplicated it.
        void BankAcc::transfer(string acc1, string acc2, double money){
                if(account == acc1){
                    amount -= money;
                }
                if(account == acc2){
                    amount += money;
                }
        }
```