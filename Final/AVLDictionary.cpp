#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string word;
    string meaning;
    Node *left;
    Node *right;
    Node(string wo, string mean)
    {
        this->word = wo;
        this->meaning = mean;
        this->left = NULL;
        this->right = NULL;
    }
};

int getHeight(Node *node)
{
    if (node == NULL)
    {
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

Node *rightRotate(Node *node)
{
    Node *x = node->left;
    Node *T2 = x->right;
    x->right = node;
    node->left = T2;
    return x;
}

Node *leftRotate(Node *node)
{
    Node *y = node->right;
    Node *T2 = y->left;
    y->left = node;
    node->right = T2;
    return y;
}

Node *insertNode(Node *&root, string wo, string mean)
{
    if (root == NULL)
    {
        root = new Node(wo, mean);
        return root;
    }
    if (wo < root->word)
    {
        root->left = insertNode(root->left, wo, mean);
    }
    else if (wo > root->word)
    {
        root->right = insertNode(root->right, wo, mean);
    }
    int bf = getBalanceFactor(root);

    // RR Rotation
    if (bf > 1 && wo < root->left->word)
    {
        return rightRotate(root);
    }
    // LL Rotation
    if (bf < -1 && wo > root->right->word)
    {
        return leftRotate(root);
    }
    // LR Rotation
    if (bf > 1 && wo > root->left->word)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL Rotation
    if (bf < -1 && wo < root->right->word)
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
    cout << root->word << "\t" << root->meaning << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->word << "\t" << root->meaning << endl;
    inOrder(root->right);
}

int main()
{
    cout << "Start" << endl;
    Node *root = NULL;
    cout << "Working Fine\n";
    root = insertNode(root, "mango", "aamba");
    root = insertNode(root, "python", "saap");
    root = insertNode(root, "java", "chai");
    root = insertNode(root, "kaffee", "coffee");
    root = insertNode(root, "cpp", "c");
    root = insertNode(root, "Nariyal", "coconut");
    root = insertNode(root, "Queen", "Rani");

    int height = getHeight(root);
    cout << "Height of root : " << height << endl;

    cout << "Pre Order : " << endl;
    cout << "Word"<< "\t"<< "Meaning" << endl;
    preOrder(root);
    cout << "\n";

    cout << "In Order : " << endl;
    cout << "Word"<< "\t"<< "Meaning" << endl;
    inOrder(root);
    cout << "\n";

    cout << "End";
}