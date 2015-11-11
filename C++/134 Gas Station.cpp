//Time O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumCost=0, sumGas=0;
        int start=0, tank=0;
        for(int i=0; i<gas.size(); i++){
            sumCost += cost[i];
            sumGas += gas[i];
            tank = tank+gas[i]-cost[i];
            if(tank<0){
                start = i+1;
                tank = 0;
            }
        }
        if(sumCost<=sumGas)
            return start;
        else
            return -1;
    }
};
