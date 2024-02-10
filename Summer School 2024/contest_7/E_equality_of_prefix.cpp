#include <bits/stdc++.h>

#define endl '\n'

using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n, q;
    vector<pair<int, int>> query;
    vector<int> a, b;
    set<int> setA, setB;
    int x, y;
    set<int> incluirEmA, incluirEmB;
    
    
    cin >> n;
    
    a.resize(n+1);
    b.resize(n+1);
    query.resize(n+1, {-1, -1});
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // setA.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        // setB.insert(b[i]);
    }
    
    int first = 1, second = 0;
    int left = -1, right = -1;
    
    setA.insert(a[first]);
    // setB.insert(b[second]);

    while(first <= n)
    {
        if (setB.find(a[first]) == setB.end())
        {
            incluirEmB.insert(a[first]);
        }
        setA.insert(a[first]);
        
        
        while((!incluirEmA.empty() && (first+1) <= n) || (!incluirEmB.empty() && (second+1) <= n))
        {
            while(!incluirEmB.empty() && (second+1) <= n)
            {
                second++;
                setB.insert(b[second]);
                if (incluirEmB.find(b[second]) != incluirEmB.end())
                {
                    incluirEmB.erase(b[second]);
                }
                else if (setA.find(b[second]) == setA.end())
                {
                    incluirEmA.insert(b[second]);
                }
            }

            while(!incluirEmA.empty() && (first+1) <= n)
            {
                first++;
                setA.insert(a[first]);
                if (incluirEmA.find(a[first]) != incluirEmA.end())
                {
                    incluirEmA.erase(a[first]);
                }
                else if (setB.find(a[first]) == setB.end())
                {
                    incluirEmB.insert(a[first]);
                }
            }
        }
        
        if (!incluirEmA.empty() || !incluirEmB.empty())
            break;
        
        left = right = second;
        while((second+1) <= n && setA.find(b[second+1]) != setA.end())
        {
            right = second+1;
            second++;
        }
        
        /////////
        query[first] = {left, right};
        while((first+1) <= n && setB.find(a[first+1]) != setB.end())
        {
            query[first+1] = {left, right};
            first++;
        }

        first++;
        // second++;
    }
    
    
    ///////////////////////////////////    
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        
        if (query[x].first <= y && query[x].second >= y)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    

    return 0;
}