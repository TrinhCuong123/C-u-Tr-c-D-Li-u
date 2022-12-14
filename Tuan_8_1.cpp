#include<iostream>
using namespace std;
template <class E> 
class BTree{
    struct BNode{
        E element; 
        BNode * left, * right; 
        BNode(E e = E(), BNode * l = 0, BNode * r = 0)
        : element (e), left(l), right(r){}
        bool isLeaf() const{ return !left && !right; }
        bool isInternal() const { return left || right; }
        // return !isLeaf(); }
    }; 
    BNode * root; 
    int size;
    void preOrderRec(const BNode * r) const{
        if (r){
            cout << r->element << " "; 
            preOrderRec(r->left); 
            preOrderRec (r->right); 
        }
    }
    void postOrderRec(const BNode * r) const{
        if (r){ 
            postOrderRec(r->left); 
            postOrderRec (r->right); 
            cout << r->element << " ";
        }
    }
    void inOrderRec(const BNode * r) const{
        if (r){ 
            inOrderRec(r->left); 
            cout << r->element << " ";
            inOrderRec (r->right); 
        }
    }
    int countNodeRec(const BNode * r) const{
        if (!r) return 0; 
        return 1+ countNodeRec(r->left) + countNodeRec(r->right); 
    }
    int countInternalNodeRec(const BNode * r) const{
        if (!r) return 0; 
        return r->isInternal() + countInternalNodeRec(r->left) 
                        + countInternalNodeRec(r->right); 
    }
    int countLeafRec (const BNode * r) const{
        if (!r) return 0; 
        return r->isLeaf() + countLeafRec(r->left) 
                            + countLeafRec(r->right); 
    }
    // {
    //     if (!r) return 0; 
    //     if (r-> isLeaf()) return 1; 
    //     return countLeafRec(r->left) + countLeafRec(r->right); 
    // }
    // int countInternalRec(const BNode * r) const{}
    // int countLeftLeaf(const BNode * r) const{}
    // int countRightLeaf(const BNode * r) const{}
    int heightRec(const BNode * r) const{
        if (!r) return -1; 
        return 1 + max(heightRec(r->left), heightRec(r->right)); 
    }

    //  add theo chi???u cao c???a c??y
    void ad??Rec1 (BNode * & r, const E & e)
    // th??m v??o c??y th???p h??n trong 2 c??y
    // n???u b???ng nhau th?? th??m v??o c??y tr??i 
    // tr?????ng h???p c?? s???: khi c??y r???ng, th?? th??m ch??nh e 
    // l??m n??t g???c, n??t duy nh???t. 
    {
        if (!r) { r = new BNode(e);}
        else {
            if (heightRec(r->left) <= heightRec(r->right))
                ad??Rec1(r->left, e); 
            else ad??Rec1(r->right, e); 
        }
    } 

    //  add c?? s???p x???p
    void addRec (BNode * & r, const E & e){
        if (!r) r = new BNode(e); 
        else{
            if (e <= r->element) addRec (r->left, e); 
            else addRec(r->right, e); 
        }
    }
    bool findRec (const BNode * r, const E & key) const {
        if (!r) return false; 
        if (key == r->element) return true; 
        if (key < r->element) return findRec(r->left, key); 
        return findRec(r->right, key); 
    }
    // {
    //     if (!r) r = new Node(e); 
    //     if (e <= r->element) addRec (r->left, e); 
    //     else addRec(r->right, e); 
    // }
    void clearRec(BNode * & r){
        if (r){
            clearRec (r->left); 
            clearRec(r->right); 
            delete r; 
            r = 0; 
        }
    }
    void copyRec(BNode * & l, const BNode * r){
        if (!r) l = 0; 
        else{
            l = new BNode(r->element); 
            copyRec(l->left, r->left); 
            copyRec(l->right, r->right); 
        }
    }
public: 
    BTree(): root(0), size(0){}
    void preOrder() const { preOrderRec(root); }
    void postOrder() const { postOrderRec(root); }
    void inOrder() const { inOrderRec(root); }
    int countNode() const{return countNodeRec(root);}
    int countLeaf() const { return countLeafRec(root);}
    int countLeftLeaf () const { return countLeafRec(root->left); }
    int countRightLeaf () const { return countLeafRec(root->right); }
    int countInternalNode() const{return countInternalNodeRec(root); }
    int height() const {return heightRec(root); }
    void add(const E e){addRec(root, e); }
    void clear(){ clearRec(root);}
    bool find(const E & key) const{return findRec(root, key ); }
    ~BTree(){ clear(); }
    BTree(const BTree<E> & r){
        copyRec(root, r.root); 
    }
    BTree<E> operator = (const BTree<E> & r){
        clear(); 
        copyrec(root, r.root); 
        return *this; 
    }
}; 
int main(){
    BTree<int> b; 
    // b.preOrder();
    b.add(5);  
    b.add(7); 
    b.add(9); 
    b.add(6); 
    b.add(2);
    b.inOrder(); 
    cout << endl; 
    cout << b.find(5) << endl; 
    cout << b.find(10) << endl; 
    // cout << b.countNode () << endl 
    // << b.countLeaf() << endl 
    // << b.countInternalNode() << endl
    // << b.countLeftLeaf() << endl 
    // << b.countRightLeaf() << endl; 
    
    cout << endl; 
    // b.postOrder(); 
    // cout << endl; 
    // b.preOrder();
    // BTree<int> c(b), d = b, e; 
    // c.inOrder(); 
    // cout << endl; 
    // d.inOrder(); 
    // cout << endl; 
    // cout << endl; 
    // b.clear(); 
    // b.inOrder();
    // cout << endl; 
    return 0; 
}