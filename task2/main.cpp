#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
public:
    //конструктор по умолчанию;
    Deque(){}
 
    //константный метод Empty, возвращающий true, если дек не содержит ни одного элемента;
    bool Empty() const
    {
        if (item.empty())
            return true;
        return false;
    }

    //константный метод Size, возвращающий количество элементов в деке;
    size_t Size() const
    {
        return item.size();
    }  
    //T& operator[](size_t index) и const T& operator[](size_t index) const;
    
    //константный и неконстантный метод At(size_t index), генерирующий стандартное исключение out_of_range, если индекс больше или равен количеству элементов в деке;
    
    //константные и неконстантные версии методов Front и Back, возвращающих ссылки на первый и последний элемент дека соответственно;
    
    //метод PushFront
    void PushFront(T const& value) {
       item.insert(item.begin(), value);
    }    
    
    //метод PushBack.
    void PushBack(T const& value) {
       item.push_back(value);
    }
   
    friend ostream& operator<< (ostream &os, Deque const &dec);
private:
   vector<T> item;
};

// перегрузка оператора вывода
ostream& operator<< (ostream &os, <T> const &dec)
{
    for (T d: dec)
        os << d << endl;
    return os;
}


int main(int argc, char** argv) {

//    vector <string> v = {"1", "2", "3"};
//    cout << v[0] << endl;
    
//    Deque <string> d = {"1", "2", "3"};
    Deque <int> d;
    d.PushBack(1);
    cout << d.Empty() << endl;
    cout << d.Size() << endl;
    d.PushFront(1);
    cout << d.Size() << endl;
    
    return 0;
}

