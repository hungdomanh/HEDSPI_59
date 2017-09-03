#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visit[100003], dd;
//-----------------
typedef struct _v{
   struct _v *son;
   struct _v *right;
   struct _v *left;
   struct _v *parent;
   int value, p, s;
}G;
typedef G* Graph;

Graph Creat(int x);
Graph findVertex (Graph g, int x);
Graph InsertVertex(Graph g, int val);
Graph InsertEdge (Graph g, int a, int b);
void prTree(Graph tree);
void prLast(Graph tree, int count);
void Last(Graph g);
void LastFull(Graph g);
void Parent(Graph g, int x);
void prTree2(int x, Graph tree);

Graph gg;
int khung = 0;
//----------------
typedef struct __v {
   struct __v *left;
   struct __v *right;
   int width, dau, cuoi;
}G2;
typedef G2* Graph2;

Graph2 Creat2(int a, int b, int w);
Graph2 InsertEdge2(Graph2 g, int a, int b, int w);
void Duyet(Graph2 tree);

//////////////////////////////.........////////////////////////////////
int main()
{
   int n , m, k, i, a, b, w;
   scanf("%d %d", &n,&m);
   for (dd=0; dd<100003; dd++) {
      visit[dd] = 0;
   }
   Graph2 g2 = (Graph2) malloc(sizeof(G2));
   g2 = NULL;
   gg = (Graph) malloc(sizeof(G));
   gg = NULL;
//////////// Input
   for(i=1; i<=m; i++) {
      scanf("%d %d %d", &a, &b, &w);
      if(a > b) {
         int t = a;  a = b;   b = t;
      }
      g2 = InsertEdge2(g2, a, b, w);
   }
/////////// Output
   Duyet(g2);
   printf("%d\n", khung);
   LastFull(gg);
   free(gg);   free(g2);
   return 0;
}

//+++++++++++++++++++++

Graph2 Creat2(int a, int b, int w) {
   Graph2 g;
   g = (Graph2) malloc (sizeof(G2));
   g->left = NULL;
   g->right= NULL;
   g->width = w;
   g->dau = a;
   g->cuoi = b;
   return g;
}

Graph2 InsertEdge2(Graph2 g, int a, int b, int w) {
   Graph2 temp = (Graph2) malloc(sizeof(G2));
   Graph2 tree = (Graph2) malloc(sizeof(G2));
   int res, t;

   if(g == NULL) {
      g = Creat2(a,b,w);
   }
   else {
      tree = g;
      while(tree != NULL) {
         temp = tree;
         res = w - tree->width;
         if(res == 0) {
            res = a - tree->dau;
            if(res == 0)   res = b - tree->cuoi;
         }
         if(res < 0) tree = tree->left;
         else tree = tree->right;
      }
      tree = Creat2(a,b,w);
      if(res < 0)   temp->left = tree;
      else temp->right = tree;
   }
   return g;
}

void Duyet(Graph2 tree) {
   if (tree)
   {
      Duyet(tree->left);
      if(visit[tree->cuoi] == 0||visit[tree->dau] == 0) {
         gg = InsertEdge(gg, tree->dau, tree->cuoi);
         khung += tree->width;
         visit[tree->dau] = 1;
         visit[tree->cuoi] = 1;
      }
      Duyet(tree->right);
   }
}



//////+++++++++++++++++


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

void LastFull(Graph g) {
   if (g)
   {
      LastFull(g->left);
      prTree2(g->value, g->son);
      LastFull(g->right);
   }
}

void prTree2(int x, Graph tree) {
   if (tree)
   {
      prTree2(x, tree->left);
      printf("%d ", x);    printf("%d ",tree->value);
      prTree2(x, tree->right);
   }
}

void Parent(Graph g, int x) {
   Graph tree = findVertex(g, x);
   if(tree)    prTree(tree->parent);
}
