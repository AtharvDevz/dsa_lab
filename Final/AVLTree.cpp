#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->key = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int max (int a, int b){
    return (a>b)?a:b;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    } 
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node *leftRotate(Node *node)
{
    Node *y = node->right;
    Node *T2 = y->left;
    y->left = node;
    node->right = T2;
    return y;
}

Node *rightRotate(Node *node)
{
    Node *x = node->left;
    Node *T2 = x->right;
    x->right = node;
    node->left = T2;
    return x;
}

Node *insertNode(Node *&root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    if (key < root->key)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertNode(root->right, key);
    }
    int bf = getBalanceFactor(root);
    cout<<bf<<" \n";

    // LL Rotation
    if (bf > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    // RR Rotation
    if (bf < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    // LR Rotation
    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL Rotation
    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* &root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main()
{
    cout << "Atharv" << endl;
    Node *root = NULL;

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 11);
    root = insertNode(root, 15);
    root = insertNode(root, 82);
    root = insertNode(root, 21);

    cout<<"Height of root : "<<getHeight(root)<<endl;
    
    cout<<"Pre Order : "<<endl;
    preOrder(root);
    cout<<"\n\n\n";

    cout<<"In Order : "<<endl;
    inOrder(root);
    cout<<"\n\n\n";
}