class ATM {
    vector<long long> banknotes;
    
public:
    ATM() : banknotes(5) {}
    
    void deposit(vector<int> banknoteCount) {
        for (int i = 0; i < banknotes.size(); i++)
            banknotes[i] += banknoteCount[i];
    }
    
    vector<int> withdraw(int amount) {
        static vector<int> nominals = { 20, 50, 100, 200, 500 };
        vector<int> banknoteCount(banknotes.size());
        
        for (int i = banknotes.size() - 1; i >= 0; i--) {
            banknoteCount[i] = min<long long>(banknotes[i], amount / nominals[i]);
            amount -= banknoteCount[i] * nominals[i];
        }
        
        if (amount)
            return { -1 };
        
        for (int i = 0; i < banknotes.size(); i++)
            banknotes[i] -= banknoteCount[i];
        
        return banknoteCount;
    }
};