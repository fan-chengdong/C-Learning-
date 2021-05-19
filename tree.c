#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _TreeNode
{
	int data;
	struct _TreeNode *leftTree;
	struct _TreeNode *rightTree;
} TreeNode;

int *InOrderTraversal(TreeNode * root, int *size, int mSize)
{
	*size = 0;
	int *result = (int *)malloc(sizeof(int) * mSize);
	TreeNode** tree = (int *)malloc(sizeof(TreeNode *) * mSize);
	int topNode = 0;
	while (root != NULL || topNode > 0) {
		while (root != NULL) {
			tree[topNode++] = root;
			root = root->leftTree;
		}
		root = tree[--topNode];
		result[(*size)++] = root->data;
		root = root->rightTree;
	}
	return result;
}