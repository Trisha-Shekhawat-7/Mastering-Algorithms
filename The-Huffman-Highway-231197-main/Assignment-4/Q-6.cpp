/*We can recursively go into the left and right nodes and check if both are null then its okay but if only one of them is null than they are not isomorphic 
<br/>*/

bool check_isomorphic(Node* n1, Node* n2){
    if(n1 && n2) return check_isomorphic(n1->left, n2->left) && check_isomorphic(n1->right, n2->right);
    else if(n1==NULL && n2 == NULL) return true ; 
    return false ;
}
