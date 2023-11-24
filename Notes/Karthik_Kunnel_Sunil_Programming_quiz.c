#include <stdio.h>
#include <stdlib.h>

#define t 3

// Node Structure for B-tree
struct BTreeNode {
    int keys[2 * t - 1];
    struct BTreeNode *next[2 * t];
    int n; // current number of keys
    int leaf; // flag to check if the node is a leaf or not
};

// Function to create a new B-tree node
struct BTreeNode *createBTreeNode() {
    struct BTreeNode *newNode = malloc(sizeof(struct BTreeNode));
    newNode->n = 0; // Initialize the number of keys to 0
    // Initializing child pointers to NULL
    for (int i = 0; i < 2 * t; i++)
        newNode->next[i] = NULL;
    newNode->leaf = 1; // It's a leaf node
    return newNode;
}

// Function to print the keys in a B-tree node and the addresses of the child pointers
void printBTreeNode(struct BTreeNode *node) {
    printf("Keys: ");
    for (int i = 0; i < node->n; i++) {
        printf("%d ", node->keys[i]);
    }
    printf("\nChild addresses: ");
    for (int i = 0; i <= node->n; i++) {
        printf("%p ", (void *)node->next[i]);
    }
    printf("\n");
}

// Function to insert a value into a B-tree node, if there is space
void insertVal2BTreeNode(struct BTreeNode *node, int val) {
    if (node->n < 2 * t - 1) {
        int i = node->n - 1;
        while (i >= 0 && node->keys[i] > val) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = val;
        node->n = node->n + 1;
    } else {
        printf("Node is full, cannot insert value.\n");
    }
}

// Function to insert a value into a B-tree node and handle node splitting if necessary
struct BTreeNode *insertVal2BTreeNodeBreak(struct BTreeNode *node, int val) {
    if (node->n < 2 * t - 1) {
        // Insert the value into the node if there is space
        insertVal2BTreeNode(node, val);
        return node;
    } else {
        // Create new nodes
        struct BTreeNode *newNode = createBTreeNode();
        struct BTreeNode *leftNode = createBTreeNode();
        struct BTreeNode *rightNode = createBTreeNode();

        // Insert the new value into the node
        node->keys[node->n] = val;
        node->n = node->n + 1;

        // Sort the keys
        int i, j, key;
        for (i = 1; i < node->n; i++) {
            key = node->keys[i];
            j = i - 1;

            while (j >= 0 && node->keys[j] > key) {
                node->keys[j + 1] = node->keys[j];
                j = j - 1;
            }
            node->keys[j + 1] = key;
        }

        // Find the median key
        int medianIndex = t;
        int median = node->keys[medianIndex];

        // Distribute the keys and children to the new nodes
        leftNode->n = medianIndex;
        for (int i = 0; i < medianIndex; i++) {
            leftNode->keys[i] = node->keys[i];
            leftNode->next[i] = node->next[i];
        }
        leftNode->next[medianIndex] = node->next[medianIndex];
        leftNode->leaf = 1;

        rightNode->n = t - 1;
        for (int i = medianIndex + 1; i < 2 * t; i++) {
            rightNode->keys[i - medianIndex - 1] = node->keys[i];
            rightNode->next[i - medianIndex - 1] = node->next[i];
        }
        rightNode->next[t - 1] = node->next[2 * t];
        rightNode->leaf = 1;

        // Set up the new root node
        newNode->keys[0] = median;
        newNode->next[0] = leftNode;
        newNode->next[1] = rightNode;
        newNode->n = 1;
        newNode->leaf = 0;

        return newNode;
    }
}

// Define a structure for a binary search tree node
struct BSTNode {
    int key;
    struct BSTNode *left, *right;
};

// Function to create a new BST node with a given value
struct BSTNode *createBSTNode(int key) {
    struct BSTNode *newNode = malloc(sizeof(struct BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node with a specific key in the BST
struct BSTNode *insertBSTNode(struct BSTNode *node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL)
        return createBSTNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insertBSTNode(node->left, key);
    else if (key > node->key)
        node->right = insertBSTNode(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

// Function to search for a node with a specific key in the BST
struct BSTNode *searchBSTNode(struct BSTNode *root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return searchBSTNode(root->right, key);

    // Key is smaller than root's key
    return searchBSTNode(root->left, key);
}

// Function to print the information related to the student
void printStudentInfo() {
    char name[] = "Karthik Kunnel Suni";
    char courseName[] = "Data Structures";
    int year = 2025;
    int rollNo = 1020221590;
    char email[] = "karthiksunil074@gmail.com";
    long long int mobNo = 6282159851;

    printf("My name: %s\nCourse Name: %s\nYear: %d\nRoll No: %d\nEmail: %s\nMob no: %lld\n",
           name, courseName, year, rollNo, email, mobNo);
}

int main() {
    // Program 1: Print student information
    printStudentInfo();

    // Program 2: Create a B-tree node structure and populate with values
    struct BTreeNode *rootBTree = createBTreeNode();
    insertVal2BTreeNode(rootBTree, 70);
    insertVal2BTreeNode(rootBTree, 20);
    insertVal2BTreeNode(rootBTree, 30);
    insertVal2BTreeNode(rootBTree, 48);

    // Program 3: Function to allocate memory for a B-tree node
    struct BTreeNode *sampleBTreeNode = createBTreeNode();

    // Program 4: Function to print the key values and addresses described by pointers in a B-tree node
    printBTreeNode(sampleBTreeNode);

    // Program 5: Function to insert a value inside a B-tree node and demonstrate the execution
    insertVal2BTreeNode(rootBTree, 52);
    printBTreeNode(rootBTree);

    // Program 6: Function to insert a value inside a B-tree node and handle node splitting if necessary
    rootBTree = insertVal2BTreeNodeBreak(rootBTree, 64);
    printBTreeNode(rootBTree->next[0]);
    printBTreeNode(rootBTree);
    printBTreeNode(rootBTree->next[1]);

    // Program 7: Create a BST with root node
    struct BSTNode *rootBST = NULL;

    // Program 8: Insert values into the BST and demonstrate the insertion process
    rootBST = insertBSTNode(rootBST, 70);
    rootBST = insertBSTNode(rootBST, 20);
    rootBST = insertBSTNode(rootBST, 30);
    rootBST = insertBSTNode(rootBST, 48);
    rootBST = insertBSTNode(rootBST, 52);
    rootBST = insertBSTNode(rootBST, 64);
    rootBST = insertBSTNode(rootBST, 11);
    rootBST = insertBSTNode(rootBST, 98);
    rootBST = insertBSTNode(rootBST, 77);
    rootBST = insertBSTNode(rootBST, 82);
    rootBST = insertBSTNode(rootBST, 89);
    rootBST = insertBSTNode(rootBST, 15);

    // Program 9: Search for key values in the BST
    int key1 = 48, key2 = 99;
    if (searchBSTNode(rootBST, key1) == NULL)
        printf("%d not found in BST\n", key1);
    else
        printf("%d found in BST\n", key1);

    if (searchBSTNode(rootBST, key2) == NULL)
        printf("%d not found in BST\n", key2);
    else
        printf("%d found in BST\n", key2);

    return 0;
}