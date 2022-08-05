//convert the existing tree to linked list.
//convert to right skewed
//Reverse Post-order
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//recursive solution- pseudocode TC: O(N) and SC: O(N)

// prev=NULL
// flatten(node)
// {
//   if(node==NULL) return;
  
//   flatten(node->right);
//   flatten(node->left);
  
//   node->right = prev; //converts to right skew
//   node->left = NULL;
  
//   prev = node;
// }

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//iterative approach-pseudocode: extension of recursive approach TC: O(N) and SC: O(N)
//uses stack

// st.push(root)
//   while(!st.empty())
//   {
//     cur = st.top(); st.pop();
    
//     if(cur->right) st.push(cur->right);
    
//     if(cur->left) st.push(cur->left);
    
//     if(!st.empty()) cur->right = st.top();
    
//     cur->left = NULL;
//   }

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Morris-traversal approach: TC: O(N) and SC: O(1)
//pseudocode
//  cur = root
//  while(cur)
//  {
//   if(cur->left)
//   {
//     prev = cur->left;
//     while(prev->right)
//       prev = prev->right;
//     prev->right = cur->right;
//     cur->right = cur->left;
//   }
//    cur=cur->right;
//  }
