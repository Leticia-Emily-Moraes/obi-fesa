#include <iostream>
using namespace std;

int main() {
	int F = 0, C = 0, E = 0, B = 0;
	cin >> F >> C >> E >> B;

	int totalAssentos = (F - E + 1) * C;

	if (B <= totalAssentos) {
		int fileira = E + (B - 1) / C;
		int posicao = (B - 1) % C;
		char letra = 'A' + posicao;

		cout << fileira << " " << letra << endl;
	}
	return 0;
}