#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node* temp = new struct node;
    temp->key = val;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

struct node* insertNode(struct node* root, int key){
    if(root == nullptr){
        root = createNode(key);
        return root;
    }
    if(key < root->key){
        root->left = insertNode(root->left, key);
    }else{
        root->right = insertNode(root->right, key);
    }
    return root;
}

struct node* searchNode(struct node* root, int key){
    struct node* temp = root;
    if(root == nullptr || root->key == key){
        return root;
    }else if(key < root->key){
        temp = searchNode(root->left, key);
    }else{
        temp = searchNode(root->right, key);
    }
    return temp;
}

void swapNode(struct node* root){
    struct node* temp = root;
    if(root == nullptr){
        return ;
    }

    if(root->left != nullptr && root->right != nullptr){
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapNode(root->left);
        swapNode(root->right);
    }else if(root->left == nullptr){
        root->left = root->right;
        root->right = nullptr;
        swapNode(root->left);
    }else{
        root->right = root->left;
        root->left = nullptr;
        swapNode(root->right);
    }
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
            cout<<front->key<<" ";
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
    cout<<root->key<<" ";
    inOrder(root->right);
}

void preOrder(struct node* root){
    if(root == nullptr){
        return ;
    }
    cout<<root->key<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node* root){
    if(root == nullptr){
        return ;
    }
    stack<struct node*> st;
    stack<int> result;
    st.push(root);
    while(!st.empty()){
        struct node* top = st.top();
        st.pop();
        result.push(top->key);

        if(top->left){
            st.push(top->left);
        }
        if(top->right){
            st.push(top->right);
        }
    }

    while(!result.empty()){
        int top = result.top();
        result.pop();
        cout<<top<<" ";
    }
}

int main(){
    cout<<"Atharv";
    struct node* root = nullptr;
    root = insertNode(root, 9);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 12);

    cout<<"BFS : "<<endl;
    bfs(root);
    cout<<"\n";

    cout<<"IN Order : "<<endl;
    inOrder(root);
    cout<<"\n";

    cout<<"Pre Order : "<<endl;
    preOrder(root);
    cout<<"\n";

    cout<<"Post Order : "<<endl;
    postOrder(root);
    cout<<"\n";

    swapNode(root);

    cout<<"BFS : "<<endl;
    bfs(root);
    cout<<"\n";

    cout<<"IN Order : "<<endl;
    inOrder(root);
    cout<<"\n";

    cout<<"Pre Order : "<<endl;
    preOrder(root);
    cout<<"\n";

    cout<<"Post Order : "<<endl;
    postOrder(root);
    cout<<"\n";

    cout<<"Max Node : ";
    struct node* max = maxNode(root);
    cout<<max->key<<endl;

    cout<<"Min Node : ";
    struct node* min = minNode(root);
    cout<<min->key<<endl;

    return 0;
}