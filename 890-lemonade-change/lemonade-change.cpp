class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        int n = bills.size();
        for(int i=0 ; i<n ; i++){
            if(bills[i]==5){
                five++;
            } else if (bills[i]==10) {
                if(five>=1) {
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }
            else{
                if(five>=1 && ten>=1){
                    five--;
                    ten--;
                    twenty++;
                }else if(five>=3){
                    five = five-3;
                    twenty++;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};