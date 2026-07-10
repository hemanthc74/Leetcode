class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorxy = x^y;
        int distance =0;
        while(xorxy>0){
            if(xorxy & 1 == 1 ) distance++;
            xorxy= xorxy>>1;
        }

        return distance;
    }
};