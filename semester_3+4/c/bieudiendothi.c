#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _v{
   struct _v *son;
   struct _v *right;
   struct _v *left;
   struct _v *parent;
   int value, p, s;
}G;

typedef G* Graph;

Graph Creat(int x) {
   Graph g;
   g = (Graph) malloc (sizeof(G));
   g->son = NULL;
   g->left = NULL;
   g->right= NULL;
   g->parent = NULL;
   g->s = 0;
   g->p = 0;
   g->value = x;
   return g;
}

Graph findVertex (Graph g, int x) {
   if(g == NULL)  return NULL;
   if(g->value == x)    return g;
   else if(x < g->value)   return findVertex(g->left, x);
   else   return findVertex(g->right, x);
}

Graph InsertVertex(Graph g, int val) {
   Graph temp = (Graph) malloc(sizeof(G));
   Graph tree = (Graph) malloc(sizeof(G));

   if(g == NULL) {
      g = Creat(val);
   }
   else if(!findVertex(g, val)) {
      tree = g;
      while(tree != NULL) {
         temp = tree;
         if(val < tree->value) tree = tree->left;
         else tree = tree->right;
      }
      tree = Creat(val);
      if(val < temp->value)   temp->left = tree;
      else temp->right = tree;
   }
   return g;
}

Graph InsertEdge (Graph g, int a, int b) {
   Graph v1 = (Graph) malloc(sizeof(G));
   Graph v2 = (Graph) malloc(sizeof(G));
   Graph temp = (Graph) malloc(sizeof(G));

   v1 = findVertex(g, a);
   v2 = findVertex(g, b);

   if(v1 == NULL)   {
      g = InsertVertex(g, a);
      v1 = findVertex(g, a);
   }
   if(v2 == NULL)   {
      g = InsertVertex(g, b);
      v2 = findVertex(g, b);
   }

   if(!findVertex(v1->son, b))   {
      v1->s += 1;
      v1->son = InsertVertex(v1->son, b);
   }

   if(!findVertex(v2->parent, a))   {
      v2->p += 1;
      v2->parent = InsertVertex(v2->parent, a);
   }

   return g;
}

void prTree(Graph tree) {
   if (tree)
   {
      prTree(tree->left);
      printf("%d ",tree->value);
      prTree(tree->right);
   }
}

void prLast(Graph tree, int count) {
   if (tree)
   {
      prLast(tree->left, count);
      printf("%d ", count);
      if(tree->s > 0)   count += tree->s;
      prLast(tree->right, count);
   }
}

void Last(Graph g) {
   if (g)
   {
      Last(g->left);
      prTree(g->son);
      Last(g->right);
   }
}

void Parent(Graph g, int x) {
   Graph tree = findVertex(g, x);
   if(tree)    prTree(tree->parent);
}

////////////////////////////////////////////////////////////////
int main()
{
   long n , m, k, i, a, b, dongcuoi[100003];
   scanf("%d %d %d", &n,&m ,&k);
   Graph g = (Graph) malloc(sizeof(G));
   g = NULL;

//////////// Input
   for(i=1; i<=m; i++) {
      scanf("%d %d", &a, &b);
      if(a != b) {
         g = InsertEdge(g, a, b);
      }
   }

   for(i=1; i<=k; i++) {
      scanf("%d", &dongcuoi[i]);
   }
/////////// Output
   printf("%d %d\n", n, m);
   prLast(g, 1);
   printf("\n");
   Last(g);
   printf("\n");
   for(i=1; i<=k; i++) {
      int h =  dongcuoi[i];
      Parent(g, h);
      printf("\n");
   }

   return 0;
}
