Node* build(vector<int>& in, int instart, int inend, vector<int>& post, int poststart, int postend, map<int, int>& mp)
{
  if(instart>inend || poststart>postend) return NULL;
  
  Node* root = new Node(post[postend]);
  
  int inroot = mp[root->val];
  int numsleft = inroot - instart;
  
  root->left = build(in, instart, inroot-1, post, poststart, poststart+numsleft-1, mp);
  root->right = build(in, inroot+1, inend, post, post+numsleft, postend-1, mp);
  
  return root;
}

Node* buildtree(vector<int>& in, vector<int>& post)
{
  if(in.size() != post.size()) return NULL;
  
  map<int, int> mp;
  
  for(int i=0; i<in.size(); i++)
    mp[in[i]]++;
  
  Node* root = build(in, 0, in.size()-1, post, 0, post.size()-1, mp);
  
  return root;
}
