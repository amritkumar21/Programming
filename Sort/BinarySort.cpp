#include<iostream>
using namespace std;
#define MAX 100
int ind = -1;

struct node
{
    struct node *left;
    int info;
    struct node *right;
};

struct node *insert(struct node * root, int key)
{
    struct node *tmp,*par,*ptr;

    ptr = root;
    par = NULL;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = key;
    tmp->left = NULL;
    tmp->right = NULL;
    if(ptr==NULL)
    {
        root = tmp;
        return root;
    }

    while(ptr!=NULL)
    {
        par = ptr;
        if(key<ptr->info)
           ptr = ptr->left;
        else
           ptr = ptr->right;
        
    }
    if(key<par->info)
      par->left = tmp;
    else 
      par->right = tmp;
    return root;
}

void inorder(struct node *root, int arr[])
{
    if(root)
    {
        inorder(root->left, arr);
        arr[++ind] = root->info;
        inorder(root->right, arr);
    }
}

void destroy( struct node *root)
{
    if(root)
    {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}
int main()
{
  struct node *root=NULL;
  int arr[MAX], n, i;
  printf("Enter the number of elements \n");
  scanf("%d", &n);

  for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

  for(i=0;i<n;i++)
     root = insert(root, arr[i]);

  inorder(root,arr);

  printf("Sorted list is : \n");
  for(int i=0;i<n;i++)
    printf("%d", arr[i]);
  destroy(root);
  return 0;
}