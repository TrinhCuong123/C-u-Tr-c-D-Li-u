/*
sắp xếp nhanh: 
a. để sắp xếp mảng S, dùng phần tử pivot để lọc các phần tử S vào 3 miền: miền < pivot, chính pivot, và miền >= pivot 
b. sắp xếp miền 1 và 3 theo cách a.
Cách 1: viết hàm lọc phần tử (partition): 
- chọn pivot là phần tử nào đó (đầu, cuối, giữa mảng, ...)
- tráo pivot với phần tử đầu, đặt smallIndex là chỉ số của phần tử cuối cùng < pivot
- từ sau pivot, đi về cuối mảng:
    + cứ gặp phần tử <= pivot thì tăng smallIndex, tráo phần tử smallIndex với phần tử vừa thấy
- tráo pivot (vẫn nằm ở đầu) với phần tử smallIndex hiện tại
*/
#include <iostream> 
using namespace std;
template <class E>                      
class AList{
    int maxSize; 
    int size; 
    E *list; 
    int partition(int first, int last) {   // bước phân hoạch thành 2 tập con
        // swap(list[first], list[(first + last) / 2]); // nếu chọn pivot là phần tử ở giữa
        E pivot = list[first]; 
        int smallIndex = first;
        for (int i = first + 1; i <= last; i++){
            if (list[i] <= pivot) {
                smallIndex++;
                swap(list[smallIndex], list[i]);
            }
            swap(list[first], list[smallIndex]);
        }
            return smallIndex;
    }
public: 
    // sắp xếp nhanh bản 1
    void quickSort(){   recQuickSort(0, size -1); }
    void recQuickSort(int first, int last) {// bước đệ quy
        if (first < last){
            int pivotLocation = partition(first, last); 
            recQuickSort(first, pivotLocation - 1); 
            recQuickSort(pivotLocation + 1, last);
        } 
    }
    // hàm cơ bản
    AList(int ms = 100):maxSize(ms), size(0), list(new E [ms])
    {   if (ms<0) throw "Kich thuoc khong the am\n";    }
    virtual ~AList() {  if (list) delete [] list; }                        
    void print() const {
        for (int i = 0; i<size; i++) cout << list[i] << " "; 
        cout << endl; 
    }                 
    void add(const E & e){ // hàm thêm vào cuối
        if (size==maxSize) throw "Danh sach day, khong the them\n"; 
        list[size] = e; 
        size++;
    }   
    int getSize() const{    return size;}              
}; 
int main(){
    try{
        AList<int> a(8);
        a.add(8); a.add(7); 
        a.add(6); a.add(5); 
        a.add(4); a.add(3); 
        a.print(); 
        a.quickSort(); 
        a.print(); 
        // a.recQuickSort(0, a.getSize() - 1); 
    } 
    catch(const char * msg){    cerr << "Bat duoc ngoai le!" << msg << "\n"; }
    return 0; 
}