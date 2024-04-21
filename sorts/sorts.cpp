#include <iostream>

using namespace std;


int merge_swap_count = 0;
int merge_if_count = 0;

class Point{
public:
    int x, y;
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y =y;
    }
    
    bool operator<(Point &p1) const{
        return (this->x * this->x + this->y * this->y) < (p1.x * p1.x + p1.y * p1.y);
    }
    
    bool operator<=(Point &p1) const{
        return (this->x * this->x + this->y * this->y) <= (p1.x * p1.x + p1.y * p1.y);
    }

    bool operator>(Point &p1) const{
        return (this->x * this->x + this->y * this->y) > (p1.x * p1.x + p1.y * p1.y);
    }
    bool operator>=(Point &p1) const{
        return (this->x * this->x + this->y * this->y) >= (p1.x * p1.x + p1.y * p1.y);
    }
    bool operator==(Point &p1) const{
        return (this->x * this->x + this->y * this->y) == (p1.x * p1.x + p1.y * p1.y);
    }
    void print(){
        cout<<this->x << ' ' << this->y << ' '<< this->x * this->x + this->y * this->y << '\n';
    }
};
void swap(Point &p1, Point &p2){
    Point t = p1;
    p1 = p2; p2 = t;
}
void merge(Point *a, int l1, int r1, Point *b, int l2, int r2, Point *c, int s){
    int i = l1, j = l2, k = s;
    while ((i <=r1) &&(j<=r2)){
        if (a[i] < b[j]){
            c[k] = a[i];
            i++;
        }
        else{
            c[k] = b[j];
            j++;
        }
        k++;
    }
    for(;i<=r1;i++,k++){
        c[k] = a[i];
    }
    for(;j<=r2;j++,k++){
        c[k] = b[j];        
    }
}
void move(Point *a, int start1, int end, Point *b, int start2) {
    for (int i = start1, j = start2; i <= end; ++i, ++j) {
        b[j] = a[i];
    }
}
void merge_sort(Point *a, int l, int r, Point *b) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(a, l, m, b);
    merge_sort(a, m + 1, r, b);
    merge(a, l, m, a, m + 1, r, b, l);
    move(b, l, r, a, l);
}
void bubble_sort(Point* arr, int l,int bubble_if_count, int bubble_swap_count){
    for (int i = 0; i < l;i++){
        for(int j = 0; j < l-1-i;j++){
            bubble_if_count+=1;
            if ((arr[j] > arr[j+1])){
                bubble_swap_count+=1;
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i = 0; i < l; i++){
        arr[i].print();
    }
    cout << bubble_if_count << ' ' << bubble_swap_count;
}
int main(){
    int l =13;
    Point arr[13] = {Point(12,1),Point(122,12),Point(-12,-12),Point(0,0)
            ,Point(4312,-12),Point(-12,12),Point(12,412),Point(-12,-112)
            ,Point(3212,0),Point(-123,0),Point(-121,12),Point(0,-12)
            ,Point(312,412)};



    Point temp[l];
    merge_sort(arr, 0, l-1, temp);
    for (int i = 0; i < l; i++) {
        arr[i].print();
    }



}