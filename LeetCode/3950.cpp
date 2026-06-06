class Solution {
public:
    bool consecutiveSetBits(int n) {
        string bin;
        for (; n; n /= 2)
            bin += '0' + n % 2;
        
        int count = 0;
        for (int i = 0; i + 1 < bin.size(); i++)
            count += bin[i] == '1' && bin[i + 1] == '1';
        return count == 1;
    }
};