class Solution {
public:
    vector<vector<int>> spiralMatrix(int h, int w, ListNode *head) {
        vector<vector<int>> a(h, vector<int>(w, -1));
        
        int y = 0, x = -1, d = 1;
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        for ( ; head; head = head->next) {
            while (1) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == -1) {
                    y = ty;
                    x = tx;
                    a[y][x] = head->val;
                    break;
                } else {
                    d = (d + 1) % 4;
                }
            }
        }
        
        return a;
    }
};