#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

template <class T>
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

    //константный метод At(size_t index), генерирующий стандартное исключение out_of_range, 
    //если индекс больше или равен количеству элементов в деке;
    void At(size_t index) const
    {
        if (index >= item.size())
            throw out_of_range("error: outside the index");
    }

    //неконстантный метод At(size_t index), генерирующий стандартное исключение out_of_range, 
    //если индекс больше или равен количеству элементов в деке;
    void At(size_t index)
    {
        if (index >= item.size())
            throw out_of_range("error: outside the index");
    }
      
    // Константный, т.е. читаем по индексу
    const T& operator[](size_t index) const
    {
        if (index < this->Size())
            return item[index];
        else
            this->At(index); 
    }

    // НЕконстантный, т.е. присваиваем по индексу
    T& operator[](size_t index)
    {
        if (index < this->Size())
            return item[index];
        else
           this->At(index); 
    }
    
    //константные и неконстантные версии методов Front и Back, 
    //возвращающих ссылки на первый и последний элемент дека соответственно;
    const T &Front() const
    {
        return item.front();
    }

    T &Front()
    {
        return item.front();
    }

    const T &Back() const
    {
        return item.back();
    }

    T &Back()
    {
        return item.back();
    } 
    
    //метод PushFront
    void PushFront(T const& value) {
       item.insert(item.begin(), value);
    }    
    
    //метод PushBack.
    void PushBack(T const& value) {
       item.push_back(value);
    }
  
//    friend ostream& operator<< (ostream &os, Deque<T> const &dec);

private:
   vector<T> item;
};

// перегрузка оператора вывода
//template <class U>
//ostream& operator<< (ostream &os, Deque<U> const &dec)
//    {   
//        for (U d: dec)
//            os << d << endl;
//        os << endl;
//        return os;
//    }


int main(int argc, char** argv) {

    try
    {            
        Deque <int> d;
        cout << "Empty: " << d.Empty() << endl;
        cout << "Всего элементов:" << d.Size() << endl;

        cout << "Добавим один"  << endl;
        d.PushBack(3);
        cout << "Empty: " << d.Empty() << endl;
        cout << "1-й элемент: " << d[0] << endl;
        cout << "Всего элементов:" << d.Size() << endl;

        cout << "Добавим парочку"  << endl;
        d.PushFront(2);
        d.PushFront(1);
        cout << "1-й элемент: " << d[0] << endl;
        cout << "2-й элемент: " << d[1] << endl;
        cout << "3-й элемент: " << d[2] << endl;
        cout << "Всего элементов:" << d.Size() << endl;        

        cout << "Изменим значение 2-го"  << endl;
        d[1] = 12;
        cout << "1-й элемент: " << d[0] << endl;
        cout << "2-й элемент: " << d[1] << endl;
        cout << "3-й элемент: " << d[2] << endl;
        cout << "4-й элемент: " << d[3] << endl;
        cout << "Всего элементов:" << d.Size() << endl;
    }
    catch (out_of_range& e)
    {
        cout << "caught exception out_of_range: " << e.what() << endl;
    }

    
    cout << "==============================" << endl;
    Deque <int> d;
    d.PushBack(1);
    d.PushBack(2);
    d.PushBack(3);
    d.PushBack(4);
    cout << "d.Front(): " << d.Front() << endl;
    cout << "d.Back(): " << d.Back() << endl;
    cout << "1-й элемент: " << d[0] << endl;
    cout << "2-й элемент: " << d[1] << endl;
    cout << "3-й элемент: " << d[2] << endl;    
    cout << "4-й элемент: " << d[3] << endl;
    
    d.Front() = 15;
    d.Back() = 51;
    
    cout << "d.Front(): " << d.Front() << endl;
    cout << "d.Back(): " << d.Back() << endl;    
    cout << "1-й элемент: " << d[0] << endl;
    cout << "2-й элемент: " << d[1] << endl;
    cout << "3-й элемент: " << d[2] << endl;
    cout << "4-й элемент: " << d[3] << endl;
    
//    for (int x : d)
//    {
//        cout << x << " " << endl;
//    }

    return 0;
}

