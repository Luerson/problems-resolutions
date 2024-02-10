#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

/*
Recebe as coordenadas de 2 pontos do poligono
*/
ld cross(ld x1, ld y1, ld x2, ld y2)
{return x1*y2-x2*y1;}

/*
Recebe um vetor com os pontos presentes no poligono
*/
ld polygonArea(vector<pair<ll,ll>>&A)
{
    ld ats = 0.0;
    for(int i=2; i<A.size(); i++)
        ats+=cross(A[i].first-A[0].first,A[i].second-A[0].second,A[i-1].first-A[0].first,A[i-1].second-A[0].second);
    return fabs(ats/2);
}


/*
Recebe um vetor com os pontos presentes no poligono
*/
ll boundary(vector<pair<ll,ll>>&A)
{
    ll ats = A.size();
    for(int i=0; i<A.size(); i++)
    {
        ll dx = (A[i].first - A[(i+1)%A.size()].first);
        ll dy = (A[i].second - A[(i+1)%A.size()].second);
        ats+=abs(__gcd(dx,dy)) - 1;
    }
    return ats;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll N;
    
    cin >> N;
    
    vector<pair<ll, ll>> vertices(N, pair<ll, ll>(0, 0));
    
    for(ll i = 0; i < N; i++){
        cin >> vertices[i].first >> vertices[i].second;
    }
    
    ll S = polygonArea(vertices);
    ll B = boundary(vertices);
    
    ll I = S + 1 - (B / 2);
    
    cout << I << " " << B << endl;

    return 0;
}