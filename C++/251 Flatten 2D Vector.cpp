/*class Vector2D {
public:
    int vecSize, pos;
    bool itInited;
    vector<vector<int>> vec2d;
    vector<int>::iterator it;
    Vector2D(vector<vector<int>>& vec2d){
        vecSize = vec2d.size();
        pos = -1;
        this->vec2d = vec2d;
        itInited = false;
        //while(pos < vecSize && vec2d[pos].empty()) i++;
        
    }

    int next() {
        int rlt = *it;
        it++;
        return rlt;
    }

    bool hasNext() {
        while(!itInited || it == vec2d[pos].end())
            if(++pos < vecSize){
                it = vec2d[pos].begin();
                itInited = true;
            }else{
                return false;
            }
        return true;
    }
};*/
//cool solution!
class Vector2D {
   int row;
   int col;
   vector<vector<int>> data;

public:
   Vector2D(vector<vector<int>>& vec2d) {
       data = vec2d;
       row = 0;
       col = 0;
   }
   int next() {
       return data[row][col++];
   }

   bool hasNext() {
       while(row < data.size() && data[row].size() == col)
           row++, col = 0;
       return row < data.size();
   }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
