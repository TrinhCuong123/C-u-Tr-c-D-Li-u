// Cài đặt ADT List: tạo, huỷ, thêm vào, bớt đi, xoá cả danh sách, lấy phần tử, và tìm kiếm khoá trả về vị trí . sử dụng ds liên kết 
	
// viêt thêm hàm getLink
#include<iostream>
using namespace std;
template<class E>
class SList{
    struct Node{
        E element;
        Node *next;
        Node(E e = E(), Node *n = 0): element(e), next(n){}
    };
    Node *head;
    int size;
public:
    SList():head(0), size(0){}
    ~SList(){clear();}
    Node *& getLink(int i){
        if(i < 0 || i > size) throw "loi chi so\n";
        if(!i) return head;
        Node *v = head;
        for(int j = 0; j < i -1; j++) v = v->next;
        return v->next;
    }
    void add(int i, const E &e){
        if(i < 0 || i > size) throw "Loi chi so\n";
        Node * & prev = getLink(i);
        Node *v = new Node(e, prev);
        prev = v;
        size++;
    }
    void remove(int i){
        if(i < 0 || i >= size) throw "Loi chi so\n";
        Node *& v = getLink(i);
        Node *p = v;
        v = v->next;
        delete(p);
        size--;
    }
    void clear(){
        while(head) remove(0);
    }
    int getElement(int i){
        if(i < 0 || i >= size) throw "Loi chi so\n";
        return getLink(i)->element;
    }
    int search(const E &e){
        for(int i = 0; i < size; i++){
            if(getElement(i) == e) return i;
        }
        return -1;
    }
    void print()const {
        for(Node *v = head; v; v=v->next) cout<<v->element<<" ";
        cout<<endl;
    }
};
int main(){
    SList<int> a;
    a.add(0,2);
    a.add(1,3);
    a.add(2,5);
    a.print();
    return 0;
}