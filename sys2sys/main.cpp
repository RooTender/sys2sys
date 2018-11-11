#include <cstdio>
#include <conio.h>
#include <stack>

//Converters
int cint(char input) { return (input >= 'A') ? input + 10 - 'A' : (int)input - '0'; }
char intc(int input) { return (input >= 10) ? input - 10 + 'A' : (char)input + '0'; }

int main()
{
	char number[255];
	int base1, base2, prcs = 0, pow = 1;

	scanf("%d %d %s", &base1, &base2, &number);
	std::stack<char> out;

	for (int i = strlen(number) - 1; i >= 0; i--) {
		prcs += cint(number[i]) * pow;
		pow *= base1;
	}

	while (prcs > 0) {
		out.push(intc(prcs % base2));
		prcs /= base2;
	}

	while (!out.empty()) {
		printf("%c", out.top());
		out.pop();
	}

	return 0;
}