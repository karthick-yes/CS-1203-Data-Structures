#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

//Function which computes teh height of a node
int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}
//Function to create the new node with the given key
struct node *createNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
void inorder(struct node * anode){
    if (anode != NULL) {
        inorder(anode->left);
        printf("%d ", anode->key);
        inorder(anode->right);
    }
}

void preorder(struct node * anode){
    if (anode != NULL) {
        printf("%d ", anode->key);
        preorder(anode->left);
        preorder(anode->right);
    }
}
//Function to get the max
int getMax(int a, int b) {
    return (a > b) ? a : b;
}
//Computes the balance factor
int getBalanceFactor(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
//Implementation of right rotation of a node
struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = getMax(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = getMax(getHeight(y->right), getHeight(y->left)) + 1;
    return x;
}
//Implementation of left rotation of a node
struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = getMax(getHeight(x->right), getHeight(x->left)) + 1 ;
    y->height = getMax(getHeight(y->right), getHeight(y->left)) + 1;
    return y;
}
//Insert a key into the AVL tree
struct node *insert(struct node *node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + getMax(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
// Perform the required notations as neccessary to maintain the balance of the AVL
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    if (bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
//Display the tree stucture
void displayTree(struct node *root, int space) {
    int i;
    if (root == NULL) return;
    space += 10;
    displayTree(root->right, space);
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    displayTree(root->left, space);
}
//Computes/finds the node with the minimum key value
struct node *minValueNode(struct node *node) {
    struct node *current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}
//Function to delete a node from the AVL tree
struct node *deleteNode(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        } else {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);

    // Added deletion operations
    root = deleteNode(root, 70);
    root = deleteNode(root, 90);

  
    preorder(root);
    printf("\n");

    
    inorder(root);
    printf("\n");

    displayTree(root, 10);
    return 0;
}


//Reference : Geeks4geeks, 

