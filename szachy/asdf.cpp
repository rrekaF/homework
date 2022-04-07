#include <iostream>

using namespace std;

void uno(char boards[125][8][8]) {
    cout << "1.1: " << endl;
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
				//cout << boards[i][kolumna][wiersz];
				if(boards[i][kolumna][wiersz] != '.'){
					clear = false;
				}
			}

			if (clear == true){
				num++;
				counter++;
			}

			//cout << endl;

		if(top < counter	){
			top = counter;
		}
		}
		if(num != num_cpy){
			co++;
		}
		num_cpy = num;
	}

	cout <<"Liczba plansz z pusta kolumna: " << counter << endl;
	cout << "Najwieksza liczba pustych kolumn na takiej planszy: " << co << endl;
}

void dos(char boards[125][8][8]){
    cout << "1.2: " << endl;
    int big[25] = {0};
    int small[25] = {0};
    int mini= 64;
    int ctr = 0;
    bool equality = true;
    int sum = 0;

    for(int i = 0; i < 125; i++){
        equality = true;
        for (int bigI = 0; bigI < 25; bigI++){
            //cout <<"big: " << big[bigI] << endl;
            big[bigI] = 0;
        }
        for (int smallI = 0; smallI < 25; smallI++){
            //cout << "small: " << small[smallI] << endl;
            small[smallI] = 0;
        }

        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                if(boards[i][j][k] > 64 && boards[i][j][k] < 91){
                    big[boards[i][j][k]-'A']++;
                } else if(boards[i][j][k] > 96 && boards[i][j][k] < 122){
                    small[boards[i][j][k]-'a']++;
                }
            }
        }
       for(int check = 0; check < 25; check++){
        if(small[check] != big[check]){
            equality = false;
            break;
        }
       }
       if(equality){
        for(int wiersze = 0; wiersze < 8; wiersze++){
            for(int kolumny = 0; kolumny < 8; kolumny++){
                //cout << boards[i][wiersze][kolumny];
            }
            //cout << endl;
        }
        //cout << endl;
        ctr++;
        for(int num = 0; num < 25; num++){
            sum += small[num];
            sum += big[num];
            //cout << sum << endl;
        }
            if(sum < mini && sum != 0){
                mini = sum;
                //cout << "---------------------------------------------------" << endl;
                //cout << mini << endl;
            }
       }
       sum = 0;

    }
    cout << "Liczba plansz w rownowadze: " << ctr << endl << "Najmniejsza liczbia pionkow na takiej planszy: " << mini << endl;

}

void tres(char boards[125][8][8]){
    cout << "1.3: " << endl;
    int whiteX = 0;
    int whiteY = 0;
    int blackX = 0;
    int blackY = 0;

    //szukanie krola
	bool isWhiteChecked = false;
	for(int i = 0; i < 125; i++){
		if(isWhiteChecked){
			cout << "Krol bialy jest zatkowany" << endl;
		}

		for(int j = 0; j < 8; j++){
			for(int k = 0; k < 8; k++){
				if(boards[i][j][k] == 'K'){
                    whiteX = k;
                    whiteY = j;
				}
				if(boards[i][j][k] == 'k'){
										blackX = k;
										blackY = j;
				}
			}
		}
		for(int y = whiteY; y < 8; y++){//szukanie w dol
			cout << boards[i][y][whiteX] << endl;
			if(boards[i][y][whiteX] != '.'){
				if(boards[i][y][whiteX] == 'w'){
					isWhiteChecked = true;
					break;
				} else {
					isWhiteChecked = false;
					break;
				}
			}
		}
		if(!isWhiteChecked){
			for(int y = whiteY; y > 0; y--){//szukanie w gore
				cout << boards[i][y][whiteX] << endl;
				if(boards[i][y][whiteX] != '.'){
					if(boards[i][y][whiteX] == 'w'){
						isWhiteChecked = true;
						break;
					} else {
						isWhiteChecked = false;
						break;
					}
				}
			}
		}
		if(!isWhiteChecked){
			for(int y = whiteY; y > 0; y--){
				if(boards[i][whiteY][y] == '.'){
					continue;
				}else{
					if(boards[i][y][whiteX] == 'w'){
						isWhiteChecked = true;
					}else{
						isWhiteChecked = false;
						break;
					}
				}

			}
		}

	}

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
	cout << endl;
	dos(boards);
	cout << endl;
	tres(boards);
	return 0;
}
