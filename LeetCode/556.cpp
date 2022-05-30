class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long res = stoll(s);
        return n < res && res <= INT_MAX ? res : -1;
    }
};