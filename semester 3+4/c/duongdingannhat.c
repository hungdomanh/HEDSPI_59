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
   int value, p, w, s, d;
}G;
typedef G* Graph;

Graph Creat(int x);
Graph findVertex (Graph g, int x);
Graph InsertVertex(Graph g, int val);
Graph InsertEdge (Graph g, int a, int b, int w);
void prTree(Graph tree);
void prLast(Graph tree, int count);
void Last(Graph g);
void LastFull(Graph g);
void Parent(Graph g, int x);
void prTree2(int x, Graph tree);

Graph g;

void Duyet(Graph s, Graph tree, Graph t){
   if(tree) {
      Duyet(s, tree->left, t);
      if(tree->d > tree->w + tree->parent->d)
         tree->d = tree->w + tree->parent->d;
      if(tree != t)  Duyet(s, tree->son, t);
      printf("\nsdfs%d\n", tree->d);
      Duyet(s, tree->right, t);
   }// else return t;
};



//////////////////////////////.........////////////////////////////////
int main()
{
   int n , m, k, i, a, b, w, s, t;
   scanf("%d %d", &n,&m);
   for (dd=0; dd<100003; dd++) {
      visit[dd] = 0;
   }
   Graph tt = (Graph) malloc(sizeof(G));
   tt = NULL;
   Graph ss = (Graph) malloc(sizeof(G));
   ss = NULL;
   g = (Graph) malloc(sizeof(G));
   g = NULL;

//////////// Input
   for(i=1; i<=m; i++) {
      scanf("%d %d %d", &a, &b, &w);
      g = InsertEdge(g, a, b, w);
   }
   scanf("%d %d", &s, &t);
/////////// Output
   ss = findVertex(g, s);
   tt = findVertex(g, t);
   if(ss == NULL) {
      g = InsertVertex(g, s);
      ss = findVertex(g, s);
   }
   if(tt == NULL) {
      g = InsertVertex(g, t);
      tt = findVertex(g, t);
   }
   ss->d = 0;
   Duyet(ss, g, tt);
//   tt = findVertex(g, t);

//   printf("\n%d\n", tt->d);
   return 0;
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
   g->w = 0;
   g->d = 99999;
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

Graph InsertEdge (Graph g, int a, int b, int w) {
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

   temp = findVertex(v1->son, b);
   if(!temp)   {
      v1->s += 1;
      v1->son = InsertVertex(v1->son, b);
      temp = findVertex(v1->son, b);
      temp->w = w;
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
