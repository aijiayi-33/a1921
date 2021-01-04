#include"chazhao.h"

void display(int a[],int n){
	printf("待查找数据：");
	for(int i = 0;i<n;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}


void selectsort(int a[],int n){
	int i,j,k,m;
	for(i = 0; i<n-1; i++){
		m = a[i];
		k = i;
		for(j = i+1; j<n; j++)
			if(a[j]<m){
				m = a[j];
				k = j;
			}
			a[k] = a[i];
			a[i] = m;
	}
}


int binarysearch(int a[],int n,int x){
	int low = 0,high = n-1,mid;
	while(low <= high){
		mid = (low+high)/2;
		if(a[mid] == x){
			return mid;
		}
		else if(x<a[mid]){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
		return -1;
}




void insert(pnode *root,datatype key){
	pnode p = (pnode)malloc(sizeof(node));
	p->key = key;
	p->left = p->right = p->parent = NULL;
	
	if((*root) == NULL){
		*root = p;
		return;
	}
	
	if((*root)->left == NULL &&(*root)->key>key){
		p->parent = (*root);
		(*root)->left = p;
		return;
	}
	
	if((*root)->right == NULL && (*root)->key<key){
		p->parent = (*root);
		(*root)->right = p;
		return;
	}
	if((*root)->key>key){
		insert(&(*root)->left,key);
	}
	else if((*root)->key<key){
		insert(&(*root)->right,key);
	}
	else return;
}


void create(pnode *root,datatype *keyArray,int length){
	for(int i = 0;i<length;i++){
		insert(root,keyArray[i]);
	}
}



pnode search(pnode root,datatype key){
	if(root == NULL){
		return NULL;
	}
	if(key>root->key){
		return search(root->right,key);
	}
	else if(key<root->key){
		return search(root->left,key);
	}
	else return root;
}


int m = 0;
void InitHashTable(HashTable *hashTable){
	m = HASHSIZE;
    	hashTable->elem = (int *)malloc(m * sizeof(int)); //申请内存
   	hashTable->count = m;
    	for(int i = 0;i < m;i++){
        hashTable->elem[i] = NULLKEY;
    }
}


datatype Hash(int key){
    return key % m;
}


void Insert(HashTable *hashTable,int key){
	int hashAddress = Hash(key); //求哈希地址
	while(hashTable->elem[hashAddress] != NULLKEY){
      
        hashAddress = (hashAddress + 1) % m;
    }
   
    hashTable->elem[hashAddress] = key;
}



datatype Search(HashTable *hashTable,int key){
    int hashAddress = Hash(key);
    while(hashTable->elem[hashAddress] != key){
        hashAddress = (hashAddress + 1) % m;
        if (hashTable->elem[hashAddress] == NULLKEY || hashAddress == Hash(key)){
            return -1;
        }
    }
    return hashAddress;
}

void DisplayHashTable(HashTable *hashTable){
	printf("待查找数据：");
	for (int i = 0;i < hashTable->count;i++){
		printf("%d  ",hashTable->elem[i]);
    }
    printf("\n");
}


