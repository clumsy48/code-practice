#include <iostream>

using namespace std;

int build(int *arr, int *st, int ss, int se, int ind)
{

    if (ss == se)
    {
        st[ind] = arr[se];
        return arr[ss];
    }
    int mid = ss + (se - ss) / 2;
    st[ind] = build(arr, st, ss, mid, 2 * ind) + build(arr, st, mid + 1, se, 2 * ind + 1);

    return st[ind];
}
void update(int *arr, int *st, int ss, int se, int index, int diff,int si)
{
    if (index < ss || index > se)
        return;
    st[si] = st[si] + diff;
    if (ss != se)
    {
        int mid = ss + (se - ss) / 2;
        update(arr, st, ss, mid, index, diff,2*si);
        update(arr, st, mid + 1, se, index, diff,2*si+1);
        
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *st = new int[2 * 9];

    build(arr, st, 0, 8, 1);
    for (int i = 1; i < 18; i++)
        cout << st[i] << " ";
        cout << endl;
    //update
    int diff = 15 - arr[7];
    arr[7] = 15;
    update(arr, st, 0, 8, 7, diff,1);
    for (int i = 1; i < 18; i++)
        cout << st[i] << " ";
}