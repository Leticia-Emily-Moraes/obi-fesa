#include <iostream>
using namespace std;

int main() {
	int N, P, convidados = 0; //Numero competidores e numero pontos para entrar
	cin >> N >> P; 

	for (int i = 0; i < N; i++) { //Pontuacao competidores
		int X, Y; //Primeira e segunda fase
		cin >> X >> Y;
		int pts = X + Y; //Pts totais

		if (pts >= P) { 
			convidados++; //Cada convidado que tiver pontuacao o suficiente para entrar, atualiza convidados
		}
	}

	cout << convidados << endl; //retorna valor
}