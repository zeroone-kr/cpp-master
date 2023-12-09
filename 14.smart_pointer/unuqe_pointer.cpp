// 스마트 포인터(unique_ptr, shared_ptr, weak_ptr): new한 객체를 특정 조건때 자동으로 delete해줌
// unique_ptr
// 한 포인터는 무조건 한 대상만 가르키도록 보장
#include <iostream>
#include <memory>

using namespace std;

class Test {

private:
    int x;

public:

    Test(int x) : x(x) {
        cout << "생성자 호출" << endl;
    }

    ~Test() {
        cout << "소멸자 호출" << endl;
    }

    int GetX() const { return x; }

};

int main() {

    unique_ptr<int> a(new int(5));

    // 1. release(): a에서 b로 소유권 이전 
    unique_ptr<int> b(a.release()); // 

    // 2. reset(): 기존에 포인터를 리셋하고 new int(6)을 가르킴
    a.reset(new int(6));

}