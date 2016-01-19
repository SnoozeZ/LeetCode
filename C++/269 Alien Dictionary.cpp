ass Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char>> neighbor;
        map<char, set<char>> inChar;
        //construct the graph
        for(int i = 0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int p = 0;
            while(p<word1.size() && p<word2.size() && word1[p] == word2[p]){
                neighbor[word1[p]];
                inChar[word1[p]];
                p++;}
            if(p==word1.size() || p==word2.size()){
                if(p==word1.size() && p!=word2.size()){
                    neighbor[word2[p]];
                    inChar[word2[p]];
                }
                continue;
            }
            neighbor[word1[p]].insert(word2[p]);
            inChar[word2[p]].insert(word1[p]);
            inChar[word1[p]];
            
        }
        //init the queue
        queue<char> queue;
        for(auto p : inChar){
            if(p.second.size() == 0)
                queue.push(p.first);
        }
        //do the topological sort
        string rlt = "";
        while(!queue.empty()){
            char cur = queue.front();
            queue.pop();
            rlt += cur;
            for(auto c : neighbor[cur]){
                inChar[c].erase(cur);
                if(inChar[c].size() == 0)
                    queue.push(c);
            }
        }

        //determine if valid
        bool valid = true;
        for(auto p : inChar){
            if(p.second.size() != 0){
                valid = false;
                break;
            }
        }
        //return
        return valid ? rlt : "";
    }
};
