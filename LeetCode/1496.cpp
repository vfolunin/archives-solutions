class Solution {
public:
    bool isPathCrossing(string path) {
        int y = 0, x = 0;
        set<pair<int, int>> seen = { { y, x } };
        
        for (char c : path) {
            if (c == 'N')
                y--;
            else if (c == 'E')
                x++;
            else if (c == 'S')
                y++;
            else
                x--;
            
            if (seen.count({ y, x }))
                return 1;
            
            seen.insert({ y, x });
        }
        
        return 0;
    }
};