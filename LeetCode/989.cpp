class Solution {
public:
    vector<int> addToArrayForm(vector<int> &a, int carry) {
        reverse(a.begin(), a.end());

        for (int i = 0; carry; i++) {
            if (i == a.size())
                a.push_back(0);
            
            a[i] += carry;
            carry = a[i] / 10;
            a[i] %= 10;
        }
        
        reverse(a.begin(), a.end());
        
        return a;
    }
};