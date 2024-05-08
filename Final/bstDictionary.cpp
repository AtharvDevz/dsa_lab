#include<iostream>
#include<queue>
using namespace std;

struct node{
    string key;
    string mean;
    struct node *left;
    struct node *right;
};

struct node* createNode(string val, string mean){
    struct node* temp = new struct node;
    temp->key = val;
    temp->mean = mean;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

struct node* insertNode(struct node* root, string key, string mean){
    if(root == nullptr){
        root = createNode(key, mean);
        return root;
    }
    if(key < root->key){
        root->left = insertNode(root->left, key, mean);
    }else{
        root->right = insertNode(root->right, key, mean);
    }
    return root;
}

struct node* searchNode(struct node* root, string key){
    struct node* temp = root;
    if(root == nullptr || root->key == key){
        return root;
    }else if(root->key < key){
        temp = searchNode(root->left, key);
    }else{
        temp = searchNode(root->right, key);
    }
    return temp;
}

struct node* maxNode(struct node* root){
    struct node* temp = root;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}

struct node* minNode(struct node* root){
    struct node* temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

void bfs(struct node* root){
    queue<struct node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        struct node* front = q.front();
        q.pop();

        if(front == nullptr){
            cout<<"\n";
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<front->key<<"\t"<<front->mean<<endl;
            if(front->left != nullptr){
                q.push(front->left);
            }
            if(front->right != nullptr){
                q.push(front->right);
            }
        }
    }
}

void inOrder(struct node* root){
    if(root == nullptr){
        return ;
    }
    inOrder(root->left);
    cout<<root->key<<"\t"<<root->mean<<endl;
    inOrder(root->right);
}

void preOrder(struct node* root){
    if(root == nullptr){
        return ;
    }
    cout<<root->key<<"\t"<<root->mean<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void deleteDictionary(struct node* root){
    if(root != nullptr){
        deleteDictionary(root->left);
        deleteDictionary(root->right);
        delete root;
    }
}

int main(){
    cout<<"Atharv";
    struct node* root = nullptr;
    root = insertNode(root, "mango", "aamba");
    root = insertNode(root, "python", "saap");
    root = insertNode(root, "java", "chai");
    root = insertNode(root, "kaffee", "coffee");
    root = insertNode(root, "cpp", "c");
    root = insertNode(root, "Nariyal", "coconut");
    root = insertNode(root, "Queen", "Rani");
    cout<<"BFS : "<<endl;

    bfs(root);
    cout<<"\n";

    cout<<"IN Order : "<<endl;
    inOrder(root);
    cout<<"\n";

    cout<<"Pre Order : "<<endl;
    preOrder(root);
    cout<<"\n";

    return 0;
}