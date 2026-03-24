#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> seg;
vector<ll> lazyA, lazyB;
vector<bool> marked;
const ll MOD = 1e9 + 7;

void apply(ll idx, ll l, ll r, ll a, ll b)
{
    ll len = r - l + 1;
    const ll inv2 = (MOD + 1) / 2;

    ll sumI = ((l + r) % MOD * len % MOD) % MOD;
    sumI = (sumI * inv2) % MOD;

    seg[idx] = (a * sumI % MOD + b * len % MOD) % MOD;

    lazyA[idx] = a;
    lazyB[idx] = b;
    marked[idx] = true;
}

void push(ll idx, ll l, ll r)
{
    if (!marked[idx])
        return;

    ll mid = (l + r) / 2;

    apply(2 * idx, l, mid, lazyA[idx], lazyB[idx]);
    apply(2 * idx + 1, mid + 1, r, lazyA[idx], lazyB[idx]);

    marked[idx] = false;
}
void build(ll idx, ll l, ll r, vector<ll> &nums)
{
    if (l == r)
    {
        seg[idx] = nums[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(idx * 2, l, mid, nums);
    build(idx * 2 + 1, mid + 1, r, nums);
    seg[idx] = (seg[idx * 2] + seg[idx * 2 + 1]) % MOD;
}

void update(ll idx, ll l, ll r, ll ql, ll qr, ll a, ll b)
{
    if (l > qr || r < ql)
        return;

    if (l >= ql && r <= qr)
    {
        apply(idx, l, r, a, b);
        return;
    }

    push(idx, l, r);

    ll mid = (l + r) / 2;

    update(2 * idx, l, mid, ql, qr, a, b);
    update(2 * idx + 1, mid + 1, r, ql, qr, a, b);

    seg[idx] = (seg[2 * idx] + seg[2 * idx + 1]) % MOD;
}

ll query(ll idx, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
    {
        return seg[idx];
    }
    ll mid = (l + r) / 2;
    push(idx, l, r);
    return (query(idx * 2, l, mid, ql, qr) + query(idx * 2 + 1, mid + 1, r, ql, qr)) % MOD;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    seg.assign(4 * n, 0);
    lazyA.assign(4 * n, 0);
    lazyB.assign(4 * n, 0);
    marked.assign(4 * n, false);
    build(1, 0, n - 1, arr);
    ll m;
    cin >> m;
    ll res = 0;
    while (m--)
    {
        vector<ll> q(3);
        for (ll i = 0; i < 3; i++)
            cin >> q[i];
        if (q[0] == 1)
        {
            ll l = q[1] - 1, r = q[2] - 1;

            ll val = query(1, 0, n - 1, l, l);

            ll a = val % MOD;
            ll b = (-val * (l - 1)) % MOD;
            b = (b + MOD) % MOD;

            update(1, 0, n - 1, l, r, a, b);
        }
        else
        {
            res = (res + query(1, 0, n - 1, q[1] - 1, q[2] - 1)) % MOD;
        }
    }
    cout << res << endl;
    return 0;
}