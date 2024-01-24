#include <iostream>
using namespace std;

class Circle {

private:
    static int number_of_circles;
    int radius;

public: 
    Circle(int r = 1);
    ~Circle(){ number_of_circles--; }

    double getArea() {return 3.14*radius * radius;}

    static int get_number_of_circles(){ return number_of_circles;}
};


Circle::Circle(int r){
    radius = r;
    number_of_circles++;
}

int Circle::number_of_circles = 0;

int main(){
    
    Circle *p = new Circle[10];
    cout << "circles instance number = " << Circle::get_number_of_circles() << endl;

    delete[] p;
    cout << "circles instance number = " << Circle::get_number_of_circles() << endl;

    Circle a;
    cout << "circles instance number = " << Circle::get_number_of_circles() << endl;

    Circle b;
    cout << "circles instance number = " << Circle::get_number_of_circles() << endl;

}

/**
 * static 멤버 함수는 오직 static 멤버들만 접근
 * static 멤버 함수는 this 사용 불가
 * 클래스간 공유하기 위해 static사용
 * 전역함수와 전역변수 사용을 캡슐화 하게 해줌(전역함수와 전역변수 사용은 지양하도록!)
*/