#include<iostream>
using namespace std;
/* Lấy lại BNode để từ đó viết BSTree: 	
    có 1 gốc trỏ đến BNode	
    hàm tạo sinh ra cây rỗng	
    hàm add: nếu cây rỗng thì thêm phần tử e vào gốc, nếu không, thì so e với phần tử ở gốc, e < gốc thì thêm e vào cây trái, e > gốc thì thêm e vào cây phải  */
template<class E>
class BSTree{
    struct BNode{
        E element;
        BNode *left, *right;
        BNode(E e = E(), BNode *l=0, BNode *r=0) : element(e),left(l),right(r){};
        bool isLeaf() { return !left && !right;}
        bool isInternal() { return !isLeaf();}
    };
    BNode *root;
    int size;
    void preOrderRec(const BNode *r) const{ //tien to
        if(r != NULL){
            cout<<r->element<<" ";
            preOrderRec(r->left);
            preOrderRec(r->right);
        }
    }
    void inOrderRec(const BNode *r) const{ //trung to
        if(r != NULL){
            inOrderRec(r->left);
            cout<<r->element<<" ";
            inOrderRec(r->right);
        }
    }
    void addRec(BNode *&r, const E &e){
        if(!r) {r = new BNode(e);}
        else{
            if(e <= r->element) addRec(r->left, e);
            else addRec(r->right, e);
        }
    }
    /* Viết hàm tìm kiếm bool findRec( BNode * & r, const E & key) tìm kiếm như sau: 	
        cây rỗng thì trả false 	
        so sánh key với gốc, nếu bằng thì trả về true	
        nếu key nhỏ hơn gốc, tìm ở cây con trái	
        còn lại, tìm ở cây con phải  */
    bool findRec(BNode *r, const E &key)const {
        if(r = NULL) return false;
        if(key == r->element) return true;
        if(key < r->element) return findRec(r->left, key);
         return findRec(r->right, key);
    }
    int heightRec(const BNode * r) const{
        if (!r) return -1; 
        return 1 + max(heightRec(r->left), heightRec(r->right)); 
    }
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
    //Viết thêm hàm searchRec() và search tìm kiếm giá trị key trong một cây, và trả về tham chiếu đến địa chỉ của nút chứa giá trị đó 
    BSTree *& searchRec(BNode *&r, const E &e){
        if(!r) {
            cout <<"Khong tim thay \n";
            return r;
        }
        if(e < r->element) return searchRec(r->left,e);
        else if (e = r->element){
            return r;
        }
        else{
            return searchRec(r->right,e);
        }             
    }
    void searchRemoveRec(BNode * & r, const E & e){ 
        if (!r) {
            cout << "Khong tim thay, khong the xoa\n"; 
            return;
        }
        if (e<r->element)searchRemoveRec(r->left, e);
        else if (e>r->element)searchRemoveRec(r->right, e);
        else{
            BNode * cur = r; 
            if (!r->left) r=r->right; 
            else if (!r->right) r = r->left;
            else{
                cur = r->left; 
                BNode * parent = r; 
                for (; cur->right;parent = cur,cur = cur->right);
                r->element = cur->element; 
                if (cur == r->left) parent->left = cur->left; 
                else parent->right = cur->left;  
            }
            delete cur; 
            cur = 0; 
        }
    }


public:
    BSTree():root(0),size(0){};
    void add(const E e) {addRec(root,e);}
    void preOrder() const {preOrderRec(root);}
    void inOrder() const{ inOrderRec(root);}
    bool find(const E &e) const {return findRec(root, e);}
    int height()const {return heightRec(root);}
    void clear() {clearRec(root);}
    ~BSTree(){ clear(); }
    BSTree(const BSTree<E> & r){
        copyRec(root, r.root); 
    }
    BSTree<E> operator = (const BSTree<E> & r){
        clear(); 
        copyrec(root, r.root); 
        return *this; 
    }
    BSTree<E> search(const E &e)const{return searchRec(root,e);}
    void searchRemove(const E & e){ searchRemoveRec(root, e);}

};
int main(){
    BSTree<int> bs;
    bs.add(8);
    bs.add(0);
    bs.add(6);
    bs.add(5);
    bs.inOrder();
    cout<<endl;
    bs.searchRemove(0);
    bs.inOrder();
    return 0;
}