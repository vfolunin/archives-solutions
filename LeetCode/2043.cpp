class Bank {
    vector<long long> balance;
    
public:
    Bank(vector<long long> &balance) : balance(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if (account1 < 0 || account1 >= balance.size() || balance[account1] < money ||
            account2 < 0 || account2 >= balance.size())
            return 0;
        
        balance[account1] -= money;
        balance[account2] += money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if (account < 0 || account >= balance.size())
            return 0;
        
        balance[account] += money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if (account < 0 || account >= balance.size() || balance[account] < money)
            return 0;
        
        balance[account] -= money;
        return 1;
    }
};