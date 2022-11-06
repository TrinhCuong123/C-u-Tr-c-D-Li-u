#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

//1.Xây dựng hàm đệ quy để tìm giá trị lớn nhất/nhỏ nhất trong mảng số nguyên chứa n phần tử
   
int max(int a[],int i) {
    if(!i) return a[i];
    return max(a[i], max(a,i-1));
}
int min(int a[],int i) {
    if(!i) return a[i];
    return min(a[i], min(a,i-1));
}

//1.Xây dựng hàm đệ quy dùng để đảo ngược một chuỗi ký tự. Ví dụ: Đảo ngược chuỗi “pots&pans” sẽ là “snap&stop”.
void reverse(string &a, int i, int  j) {
    if(i<j){
        swap(a[i],a[j]);
        reverse(a,i+1,j-1);
    }
}
//.Xây dựng hàm đệ quy để kiểm tra một chuỗi ký tự có phải là chuỗi palindrome hay không. Chuỗi palindrome là chuỗi mà khi đảo ngược lại, nó vẫn là chuỗi ban đầu. Ví dụ: Chuỗi “racecar” hay chuỗi “able was i ere i saw elba”
bool ispalindrome(string s, int i, int j){
    if(i>=j) return true;
    return(s[i]==s[j])&&(ispalindrome(s,i+1,j-1));
}
// đệ quy đôi - bài toán tháp Hnoi
void moveDisk(int count, int src, int des, int inter){
    if(count>0){
        moveDisk(count-1,src, inter, des);
        cout<<" Chuyen dia "<<count<<" tu "<<src<<" den "<<des<<"."<<endl;
        moveDisk(count-1, inter, des, src);
    }
}

//binary search recursive :Xây dựng hàm đệ quy cho tìm kiếm nhị phân
int binarySearch(int arr[], int l, int r, int key)
{
    if (r >= l)
    {
        int mid = (l + r)/2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key) return binarySearch(arr, l, mid-1, key);
        return binarySearch(arr, mid+1, r, key);
    }
    return -1;
}
//Xây dựng hàm đệ quy để tính tổng giá trị tất cả các phần tử của một mảng vuông số nguyên 2 chiều (n x n).

int sum(int ** arr, int i, int j, int size) {

    if (!i && !j) return arr[i][j];

    if (!j) return arr[i][j] + sum(arr, i - 1, size, size);

    return arr[i][j] + sum(arr, i, j - 1, size);

}

//Xây dựng hàm đệ quy để tính tích của 2 số nguyên dương và chỉ được phép sử dụng phép cộng và phép trừ.
int mul(int a, int b){
    if(!a) return 0;
    return b+ mul(a-1,b);
}
//Viết hàm insertionSort nhập vào một mảng , sắp xếp mảng đó dùng thuật toán sắp xếp chèn
void insertionSort(int *a, int n)
{
    for(int i = 0; i<n; i++){
        int y=i;
        while (y>0)
        {
            if(a[y-1] > a[y]) swap(a[y-1],a[y]);
            y--;
        }
        
    }
};

int main(){
    int a[]={45,2,-3,4,5,99,54};
    insertionSort(a,7);
    for(int i = 0; i<7; i++){
        cout<<a[i]<<" ";
    }

    /*cout<<"Max: "<<max(a,6)<<endl;
    cout<<"Min: "<<min(a,6)<<endl; */

    //string s;
    /* cout<<"Xau: ";
    getline(cin,s);
    reverse(s,0,8);
    cout<<s<<endl; */

    //cout<<ispalindrome(s,0,s.length()-1)<<endl;

    /* int index=binarySearch(a,0,5,5);
    if(index==-1) throw"Khong co trog mang\n";
    else cout<<"Co trong mang tai vi tri: "<<index<<endl; */
    //int N = sizeof(a) / sizeof(a[0]);

    /* int n;
    cout << "n: "; cin >>n;
    int * a[n];
    for (int i = 0; i<n; i++) a[i] = new int [n];
    for (int i =0; i<n; i++)
        for (int j = 0; j<n; j++) a[i][j] = 1;
    cout << sum(a, n-1, n-1, n-1) << endl; */
    return 0;
}