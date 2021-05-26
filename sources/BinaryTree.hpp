
#include <iostream>
#include <unordered_map>
#include <utility>     

using namespace std;
namespace ariel {

template <typename temp_type>
class BinaryTree {
private:
temp_type vertex;
class iterator
{
public:
temp_type it;


iterator(temp_type v) : it(v){
}

bool operator!=(BinaryTree::iterator const&_it)const
{
        return false;
}
bool operator==(BinaryTree::iterator const &_it) const
{
        return false;

}
 temp_type operator*() 
{
        return it;
}
iterator &operator++()
{

        
        return *this;
}
iterator *operator->() 
{
        iterator *goal;
        return goal;
}
int size(){
return 1;
}
};


public:
BinaryTree() {
}
BinaryTree<temp_type>& add_root(temp_type first){
        return *this;
}
BinaryTree<temp_type>& add_left(temp_type parent,temp_type son_l){
        return *this;
}
BinaryTree<temp_type>& add_right(temp_type parent,temp_type son_r){
        return *this;
}
iterator begin(){
    return iterator(vertex);
}
iterator   end(){
    return iterator(vertex);
  }
iterator   begin_preorder(){
    return iterator(vertex);
}
iterator  end_preorder(){
    return iterator(vertex);
}
iterator   begin_inorder(){
    return iterator(vertex);
}
iterator   end_inorder(){
    return iterator(vertex);
}
iterator   begin_postorder(){
    return iterator(vertex);
}
iterator end_postorder(){

    return iterator(vertex);
}
friend ostream& operator<<(ostream& os,BinaryTree<temp_type>& tree){
        return os;
}
};




}
