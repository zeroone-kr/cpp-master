// 클래스 템플릿
#include <iostream>

using namespace std;

// Vector2는 template, Vector2<T>는 타입
template<typename T>
class Vector2 {

private:
	T x, y;

public:
	Vector2() : x(0), y(0) {}
	Vector2(T x, T y) : x(x), y(y) {}
	T GetX() const { return x; }
	T GetY() const { return y; }

	// 복사 생성자 (테스트용)
	Vector2(const Vector2& rhs) {
		cout << "Vector2(const Vector2& rhs) 복사 생성자 호출!" << endl;
		x = rhs.x;
		y = rhs.y;
	}

	// 연산자 오버로딩
	Vector2<T> operator+(const Vector2<T>& rhs) const {
		return Vector2<T>(x + rhs.x, y + rhs.y);
	}

	// 연산자 오버로딩
	// <T> 생략 가능 -> 한 객체 내에서는 T가 동일한 형식이기 때문
	Vector2 operator-(const Vector2& rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}

	// 연산자 오버로딩
	Vector2& operator+=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	// 연산자 오버로딩
	Vector2& operator-=(const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

};

int main() {

	Vector2<float> v1(2, 3); 
	Vector2<double> v2(4, 5); 
	
	// v1객체는 8바이트
	cout << sizeof(v1) << endl;

	// v2객체는 16바이트
	cout << sizeof(v2) << endl;

	// 벡터 덧셈 수행
	Vector2<float> v3(4, 5);
	Vector2<float> v4 = v1 + v3; // <- 테스트 결과 복사 생성자 호출 x -> (임시 객체 생성)
	cout << v4.GetX() << ", " << v4.GetY() << endl;

}