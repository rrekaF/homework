#include <iostream>

using namespace std;

void uno(char boards[125][8][8]) {
	int top = 0;
	bool clear = false;
	int counter = 0;
	int num = 0;
	int num_cpy = 0;
	int co = 0;
	for(int i = 0; i < 125; i++){
		counter = 0;
		if(num != num_cpy){
			co++;
		}
		num_cpy = num;
		for(int wiersz = 0; wiersz < 8; wiersz++){


			clear = true;

			for (int kolumna = 0; kolumna < 8; kolumna++){
				cout << boards[i][kolumna][wiersz];
				if(boards[i][kolumna][wiersz] != '.'){
					clear = false;
				}
			}

			if (clear == true){
				num++;
				counter++;
			}

			cout << endl;

		if(top < counter	){
			top = counter;
		}
		}
		if(num != num_cpy){
			co++;
		}
		num_cpy = num;
	}

	cout <<"max: " << counter << endl;
	cout << "boards: " << co << endl;
}

int main(){
	char boards[125][8][8];

	for(int i = 0; i < 125; i++){
		for(int j = 0; j < 8; j++){
			for(int k = 0; k < 8; k++){
				cin >> boards[i][j][k];
			}
		}
	}

	uno(boards);

	// for(int i = 0; i < 125; i++){
	// 	for(int j = 0; j < 8; j++){
	// 		for(int k = 0; k < 8; k++){
	// 			cout << boards[i][j][k];
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }


	return 0;
}