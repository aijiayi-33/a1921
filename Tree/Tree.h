
#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
#define MAXSIZE 100

typedef struct BiTreeNode;
typedef struct BiTreeNode
{
        char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
}BiTreeNode,*BiTree;
void CreateBiTree(BiTree *T);

 
/**先序遍历  根左右**/
void PreOrderTravel(BiTree T);

 
/**中序遍历 左根右**/
void InOrderTravel(BiTree T);

 
/**后序遍历 左右根**/
void TailOrderTravel(BiTree T);




#endif

