#include <iostream>

using namespace std;

class Animal {
private:
	int food;
	int weight;

public:

	void set_animal(int _food, int _weight);
	
	void increase_food(int inc);

	void view_stat();

};


void Animal::set_animal(int food, int weight) {
	this->food = food;
	this->weight = weight;
}

void Animal::increase_food(int inc) {
	this->food += inc;
	this->weight += (inc / 3);
}

void Animal::view_stat() {
	
	cout << "이 동물의 food: " << this->food << endl;
	cout << "이 동물의 weight: " << this->weight << endl;
	
}


int main() {
	
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);
	animal.view_stat();
	return 0;
}