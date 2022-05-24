class Solution {
public:
    vector<int> sortEvenOdd(vector<int> &a) {
        for (int i = 0; i < a.size(); i += 2) {
            int j = i;
            while (0 < j && a[j - 2] > a[j]) {
                swap(a[j - 2], a[j]);
                j -= 2;
            }
        }
        
        for (int i = 1; i < a.size(); i += 2) {
            int j = i;
            while (1 < j && a[j - 2] < a[j]) {
                swap(a[j - 2], a[j]);
                j -= 2;
            }
        }
        
        return a;
    }
};