#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        struct node* left; 
        struct node* right; 
        char* label;
        } Node;

int main () {
    Node* root = malloc(sizeof(Node));
    Node* node1 = malloc(sizeof(Node));
    Node* node2 = malloc(sizeof(Node));
    Node* node3 = malloc(sizeof(Node));
    Node* node4 = malloc(sizeof(Node));

    root->label = "ROOT";
    node1->label = "Node1";
    node2->label = "Node2";
    node3->label = "Node3";
    node4->label = "Node4";

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

    printTree(root, 0);

    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("|-- %s\n", root->label);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}