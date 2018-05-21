//
// Created by niubin on 18-5-5.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cmp (const void *a , const void *b) {
    return *(double *)a > *(double *)b ? 1:0 ;
}
double greedy(double *, int);

int main(){
   
    ifstream in("input",ios::out|ios::in);
    int n;
    in >> n;
    int *a = new int[n];
    int i = 0;
    while (!in.eof()){
        in >> a[i];
        i ++ ;
    }
    in.close();
    double *b = new double[n];
    int sum = 0;
    for (int j = 0;j < n ;j++){
        sum += a[j];
    }
    for (int j = 0;j < n;j ++){
        b[j] = (a[j] * 1.0) / sum;
    }
    double result;
    result = greedy(b,n);
    fstream out("output",ios::in|ios::out);

    out << result;
    out.close();
    delete(a);
}
double greedy(double b[],int n) {
    qsort(b,n,sizeof(double),cmp);
    int mid = (n - 1) / 2;
    double x[n];
    x[mid] = b[n-1];
    for(int i = mid+1;i < n;i++)
        x[i] = b[n - 2*(i-mid)];
    for(int i = mid-1;i >= 0;i--)
        x[i] = b[n - 2*(mid-i) - 1];
    double sum = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n && j != i;j++){
            sum += abs((i - j))*1.0*x[i]*x[j];
        }
    }
    return sum;
}