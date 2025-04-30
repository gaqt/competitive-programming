// author: gaqt (logemi on codeforces)
// https://github.com/gaqt/competitive-programming
// yes, I use 3 space indentation

#ifndef __DEBUG__
#pragma GCC optimize("O3,unroll-loops")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
#define x first
#define y second
#define all(a) begin(a), end(a)
#define sz(a) ((a).size())
#define len(a) ((a).length())
#define INF LLONG_MAX
#define PI 3.1415926535897932384626433832795l
#define FORI(x, n) for (ll i = (x); i < (n); i++)
#define FORJ(x, n) for (ll j = (x); j < (n); j++)
#define FORH(x, n) for (ll h = (x); h < (n); h++)
#define FORK(x, n) for (ll k = (x); k < (n); k++)
#define FORL(x, n) for (ll l = (x); l < (n); l++)
#define FORR(x, n) for (ll r = (x); r < (n); r++)
#define bflip(a, b) ((a) ^= (1ull) << (b))
#define bset(a, b) ((a) |= (1ull) << (b))
#define bclear(a, b) ((a) &= ~(1ull) << (b))
#define bcheck(a, b) (!!((a) & (1ull << (b))))
inline void yes() { cout << "YES" << "\n"; }
inline void no() { cout << "NO" << "\n"; }
#define newl "\n" // print newline without flushing
#define spc " "
#define POLICY_MAP(Key, Mapped, Cmp)                                           \
   tree<Key, Mapped, Cmp, rb_tree_tag, tree_order_statistics_node_update>
