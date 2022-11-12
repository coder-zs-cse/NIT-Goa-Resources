class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int count=0;
        int count_closed=0;
        for(auto it:s){
            if(it=='('){
                count++;
            }
            else if(it==')'){
                if(count>0){
                    count_closed++;
                    count--;
                }
            }
        }
        string output="";
        int count_open=0;
        for(auto it:s){
            if(it==')'){
                if(count_open>0){
                    output += it;
                    count_open--;
                }
            }
            else if(it=='('){
                if(count_closed>0) {
                    output += it;
                    count_open++;
                    count_closed--;
                }
                
            }
            else output += it;
        }
        return output;
    }
};