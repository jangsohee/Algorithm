#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

int str_leng(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}
int main() {
	string str = "abc";
	//int i = 0;
	//gets(str);
	/*while (getchar() != '\n') {
		str[i++]
	}*/
	str = str.substr(3);
	int s = str.size();
	
	cout << s << endl;
}