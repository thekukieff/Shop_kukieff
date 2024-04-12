#include <iostream>
#include <string>
#include <limits>

//роллы. Магазин Cушан
//НЕ СТАВИТЬ NAMESPACE
void Start();
//Создать функцию ignor







int main() {
	setlocale(LC_ALL, "ru");
	Start();


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
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//очистка cin(всего потока даных)от начала до конца
			std::cin >> choose;
			if (choose == 1){
				exit = true;
		}



		}
		else {
			exit = true;//закончить цикл
			int chooseStorageType;
			do {
				std::cout << "Выберите формат склада: \n 1-готовый \n 2 - создать вручную";
				std::cin >> chooseStorageType;
			} while (chooseStorageType<1|| chooseStorageType>2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//очистка cin(всего потока даных)от начала до конца
			if (chooseStorageType == 1) {
				//создать и запустить
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
