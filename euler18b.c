#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct *node newNode(int data) {
    struct *node node = (struct *node)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct *node insert(struct *node node, int data) {
    if(node == NULL)
        return newNode(data);
    if()
}

int main() {
    int n = 0;
    n = scanf("%d", &n);
    struct node* tree = insert(tree, n);
    while((n = scanf("%d", &n)) != EOF) {
        insert(tree, n);
    }
    
    return 0;
}
