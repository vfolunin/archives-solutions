class Solution {
public:
    vector<int> addNegabinary(vector<int> &a, vector<int> &b) {
        vector<int> res;
        
        for (int ai = a.size() - 1, bi = b.size() - 1, carry = 0; ai >= 0 || bi >= 0 || carry; ai--, bi--) {
            int aDigit = ai >= 0 ? a[ai] : 0;
            int bDigit = bi >= 0 ? b[bi] : 0;
            int sum = aDigit + bDigit + carry;
            
            res.push_back((sum % 2 + 2) % 2);
            if (sum < 0)
                carry = 1;
            else if (sum < 2)
                carry = 0;
            else
                carry = -1;
        }
        
        while (res.size() > 1 && !res.back())
            res.pop_back();
        reverse(res.begin(), res.end());
        
        return res;
    }
};