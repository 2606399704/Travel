#include<iostream>
using namespace std;
#include<stack>

int main() {
	int n;
	char ch;
	scanf_s("%d", &n);
	getchar();
	while (n--) {
		stack<char>s;
		while (true) {
			ch = getchar();
			if (ch == ' ' || ch == '\n' || ch == EOF) {
				while (!s.empty()) {
					printf("%c", s.top());
					s.pop();
				}
				if (ch == '\n' || ch == EOF) break;
				printf(" ");
			}
			else s.push(ch);
		}
		printf("\n");
	}
	return 0;
}