#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>

namespace debug {
using namespace std;
string to_string(const string &s, string pad="");
string to_string(const char s[], string pad="");
string to_string(const char c, string pad="");
string to_string(const long long x, string pad="");
string to_string(const int x, string pad="");
string to_string(const size_t x, string pad="");
template<typename A, typename B>
string to_string(pair<A, B> p, string pad="");
template<typename T>
string to_string(const vector<T> &v, string pad="");
template<typename T, size_t N>
string to_string(const array<T, N> &v, string pad="");
template<typename T>
string to_string(const T v[], const size_t n);
template<typename T>
string to_string(T *v, const size_t n, const size_t m);
template<typename T>
string to_string(const set<T> &v, string pad="");
template<typename T>
string to_string(const unordered_set<T> &v, string pad="");
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
string to_string(const map<Key, T, Compare, Allocator> &v, string pad="");
template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
string to_string(const unordered_map<Key, T, KeyEqual, Allocator> &v, string pad="");
}
