class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorxy = x^y;
        int distance =0;
        while(xorxy>0){
            distance++;
            xorxy&=(xorxy-1);
        }

        return distance;
    }
};