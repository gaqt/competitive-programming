#include "libdebug.h"
#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>

namespace debug {
using namespace std;

typedef long long ll;
template<class T>
bool use_pad;

template<> bool use_pad<int> = false;
template<> bool use_pad<ll> = false;
template<> bool use_pad<size_t> = false;
template<> bool use_pad<char> = false;

template<> bool use_pad<string> = true;
template<> bool use_pad<char[]> = true;
template<> bool use_pad<char*> = true;
template<class T> bool use_pad<vector<T> > = true;
template<class T, size_t N> bool use_pad<array<T,N> > = true;
template<class T> bool use_pad<set<T> > = true;
template<class T> bool use_pad<unordered_set<T> > = true;
template<class K, class V, class C, class A>
bool use_pad<map<K,V,C,A> > = true;
template<class K, class V, class C, class A>
bool use_pad<unordered_map<K,V,C,A> > = true;

string to_string(const string &s, string pad) {
    return "\"" + s + "\"";
}

string to_string(const char s[], string pad) {
    return to_string(string(s));
}

string to_string(const char c, string pad) {
    string s = "'";
    s += c;
    s += "'";
    return s;
}

string to_string(const long long x, string pad) {
    return std::to_string(x);
}

string to_string(const int x, string pad) {
    return std::to_string(x);
}

string to_string(const size_t x, string pad) {
    return std::to_string(x);
}

template<typename A, typename B>
string to_string(pair<A, B> p, string pad) {
    string s = "\n";

    s += pad + "  ( x: ";
    s += to_string(p.first, pad+"    ") + "\n";
    s += pad + "  ( y: ";
    s += to_string(p.second, pad+"    ") + "\n";

    return s;
}

template<typename T>
string to_string(const vector<T> &v, string pad) {
    string s = "\n";
    for (size_t i = 0; i < v.size(); i++) {
        s += pad + "  | ";
        s += to_string(i) + ": ";
        s += to_string(v[i], pad+"    ") + "\n";
    }
    return s;
}

template<typename T, size_t N>
string to_string(const array<T, N> &v, string pad) {
    string s = "\n";
    for (size_t i = 0; i < v.size(); i++) {
        s += pad + "  | ";
        s += to_string(i) + ": ";
        s += to_string(v[i], pad+"    ") + "\n";
    }
    return s;
}

template<typename T>
string to_string(const T v[], const size_t n) {
    string s = "\n";
    for (size_t i = 0; i < n; i++) {
        s += "  | " + to_string(i) + ": " + to_string(v[i]) + "\n";
    }
    return s;
}

template<typename T>
string to_string(T *v, const size_t n, const size_t m) {
    string s = "\n";
    for (size_t i = 0; i < n; i++) {
        s += "  | ";
        for (size_t j = 0; j < m; j++) {
            s += to_string(v[i*m + j]) + " ";
        }
        s += "|\n";
    }
    return s;
}

template<typename T>
string to_string(const set<T> &v, string pad) {
    string s = ""; string pad0 = "";
    if (use_pad<T>) pad0 = "\n" + pad;

    s += pad0 + "{ ";
    for (T &x: v) {
        s += to_string(x, pad+"  ");
        s += pad0 + " ";
    }
    s += "}";
    return s;
}

template<typename T>
string to_string(const unordered_set<T> &v, string pad) {
    string s = ""; string pad0 = "";
    if (use_pad<T>) pad0 = "\n" + pad;

    s += pad0 + "{ ";
    for (T &x: v) {
        s += to_string(x, pad+"  ");
        s += pad0 + " ";
    }
    s += "}";
    return s;
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator>
string to_string(const map<Key, T, Compare, Allocator> &v, string pad) {
    string s = "\n";
    for (auto &[k,val]: v) {
        s += pad + "  { ";
        s += to_string(k, pad+"    ") + ": " + to_string(val, pad+"    ") + "\n";
    }
    return s;
}

template<
    class Key,
    class T,
    class Hash,
    class KeyEqual,
    class Allocator>
string to_string(const unordered_map<Key, T, KeyEqual, Allocator> &v, string pad) {
    string s = "\n";
    for (auto &[k,val]: v) {
        s += pad + "  { ";
        s += to_string(k, pad+"    ") + ": " + to_string(val, pad+"    ") + "\n";
    }
    return s;
}
}


#define debug(x) cout << #x << ": " << debug::to_string(x) << "\n";
#define debugarr(x,n) cout << #x << ": " << debug::to_string(x,n) << "\n";
#define debugarr2(x,n,m) cout << #x << ": " << debug::to_string(x[0],n,m) << "\n";
