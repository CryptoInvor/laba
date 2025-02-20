#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool task1(char words[], char sub[], int subword, int word) { // функция 1
	char sub1[100]{};
	bool flag = false;
	int count = 0, count2 = subword, count3 = 0;
	for (int i = 0; i < count2; i++) {
		for (int w = i; w < count2-1; w++) {
			if (sub[i] == sub[w+1]) {
				subword -= 1;
				flag = true;
				break;
			}
		}
		if (!flag) {
			sub1[i] = sub[i];
		}
		else {
			flag = false;
		}
		cout << flag << endl;
	}
	for (int i = 0; i < word; i++) { // перебор строки и подстроки
		for (int j = 0; j < subword; j++) {
			if (words[i] == sub1[j]) { // поиск совпадений 
				count += 1;
				sub1[j] = ' ';
				break;
			}
		}
		if (count != 0){ // проверка на совпадение всех символов подстроки
			count3 += 1;
		}
		count = 0;
		if (count3 == subword) break; // проверка 
	
	}
	if (count3 == subword) {
			return true;
			}
		else {
			return false;
			}
}


bool task2(char words[], char sub[], int subword, int word) { // функция 2
	int counter = 0;
	
	if (word >= subword) {
		for (int i = 0; i <= (word - subword); i++) {
			for (int j = 0; j < subword; j++) {
				if (words[i + j] == sub[j]) {
					counter += 1;
				}
			}
			if (counter == subword) {
				return true;
			}
			else {
				counter = 0;
			}
		}
		return false;
	}
	else {
		return false;
	}
	return false; 
}


vector<string> split(string& s, string& delimiter) {
	vector<string> tokens;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		tokens.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	tokens.push_back(s);

	return tokens;
}


int main(int argc, char *argv[])
{	
	setlocale(LC_CTYPE, "");
	int siz = 0; // инициализация переменных
	const int charlength = 100;
	char words[charlength]{};
	char taskwords[charlength]{};
	char subwords[charlength]{};
	char finale[charlength] {};
	int length = 1, counter = 0, space = 0, subword = 0;
		
switch (stoi(argv[1])) {
	case 1: {
		cout << "Введите слова через пробел:" << endl; // ввод строки и подстроки
		cin.getline(words, charlength);
		cout << "Введите искомую подстроку:" << endl;
		cin >> subwords;
		for (int i = 0; subwords[i] != taskwords[i]; i++) { // подсчет длинны подстроки
			subword += 1;
		}
		for (int i = 0; i < charlength; i++) { // подсчет длинны строки
			if (words[i] == ' ') length += 1;
		}
		cout << "-------Задание 1-------" << endl;
		for (int p = 0; space < length; p++) { // поиск слов для первого задания
			if ((words[p] != ' ') && (words[p] != '\0')) {
				counter += 1;
				taskwords[p - siz] = words[p];
			}
			else {
				space += 1;
				siz = p + 1;
				if (task1(taskwords, subwords, subword, counter)) { // вывод результатов первого задания
					cout << "В слове " << taskwords << " обнаружены все символы слова " << subwords << endl; // вывод если true
				}
				else {
					cout << "В слове " << taskwords << " нет всех символов слова " << subwords << endl; // вывод если false
				}
				for (int k = 0; k < counter; k++) {
					taskwords[k] = ' ';
				}
				counter = 0;
			}
		}
		for (int k = 0; k < counter; k++) { // обнуление переменных
			taskwords[k] = ' ';
		}
		counter = 0;
		space = 0;
		siz = 0;
		cout << "-------Задание 2-------" << endl;
		for (int p = 0; space < length; p++) { // поиск слов для второго задания
			if ((words[p] != ' ') && (words[p] != '\0')) {
				counter += 1;
				taskwords[p - siz] = words[p];
			}
			else {
				space += 1;
				siz = p + 1;
				if (task2(taskwords, subwords, subword, counter)) { // вывод результатов второго задания
					space = 0;
					for (int m = 0; space < length; m++) {
						if (m < counter + 1) {
							finale[m] = words[m + (siz - counter - 1)];
							if (words[m + (siz - counter - 1)] == ' ') space += 1;
						}
						else if (((m - counter) < (siz - counter - 1))) {
							finale[m] = words[m - counter - 1];
							if (words[m - counter - 1] == ' ') space += 1;
						}
						else {
							finale[m] = words[m];
							if (words[m] == ' ') space += 1;
						}
					}
					cout << "финальная строка: " << finale << endl;
					return 0;// вывод если true
				}
				else {
					// вывод если false
				}
				for (int k = 0; k < counter; k++) {
					taskwords[k] = ' ';
				}
				counter = 0;
			}
		}
	}break;
	case 2: {
		string words1;
		string subwords1;
		cout << "Введите слова через пробел:" << endl; // ввод строки и подстроки
		cin.getline(words, charlength);
		cout << "Введите разделяющую подстроку:" << endl;
		cin >> subwords;
		for (int i = 0; subwords[i] != taskwords[i]; i++) { // подсчет длинны подстроки
			subword += 1;
		}
		for (int i = 0; i < charlength; i++) { // подсчет длинны строки
			if (words[i] != (char)0) { 
				length += 1;
				words1 += words[i];
			}
		}
		cout << words << endl;
		vector<string> result = split(words1, subwords1);
		cout << "разделенный массив: ";
		for(int q = 0; q < result.size(); q++){
			if(q != result.size() - 1){
				cout << result[q] << ", ";
			}
			else {
				cout << result[q] << ", ";
			}
		}
	}break;
	}

	return 0;
	
}


