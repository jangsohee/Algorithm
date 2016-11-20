#include <iostream>

using namespace std;
int mon[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
char today[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main() {
	int x = 0, y = 0;
	cin >> x >> y;

	int day = 0;

	for (int i = 0; i < x; i++) {
		day += mon[i];
	}
	day += y;
	day = day % 7;
	
	cout << today[day] << endl;
	  
	return 0;
}