ass Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l = 0, w = 0;
        //cal the length
        int left = max(A, E);
        int right = min(C, G);
        l = left >= right? 0 : right-left;
        //cal the width
        left = min(D, H);
        right = max(B, F);
        w = left <= right ? 0 : left - right;
            
        return (C-A)*(D-B) + (G-E)*(H-F) - w*l;
    }
};
