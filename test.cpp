#include <iostream> 
using namespace std; 
template <class E> 
class BTree{
    struct BNode{
        E data;
        BNode *left, *right;
        BNode(E e = E(), BNode *l = 0, BNode *r = 0): data(e), left(l), right(r){}
        bool isLeaf() const{ return !left && !right;    }
        bool isInternal() const { return !isLeaf(); }
    }; 
    BNode * root; 
    int size;
    void preOrderRec(const BNode * r) const{        // duyệt kiểu tiền tố (các cha trước rồi đến con)
        cout << r->data << " ";
        preOrderRec(r->left);
        preOrderRec(r->right);
    }
    void postOrderRec(const BNode * r) const{   // duyệt kiểu hậu tố (các con trước rồi đến cha)
        preOrderRec(r->left);
        preOrderRec(r->right);
        cout << r->data << " ";
    }
    void inOrderRec(const BNode * r) const{     //Trung tố (con cha con)
        preOrderRec(r->left);
        cout << r->data << " ";
        preOrderRec(r->right);
    }
    int countNodeRec(const BNode * r) const{
        if(!r) return 0;
        return 1 + countNodeRec(r->left) + countNodeRec(r->right);
    }
    int countLeafRec (const BNode * r) const{
        if(!r) return 0;
        return isLeaf() + countNodeRec(r->left) + countNodeRec(r->right);
    }
    int countInternalRec(const BNode * r) const{
        if(!r) return 0;
        return isInternal() + countNodeRec(r->left) + countNodeRec(r->right);
    }
    // int countLeftLeaf(const BNode * r) const{}
    // int countRightLeaf(const BNode * r) const{}
    int heightRec(const BNode * r) const{
        
    }
    void addRec (BNode * & r, const E & e)
    {
        
    } 

public: 
    BTree(): root(0), size(0){}
    void preOrder() const { preOrderRec(root); }
    void postOrder() const { postOrderRec(root); }
    void inOrder() const { inOrderRec(root); }
    int countNode() const{return countNodeRec(root);}
    int countLeaf() const { return countLeafRec(root);}
    int height() const {return heightRec(root); }
    void add(const E e){addRec(root, e); }
    int countInternal() const {     return countInternalRec(root);}
}; 
int main(){
    BTree<int> b; 
    b.add(1);  
    b.add(2); 
    b.add(3); 
    b.add(4); 
    b.add(5); 
    b.inOrder(); 
    cout << endl; 
    b.postOrder(); 
    cout << endl; 
    b.preOrder(); 
    cout << endl; 
    cout<<"Internal: "<<b.countInternal()<<endl;
    return 0; 
}