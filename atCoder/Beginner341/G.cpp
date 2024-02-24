#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 988'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;

struct Point {
    ll x, y;
};

struct Arrow {
    ll x, y;
};

Point make_point(ll x, ll y) {
    Point point;
    point.x = x;
    point.y = y;

    return point;
}

Arrow make_arrow(Point start, Point end) {
    Arrow newArrow;

    newArrow.x = end.x - start.x;
    newArrow.y = end.y - start.y;

    return newArrow;
}

bool clockWiseTurn(Arrow start, Arrow end) {
    return ((start.x * end.y) - (start.y * end.x)) < 0;
}

stack<Point> points;
stack<Point> convexHull;
vector<ld> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////

    int n;
    cin >> n;

    points.push(make_point(0, 0));

    for (int i = 1; i <= n; i++) {
        ll value;
        cin >> value;

        points.push(make_point(i, points.top().y + value));
    }

    Point final = points.top();
    points.pop();
    Point begin = points.top();
    points.push(final);

    ans.push_back((ld)(final.y - begin.y)/(ld)(final.x - begin.x));

    convexHull.push(points.top());
    points.pop();

    convexHull.push(points.top());
    points.pop();

    while (!points.empty()) {
        Point pointBegin, pointMiddle, pointEnd;

        //debug2(convexHull.top().x, convexHull.top().y);

        do {
            pointBegin = points.top();
            pointMiddle = convexHull.top();
            convexHull.pop();

            if (convexHull.empty()) break;

            pointEnd = convexHull.top();

        } while (!clockWiseTurn(make_arrow(pointBegin, pointMiddle), make_arrow(pointMiddle, pointEnd)));

        convexHull.push(pointMiddle);
        convexHull.push(pointBegin);

        ld dividend = (pointMiddle.y - pointBegin.y);
        ld divisor = (pointMiddle.x - pointBegin.x);

        ld med = dividend/divisor;

        ans.push_back(med);
        points.pop();
    }

    reverse(all(ans));

    for (int i = 0; i < ans.size(); i++) {
        cout << fixed << setprecision(10) << ans[i] << endl;
    }

    return 0;
}