class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int posA = m-1, posB = n-1, valA, valB;
        for(int posTail = m+n-1; posTail >= 0; posTail--){
            valA = posA>=0 ? A[posA] : INT_MIN;
            valB = posB>=0 ? B[posB] : INT_MIN;
            A[posTail] = max(valA,valB);
            valA > valB ? posA-- : posB--;
        }
    }
};