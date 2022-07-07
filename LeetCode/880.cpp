class Solution {
public:
    string decodeAtIndex(string &s, int k) {
        k--;
        
        long long size = 0;
        int i = 0;
        
        while (1) {
            if (isalpha(s[i]))
                size++;
            else
                size *= s[i] - '0';
            
            if (size > k)
                break;
            i++;
        }
        
        cout << size << " " << i;
        
        if (isalpha(s[i]))
            return string(1, s[i]);
        else
            return decodeAtIndex(s, k % (size / (s[i] - '0')) + 1);
    }
};