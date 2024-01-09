class Solution {
public:
    int missingInteger(vector<int> &a) {
        int sum = a[0];
        for (int i = 1; i < a.size() && a[i - 1] + 1 == a[i]; i++)
            sum += a[i];
        
        sort(a.begin(), a.end());

        while (binary_search(a.begin(), a.end(), sum))
            sum++;
        return sum;
    }
};