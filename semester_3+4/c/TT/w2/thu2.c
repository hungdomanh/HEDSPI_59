#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bin_tree {
   int dollar;
   char job[18];
   struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val, char j[]) {
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->dollar = val;
        strcpy(temp->job, j);
        *tree = temp;
        return;
    }

    if(strcmp(j, (*tree)->job) < 0)
    {
        insert(&(*tree)->left, val, j);
    }
    else if(strcmp(j, (*tree)->job) > 0)
    {
        insert(&(*tree)->right, val, j);
    }

}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, char j[])
{
    if(!(*tree))
    {
        return NULL;
    }

    if(strcmp(j, (*tree)->job) < 0)
    {
        search(&((*tree)->left), j);
    }
    else if(strcmp(j, (*tree)->job) > 0)
    {
        search(&((*tree)->right), j);
    }
    else if(strcmp(j, (*tree)->job) == 0)
    {
        return *tree;
    }
}


int main()
{
   node *root;
   node *tmp;
   root = NULL;
   int a, b, i;
   scanf("%d %d", &a, &b);


   char j[18], line[30];
   int  salary, d;

   for(i=0; i<a; i++) {
      fflush(stdin);
      scanf("%s %d", j, &d);
      insert(&root, d, j);
   }

   for(i=0; i<b; i++) {
      salary = 0;
      fflush(stdin);
      scanf("%s", line);

      while(strcmp(line, ".") ) {
         tmp = search(&root, line);
         if(tmp)    salary += tmp->dollar;
         fflush(stdin);
         scanf("%s", line);
      }

      printf("%d\n", salary);
   }



   return 0;
}
