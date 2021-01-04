#ifndef tu_h
#define tu_h

#include <stdio.h>
#include <stdlib.h>
 
#define maxsize 100
 
typedef struct ArcNode {
    int num;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    ArcNode *firstarc;
}VNode;
typedef struct Graph {
    VNode VNodeList[maxsize];
    int n,e;
}Graph;
 
void bulidGraph(Graph *g);
 
int visitdfs[maxsize];
void DFS(Graph *g ,int v);
void dfs(Graph *g);
 
int visit[maxsize];
void bfs(Graph *g);
void BFS(Graph *g ,int v);
 
#endif
