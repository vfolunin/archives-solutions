class Solution {
public:
    int minimumBoxes(int n) {
        int size = 1, floor = 1, total = 1;
        while (total < n) {
            size++;
            floor += size;
            total += floor;
        }
        
        if (total > n) {
            total -= floor;
            floor -= size;
            size--;
            
            int add = 0;
            while (total < n) {
                add++;
                floor++;
                total += add;
            }
        }
        
        return floor;
    }
};