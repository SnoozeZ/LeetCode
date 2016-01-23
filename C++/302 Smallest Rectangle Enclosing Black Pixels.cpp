class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;
        vector<int> status({left, right, top, bottom});
        helper(image, x, y, status);
        //cal area
        int area = (status[1] - status[0] + 1) * (status[3] - status[2] + 1);
        return area;
    }
    
    void helper(vector<vector<char>>& image, int x, int y, vector<int>& status){
        if(x<0 || y<0 || x>=image.size() || y>=image[0].size())
            return;
        if(image[x][y] != '1')//white pixel or have searched
            return;
        //change status
        status[2] = min(status[2], x);
        status[3] = max(status[3], x);
        status[0] = min(status[0], y);
        status[1] = max(status[1], y);
        image[x][y] = '#'; // => have searched
        //search
        helper(image, x+1, y, status);
        helper(image, x-1, y, status);
        helper(image, x, y-1, status);
        helper(image, x, y+1, status);
    }
    
};
