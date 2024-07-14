#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string to_string(const string &s) {
    return "\"" + s + "\"";
}

string to_string(const char s[]) {
    return to_string(string(s));
}

string to_string(const char c) {
    string s = "'";
    s += c;
    s += "'";
    return s;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename T>
string to_string(const vector<T> &v) {
    string s = "[ ";
    for (const T &x: v) {
        s += to_string(x) + ", ";
    }
    s += "]";
    return s;
}

template<typename T, size_t N>
string to_string(const array<T, N> &v) {
    string s = "[ ";
    for (const T &x: v) {
        s += to_string(x) + ", ";
    }
    s += "]";
    return s;
}

template<typename T>
string to_string(const T v[], const size_t n) {
    string s = "[ ";
    for (size_t i = 0; i < n; i++) {
        s += to_string(v[i]) + ", ";
    }
    s += "]";
    return s;
}

template<typename T>
string to_string(const set<T> &v) {
    string s = "[ ";
    for (T x: v) {
        s += to_string(x) + ", ";
    }
    s += "]";
    return s;
}

template<typename T>
string to_string(const unordered_set<T> &v) {
    string s = "[ ";
    for (T x: v) {
        s += to_string(x) + ", ";
    }
    s += "]";
    return s;
}

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
string to_string(const map<Key, T, Compare, Allocator> &v) {
    string s = "[ ";
    for (pair<Key,T> p: v) {
        s += to_string(p) + ", ";
    }
    s += "]";
    return s;
}

template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
string to_string(const unordered_map<Key, T, KeyEqual, Allocator> &v) {
    string s = "[";
    for (pair<Key, T> p: v) {
        s += to_string(p) + ", ";
    }
    s += "]";
    return s;
}

#define debug(x) cout << #x << ": " << to_string(x) << "\n";
#define debugarr(x, n) cout << #x << ": " << to_string(x, n) << "\n";
