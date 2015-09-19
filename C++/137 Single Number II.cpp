class Solution {
public:
    int singleNumber(int A[], int n) {
        int b[32]={0};
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<32;j++)
                b[j] += (A[i]>>j)&1;
                //b[j] = b[j]+ (A[i]>>j)&1;//notice that the privalige of the >> and << are lower than +
        for(int k=0;k<32;k++)
            ans |= (b[k]%3)<<k;
        return ans;
    }
};
