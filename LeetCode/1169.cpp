vector<string> split(string &line, const string &separators) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (separators.find(c) == -1) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

struct Transaction {
    string str, name, city;
    int time, amount;
    
    Transaction(string &s) {
        str = s;
        vector<string> tokens = split(s, ",");
        name = tokens[0];
        time = stoi(tokens[1]);
        amount = stoi(tokens[2]);
        city = tokens[3];
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string> &log) {
        unordered_map<string, vector<Transaction>> transactions;
        for (string &row : log) {
            Transaction t(row);
            transactions[t.name].push_back(t);
        }
        
        vector<string> res;
        
        for (auto &[name, t] : transactions) {
            for (int i = 0; i < t.size(); i++) {
                if (t[i].amount > 1000) {
                    res.push_back(t[i].str);
                    continue;
                }
                
                for (int j = 0; j < t.size(); j++) {
                    if (abs(t[i].time - t[j].time) <= 60 && t[i].city != t[j].city) {
                        res.push_back(t[i].str);
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};