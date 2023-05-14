class Solution {
public:
    vector<int> colorTheArray(int size, vector<vector<int>> &queries) {
        vector<int> a(size), res(queries.size());
        int count = 0;
        
        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0], value = queries[i][1];

            count -= index && a[index] && a[index - 1] == a[index];
            count -= index + 1 < size && a[index] && a[index] == a[index + 1];

            a[index] = value;

            count += index && a[index] && a[index - 1] == a[index];
            count += index + 1 < size && a[index] && a[index] == a[index + 1];

            res[i] = count;
        }
        
        return res;
    }
};