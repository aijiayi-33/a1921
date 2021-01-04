
#include "tu.h"

int main()
{
    Graph *g;
    g=(Graph *) malloc(sizeof(Graph));
    bulidGraph(g);
 
    dfs(g);
    printf("\n");
    bfs(g);
    return 0;
}
 

