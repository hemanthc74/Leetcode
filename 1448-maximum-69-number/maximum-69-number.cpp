class Solution {
public:
    int maximum69Number (int num) {
        string numstr = to_string(num);
        
        
        for (auto& it : numstr) {
            if (it == '6') { 
                it = '9';    
                break;       
            }
        }

        return stoi(numstr);
    }
};
