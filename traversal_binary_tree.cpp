#include<iostream>
#include "./header_files/create_binary_tree.hpp"
#include<stack>

using namespace std;

class tree_traversal : public binary_tree{

    public:
       void preorder();
};

void tree_traversal::preorder(){

    stack<node*> st;
    st.push(root);

    while(st.empty() == 0){
        node* curr = st.top();
        st.pop();
        while(curr!=NULL){

            cout<<"\t"<<curr->data;
            if(curr->right!=NULL)
                st.push(curr->right);
            
            curr = curr->left;
            }
        
        }
    }



int main(){

    tree_traversal t;
    t.create_recur_tree();
    t.preorder();

    return 0;
}