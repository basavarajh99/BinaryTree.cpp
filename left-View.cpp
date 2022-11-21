vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   
   if(!root) return ans;
   
   queue<Node*> q;
   
   q.push(root);
   
   while(!q.empty()){
       int size = q.size();
       ans.push_back(q.front()->data);
       for(int i = 0; i < size; i++){
           Node* node = q.front();
           q.pop();
           
           if(node->left) q.push(node->left);
           if(node->right) q.push(node->right);
       }
   }
   
   return ans;
}
