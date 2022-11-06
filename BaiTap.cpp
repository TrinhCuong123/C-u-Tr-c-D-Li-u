#include<iostream>
using namespace std;
template<class T>
class List{
    int sizeMax,size;
    T *arr;
    bool wrong(int i)const{
        return (i<0||i>=size);
    }
public:
// 1. Khởi tạo danh sách (constructor)
    List(int n=100):sizeMax(n),size(0),arr(new T[sizeMax]){};

// 2. (phụ) Hàm in ra (print)
    void print()const{ 
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
// 3. Lấy ra giá trị một phần tử tại một vị trí cụ thể (getElement)
    int getElement(int j) const{ 
        if(wrong(j)) throw "loi";
        return arr[j];
    }
// 4. Tìm kiếm một giá trị khoá trong danh sách (search/find)
    bool find(int key){
        for(int i=0;i<size;i++){
            if(arr[i]==key) return true;
        }
        return false;
    }
    int search(int key){
        for(int i=0;i<size;i++){
            if(arr[i]==key) return i;
        }
        return -1;
    }
// 5. Thêm phần tử vào danh sách tại một vị trí cụ thể (add)
    void add(int index,int x){
        if(index<0||index>size||size==sizeMax){
            cout<<"Loi";
            return;                                  
        }
        for(int i=size;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=x;
        size++;
    }
// 6. Loại bỏ phần tử tại một vị trí cụ thể, loại bỏ một khoá (remove/removeKey)
void remove(int index){
    if(index<0||index>=size||size==0)
    {
        cout<<"Loi"<<endl;
        return;
    }
    for(int i=index; i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
// 7. Thay thế giá trị của một phần tử tại một vị trí cụ thể (replace)
void replace(int i,int x){
    if(wrong(i)) throw "loi";
    arr[i]=x;
}
// 8. Xóa rỗng danh sách, (phụ) hàm huỷ (clear, destructor)
void Clear(){
    size=0;
}
~List(){ delete [] arr;}
// 9. Tính kích thước (getSize)
int getSize(){ 
    int i=0,count=0;
    while(arr[i]!=0){
        count++;
        i++;
    }
    return count;
}
// 10. Kiểm tra danh sách rỗng (isEmpty)
bool isEmpty()const{ 
    return size==0;
}
// 11. Kiểm tra danh sách đầy (isFull)
bool isFull() const{ 
    return size==sizeMax;
}
// 12.(phụ) Hàm tạo sao chép (copy constructor)
List(const List& r){
    size=r.size;
    sizeMax=r.sizeMax;
    arr=new int[sizeMax];
    for(int i=0;i<size;i++){
        arr[i]=r.arr[i];
    }
}
// Note: hàm in ra, hàm huỷ, và hàm tạo sao chép là các hàm thêm vào khi cài đặt,
// không tính trong ADT

};
int main(){
    List<int> l;
    l.add(0,1);
    l.add(1,2);
    l.print();
    l.remove(0);
    l.print();
    return 0;
}