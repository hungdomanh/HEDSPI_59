/*
- Cách làm:
   + Với mỗi trường hợp lưu list phone vào tree
   + Khi lưu thì so sánh trước khi chèn vào nếu phone này là đầu của phone kia thì return -1
   + Tạo 1 biến kiểm tra giá trị trả về của hàm insert. kt = 0, kt = -1
   + Nếu kt == -1 thì chỉ nhập chứ ko chèn vào tree nữa
   + Kết thúc nhập => in ra YES NO tùy vào biến kt.
- Độ phức tạp:
   O(nlog(n))
   n là số node trong tree
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bin_tree {
   char str[23];
   struct bin_tree * right, * left;
};
typedef struct bin_tree node;

int min(int a, int b) {
   return a<b ? a : b;
}

int insert(node ** tree, char j[]) {
    node *temp = NULL;

    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        strcpy(temp->str, j);
        *tree = temp;
        return 0;
    }

    int m = min (strlen(j), strlen((*tree)->str) );
    int res = strncmp(j, (*tree)->str, m );

    if( res == 0 )   return -1;
    if(res < 0) {
        insert(&(*tree)->left, j);
    }
    else  {
        insert(&(*tree)->right, j);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {    print_preorder(tree->left);
        printf("%s\n",tree->str);

        print_preorder(tree->right);
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

///////////////////
int main()
{
   node *root;
   node *tmp;

   int t, n, i, j, kt;
   scanf("%d", &t);

   char phone[23];

   for(i=0; i<t; i++) {
      root = NULL;
      scanf("%d", &n);
      kt = 0;
      for(j=0; j<n; j++) {
         scanf("%s", phone);
         if(kt == 0) {
            kt = insert(&root, phone);
         }
      }

      if(kt == 0)    printf("YES\n");
      else printf("NO\n");
      deltree(root);
   }

   return 0;
}
