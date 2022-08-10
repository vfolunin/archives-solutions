class Solution {
public:
    string repeatLimitedString(string &s, int limit) {
        map<char, int> freqs;
        for (char c : s)
            freqs[c]++;
        
        int row = 0;
        string res;
        
        while (!freqs.empty()) {
            auto it = prev(freqs.end());
            auto &[c, freq] = *it;
            
            if (res.empty() || res.back() != c || row < limit) {
                if (res.empty() || res.back() != c)
                    row = 1;
                else
                    row++;
                res += c;                
                
                if (!--freq)
                    freqs.erase(it);
            } else if (freqs.size() == 1) {
                break;
            } else {
                auto it = prev(prev(freqs.end()));
                auto &[c, freq] = *it;
                
                row = 1;
                res += c;
                
                if (!--freq)
                    freqs.erase(it);
            }
        }
        
        return res;
    }
};