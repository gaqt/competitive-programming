// author: logemi

#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma GCC diagnostic ignored "-Wdeprecated-register"
#ifdef __DEBUG__
    #pragma GCC optimize("O0,trapv")
    #include "../libdebug.hpp"
#else
    #pragma GCC optimize("O3,unroll-loops")
    #ifdef __x86_64__
        #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
    #endif
#endif
#ifdef __clang__
    #include <cstdint>
    #include <iostream>
    #include <map>
    #include <unordered_map>
    #include <set>
    #include <unordered_set>
    #include <vector>
    #include <deque>
    #include <algorithm>
#else
    #include <bits/stdc++.h>
#endif
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ld> pdd;
#define x first
#define y second
#define psb push_back
#define ppb pop_back
#define ins insert
#define bg begin
#define all(a) (a).begin(), (a).end()
#define sz(a) ((a).size())
#define mkp make_pair
#define INF LONG_MAX
#define PI 3.1415926535897932384626433832795l
#define MOD 1000000007ll
#define MAX2 112ll
#define MAX3 1123ll
#define MAX4 11234ll
#define MAX5 112345ll
#define MAX6 1123456ll
#define MAX7 11234567ll
#define MAX8 112345678ll
#define MAX9 1123456789ll
#define FORI(n) for(ll i=0;i<(n);i++)
#define FORI1(n) for(ll i=1;i<(n);i++)
#define FORJ(n) for(ll j=0;j<(n);j++)
#define FORJ1(n) for(ll j=1;j<(n);j++)
#define FORH(n) for(ll h=0;h<(n);h++)
#define FORH1(n) for(ll h=1;h<(n);h++)
#define FORK(n) for(ll k=0;k<(n);k++)
#define FORK1(n) for(ll k=1;k<(n);k++)
#define FOR0(k,n) for(ll k=0;k<(n);k++)
#define FOR1(k,n) for(ll k=1;k<(n);k++)
#define BIT_INV(a) (a^1)
#define BIT_FLIP(a,b) ((a)^=(1ull)<<(b))
#define BIT_SET(a,b) ((a)|=(1ull)<<(b))
#define BIT_CLEAR(a,b) ((a)&=~(1ull)<<(b))
#define BIT_CHECK(a,b) (!!((a)&(1ull<<(b))))
ld distE(pdd a, pdd b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}
ld distM(pdd a, pdd b) {return abs(a.x-b.x)+abs(a.y-b.y);}
ld distE(pii a, pii b) {return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));}
ll distM(pii a, pii b) {return abs(a.x-b.x)+abs(a.y-b.y);}
template<typename T> T gcd(T a,T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a,T b){return(a*(b/gcd(a,b)));}
void extended_gcd(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return;
    }
    ll x_, y_;
    extended_gcd(b%a, a, &x_, &y_);
    *x = y_ - x_*(b/a);
    *y = x_;
}
ll mod_inv(ll a, ll m) {
	ll x, y;
    extended_gcd(a, m, &x, &y);
    x = (1 - y*m) / a;
    if (x < 0) {
        return x + m*(1+ abs(x)/m);
    } else {
        return x % m;
    }
}
ll ipow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r *= b;
        b *= b; e >>= 1;
    }
    return r;
}
pair<vector<int>, vector<bool> > get_primes(const ll n) {
    vector<bool> sieve(n+1, true);
    vector<int> primes;
    primes.reserve(1.1l*n/log((ld)n));
    sieve[0] = false;
    sieve[1] = false;
    for (register int i = 2; i < n+1; i++) {
        if (!sieve[i]) continue;
        sieve[i] = true;
        primes.push_back(i);
        for (register int x = 2*i; x < n+1; x += i) sieve[x] = false;
    }
    return make_pair(primes, sieve);
}
vector<int> prime_dcmp(const ll x, const vector<int> primes) {
    vector<int> dcmp;
    int max_p = 1+sqrt(x);
    for (int p: primes) {
        if (p >= max_p) break;
        if (x % p == 0) dcmp.push_back(p);
    }
    return dcmp;
}
template<class T, class Compare = less_equal<T> >
int inversions(T arr[], const int l, const int r) {
    if (l == r-1) return 0;
    int inv = 0, mid = (l+r)/2;
    inv += inversions(arr, l, mid);
    inv += inversions(arr, mid, r);
    int szl = mid-l, szr = r-mid;
    T left[szl], right[szr];
    memcpy(left, arr+l, szl*sizeof(T));
    memcpy(right, arr+mid, szr*sizeof(T));
    register int x = 0, y = 0, i = l;
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
        i++; x++;
    }
    while (y < szr) {
        arr[i] = right[y];
        i++; y++;
    }
    return inv;
}

//     SOLUTION GOES HERE
//----------------------------------------------------------------------------------

void _preprocess_() {

}


void _solve_() {

}

#define USE_TEST_CASES

int main() {
	_preprocess_();
	#ifdef USE_TEST_CASES
		int test_cases;
		scanf("%d", &test_cases);
		while (test_cases--) _solve_();
	#else
		_solve_();
	#endif
	return 0;
}
