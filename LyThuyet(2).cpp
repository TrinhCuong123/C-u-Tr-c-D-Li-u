// Tuần 3
// push pop top size isempty
#include<iostream>
using namespace std;
template<class E>

// TODO: AStack

class AStack{
    int maxSize, size;
    E *a;
public:
    AStack(int max=100):maxSize(max),size(0), a(new E[maxSize]){}
    ~Astack(){delete []a;}
    void print()const{
        for(int i=0;i<size; i++)    cout<<a[i]<<" ";
        cout<<endl;
    }
    void push(const E&e){
        if(size==maxSize) throw "Loi\n";
        a[size++]=e;
    }
    void pop(){
        if(size==0) throw "Loi\n";
        size--;
    }
    E top()const{
        if(size==0) throw "Loi\n";
        return a[size-1]
    }
    void push(const T &x){
        if(size==maxSize) throw "Loi\n";
        a[size++]=x; 
    }
    int getSize()const{     return size; }
    bool isEmpty()const{    return size==0; }
    bool isFull()const{     return size==maxSize; }
    void clear(){   size=0; }


    Astack<E> operator=(const Astack<E> &r){
        maxSize=r.maxSize;
        size=r.size;
        delete [] a;
        a = new E[maxSize];
        for(int i=0; i<size; i++) a[i]=r.a[i];
        return *this;
    }
    Astack(const Astack &r){
        maxSize = r.maxSize;
        size = r.size;
        a = new E[maxSize];
        for(int i=0; i<size; i++) a[i]=r.a[i];
    }
};

// TODO: SLStack

template<class E>
class SLstack{
    struct Node{
        E element;
        Node *next;
        Node(E e = E(),Node * n=0): element(e), next(n){}
    };
    Node *head = 0;
    int size;
public:
    SLstack(): head(0),size(0){}
    void print()const {
        for(Node *v=head; v; v = v->head)   cout<<v->element<<" ";
        cout<<endl;
    }
    void push(const E &e){
        Node *v = new Node(e, head);
        head = v;
        size++;
    }
    void pop(){
        if(size==0) throw "Loi\n";
        Node *v = head;
        head = head->next;
        delete v;
        size--;
    }
    E top() const {
        if(size==0) throw "Loi\n";
        return head->element;
    }
    bool isEmpty()const{    return size==0; }
    int getSize()const {    return size;    }
};



// TODO: OAList

#include<iostream>
using namespace std;
template<class T>
class OAlist{
    int maxSize, size;
    T *arr;
    public:
    OAlist(int n=100):maxSize(n), size(0), arr(new T[maxSize]){}
    ~OAlist(){
        delete []arr;
    }
    void print()const{
        for(int i=0; i<size; i++) cout<<arr[i]<<" ";
    }
    void add(const T e){
        if(size==maxSize) throw'loi';
        int i=0;
        for(;i<size; i++){
            if(e<=arr[i]) break;
        }
        for(int j=size; j>i; j--) arr[j]=arr[j-1];
        arr[i]=e;
        size++;
    }
    void remove(int i){
        if(size==0) throw'loi';
        if(i<0||i>=size) throw'loi';
        for(int j=i; j<size; j++){
            arr[j]=arr[j+1];
        }
        size--;
    }
    bool isEmpty()const{return size==0;}
    bool isFull()const{return size==maxSize;}
    int getSize()const{return size;}
    OAlist(const OAlist &o){
        maxSize=o.maxSize;
        size=o.size;
        arr=new T[maxSize];
        for(int i=0; i<size; i++) arr[i]=o.arr[i];
    }
    OAlist<T> &operator=(const OAlist &o){
        maxSize=o.maxSize;
        size=o.size;
        for (int i = 0; i < size; i++)
        {
            arr[i]=o.arr[i]
        }
        return *this;
    }
};
int main(){
    OAlist<int> o;
    o.add(1);
    o.add(3);
    o.add(2);
    o.add(5);
    o.add(4);
    o.print();
    cout<<endl;
    o.remove(1);
    o.print();
}


// TODO: OSList

#include<iostream>
using namespace std;
template<class T>
class OSlist{
    struct Node
    {
        T data;
        Node *next;
        Node(T e = T(), Node *n = NULL):data(e), next(n){};
    };
    Node *head;
    int size;
    Node *&getlink(int i){
        if(i<0||i>size) throw'loi';
        if(!i) return head;
        Node *tmp=head;
        for(int j=0; j<i-1; j++){
            tmp=tmp->next;
        }
        return tmp->next;
    }
    public:
    OSlist():head(NULL), size(0){}
    void print()const{
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
    }
    void add(const T x){
        int i=0;
        Node *tmp=head;
        for (; i<size; tmp=tmp->next, i++)
            if (x<=tmp->data) break;
        Node *&v=getlink(i);
        Node *tmp2 = new Node(x, v);
        v=tmp2;
        size++;
    }
    void remove(int i){
        if(i<0||i>=size) throw'loi';
        Node *&tmp=getlink(i);
        Node *tmp2 = tmp;
        tmp=tmp->next;
        delete tmp2;
        size--;
    }
    void replace(int i, const T e){
        if(i<0||i>=size) throw'Loi';
        remove(i);
        add(e);
    }
    bool isEmpty()const{return size==0;}
    int getSize()const{return size;}
    ~OSlist(){
        while (head)
        {
            remove(0);
        }
    }
    OSlist(const OSlist &s){
        size=s.size;
        head=s.head;
        // Node *tmp = head;
    }
    OSlist<T> &operator=(const OSlist &s){
        size=s.size;
        head=s.head;
        return *this;
    }
};
int main(){
    OSlist<int> O;
    O.add(3);
    O.add(4);
    O.add(1);
    O.add(2);
    O.print();
    cout<<endl;
    OSlist<int> O2(O);
    O2.print();
    cout<<endl;
    OSlist<int> O3=O2;
    O3.print();
}


