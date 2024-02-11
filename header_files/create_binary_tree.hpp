#ifndef CREATE_BINARY_TREE_HPP
#define CREATE_BINARY_TREE_HPP

#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

    friend class binary_tree;
};

class binary_tree{


        
    public:
        node *root;
        void create_binary_tree_nr();
        node* create_recur_tree();
}; 

void binary_tree::create_binary_tree_nr(){

    queue<node*> current_node_queue;

    node *root;
    root = new node();

    current_node_queue.push(root);
    cout<<"\n\n"<<endl;
    cout<<"Enter the data for root node: "<<endl;
    cin>>root->data;

    char choice;

    while(!current_node_queue.empty()){
        node *curr = current_node_queue.front();

        current_node_queue.pop();
        cout<<"\n\n"<<endl;
        cout<<"Current node: "<<curr->data<<endl;

        cout<<"Do you want to add a left child?(Y/N)"<<endl;
        cin>>choice;

        if(choice == 'Y' || choice == 'y'){
            

            curr->left = new node();
            cout<<"Enter the data for left child"<<endl;
            cin>>curr->left->data;
            current_node_queue.push(curr->left);
        }

        cout<<"Do you want to add a right child?(Y/N)"<<endl;
        cin>>choice;

        if(choice == 'Y' || choice == 'y'){

            curr->right = new node();
            cout<<"Enter the data for right child"<<endl;
            cin>>curr->right->data;
            current_node_queue.push(curr->right);
        }
        
    }
    
}

node* binary_tree::create_recur_tree(){

    char choice;

    node* root = new node();
    cout<<"\n"<<endl;
    cout<<"Enter the data for the node: "<<endl;
    cin>>root->data;
    root->left=root->right=NULL;

    cout<<"Current node: "<<root->data<<endl;
    cout<<"Do you want to add a left child?(Y/N)"<<endl;
    cin>>choice;
    if(choice == 'Y' || choice == 'y'){
        root->left = create_recur_tree();
    }
    cout<<"Current node: "<<root->data<<endl;
    cout<<"Do you want to add a right child?(Y/N)"<<endl;
    cin>>choice;
    if(choice == 'Y' || choice == 'y'){
        root->right = create_recur_tree();
    }

    return root;
}

#endif