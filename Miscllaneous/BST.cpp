#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};

struct node *search (struct node * root, int num)
{
    struct node *ptr = root;
    while(ptr)
    {
      if(ptr->data==num) break;
      if(ptr->data>num) ptr=ptr->left;
      else ptr = ptr->right;
    }
    return ptr;
}

struct node *insert (struct node * root, int num)
{
    struct node *ptr = root,*par = NULL;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp ==NULL)
    {
      printf("Heap Overflow \n");
      return NULL;
    }
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;

    if(ptr==NULL) // if tree is empty
    {
      ptr = temp;
      return ptr;
    }

    while(ptr)
    {
       par = ptr;
       if(ptr->data>num)
       {
         ptr = ptr->left;
       }
       else
       {
         ptr = ptr->right;
       }
    }
    if(par->data>num) par->left = temp;
    else par->right = temp;
    return root;

}

void inorder(struct node *root)
{
  if(root)
  {
    
    inorder(root->left);
    printf("%d ",root->data );
    inorder(root->right);

  }
}
void postorder(struct node *root)
{
  if(root)
  {
    postorder(root->left);
    printf("%d ",root->data );
    postorder(root->right);

  }
}
void preorder(struct node *root)
{
  if(root)
  {
    printf("%d ",root->data );
    preorder(root->left);
    preorder(root->right);

  }
}

int height(struct node *root)
{
  if(root)
  {
    int l = height(root->left);
    int r = height(root->right);
    if(l>r) return 1+l;
    else return 1+r;
  }
  else
  return 0;
}

struct node* min(struct node* root)
{
   while(root->left) root=root->left;
   return root;
}
struct node* max(struct node* root)
{
   while(root->right) root=root->right;
   return root;
}
struct node * del(struct node* ptr, int key)
{
   struct node *tmp,*succ;
   if(ptr==NULL)
   {
     printf("key not found \n");
     return NULL;
   } 
   if(key > ptr->data) ptr->right = del(ptr->right,key);
   else if(key < ptr->data) ptr->left =  del(ptr->left,key);
   else
   {
     if(ptr->left && ptr->right)
     {
           succ = ptr->right;
           while(succ->left) succ=succ->left;
           ptr->data= succ->data;
           ptr->right = del(ptr->right,succ->data);

     }
     else
     {
       tmp = ptr;
       if(ptr->left)
       {
           ptr= ptr->left;
       }
       else if(ptr->right)
       {
         ptr= ptr->right;
       } 
       else 
       {
         ptr=NULL;
       }
       free(tmp);
     }
   }
  return ptr;
}

int main()
{
   struct node *root = NULL;
   struct node *ptr = NULL;
   int choice, k;
   while(1)
   {
     printf("\n");
     printf("1. Search \n");
     printf("2. Insert \n");
     printf("3. Delete \n");
     printf("4. Preorder Traversal \n");
     printf("5. Inorder Traversal \n");
     printf("6. Postorder Traversal \n");
     printf("7. Height of Tree \n");
     printf("8. Find minimum and maximum \n");
     printf("9. Quit \n");
     printf(" Enter your choice :");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:
              printf("Enter the number to be searched : ");
              scanf("%d",&k);
              ptr = search(root,k);
              if(ptr==NULL)
                printf("Number not present \n");
              else
                printf("Number present \n");
              break;
        case 2:
             printf("Enter the number to be inserted :");
             scanf("%d",&k);
             root = insert(root,k);
             break;
        case 3:
             printf("Enter the key to be deleted : ");
             scanf("%d",&k);
             root = del(root,k);
             break;
        case 4:
            preorder(root);
            break;
        case 5:
            inorder(root);
            break;
        case 6:
            postorder(root);
            break;
        case 7:
            printf("Height of binary Tree is %d \n",height(root));
            break;
        case 8:
             ptr = min(root);
             if(ptr) printf("Minimum key is %d\n",ptr->data);
             ptr = max(root);
             if(ptr) printf("Maximum key is %d\n",ptr->data);
             break;
        case 9:
             exit(1);
        default:
             printf("Wrong choice \n");

     }
   }
   return 0;
}
