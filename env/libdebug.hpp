#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <vector>
#include <iostream>
#include <string>
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
    s += "]\n";
    return s;
}

template<typename T>
string to_string(const T v[], const size_t n) {
    string s = "[ ";
    for (size_t i = 0; i < n; i++) {
        s += to_string(v[i]) + ", ";
    }
    s += "]\n";
    return s;
}

#define debug(x) cout << #x << ": " << to_string(x);
