
//Use Abstract Syntax Tree. 
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(0, input.size()-1, input);
    }
    
    vector<int> helper(int left, int right, string input){
        vector<int> result;
        bool isConstant = true;
        for(int i=left; i<=right; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                isConstant = false;
                vector<int> Left = helper(left, i-1, input);
                vector<int> Right = helper(i+1, right, input);
                for(int l : Left){
                    for(int r : Right){
                        if(input[i] == '+') result.push_back(l+r);
                        if(input[i] == '-') result.push_back(l-r);
                        if(input[i] == '*') result.push_back(l*r);
                    }
                }
            }
        }
        //if the interval is constant
        if(isConstant){
            int num=0;
            for(int i = right; i>=left; i--){
                int cur = input[i] - '0';
                num += cur*pow(10, right-i);
            }
            result.push_back(num);
        }
        return result;
    }
};
