#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> v){
 for(int i = 0 ;i< v.size() ; i++)
 {
     cout << v[i] <<  " ";
 }
}
int main(){

vector<int> v(10);
fill(begin(v),end(v),12);
printVector(v);

fill_n(begin(v),8,8);
printVector(v);
}