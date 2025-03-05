#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
} T;

T *root = NULL;

void insert()
{
	int value;
	printf("Enter value to be inserted: ");
	scanf("%d", &value);

	T *nn = malloc(sizeof(T));

	if (nn == 0){
		printf("No space");
		return;
	}

	nn->data = value;
	nn->left = nn->right = NULL;

	if (root == NULL)
	{
		root = nn;
		return;
	}

	T *temp = root;
	T *parent = NULL;

	while (1)
	{
		parent = temp;
		if (temp->data > value)
		{
			temp = temp->left;
			if (temp == NULL)
			{
				parent->left = nn;
				return;
			}
		}
		else if(temp->data < value)
			{
				temp=temp->right;
				if (temp == NULL)
				{
					parent->right = nn;
					return;
				}
			}
	}
}

	void preorder(T * node) {if(node)
	{
		printf("%d", node->data);
		preorder(node->left);
		preorder(node->right);
	}
	}

	void inorder(T * node) {if(node)
	{
		inorder(node->left);
		printf("%d", node->data);
		inorder(node->right);
	}
	}
	void postorder(T * node) {if(node)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d", node->data);
	}
	}

	int main()
	{
		int c;
		while (1)
		{
			printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Exit");
			scanf("%d", &c);
			switch (c)
			{
			case 1:
				insert();
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(0);
			default:
				printf("Invlid choice");
			}
		}
	}
