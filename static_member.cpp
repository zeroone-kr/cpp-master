#include <iostream>
using namespace std;

class MyData {
private:
    int m_nData;
    static int m_nCount; // 정적 멤버변수 선언.(정적 멤버변수는 선언과 정의가 분리되어 있어야 합니다.)
    
public:
    MyData(int nParam) : m_nData{ nParam } { m_nCount++; }
    ~MyData() { /* do somthing */ }
    
    int GetData() const { return m_nData; }
    
    void ResetCount() { m_nCount = 0; }
    
    static int GetCount() { return m_nCount; }
};
 
int MyData::m_nCount = 0; // 정적 멤버변수 정의.(정적 멤버변수는 선언과 정의가 분리되어 있어야 합니다.)
 
int main() {

    MyData myData(10);
    
    cout << myData.GetCount() << endl;    // 인스턴스를 통해 '정적 멤버함수'를 호출합니다.
    cout << MyData::GetCount() << endl;  // 클래스를 통해 '정적 멤버함수'를 호출합니다.

}

//출처: https://pangtrue.tistory.com/24