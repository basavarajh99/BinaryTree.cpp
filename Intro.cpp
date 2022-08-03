Full BT : Every node has either 0 or 2 nodes.
Complete BT : All the levels are completely filled except the last level; In the last level all the nodes are as left as possible.
Perfect BT : All leaf nodes are at same level
Balanced BT : Height of tree at max log(N)
Degenerate tree : every node has single children

representation in c++;

struct Node 
{
  int data;
  struct Node* left;
  struct Node* right;
  
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int main()
{
  struct Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
}


