# c++ code to return a list of nodes from top view of a binary tree from left to right.

#
vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>result;
        map<int,int>mp;
        queue <pair<Node*,int> >q;
        
        if(root==NULL)return result;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            
            Node* frontnode=temp.first;
            int hd=temp.second;
            
            if(mp.find(hd)==mp.end()){
                mp[hd]=frontnode->data;
            }
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:mp){
            result.push_back(i.second);
        }
        return result;
    }

