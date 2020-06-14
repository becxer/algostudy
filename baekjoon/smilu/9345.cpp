#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF

template <class T>
class Seg {
  vector<T> _v;
  int _begin, _end, _size;
  T _update(int n, int s, int e, int x, T uv) {
    if (s == e) return _v[n] = uv;
    int m = (s+e)>>1, l = n<<1, r = l|1;
    if (x <= m) _update(l,s,m,x,uv);
    else        _update(r,m+1,e,x,uv);
    return _v[n] = _v[l] + _v[r];
  }
  T _query(int n, int s, int e, int f, int t) {
    if (t < s || e < f) return T::zero();
    if (f <= s && e <= t) return _v[n];
    int m = (s+e)>>1, l = n<<1, r = l|1;
    return _query(l,s,m,f,t) + _query(r,m+1,e,f,t);
  }
public:
  Seg(int begin, int end) {
    _begin = begin;
    _end = end;
    _size = 1 << ((int)ceil(log2(end - begin + 1)) + 1);
    _v = vector<T>(_size);
  }
  T update(int x, T uv) {
    return _update(1, _begin, _end, x, uv);
  }
  T query(int f, int t) {
    return _query(1, _begin, _end, f, t);
  }
};

struct MaxSegItem {
  int v;
  static MaxSegItem zero() {
    const MaxSegItem ret = {-0x7fffffff};
    return ret; 
  }
  MaxSegItem operator+(const MaxSegItem &b) const {
    return {max(v, b.v)};
  }
};
typedef Seg<MaxSegItem> MaxSeg;

struct MinSegItem {
  int v;
  static MinSegItem zero() {
    const MinSegItem ret = {0x7fffffff};
    return ret; 
  }
  MinSegItem operator+(const MinSegItem &b) const {
    return {min(v, b.v)};
  }
};
typedef Seg<MinSegItem> MinSeg;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> arr(n);
  iota(arr.begin(), arr.end(), 0);
  MinSeg s_min(0, n-1);
  MaxSeg s_max(0, n-1);
  for (int i = 0; i < n; i++) {
    s_min.update(i, {i});
    s_max.update(i, {i});
  }
  while (k--) {
    int cd; cin >> cd;
    if (cd == 0) {
      int a, b; cin >> a >> b;
      int va = arr[a], vb = arr[b];
      s_min.update(a, {vb});
      s_min.update(b, {va});
      s_max.update(a, {vb});
      s_max.update(b, {va});
      swap(arr[a], arr[b]);
    } else if (cd == 1) {
      int a, b; cin >> a >> b;
      if (a > b) swap(a, b);
      int mv = s_min.query(a, b).v;
      int Mv = s_max.query(a, b).v;
      bool res = mv == a && Mv == b;
      cout << (res ? "YES\n" : "NO\n");
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
