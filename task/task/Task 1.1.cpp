#include "Student.h"
using namespace std;


void task_1_1();
void task_2_2();
void OOP();
int Kratkiy_path(string str);


int main() {
	setlocale(LC_ALL, "Russian");

	while (true) {
		cout << "Введите номер задачи 1 или 2 или ООП(3) или про Белую(4)" << endl;
		char x; cin >> x;
		switch (x) {
		case '1':
			task_1_1();
			break;
		case '2':
			task_2_2();
			break;
		case '3':
			OOP();
			break;

		case '4':
			string str;
			cin >> str;
			cout << Kratkiy_path(str) << endl;
			break;
		}

	}
	return 0;
}
int Kratkiy_path(string str) {
	char location = 'L';
	int count(0);
	/*count - Количество переправ; В цикле останавливаемся перед последней переправой,
	чтобы учесть условие - Поход заканчивается на правом берегу*/

	for (int i = 0; i < str.size() - 1; i++) {

		if (str[i] == str[i + 1] && str[i] == location) { /*Находим участок с двумя притоками подряд на одной стороне, выгодно его обойти*/
			count++;
			location = (location == 'R') ? 'L' : 'R'; /*Переправляемся через реку*/
			while (str[i] == str[i + 1])i++; /*Продолжаем движение, пока притоки на противоположной стороне*/
		}
		else if (str[i] == location || str[i] == 'B')count++; /*Иначе, если встречаем одиночный приток - преодолеваем*/

	}
	if (location == 'L' && str[str.size() - 1] == 'B')count += 2; /*Перед последней переправой возможен вариант, что мы на левой стороне, при этом притоки
																  с обеих; Деваться некуда.*/
	else if (location == 'R' && str[str.size() - 1] != 'R');/*Возможно, нам повезло, заканчиваем путь без преград по правой стороне*/
	else count++;
	return count;
}
void task_1_1() {
	string input, output;
	int same_count(1);
	cout << "Введите код ДНК" << endl;
	cin >> input;
	int input_size = input.size() - 1;
	for (int i(0); i < input_size; i++) {
		same_count = 1;
		while (input[i] == input[i + 1] && i < input_size) { /*Обнаруживаем одинаковые литералы, перебираем их и считаем*/
			same_count++;
			i++;
		}
		output += input[i] + to_string(same_count);
	}
	output += same_count == 1 ? input[input_size] + to_string(same_count) : "";
	cout << "Результат сжатия:" << output << endl;
	output.clear();
}
void task_2_2() {
	/*Я призадумался, но обнаружил одинаковые структуры в таком массиве - это квадраты, вложенные друг в друга,
	ячейки в их сторонах можно заполнить по алгоритму, у меня было два варианта, вот один из них*/
	int size, i, j;
	cout << "Укажите размерность массива" << endl;
	cin >> size;
	int** array = new int* [size];
	for (i = 0; i < size; i++) {
		array[i] = new int[size];
	}
	int num(0);
	for (i = 1; i <= size / 2 + size % 2; i++) { /*Можно интуитивно догадаться какая закономерность кол-ва квадратов в зависимости от размерности*/
		for (int j = i - 1; j <= size - i; j++) { /*Уменьшая рамки квадрата, в зависимости от i, заполняем верхнюю сторону квадрата*/
			array[i - 1][j] = num++;
		}
		for (j = i; j <= size - i; j++) {/*Аналогично правую сторону, учитывая, что верхний угол уже заполнен*/
			array[j][size - i] = num++;
		}
		for (j = size - i - 1; j >= i - 1; j--) { /*Нижний правый угол так же заполнен, при этом заполняем начиная с него*/
			array[size - i][j] = num++;
		}
		for (j = size - i - 1; j >= i; j--) {/*И верхний и нижний уже заполнены, так же в обр. порядке*/
			array[j][i - 1] = num++;
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cout << array[i][j] << "  ";

		}
		cout << "\n";
		delete[] array[i];
	}
	delete[] array;
}


void OOP() {
	cout << "Сколько студентов?" << endl;
	int count;
	cin >> count;
	Student* students = new Student[count];
	char str[256];
	for (int i = 0; i < count; i++) {
		cout << "Введите данные студентов в формате Фамилия, Имя, Отчество, Год рождения, Адрес, Телефон, Факультет, Курс и нажмите Enter():" << endl;

		/*Заполняем данные, как в формате выше, используя сеттеры, поля разделяем запятыми*/
		cin.getline(str, 256, ','); students[i].setName(str);
		getchar(); cin.getline(str, 256, ','); students[i].setSurname(str);
		getchar(); cin.getline(str, 256, ','); students[i].setMiddle_name(str);
		getchar(); cin.getline(str, 256, ','); students[i].setDOB(str);
		getchar(); cin.getline(str, 256, ','); students[i].setAddress(str);
		getchar(); cin.getline(str, 256, ','); students[i].setP_Number(str);
		getchar(); cin.getline(str, 256, ','); students[i].setFaculty(str);
		getchar(); students[i].setCourse(getchar());

	}
	bool t(true);
	while (t) {
		cout << "Вывести: 1) список студентов заданного факультета\n2) список студентов для заданного курса\n3) список студентов, родившихся после заданного года.\n";
		char x; cin >> x;
		switch (x) {
			/*Перебираем все элементы массива объектов класса Student, сравнивая соотв. поля;
			Циклы похожи, можно было бы перегрузить все три варианта поиска и вывода одной функцией*/
		case '1':
			cout << "Введите название факультета\n";
			char faculty[256];
			cin >> faculty;
			for (int i = 0; i < count; i++) {
				if (!strcmp(faculty, students[i].getFaculty())) {
					cout << students[i].getName() << ", " << students[i].getSurname() << ", " << students[i].getMiddle_name() << ", " << students[i].getDOB() << ", " << students[i].getAddress() << ", " << students[i].getP_Number() << ", " << students[i].getFaculty() << ", " << students[i].getCourse() << endl;
				}
			}
			break;
		case '2':
			cout << "Введите курс\n";
			char course;
			cin >> course;
			for (int i = 0; i < count; i++) {
				if (course == students[i].getCourse()) {
					cout << students[i].getName() << ", " << students[i].getSurname() << ", " << students[i].getMiddle_name() << ", " << students[i].getDOB() << ", " << students[i].getAddress() << ", " << students[i].getP_Number() << ", " << students[i].getFaculty() << ", " << students[i].getCourse() << endl;
				}
			}
			break;
		case '3':
			cout << "Введите дату рождения\n";
			int DOB; cin >> DOB;

			for (int i = 0; i < count; i++) {
				if (DOB == atoi(students[i].getDOB())) {
					cout << students[i].getName() << ", " << students[i].getSurname() << ", " << students[i].getMiddle_name() << ", " << students[i].getDOB() << ", " << students[i].getAddress() << ", " << students[i].getP_Number() << ", " << students[i].getFaculty() << ", " << students[i].getCourse() << endl;
				}
			}
			cout << "Введите год\n";
			break;
		default:
			t = false;
			break;
			
		}


	}


}
