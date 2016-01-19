class UnionFind{
private:
    vector<int> tag;
    int size;
    int uniqueComponents;
public:
    UnionFind(int n){
        size = n;
        uniqueComponents = n;
        for(int i = 0; i < size; i++)
            tag.push_back(i);
    }
    
    void Union(int node1, int node2){
        //union with time O(n)
        // int oldTag = find(node1), newTag = find(node2);
        // if(oldTag == newTag) return;
        // for(int i = 0; i < size; i++){
        //     if(tag[i] == oldTag){
        //         tag[i] = newTag;
        //     }
        // }
        
        //union with time O(logn). Cool!
        while(find(node1) != node1) node1 = find(node1);
        while(find(node2) != node2) node2 = find(node2);
        if(node1 == node2) 
            return;
        else
            tag[node1] = node2;
        uniqueComponents--;
    }
    
    int find(int node){
        return tag[node];
    }
    
    int getSize(){
        return uniqueComponents;
    }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UnionFind uf(n);
        for(auto edge : edges){
            uf.Union(edge.first, edge.second);
        }
        return uf.getSize();
    }
};
