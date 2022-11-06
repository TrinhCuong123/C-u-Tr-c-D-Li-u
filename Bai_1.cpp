// Một ADT List gồm các thao tác sau: 
// - Khởi tạo danh sách (constructor)
// - Xóa rỗng danh sách, hàm huỷ (clear, destructor)
// - Thêm phần tử vào danh sách tại một vị trí cụ thể (add)
// - Loại bỏ phần tử tại một vị trí cụ thể (remove)
// - Kiểm tra danh sách rỗng (isEmpty)
// - Kiểm tra danh sách đầy (isFull)
// - Tính kích thước (getSize)
// - Lấy ra giá trị một phần tử tại một vị trí cụ thể (getElement)
// Chỉ cài các hàm sau khi đề bài yêu cầu rõ ràng: 
// - Thay thế giá trị của một phần tử tại một vị trí cụ thể (replace)
// - Tìm kiếm một giá trị khoá trong danh sách (search/find)
// - (phụ) Hàm in ra (print)
// - (phụ) Hàm tạo sao chép
// - (phụ) Toán tử bằng

// Cài đặt ADT List: tạo, huỷ, thêm vào, bớt đi, xoá cả danh sách, và tìm kiếm khoá trả về vị trí
#include <iostream> 
using namespace std; 
template <class E> 
class AList{
    int maxSize, size; 
    E * a; 
public: 
    AList(int n): maxSize(n), size(0), a(new E [n]){}
    ~AList(){ delete [] a; }
    void add(int i, const E & e){
        if(size == maxSize || i < 0 || i > size) throw "Loi chi so\n";
        for(int j = size; j > i; j--) a[j] = a[j-1];
        a[i] = e;
        size ++;
    }
    void remove(int i){
        if(size == 0|| i < 0 || i >= size) throw "Loi\n";
        for(int j = i; j < size - 1; j++) a[j] = a[j+1];
        size--;
    }
    void clear(){ size = 0}
    int search(const E & e){
        for(int i = 0; i < size; i++){
            if(a[i] == e) return i;
        }
        return -1;
    }
};
int main(){
    return 0;
}