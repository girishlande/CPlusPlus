#include <iostream>
#include <vector>

using namespace std;
int main() 
{
	cout << "Hello Girish" << endl;
	auto a={"Girish","Ajit","Suhas"};
	for(auto x:a) {
		cout << "output:"<<x<<endl;
	}
	
	vector<string> b;
	b.push_back("Girish Lande");
	b.push_back("Ajit Lande");
	b.push_back("Suhas Walase");
	for(auto y:b) {
		cout << "output:" << y << endl;
	}
	
	
	string str("Hello Girish");
	for(auto z:str) {
		cout << "char:" << z <<endl;
	}
	
	return 0;
}