#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  Node *left;
  Node *right;
}

Node* newNode(int val)
{
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
};

Node *buildTree(string str)
{
   
   Node *root = newNode(stoi(str[0]));
   queue<Node*> queue;
   queue.push(root);
   int i=1;
   while(!queue.empty())

}

void inorder(Node* root)
{
  if(root)
  {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}
int main()
{
   string s;
   getline(cin,s);
   if(str.legth()==0||str[0]==N) return NULL;
   Node* root = buildTree(s);
   inorder(root);
   return 0;
}