#define POLICY_SET(Key, Cmp) POLICY_MAP(Key, null_type, Cmp)
/// wraps value between vmin and vmax (float)
constexpr inline ld wrapf(ld value, const ld vmin, const ld vmax) {
#define _DIFF (vmax - vmin)
   if (value < vmin)
      value += _DIFF * ceil((ld)(vmin - value) / (ld)_DIFF);
   else if (value > vmax)
      value -= _DIFF * ceil((ld)(value - vmax) / (ld)_DIFF);

   return value;
}
/// wraps value between vmin and vmax (integer)
constexpr inline ll wrapi(ll value, const ll vmin, const ll vmax) {
#define _DIFF (vmax - vmin)
   if (value < vmin)
      value = vmin + (vmin - value) % _DIFF;
   else if (value > vmax)
      value = vmin + (value - vmax) % _DIFF;

   return value;
}
template <typename T>
constexpr inline bool inRange(const T value, const T vmin, const T vmax) {
   return vmin <= value && value <= vmax;
}
/// integer absolute value
constexpr inline ll absi(const ll x) { return x < 0 ? -x : x; }
/// manhattan distance (integers)
constexpr inline ll distmi(const pii a, const pii b) {
   return absi(a.x - b.x) + absi(a.y - b.y);
}
/// euclidean distance squared (integers)
constexpr inline ll diste2i(const pii a, const pii b) {
#define _DIFFX (a.x - b.x)
#define _DIFFY (a.y - b.y)
   return _DIFFX * _DIFFX + _DIFFY * _DIFFY;
}
/// euclidean distance (integers)
constexpr inline ld distei(const pii a, const pii b) {
   return sqrt(diste2i(a, b));
}
constexpr ll _gcd_internal(const ll a, const ll b) {
   if (b == 0)
      return a;
   return _gcd_internal(b, a % b);
}
/// greatest common divisor of a and b
constexpr inline ll gcd(const ll a, const ll b) {
   if (a > b)
      return _gcd_internal(a, b);
   if (a < b)
      return _gcd_internal(b, a);
   return a;
}
/// least common multiple of a and b
constexpr inline ll lcm(const ll a, const ll b) { return a * (b / gcd(a, b)); }
void extended_gcd(ll a, ll b, ll *x, ll *y) {
   if (a == 0) {
      *x = 0;
      *y = 1;
      return;
   }
   ll x_, y_;
   extended_gcd(b % a, a, &x_, &y_);
   *x = y_ - x_ * (b / a);
   *y = x_;
}
/// modular inverse aka a^(-1) (mod m)
__attribute__((const)) ll modInv(const ll a, const ll m) {
   ll x, y;
   extended_gcd(a, m, &x, &y);
   x = (1 - y * m) / a;
   if (x < 0) {
      return x + m * (1 + abs(x) / m);
   } else {
      return x % m;
   }
}
/// fast integer exponentiation
__attribute__((pure)) ll ipow(ll b, ll e) {
   switch (b) {
   case 0:
   case 1:
      return b;
   case 2:
      return 1 << max(0ll, e - 1);
   }
   ll r = 1;
   while (e) {
      if (e & 1)
         r *= b;
      b *= b;
      e >>= 1;
   }
   return r;
}
/// returns list of primes and the sieve
pair<vector<ll>, vector<bool>> genPrimes(const ll n) {
   vector<bool> sieve(n + 1, true);
   vector<ll> primes;
   primes.reserve(1.1l * n / log((ld)n));
   sieve[0] = false;
   sieve[1] = false;
   for (int i = 2; i <= sqrt(n + 1); i++) {
      if (!sieve[i])
         continue;
      for (int x = i * i; x < n + 1; x += i)
         sieve[x] = false;
   }
   for (int i = 2; i < n + 1; i++) {
      if (sieve[i])
         primes.push_back(i);
   }
   return make_pair(primes, sieve);
}
/// returns true if x is prime
bool isPrime(const ll x, const vector<ll> &primes, const vector<bool> &sieve) {
   if (x < sieve.size())
      return sieve[x];
   ll max_p = 1 + sqrt(x);
   for (ll p : primes) {
      if (p > max_p)
         return true;
      if (x % p == 0)
         return false;
   }
   return true;
}
/// returns prime factorization of x
multiset<ll> primeFact(ll x, const vector<ll> &primes,
                       const vector<bool> &sieve) {
   multiset<ll> fact;
   ll max_p = 1 + sqrt(x);
   for (ll p : primes) {
      if (p > max_p)
         break;
      while (x % p == 0) {
         fact.insert(p);
         x /= p;
      }
      max_p = 1 + sqrt(x);
   }
   if (isPrime(x, primes, sieve)) {
      fact.insert(x);
   }
   return fact;
}
/// counts number of inversions in T array
template <class T, class Compare = less_equal<T>>
ll inversions(T arr[], const ll l, const ll r) {
   if (l == r - 1)
      return 0;
   ll inv = 0, mid = (l + r) / 2;
   inv += inversions(arr, l, mid);
   inv += inversions(arr, mid, r);
   ll szl = mid - l, szr = r - mid;
   vector<T> left(szl), right(szr);
   copy_n(arr + l, szl, left.begin());
   copy_n(arr + mid, szr, right.begin());
   ll x = 0, y = 0, i = l;
   Compare cmp;
   while (x < szl && y < szr) {
      if (cmp(left[x], right[y])) {
         arr[i] = left[x];
         x++;
      } else {
         arr[i] = right[y];
         inv += szl - x;
         y++;
      }
      i++;
   }
   while (x < szl) {
      arr[i] = left[x];
      i++;
      x++;
   }
   while (y < szr) {
      arr[i] = right[y];
      i++;
      y++;
   }
   return inv;
}
/// Reads word from stdin (delimited by space or newline)
string readWord() {
   string s;
   cin >> s;
   return s;
}
/// Reads line from stdin (delimited by newline)
string readLine() {
   string s;
   getline(cin, s);
   return s;
}
/// Reads int from stdin
ll readInt() {
   ll n;
   cin >> n;
   return n;
}
/// Reads char from stdin (skips newline)
char readChar() {
   char c;
   cin >> c;
   return c;
}
/// Reads ints from stdin
vector<ll> readInts(const ll n) {
   vector<ll> ints(n);
   for (ll i = 0; i < n; i++)
      cin >> ints[i];

   return ints;
}
/// Read ints from stdin (one indexed)
vector<ll> readIntsOne(const ll n) {
   vector<ll> ints(n + 1);
   for (ll i = 1; i <= n; i++)
      cin >> ints[i];

   return ints;
}
/// Reads int pairs from stdin
vector<pii> readPairs(const ll n) {
   vector<pii> pairs;
   pairs.resize(n);
   for (ll i = 0; i < n; i++) {
      ll a, b;
      cin >> a >> b;
      pairs[i] = {a, b};
   }
   return pairs;
}
/// Reads int pairs from stdin (one indexed)
vector<pii> readPairsOne(const ll n) {
   vector<pii> pairs;
   pairs.resize(n + 1);
   for (ll i = 1; i <= n; i++) {
      ll a, b;
      cin >> a >> b;
      pairs[i] = {a, b};
   }
   return pairs;
}
vector<char> _outbuf(1024);
/// Formatting print using ostreams
#define printf(format, ...)                                                    \
   {                                                                           \
      size_t _bytes =                                                          \
          snprintf(_outbuf.data(), _outbuf.size(), format, __VA_ARGS__);       \
      if (_bytes >= _outbuf.size()) {                                          \
         _outbuf.resize(2 * _bytes);                                           \
         sprintf(_outbuf.data(), format, __VA_ARGS__);                         \
      }                                                                        \
      cout.write(_outbuf.data(), _bytes);                                      \
   }

//     SOLUTION GOES HERE
//----------------------------------------------------------------------------------

/* <--- Notes --->



*/

inline void _preprocess() {}

inline void _solve() {
   ll n = readInt();
   vector<ll> a = readInts(n);
}

#define USE_TEST_CASES
// #define INTERACTIVE

int main(void) {
#ifndef INTERACTIVE
   cin.tie(0);
#endif
   ios_base::sync_with_stdio(false);
   _preprocess();
#ifdef USE_TEST_CASES
   ll tt = atoll(readLine().c_str());
   while (tt--) {
      _solve();
   }
#else
   _solve();
#endif
   return 0;
}
