#include <iostream>
using namespace std;
int main(){
	string s = "aromino";
	
	auto func = [&s]()mutable -> void{
		s = "peniala";
	};
	func();
	cout << s;
}
