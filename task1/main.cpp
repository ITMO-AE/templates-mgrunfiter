#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Для чисел
template <typename T>
T Sqr(T & t)
{
    return t * t;
}

// Специализация для vector
template <typename T>
vector <T> Sqr(vector<T> &v)
{
    for(auto &x : v){
        x = Sqr(x);
    }
    return v;
}

// Специализация для pair
template <typename T>
pair <T, T> Sqr(pair<T, T> &p)
{
    p.first *= p.first;
    p.second *= p.second;
    return p;
}

// Специализация для map
template <typename T>
map <int, T>Sqr(map <int, T> &m)
{
    for (auto& x : m)
    {
        x.second = Sqr(x.second);  
    }
    return m;
}

int main(int argc, char** argv) {
// Пример вызова функции
    
// int    
    int a = 2;
    cout << "int a = " << a << " Sqr(a) = " << Sqr(a) << endl;
// double
    double b = 2;
    cout << "double b = " << b << " Sqr(b) = " << Sqr(b) 
            << endl << endl;
    
// vector
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl << endl;
    
// pair    
    pair<int, int> pr = {3, 4};
    cout << "pairs:" << endl;
    cout << "{" << pr.first << ", " << pr.second << "}" << endl;
    pr = Sqr(pr);
    cout << "Sqr pairs:" << endl;
    cout << "{" << pr.first << ", " << pr.second << "}" 
            << endl << endl;

// map 1
    map<int, int> map_of_int = {
      {4, 2},
      {7, 4}
    };
    cout << "map of int:" << endl;
    for (const auto& x : Sqr(map_of_int)) {
      cout << x.first << ' ' << x.second << endl;
    }
    
// map 2   
    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' 
              << x.second.second << endl;
    }

    return 0;
}

