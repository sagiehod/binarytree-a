
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;
#include "sources/BinaryTree.hpp"
using namespace ariel;

TEST_CASE("add root to BinaryTree"){
    //new tree-add root
    //int
    BinaryTree<int> bTree_init_int;
    CHECK_NOTHROW(bTree_init_int.add_root(1));
    auto it=bTree_init_int.begin_inorder();
    CHECK((*it)==1);
    CHECK_NOTHROW(bTree_init_int.add_root(2));
    CHECK_NOTHROW(bTree_init_int.add_root(3));
    it=bTree_init_int.begin_inorder();
    CHECK((*it)==3);

    //string   
    BinaryTree<string> bTree_init_string;
    CHECK_NOTHROW(bTree_init_string.add_root("A"));
       auto it_s=bTree_init_string.begin_preorder();
        CHECK((*it_s)=="A");     
        CHECK_NOTHROW(bTree_init_string.add_root("B"));
        CHECK_NOTHROW(bTree_init_string.add_root("3"));
        it_s=bTree_init_string.begin_preorder();
        CHECK((*it_s)=="3");
}
TEST_CASE("add left to BinaryTree"){
    //int
    BinaryTree<int> bTree_left_int;
    CHECK_NOTHROW(bTree_left_int.add_root(21));
    CHECK_NOTHROW(bTree_left_int.add_left(21, 3));
    CHECK_NOTHROW(bTree_left_int.add_left(3, 6));
    CHECK_THROWS(bTree_left_int.add_left(5, 3));
    CHECK_NOTHROW(bTree_left_int.add_left(21, 5));
    CHECK_NOTHROW(bTree_left_int.add_left(5, 3));
    CHECK_THROWS(bTree_left_int.add_left(2, 6));
    int Preorder[]={21,5,3};
    int i=0;    
    for (auto it=bTree_left_int.begin_preorder(); it!=bTree_left_int.end_preorder(); ++it) {
        CHECK((*it)==Preorder[i++]);   
    }
//         21
//     |
//     5            
//   |    
//   3      
//   */
     //String
    
    BinaryTree<string> bTree_init_string;
    CHECK_NOTHROW(bTree_init_string.add_root("Sagie"));
    CHECK_NOTHROW(bTree_init_string.add_left("Sagie", "B"));
    CHECK_NOTHROW(bTree_init_string.add_left("B", "29"));
    CHECK_THROWS(bTree_init_string.add_left("c", "B"));
    CHECK_NOTHROW(bTree_init_string.add_left("29", "c"));
    CHECK_NOTHROW(bTree_init_string.add_left("Sagie", "D"));
    CHECK_THROWS(bTree_init_string.add_left("E", "29"));
    string Inorder[]={"c","29","D","Sagie"};
     i=0;
    for (auto it=bTree_init_string.begin_inorder(); it!=bTree_init_string.end_inorder(); ++it) {
        CHECK((*it)==Inorder[i++]);  
    }   
//         Sagie
//       |
//       D            
//     |    
//     29
//   |
//   C
//   */

    }
    TEST_CASE("add right to BinaryTree"){
    //int
    BinaryTree<int> bTree_right_int;
    CHECK_NOTHROW(bTree_right_int.add_root(1));
    CHECK_NOTHROW(bTree_right_int.add_right(1, 3));
    CHECK_NOTHROW(bTree_right_int.add_right(3, 9));
    CHECK_THROWS(bTree_right_int.add_right(27, 81));
    CHECK_NOTHROW(bTree_right_int.add_right(9, 27));
    CHECK_NOTHROW(bTree_right_int.add_right(27, 81));
    CHECK_THROWS(bTree_right_int.add_right(15, 6));
    int Postorder[]={81,27,9,3,1};
    int i=0;    
    for (auto it=bTree_right_int.begin_postorder(); it!=bTree_right_int.end_postorder(); ++it) {
        CHECK((*it)==Postorder[i++]);   
    }
//         1
//              |
//              3           
//                |    
//                9
//                   |    
//                    27 
//                       |    
//                        81 
//     */

     //String 
    BinaryTree<string> bTree_right_string;
    CHECK_NOTHROW(bTree_right_string.add_root("Hod"));
    CHECK_NOTHROW(bTree_right_string.add_right("Hod", "0"));
    CHECK_NOTHROW(bTree_right_string.add_right("0", "29"));
    CHECK_THROWS(bTree_right_string.add_right("cC", "0"));
    CHECK_NOTHROW(bTree_right_string.add_right("29", "cC"));
    CHECK_NOTHROW(bTree_right_string.add_right("Hod", "D"));
    CHECK_THROWS(bTree_right_string.add_right("E", "29"));
    string Preorder[]={"Hod","D","29","cC"};
     i=0;
    for (auto it=bTree_right_string.begin_preorder(); it!=bTree_right_string.end_preorder(); ++it) {
        CHECK((*it)==Preorder[i++]); 
    }    
//         Hod
//              |
//              D           
//                |    
//                29
//                   |    
//                    C                       
//     */

}
TEST_CASE(" Binary tree (root_left_right )-int"){
    //int
    BinaryTree<int> bTree_full_int;
    CHECK_NOTHROW(bTree_full_int.add_root(1));
    CHECK_NOTHROW(bTree_full_int.add_root(2));
    CHECK_NOTHROW(bTree_full_int.add_left(2, 3));
    CHECK_NOTHROW(bTree_full_int.add_right(2, 4));
    CHECK_NOTHROW(bTree_full_int.add_left(3, 5));
    CHECK_NOTHROW(bTree_full_int.add_right(3, 6));
    CHECK_NOTHROW(bTree_full_int.add_left(4, 7));
    CHECK_NOTHROW(bTree_full_int.add_right(4,8));
    CHECK_NOTHROW(bTree_full_int.add_left(4,9));
    CHECK_NOTHROW(bTree_full_int.add_right(4,10));
    CHECK_THROWS(bTree_full_int.add_left(1,11));
    CHECK_THROWS(bTree_full_int.add_left(8,12));
    CHECK_THROWS(bTree_full_int.add_left(7,13));
//         2
//     |--------|
//     3        4    
//   |---|    |---|
//   5   6    9   10
//   */
    int Inorder[]={5,3,6,2,9,4,10};
    int Preorder[]={2,3,5,6,4,9,10};
    int Postorder[]={5,6,3,9,10,4,2};
    int i=0;
    for (auto it=bTree_full_int.begin_inorder(); it!=bTree_full_int.end_inorder(); ++it) {
        CHECK((*it)==Inorder[i++]);     
    }
     i=0;    
    for (auto it=bTree_full_int.begin_preorder(); it!=bTree_full_int.end_preorder(); ++it) {
        CHECK((*it)==Preorder[i++]);       
    }
    i=0;
    for (auto it=bTree_full_int.begin_postorder(); it!=bTree_full_int.end_postorder(); ++it) {
        CHECK((*it)==Postorder[i++]);       
    }
  //string

}
TEST_CASE(" Binary tree (root_left_right )-string"){

    BinaryTree<string> bTree_full_String;
    CHECK_NOTHROW(bTree_full_String.add_root("s"));
    CHECK_NOTHROW(bTree_full_String.add_root("i"));
    CHECK_NOTHROW(bTree_full_String.add_left("i","a"));
    CHECK_NOTHROW(bTree_full_String.add_right("a", "l"));
    CHECK_NOTHROW(bTree_full_String.add_left("a", "S"));
    CHECK_NOTHROW(bTree_full_String.add_right("a","g"));
    CHECK_THROWS(bTree_full_String.add_left("l","12"));
    CHECK_NOTHROW(bTree_full_String.add_right("i","Hod"));
    CHECK_NOTHROW(bTree_full_String.add_left("Hod", "e"));
    CHECK_NOTHROW(bTree_full_String.add_right("Hod","29"));
    CHECK_THROWS(bTree_full_String.add_left("4","9"));
    CHECK_THROWS(bTree_full_String.add_left("E","i"));
    CHECK_THROWS(bTree_full_String.add_left("1","11"));
//         i
//     |--------|
//     a        Hod    
//   |---|     |---|
//   S   g     e   29
//   */
    string Inorder[]={"S","a","g","i","e","Hod","29"};
    string Preorder[]={"i","a","S","g","Hod","e","29"};
    string Postorder[]={"S","g","a","e","29","Hod","i"};
    int i=0;
    for (auto it=bTree_full_String.begin_inorder(); it!=bTree_full_String.end_inorder(); ++it) {
        CHECK((*it)==Inorder[i++]);
    }
     i=0;    
    for (auto it=bTree_full_String.begin_preorder(); it!=bTree_full_String.end_preorder(); ++it) {
        CHECK((*it)==Preorder[i++]);  
    }
    i=0;
    for (auto it=bTree_full_String.begin_postorder(); it!=bTree_full_String.end_postorder(); ++it) {
        CHECK((*it)==Postorder[i++]);    
    }

}
