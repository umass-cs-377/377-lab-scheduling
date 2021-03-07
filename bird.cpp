#include <iostream>
#include <queue>

using namespace std;

struct Bird {
	float size;
	
	Bird(float size2){
		size = size2;
	}
};

struct SizeCheck{
	bool operator()(Bird const& b1, Bird const& b2){
		return b1.size < b2.size;
	}
};

int main() {
	priority_queue<int> numbers; //This is a simple priority queue of numbers
	numbers.push(5);
	numbers.push(10);
	numbers.push(99);
	numbers.push(60);
	numbers.push(94);
	while (!numbers.empty()){
		cout << numbers.top() << "\n"; //Prints out the order of 99, 94, 60, 10, 5
		numbers.pop();
	}
	cout << "\n";
	
	priority_queue<Bird, vector<Bird>, SizeCheck> birds; //Uses the Bird struct, a vector of type Bird, and the SizeCheck operator to compare Birds
	birds.push(Bird(30));
	birds.push(Bird(3));
	birds.push(Bird(8));
	birds.push(Bird(12));
	birds.push(Bird(35));
	while (!birds.empty()){
		Bird b = birds.top();
		birds.pop();
		cout << b.size << "\n"; //Prints out the order of 35, 30, 12, 8, 3
	}
	cout << "\n";


	return 0;
}
