#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class BankAPI {
private:
  // TODO - in-memory db should be changed to use real banking-releted API.
  unordered_map<string, int> balanceByAccount;
  unordered_map<string, string> pinByAccount;

public:
  BankAPI() {
  }

  // Simulates fetching account balance from the bank
  virtual int getBalance(const string& accountNumber) {
    return this->balanceByAccount[accountNumber];
  }

  // Simulates updating account balance after deposit
  virtual bool deposit(const string& accountNumber, int amount) {
    this->balanceByAccount[accountNumber] += amount;
    return true;
  }

  // Simulates updating account balance after withdrawal
  virtual bool withdraw(const string& accountNumber, int amount) {
    if(this->balanceByAccount[accountNumber] < amount) {
      return false;
    }

    this->balanceByAccount[accountNumber] -= amount;
    return true;
  }

  // Simulates PIN verification with the bank
  virtual bool verifyPIN(const string& accountNumber, const string& pin) {
    // TODO - Verify PIN with the bank API.
    return this->pinByAccount[accountNumber] == pin;
  }
};

class ATMController {
private:
  BankAPI& bankAPI;

public:
  ATMController(BankAPI& bankAPI) : bankAPI(bankAPI) {}

  void insertCard() {
    cout << "Card inserted." << endl;
  }

  bool enterPIN(const string& accountNumber, const string& pin) {
    cout << "PIN entered." << endl;
    return bankAPI.verifyPIN(accountNumber, pin);
  }

  int seeBalance(const string& accountNumber) {
    std::cout << "Seeing balance." << endl;
    return bankAPI.getBalance(accountNumber);
  }

  bool deposit(const string& accountNumber, int amount) {
    std::cout << "Depositing $" << amount << "." << endl;
    return bankAPI.deposit(accountNumber, amount);
  }

  bool withdraw(const string& accountNumber, int amount) {
    std::cout << "Withdrawing $" << amount << "." << endl;
    return bankAPI.withdraw(accountNumber, amount);
  }
};

/*int main() {
  BankAPI bankAPI; 
  ATMController atm(bankAPI);

  atm.insertCard();

  string accountNumber = "851-51";
  string pin = "1234";

  if (atm.enterPIN(accountNumber, pin)) {
    int balance = atm.seeBalance(accountNumber);
    cout << "Balance: $" << balance << endl;

    atm.deposit(accountNumber, 100);
    atm.withdraw(accountNumber, 50);

    balance = atm.seeBalance(accountNumber);
    cout << "Balance: $" << balance << endl;
  } else {
    cout << "Incorrect PIN." << endl;
  }

  return 0;
}
*/