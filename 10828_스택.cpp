#include <iostream>
#include <string>

using namespace std;

struct Stack {
	int arr[10002];
	int size;

	void push(int num) {
		arr[++size] = num;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		return arr[size--];
	}

	int empty() {
		if (size == 0) {
			return 1;
		}
		return 0;
	}

	int top() {
		if (empty()) {
			return -1;
		}
		return arr[size];
	}

	int getSize() {
		return size;
	}
};
int main() {

	Stack s {};
	int tc;
	cin >> tc;

	while (tc--) {
		string str;
		int num = 0;
		cin >> str;
		
		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			cout << s.pop() << '\n';
		}
		else if (str == "empty") {
			cout << s.empty() << '\n';
		}
		else if (str == "top") {
			cout << s.top() << '\n';
		}
		else if (str == "size") {
			cout << s.getSize() << '\n';
		}

	}
	return 0;
}