// // Bài 1. Cài đăt lớp SList có các thành viên: 
// // - con trỏ head đến nút đầu
// // - kích thước danh sách

// // Bài 2. Hàm tạo ko tham số khởi tạo ds rỗng
#include<iostream>
using namespace std;
struct Node {
    int value;
    Node *next;
    Node(int value = 0, Node *next = NULL) : value(value), next(next) {}
};
class SList{
        Node *head;
        int size;
    public:
        SList():head(NULL),size(0){}
        // Viết hàm void add (int v) chèn nút có dữ liệu lõi là v vào danh sách
        void addfirst(int v){
            Node*a=new Node(v,head);
            head=a;
            size++;
        }
        void addLast(int v){
            Node*a=new Node(v);
            if(head==NULL){
                head=a;
            }
            else{
                // while(head->next!=NULL){
                //     head=head->next
                // }
                Node *i=head;
                for(;i->next;i=i->next);
                i->next=a;
            }
                size++;
        }
};
int main(){
    return 0;
}

#include <iostream> 
using namespace std; 
template <class T>
class List1{
    struct Node{
    T element; 
    Node * next; 
    Node (T e = T(), Node * n = 0): element(e), next(n){}
}; 
    Node * head; 
    int size; 
public: 
    List1(): head(0), size(0){}
    void addFirst (T e){
        Node * v = new Node(e, head); 
        head = v; 
        size++; 
    }
    void addLast (T e){
        Node * v = new Node(e); 
        if (!head) head = v; 
        else {
            Node * i = head; 
            for (; i->next; i = i->next);
            i->next = v; 
        }
        size++; 
    }
    void remove(int e){
        if(head->next==e){
            head=head->next;
            delete head;
            size--;
        }
    }
};

#include <iostream> 
using namespace std; 
struct Node{
    int element; 
    Node * next; 
    Node (int e = 0, Node * n = 0): element(e), next(n){}
}; 
class SList{
    Node * head; 
    int size; 
public: 
    SList(): head(0), size(0){}
    void addFirst (int e){
        Node * v = new Node(e, head); 
        head = v; 
        size++; 
    }
    void addLast (int e){
        Node * v = new Node(e); 
        if (!head) head = v; 
        else {
            Node * i = head; 
            for (; i->next; i = i->next);
            i->next = v; 
        }
        size++; 
    }
};