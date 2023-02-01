#ifndef BINARYTREE_H
#define BINARYTREE_H
template <class T>
class binary_tree_node{
public:
// CONSTRUCTOR
  binary_tree_node(){
    data_field = NULL;
    left_field = NULL;
    right_field = NULL;
  }
  binary_tree_node(T init_data, binary_tree_node* init_left = NULL, binary_tree_node* init_right = NULL){
         data_field = init_data;
         left_field = init_left;
         right_field = init_right;
  }
  //DESTRUCTOR
  ~binary_tree_node(){
    delete left_field;
    left_field = NULL;
    delete right_field;
    right_field = NULL;
  }
  //GETTERS
  T data( ){ return data_field; }
  binary_tree_node* left( ) { return left_field; }
  binary_tree_node* right( ) { return right_field; }
  //SETTERS
  void set_data(T new_data) { data_field = new_data; }
  void set_left(binary_tree_node* new_left) { left_field = new_left; }
  void set_right(binary_tree_node* new_right) { right_field = new_right; }
  //CHECKS TO SEE IF CURRENT ROOT IS THE LEAF
  bool is_leaf( ) const
  { return (left_field == NULL) && (right_field == NULL); }

private:
  T data_field;
  binary_tree_node *left_field;
  binary_tree_node *right_field;
};

template<class T>
binary_tree_node<T>* heapification(binary_tree_node <T> * root){
  if(root->is_leaf()){
    return root;
  }
  else{
    if(root->left()->data() < root->data()){
      heapification(root->left());
    }
     else{
       T temp = root->data();
       root->set_data(root->left()->data());
       root->left()->set_data(temp);
     }

    //CHECKING RIGHT
      if(root->right() !=NULL){
            if(root->right()->data() < root->data()){
              heapification(root->right());
            }
            else{
              T temp = root->data();
              root->set_data(root->right()->data());
              root->right()->set_data(temp);
            }
        }
          if(root->data() < root->left()->data()){

            heapification(root);
          }

        if(root->right() != NULL){
          if(root->data() < root->right()->data()){

            heapification(root);
          }
       }

      }
  return root;
}

template<class T>
void traverse(binary_tree_node <T>* root){
  if(root->is_leaf()){
    cout << root->data() <<endl;
    return;
  }
  else{
    cout << root->data() <<endl;
    traverse(root->left());
    if(root->right() != NULL)
      traverse(root->right());
  }
}


template<class T>
binary_tree_node<T> * addList(binary_tree_node<T> * root, T newData){
  if(root->is_leaf()){
    binary_tree_node<T>* temp = new binary_tree_node<T> (newData);
    root->set_left(temp);
  }
  else if(root->right() == NULL){
    binary_tree_node<T>* temp = new binary_tree_node<T> (newData);
    root->set_right(temp);
  }
  //ISSUE
  else if(root->left() != NULL&&root->right() != NULL){
    addList(root->left(), newData);
  }
   heapification(root);
  return root;
}

//FOR HEAP NOT ALL BINARY TREES
template<class T>
binary_tree_node<T> * removeList(binary_tree_node <T> * root){
  if(root->is_leaf()){
    // cout << "issue 1" << endl;
    delete root;
    root = NULL;
  }
  else if(root->right() != NULL){
    //cout << "issue 2" << endl;
    T temp = root->data();
    root->set_data(root->right()->data());
    root->right()->set_data(temp);
    delete root->right();
    root->set_right(NULL);
  }
  else{
    if(root->left()->is_leaf()){
      // cout << "issue 3" << endl;
      T temp = root->data();
      root->set_data(root->left()->data());
      root->left()->set_data(temp);
      delete root->left();
      root->set_left(NULL);
    }
    else{
      // cout << "issue 4" << endl;
      T temp = root->data();
      root->set_data(root->left()->data());
      root->left()->set_data(temp);
      removeList(root->left());
    }
  }
  if(root != NULL){
    // cout << "issue" <<endl;
  heapification(root);
  }
  return root;
}

#endif
