#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


vector<priority_queue<int>> adj1, adj2;
int root1, root2;

queue<int> q1, q2;


void readChart(vector<priority_queue<int>>& adj, int& root) {
    int node;
    string line;
    int left, right;
    stack<int> stk;
    
    
    getline(cin, line);
    // cout << line << endl;
    
    left = 0;
    while(!isdigit(line[left]))
        left++;
    
    right = left;
    while((right+1 < line.size()) && isdigit(line[right+1]))
        right++;
        
    root = stoi(line.substr(left, (right-left)+1));
    stk.push(root);


    for (int i = right+1; i < line.size(); i++)
    {
        if (line[i] == '(')
        {
            left = i+1;
            while(!isdigit(line[left]))
                left++;
            
            right = left;
            while(isdigit(line[right+1]))
                right++;


            node = stoi(line.substr(left, (right-left)+1));
            adj[stk.top()].push(node);
            stk.push(node);
            
            i = right;
        }
        else if (line[i] == ')')
        {
            stk.pop();
        }
    }
}


void dfs(int node, vector<priority_queue<int>>& adj, queue<int>& q) {
    q.push(node);
    
    while(!adj[node].empty())
    {
        dfs(adj[node].top(), adj, q);
        adj[node].pop();
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    
    adj1.resize(1000001);
    adj2.resize(1000001);
    
    readChart(adj1, root1);
    readChart(adj2, root2);
    
    dfs(root1, adj1, q1);
    dfs(root2, adj2, q2);
    
    bool equal = true;
    while(!q1.empty() && !q2.empty())
    {
        if (q1.front() != q2.front())
        {
            equal = false;
            break;
        }
        
        q1.pop();
        q2.pop();
    }
    
    if (!q1.empty() || !q2.empty())
        equal = false;
    
    if (equal) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    // cout << "root1 = " << root1 << endl;
    // dfs(root1, adj1);
    
    // cout << endl;
    // cout << "root2 = " << root2 << endl;
    // dfs(root2, adj2);
    // cout << endl;
    

    return 0;
}