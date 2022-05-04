class Solution {
public:
    string convertToTitle(int columnNumber) {
        columnNumber--;
        int size = 1;
        long long count = 26;
        while (columnNumber >= count) {
            columnNumber -= count;
            size++;
            count *= 26;
        }
        
        string res(size, ' ');
        for (int i = size - 1; i >= 0; i--) {
            res[i] = columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        return res;
    }
};