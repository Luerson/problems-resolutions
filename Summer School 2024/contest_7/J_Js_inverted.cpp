#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;

int BIT[MAX + 1];

void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
          BIT[x] += delta;
}


int query(int x)//returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}

int binarySearch(int low,int high,int key)
{
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(query(mid)<key)
     {
         low=mid+1;
     }
     else if(query(mid)>key || (query(mid)==key && mid != 0 && query(mid-1) == query(mid)))
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;                //key not found
 }


int main()
{
    int n;
    vector<int> valores;
    vector<int> resp;
    
    cin >> n;
    valores.resize(n);
    resp.resize(n);
    
    memset(BIT, 0, sizeof BIT);
    
    for (int i = 0; i < n; i++) {
        cin >> valores[i];
        update(i+1, 1);
    }
    
    for (int i = n-1; i >= 0; i--) {
        int numero = binarySearch(0, 2000, query(2000) - valores[i]);
        resp[i] = numero;
        update(numero, -1);
    }
    
    for (int i = 0; i < n; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;

    return 0;
}