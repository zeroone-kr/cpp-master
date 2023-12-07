#include <iostream>
#include <string>


// 함수 템플릿
template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

public:
    Vector(int n =1) : data(new T[n]), capacity(n), length(0) {}

    //맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s){
        if (capacity <= length){
            T* temp = new T[capacity *2];
            for (int i =0 ;i < length;i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *=2;
        }

        data[length] =s;
        length++;
    }

    // 임의의 위치 원소에 접근
    T operator[](int i){return data[i];}


    // x 번째 위치한 원소 제거
    void remove(int x){
        for(int i = x+1; i< length; i++){
            data[i-1] =data[i];
        }
        length--;
    }

    // 현재 벡터 크기를 구함
    int size() { return length; }

    ~Vector(){
        if (data){
            delete[] data;
        }
    }
};

int main(){
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector --------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");

    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

}