  vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result(deck.size());
        queue<int> q;
        sort(deck.begin(),deck.end());
        for(int i =0; i < deck.size(); ++i){
            q.push(i);
        }
        int i =0;
        while(!q.empty()){
            result[q.front()]=deck[i];
            ++i;
            q.pop();
            if(!q.empty()){
              q.push(q.front());
              q.pop();
            }
        }
        return result;
    }