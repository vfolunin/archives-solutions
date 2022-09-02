class Solution {
    vector<int> check(string &s, int a, int b) {
        string cur = to_string(a) + to_string(b);
        vector<int> res = { a, b };
        
        while (cur.size() < s.size()) {
            long long c = 0LL + a + b;
            if (c >= 1LL << 31)
                return {};
            
            cur += to_string(c);
            res.push_back(c);
            
            a = b;
            b = c;            
        }
        
        if (cur.size() == s.size() && cur == s)
            return res;
        else
            return {};
    }
    
    
public:
    vector<int> splitIntoFibonacci(string &s) {
        for (int lenA = 1; lenA <= 10 && lenA < s.size(); lenA++) {
            string sa = s.substr(0, lenA);
            if (lenA > 1 && sa[0] == '0')
                continue;
            long long a = stoll(sa);
            if (a >= 1LL << 31)
                continue;
            
            for (int lenB = 1; lenB <= 10 && lenA + lenB < s.size(); lenB++) {
                string sb = s.substr(lenA, lenB);
                if (lenB > 1 && sb[0] == '0')
                    continue;
                long long b = stoll(sb);
                if (b >= 1LL << 31)
                    continue;
                
                if (vector<int> res = check(s, a, b); !res.empty())
                    return res;
            }
        }
        
        return {};
    }
};