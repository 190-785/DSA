#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INV2 = 500000004LL; // inverse of 2 mod 1e9+7

struct LazyTag {
    ll a, d;   // AP starts with a, common difference d
    bool has;
    LazyTag() : a(0), d(0), has(false) {}
};

vector<ll> seg;
vector<LazyTag> lazyTag;

ll norm(ll x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

ll apSum(ll n, ll a, ll d) {
    a = norm(a);
    d = norm(d);
    n %= MOD;
    ll term = (2 * a + ((n - 1 + MOD) % MOD) * d) % MOD;
    return (n * term % MOD) * INV2 % MOD;
}

void build(int idx, int l, int r, const vector<ll>& arr) {
    if (l == r) {
        seg[idx] = norm(arr[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(idx * 2, l, mid, arr);
    build(idx * 2 + 1, mid + 1, r, arr);
    seg[idx] = (seg[idx * 2] + seg[idx * 2 + 1]) % MOD;
}

void apply(int idx, int l, int r, ll a, ll d) {
    seg[idx] = apSum(r - l + 1, a, d);
    lazyTag[idx].a = norm(a);
    lazyTag[idx].d = norm(d);
    lazyTag[idx].has = true;
}

void push(int idx, int l, int r) {
    if (!lazyTag[idx].has || l == r) return;

    int mid = (l + r) / 2;
    int leftLen = mid - l + 1;

    apply(idx * 2, l, mid, lazyTag[idx].a, lazyTag[idx].d);

    ll rightStart = (lazyTag[idx].a + 1LL * leftLen * lazyTag[idx].d) % MOD;
    apply(idx * 2 + 1, mid + 1, r, rightStart, lazyTag[idx].d);

    lazyTag[idx].has = false;
}

void update(int idx, int l, int r, int ql, int qr, ll x, ll y) {
    if (r < ql || qr < l) return;

    if (ql <= l && r <= qr) {
        ll start = (x + 1LL * (l - ql) * y) % MOD;
        apply(idx, l, r, start, y);
        return;
    }

    push(idx, l, r);

    int mid = (l + r) / 2;
    update(idx * 2, l, mid, ql, qr, x, y);
    update(idx * 2 + 1, mid + 1, r, ql, qr, x, y);

    seg[idx] = (seg[idx * 2] + seg[idx * 2 + 1]) % MOD;
}

ll query(int idx, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;

    if (ql <= l && r <= qr) {
        return seg[idx];
    }

    push(idx, l, r);

    int mid = (l + r) / 2;
    return (query(idx * 2, l, mid, ql, qr) +
            query(idx * 2 + 1, mid + 1, r, ql, qr)) % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    seg.assign(4 * n + 5, 0);
    lazyTag.assign(4 * n + 5, LazyTag());

    build(1, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        ll x, y;
        cin >> l >> r >> x >> y;
        update(1, 0, n - 1, l, r, x, y);
    }

    cout << query(1, 0, n - 1, 0, n - 1) % MOD << '\n';
    return 0;
}