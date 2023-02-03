class Solution {
public:
    bool validWordSquare(vector<string> &a) {
        int size = a.size();
        for (string &s : a)
            size = max<int>(size, s.size());

        a.resize(size, string(size, ' '));
        for (string &s : a)
            s.resize(size, ' ');

        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                if (a[y][x] != a[x][y])
                    return 0;
        
        return 1;
    }
};