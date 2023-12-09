// 스마트 포인터(unique_ptr, shared_ptr, weak_ptr): new한 객체를 특정 조건때 자동으로 delete해줌
// weak_ptr
// use_count값을 참고하여 여러 포인터 변수가 객체를 가르키도록 허용
// 하지만, weak pointer가 가르키고 있어도 use_count가 올라가지 않음
// use_count값이 0이되는 순간 객체는 소멸

#include <iostream>
#include <memory>

using namespace std; 

class Test {

private:
    int x;

public:

    Test(int x): x(x) {
        cout << "생성자 호출" << endl;
    }

    ~Test() {
        cout << "소멸자 호출" << endl;
    }

    int GetX() const { return x; }

};

int main() {

    weak_ptr<Test> b;
    {
        shared_ptr<Test> a(new Test(5));
        b = a;
        cout << a.use_count() << endl;
        cout << b.use_count() << endl;
        if (!b.expired()) {
            cout << b.lock()->GetX() << endl;
        }
    }
    
    cout << b.use_count() << endl;

    if (!b.expired()) {
        cout << b.lock()->GetX() << endl;
    }

}