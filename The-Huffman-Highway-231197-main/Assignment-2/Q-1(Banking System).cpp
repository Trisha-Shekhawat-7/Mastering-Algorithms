#include <bits/stdc++.h>
using namespace std;

long long int Bank_account_counter = 1LL ;
const string password = "231197" ;

class Transaction {
public:
    int amount; // Transaction Amount
    int current_balance; // Current balance after the transaction
    string date; // Date of transaction in dd/mm/yyyy format
    string transaction_type; // Type of transaction (e.g., Deposit, Withdrawal, Loan)

    Transaction(int amt, int curr_bal, const string& dt, const string& type) 
        : amount(amt), current_balance(curr_bal), date(dt), transaction_type(type) {}
};

class Account {
private:
    long long int account_number;
    vector<pair<string, string>> account_holders; // List of account holders (name pairs)
    string address;
    int account_balance;
    vector<Transaction> transactions;
    string account_type;
    vector<pair<int, string>> loans; // Loan amount and date

public:
    Account() : account_balance(0) {}

    void make_account(long long int acc_num, const string& fname, const string& mname, const string& lname, const string& addr, const string& acc_type) {
        account_number = acc_num;
        account_holders.push_back({fname + " " + mname, lname});
        address = addr;
        account_type = acc_type;
    }

    void deposit(int money_to_be_deposited, const string& date) {
        account_balance += money_to_be_deposited;
        transactions.push_back(Transaction(money_to_be_deposited, account_balance, date, "Deposit"));
        cout << "Deposited\n";
    } 

    void withdraw(int money, const string& date) {
        if (account_balance >= money) {
            account_balance -= money;
            transactions.push_back(Transaction(money, account_balance, date, "Withdrawal"));
            cout << "Money withdrawn successfully\n";
        } else {
            cout << "INSUFFICIENT BALANCE\n";
        }
    }  

    void update_account_info(const string& new_address) {
        address = new_address;
        cout << "Address updated successfully\n";
    } 

    // Joint Account
    void add_account_holder(const string& fname, const string& lname) {
        account_holders.push_back({fname, lname});
        cout << "Joint account holder added successfully\n";
    }

    void loan(int money, const string& date) {
        account_balance += money;
        loans.push_back({money, date});
        transactions.push_back(Transaction(money, account_balance, date, "Loan"));
        cout << "Loan Granted\n";
    }
    
    // Transferring Funds between two accounts
    void transfer(Account& to_account, int amount, const string& date) {
        if (account_balance >= amount) {
            withdraw(amount, date);
            to_account.deposit(amount, date);
            cout << "Transferred " << amount << " to account number " << to_account.get_account_number() << endl;
        } else {
            cout << "INSUFFICIENT BALANCE\n";
        }
    }

    void view_passbook() const {
        cout << "Passbook for account number: " << account_number << endl;
        for (const auto& it : transactions) {
            cout << "Amount: Rs. " << it.amount << "/- | Transaction Date: " << it.date 
                 << " | Transaction Type: " << it.transaction_type << endl;
            cout << "Current Account Balance: Rs. " << it.current_balance << "/-" << endl;
            cout << "\n";
        }
    }

    void search_transaction(int transaction_amount, const string& transaction_date) const {
        int flag = 0;
        for (const auto& it : transactions) {
            if (it.amount == transaction_amount && it.date == transaction_date) {
                cout << "Transaction Found. Transaction details are as follows...\n"; 
                cout << "Amount: Rs. " << it.amount << "/- | Transaction Date: " << it.date 
                     << " | Transaction Type: " << it.transaction_type << endl;
                cout << "Current Account Balance: Rs. " << it.current_balance << "/-\n";
                flag++;
            }
        }
        if (flag == 0) {
            cout << "No Such Transaction found.\n";
        }
    }

    long long get_account_number() const {
        return account_number;
    }
    
    void print(){
        for(auto holder : account_holders) cout<<holder.first<<" "<<holder.second<<endl ;
        cout<<account_balance<<endl ;
    }
    
};

void print_menu() {
    cout << "Select one option from below:\n";
    cout << "1. Open an Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Update Account Information\n";
    cout << "5. Joint Account\n";
    cout << "6. View Passbook\n";
    cout << "7. Search Transaction History\n";
    cout << "8. Transfer Money\n";
    cout << "9. Details of all Bank Accounts\n";
    cout << "10. Quit\n";
    cout << "Enter Your Choice: ";
}

int main() {
    map<long long int, Account> Bank; 
    int choice;

    while (true) {
        print_menu();
        cin >> choice;
        if (choice == 10) break;

        switch(choice) {
            case 1: {
                long long int acc_num = Bank_account_counter ;
                string fname, mname, lname, addr, acc_type;
                cout << "Enter First Name: ";
                cin >> fname;
                cout << "Enter Middle Name: ";
                cin >> mname;
                cout << "Enter Last Name: ";
                cin >> lname;
                cout << "Enter Address: ";
                cin.ignore();
                getline(cin, addr);
                cout << "Enter Account Type (e.g., Savings, Checking): ";
                cin >> acc_type;
                Account new_account;
                new_account.make_account(acc_num, fname, mname, lname, addr, acc_type);
                Bank[acc_num] = new_account;
                cout << "Account created successfully.\nYour Account Number is :"<<Bank_account_counter<<endl ;
                
                Bank_account_counter++ ;
                break;
            }
            case 2: {
                long long int acc_num;
                int amount;
                string date;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                cout << "Enter Date (dd/mm/yyyy): ";
                cin >> date;
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].deposit(amount, date);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                long long int acc_num;
                int amount;
                string date;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                cout << "Enter Date (dd/mm/yyyy): ";
                cin >> date;
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].withdraw(amount, date);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                long long int acc_num;
                string new_address;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                cout << "Enter New Address: ";
                cin.ignore();
                getline(cin, new_address);
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].update_account_info(new_address);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 5: {
                long long int acc_num;
                string fname, lname;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                cout << "Enter Joint Account Holder's First Name: ";
                cin >> fname;
                cout << "Enter Joint Account Holder's Last Name: ";
                cin >> lname;
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].add_account_holder(fname, lname);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 6: {
                long long int acc_num;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].view_passbook();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 7: {
                long long int acc_num;
                int amount;
                string date;
                cout << "Enter Account Number: ";
                cin >> acc_num;
                cout << "Enter Transaction Amount: ";
                cin >> amount;
                cout << "Enter Transaction Date (dd/mm/yyyy): ";
                cin >> date;
                if (Bank.find(acc_num) != Bank.end()) {
                    Bank[acc_num].search_transaction(amount, date);
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 8: {
                long long int from_acc_num, to_acc_num;
                int amount;
                string date;
                cout << "Enter Your Account Number: ";
                cin >> from_acc_num;
                cout << "Enter Recipient Account Number: ";
                cin >> to_acc_num;
                cout << "Enter Amount to Transfer: ";
                cin >> amount;
                cout << "Enter Date (dd/mm/yyyy): ";
                cin >> date;
                if (Bank.find(from_acc_num) != Bank.end() && Bank.find(to_acc_num) != Bank.end()) {
                    Bank[from_acc_num].transfer(Bank[to_acc_num], amount, date);
                } else {
                    cout << "One or both accounts not found.\n";
                }
                break;
            }
            case 9: {
                string pwd ;
                cout<<"Enter Password : \n" ;
                cin>>pwd ;
                if(pwd != password ){
                    cout<<"Wrong Password!Try Again.\n" ;
                }else{
                    for(auto acc : Bank){
                        Bank[acc.first].print() ;
                    }
                } 
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
