#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//vector_of_vectors
void vector_of_vectors()
{
    vector<vector<int>> vv;
    int a = 5, b = 49;
    for (int i = 0; i < 20; i += 2)
    {
        vector<int> v(6);
        fill(begin(v), end(v), i);
        vv.push_back(v);
    }
    vector<vector<int>>::iterator vvi;
    for (vvi = begin(vv); vvi != end(vv); vvi++)
    {
        vector<int>::iterator vi = begin(*vvi);
        for (; vi != end(*vvi); vi++)
        {
            cout << *vi << " ";
        }
        cout << endl;
    }
}
//vector of pairs
void vector_of_pairs(){
    vector<pair<int, int>> v;
    int a = 5, b = 49;
    for (int i = 0; i < 10; i++, a += 4, b -= 2)
    {
        v.push_back(make_pair(a, b));
    }
    vector<pair<int, int>>::iterator x;
    for (x = begin(v); x != end(v); x++)
    {
        pair<int, int> temp = *x;
        cout << temp.first << " " << temp.second << endl;
    }
}
int main()
{

    //vector_of_pairs();
   // vector_of_vectors();
}