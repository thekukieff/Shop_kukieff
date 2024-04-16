#include <iostream>
#include <string>
#include <limits>

//роллы. Магазин Cушан
//НЕ СТАВИТЬ NAMESPACE

//глобальные массивы
//при нажатии на 1 загрузить Cout
int size = 10;
int* id_arr = new int[size];
std::string *name_arr = new std::string[size];
int *count_arr = new int[size];
float* price_arr = new float[size];


//функции
void Start();

void Ignore();

void Delete_main_arr();//удаление всех дин массивов

void Create_storage();//создание склада

template <typename arr_type>

void Fill_arr(arr_type static_arr, arr_type dinArr, int size);//заполнение

void Cout_storage();//вывод магазина

void Shop();//основная функция


int main() {

	setlocale(LC_ALL, "ru");
	
	Start();
	Delete_main_arr();
	return 0;
}

void Start()
{
	std::cout << "Добро пожаловать В Сушан" << std::endl;

	std::string adminLogin = "Syshan";
	std::string adminPassword = "Syshi";
	std::string login, password;
	int choose;
	int exit = false;

	do {
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);

		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль" << std::endl;
			std::cout << "Попробовать еще раз?" << std::endl << "1 - Выйти" << std::endl << "2 - Вернуться в программу";
			std::cin >> choose;
			Ignore();
			if (choose == 1){
				exit = true;
		}



		}
		else {
			exit = true;//закончить цикл
			int chooseStorageType;
			do {
				std::cout << "Выберите формат склада: \n 1-готовый \n 2 - создать вручную\n";
				std::cin >> chooseStorageType;

			} while (chooseStorageType<1|| chooseStorageType>2);

			Ignore();
			if (chooseStorageType == 1) {
				//создать и запустить
				Create_storage();
			}
			else if (chooseStorageType == 2) {
				std::cout << "В разработке\n";
			}
			else {
				std::cerr << "Error\n";
			}
		
		}
	
	}

	while (! exit);
	

	

}

void Ignore() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//очистка cin(всего потока даных)от начала до конца

}

void Delete_main_arr() {
	delete[]id_arr;
	delete[]name_arr;
	delete[]count_arr;
	delete[]price_arr;
	


}

void Create_storage() {
	const int SIZE = 10;
	int id[SIZE]{0,1,2,3,4,5,6,7,8,9};
	std::string name[SIZE]{
	"Суши с креветками","Суши с холодцом\t","Суши с печенью коровы","Суши с водорослями",
	"Филадельфия\t","Суши с крабом\t","Суши с раками\t","Суши острые\t","Суши веганские\t","Суши с осьминогом"
	
	
	};
	int count[SIZE]{4,5,4,9,3,2,5,9,9,4};
	float price[SIZE]{542, 305, 499, 299, 399, 649, 549, 379, 259, 509};//цена за 10 штук
	Fill_arr(id, id_arr, SIZE);//заполняем все списки
	Fill_arr(name, name_arr, SIZE);
	Fill_arr(count, count_arr, SIZE);
	Fill_arr(price, price_arr, SIZE);
	Cout_storage();

}

template<typename arr_type>
void Fill_arr(arr_type static_arr, arr_type din_arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		din_arr[i] = static_arr[i];
	}



}


void Cout_storage() {
	std::cout << "ID \t Название товара\t\tколичество товара\t цена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << id_arr[i]<< "\t" << name_arr[i] << "\t\t\t " << count_arr[i] << "\t\t " << price_arr[i] << "р" << std::endl;
	}

}

void Shop() {
	int choose;
	while (true)
	{
		do 
		{
			std::cout << "1-показать склад\n";
			std::cout << "2-начать продажу\n";
			std::cout << "3-изменить цену\n";
			std::cout << "4-Списать товар\n";
			std::cout << "5-пополнить товар\n";
			std::cout << "6-изменить склад\n";
			std::cout << "0-закончить смену\n";
			std::cin >> choose;








		} while (choose<0||choose>6);

		if (choose == 1)
		{

		}
		else if(choose == 2){
		
		}

		else if (choose == 3) {
		
		}

		else if (choose == 4) {
		
		}

		else if (choose == 5) {
		
		}

		else if (choose == 6) {
		
		}

		else if (choose == 0) {
			break;
		}

		else {
			std::cerr << "error" << std::endl;
		}

	}





}