#include<iostream>
using namespace std;

//Viết hàm bubbleSort nhập vào một mảng và sắp xếp nổi bọt mảng này
void bubbleSort(int a[], int n){
    bool swapped;
    do
    {
        swapped=false;
        for(int i=0; i<n-1; i++){
            if(a[i]>a[i+1]){
                swap(a[i], a[i+1]);
                swapped=true;
            }
        }
        n--;
    } while (swapped);    
}
//Viết hàm selectionSort nhập vào một mảng và sắp xếp chọn mảng này 
void selectionSort(int a[], int n){
    for(int scan = 0; scan< n-1; scan++){
        int minIndex= scan;
        for(int j = scan + 1; j < n ; j++){
            if(a[j]<a[minIndex])
                minIndex=j;
        }
    swap(a[scan], a[minIndex]);
    }
}
//Viết hàm insertionSort nhập vào một mảng , sắp xếp mảng đó dùng thuật toán sắp xếp chèn
void insertionSort(int *a, int n)
{
    for(int i = 0; i<n; i++){
        int y=i;
        while (y>0){
            if(a[y-1] > a[y]) swap(a[y-1],a[y]);
            y--;
        }        
    }
}

void combine(int a[], int b[], int c[], int m, int n){
        int i, j, k = i = j = 0;
        while(i < m && j < n){
            a[k] = b[i] < c[j] ? b[i] : c[j];
            b[i] < c[j] ? i++ : j++;
            k++;
        }
        for(; i<m; i++, k++) a[k] = b[i];
        for(; j<n; j++, k++) a[k] = c[j];
}
void merge (int a[], int n){
    if(n<2) return ;
    int mid = n/2; 
    int b[mid], c[n-mid]; 
    for (int i = 0; i < mid; i++) b[i] = a[i]; 
    // for (int i = 0; i<n-mid; i++) c[i] = a[i+mid]; 
    for (int i = mid; i < n; i++) c[i-mid] = a[i];
    merge (b, mid); 
    merge (c, n-mid); 
    combine (a, b, c, mid, n-mid);
}

int partition(int a[], int first, int last) {    // bước phân hoạch thành 2 tập con
        // swap(list[first], list[(first + last) / 2]); // nếu chọn pivot là phần tử ở giữa
        int pivot = a[first]; 
        int index = first;
        for (int i = first + 1; i <= last; i++) 
            if (a[i] <= pivot){
                index++;
                swap(a[index], a[i]);
            }
        swap(a[first], a[index]);
        return index;
}  
void quickSort (int a[], int first, int last){
    if (first < last){
        int pivot = partition (a, first, last); 
        quickSort (a, first, pivot-1); 
        quickSort(a, pivot+1, last); 
    }
}

int main(){

    return 0;
}