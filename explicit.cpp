// 컴파일 에러 나야함
#include <iostream>

class MyString{

    char *string_content;
    int string_length;
    int memory_capacity;

public:
    // explicit keyword: 명시적으로 생성자를 부를 때 에만 허용
    explicit MyString(int capacity);

    MyString(const char *str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;

};

MyString::MyString(int capacity){
    
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;

}

MyString::MyString(const char *str){

    string_length =0;
    while(str[string_length++]){
    }
    string_content = new char[string_length];
    memory_capacity = string_length;
    for(int i=0; i != string_length; i++) string_content[i] = str[i];

}

MyString::MyString(const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for(int i=0 ;i != string_length; i++){
        string_content[i] = str.string_content[i];
    }
}


MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s) {
    // Do something...
}

int main() {
    DoSomethingWithString(3); // ????
}


