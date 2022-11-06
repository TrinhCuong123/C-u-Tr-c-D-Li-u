#include <iostream> 
using namespace std;
template <class E>                      
class AList{ 
    int maxSize; 
    int size; 
    E * a; 
public: 
    void selectionSort(){
        for (int scan = 0; scan<size-1; scan++)
        {
            int iMin = scan;  
            for (int j = scan + 1; j<size; j++)
                if (a[j] < a[iMin]) iMin = j;
            swap(a[scan], a[iMin]); 
        }
    }  
    void bubbleSort(){
        for (int i = 0; i < size-1; i++)
            for (int j = 0; j < size - 1; j++)
                if (a[j]> a[j+1]) swap (a[j], a[j+1]); 
    }
    void insertionSort(){
        for (int i = 0; i<size; i++){
            int j = i; 
            while (j>0){
                if (a[j-1]>a[j])swap (a[j-1], a[j]); 
                j--; 
            }
        }
    }
    // hàm cơ bản
    AList(int ms = 100):maxSize(ms), size(0), a(new E [ms])
    { if (ms<0) throw "Kich thuoc khong the am\n"; }
    virtual ~AList() {delete [] a;}                       
    void print() const {
        for (int i = 0; i<size; i++) cout << a[i] << " "; 
        cout << endl; 
    }                 
    void add(const E & e){  // hàm thêm vào cuối
        if (size==maxSize) throw "Danh sach day, khong the them\n"; 
        a[size] = e; 
        size++;
    }                    
}; 
int main(){
    try{
        AList<int> a(4);
        a.add(8); a.add(7); 
        a.add(6); a.add(5); 
        a.print(); 
        // a.selectionSort(); a.print(); 
        // a.bubbleSort(); a.print(); 
        a.insertionSort(); a.print();
    } 
    catch(const char * msg){ cerr << "Bat duoc ngoai le!" << msg << "\n"; }
    return 0; 
}