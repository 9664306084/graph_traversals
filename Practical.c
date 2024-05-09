#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student {
    char name[100];
    float grade;
} Student;

typedef struct TreeNode {
    Student data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode* root;
} BinaryTree;

TreeNode* create_tree_Node(char name[100], float grade) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }
    strcpy(newNode->data.name, name);
    newNode->data.grade = grade;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert_node(TreeNode* root, char name[100], float grade) {
    if (root == NULL) {
        return create_tree_Node(name, grade);
    }

    if(grade < root->data.grade) {
        root->left = insert_node(root->left, name, grade);
    }
    else if(grade > root->data.grade) {
        root->right = insert_node(root->right, name, grade);
    }

    return root;
    
}

TreeNode* inOrderTraversal(TreeNode* root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s & Grade: %f\n", root->data.name, root->data.grade);
        inOrderTraversal(root->right);
    }
    return NULL;
}

TreeNode* minimum_grade(TreeNode* root) {
    if(root->left == NULL) {
        printf("Minimum Grades: %f obtained by %s\n", root->data.grade, root->data.name);
        return root->left;
    }
    return minimum_grade(root->left);   
}

TreeNode* maximum_grade(TreeNode* root) {
    if(root->right == NULL) {
        printf("Maximum Grades: %f obtained by %s\n", root->data.grade, root->data.name);
        return root->right;
    }
    return maximum_grade(root->right);   
}

int main() {

    BinaryTree tree;
    tree.root = NULL;

    tree.root = insert_node(tree.root, "John", 8.9);
    tree.root = insert_node(tree.root, "Robb", 7.9);
    tree.root = insert_node(tree.root, "Arya", 7.2);
    tree.root = insert_node(tree.root, "cena", 8.2);
    tree.root = insert_node(tree.root, "Theon", 5.9);

    inOrderTraversal(tree.root);

    minimum_grade(tree.root);

    maximum_grade(tree.root);

    return 0;
}