#include <iostream>
#include <string>
#include <limits>
#include <windows.h>


//роллы. Магазин Cушан
//НЕ СТАВИТЬ NAMESPACE

//глобальные массивы
//при нажатии на 1 загрузить Cout
int size = 10;

int* id_arr = new int[size];
std::string* name_arr = new std::string[size];
int* count_arr = new int[size];
float* price_arr = new float[size];

float cash = 23444;
float cash_in_come = 0, card_in_come = 0, total_in_come = 0;

//Массивы для чека receipt
int size_receipt = 1;



std::string* name_arr_receipt = new std::string[size_receipt];
int* count_arr_receipt = new int[size_receipt];
float* price_arr_receipt = new float[size_receipt];


//для ручного склада
int size_arm = 1;
std::string* name_arr_arm = new std::string[size_arm];
int* count_arr_arm = new int[size_arm];
float* price_arr_arm = new float[size_arm];
int* id_arr_arm = new int[size_arm];


//функции
void Start();

void Ignore();

void Delete_main_arr();//удаление всех дин массивов

void Create_storage();//создание склада

template <typename arr_type>

void Fill_arr(arr_type static_arr, arr_type dinArr, int size);//заполнение

void Cout_storage();//вывод магазина

void Shop();//основная функция

void Cout_storage();//вывод магазина

void Sell();//продажа

void Add_size_receipt(int id, int count);

void Delete_arr_receipt();

void Cout_recipt();

void Change_price();//Изменить цену

void Remove_from_storage();

void Add_to_storage();

void DeleteElementByIndex();

void ChangeStorage();

void Add_element_to_end();

void Cash_status();

void discount(int count, float &total_sum);

void Arm_storage();



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Start();
	Delete_main_arr();
	Delete_arr_receipt();
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
			if (choose == 1) {
				exit = true;
			}



		}
		else {
			exit = true;//закончить цикл
			int chooseStorageType;
			do {
				std::cout << "Выберите формат склада: \n1 - готовый \n2 - создать вручную\n";
				std::cin >> chooseStorageType;

			} while (chooseStorageType < 1 || chooseStorageType>2);

			Ignore();
			system("cls");
			if (chooseStorageType == 1) {
				//создать и запустить
				Create_storage();
				Shop();
			}
			else if (chooseStorageType == 2) {
				std::cout << "В разработке\n";
				Arm_storage();

			}
			else {
				std::cerr << "Error\n";
			}

		}

	}

	while (!exit);




}

void Ignore() {

	std::cin.ignore(32000, '\n');//очистка cin(всего потока данных)от начала до конца


}

void Delete_main_arr() {
	delete[]id_arr;
	delete[]name_arr;
	delete[]count_arr;
	delete[]price_arr;



}

void Create_storage() {
	const int SIZE = 10;
	int id[SIZE]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string name[SIZE]{
	"Суши с креветками","Суши с холодцом\t","Суши с печенью коровы","Суши с водорослями",
	"Филадельфия\t","Суши с крабом\t","Суши с раками\t","Суши острые\t","Суши веганские\t","Суши с осьминогом"


	};
	int count[SIZE]{ 4,5,4,9,3,2,5,9,9,4 };
	float price[SIZE]{ 542, 305, 499, 299, 399, 649, 549, 379, 259, 509 };//цена за 10 штук
	Fill_arr(id, id_arr, SIZE);//заполняем все списки
	Fill_arr(name, name_arr, SIZE);
	Fill_arr(count, count_arr, SIZE);//


	Fill_arr(price, price_arr, SIZE);


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
		std::cout << id_arr[i] << "\t" << name_arr[i] << "\t\t\t " << count_arr[i] << "\t\t " << price_arr[i] << "р" << std::endl;
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
			std::cout << "7-показать кассу\n";
			std::cout << "0-закончить смену\n";
			std::cin >> choose;








		} while (choose < 0 || choose>7);
		system("cls");

		if (choose == 1)
		{

			Cout_storage();

		}
		else if (choose == 2) {


			Sell();


		}


		else if (choose == 3) {

			Change_price();

		}

		else if (choose == 4) {

			Remove_from_storage();
		}

		else if (choose == 5) {
			Add_to_storage();
		}

		else if (choose == 6) {
			ChangeStorage();
		}
		else if (choose == 7) {
			Cash_status();
		}


		else if (choose == 0) {
			break;
			Cash_status();
		}

		else {
			std::cerr << "error" << std::endl;
		}

	}





}
void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - Добавить товар в склад\n";
		std::cout << "2 - Убрать товар из склада\n";
		std::cout << "0 - Выход\n";
		std::cin >> choose;
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		Add_element_to_end();
	}
	else if (choose == 2)
	{
		DeleteElementByIndex();
	}
	else
	{
		std::cout << "Выход";
	}
}
void Sell()
{
	int id, count, confirm;//id, количество
	bool First = true;
	float total_sum = 0;
	int sum_count = 0;
	int pay;
	while (true)
	{
		do {
			std::cout << "Введите id товара: ";
			std::cin >> id;
			if (id < 1 || id>size)
			{
				std::cerr << "Данного товара нет!" << std::endl;
				continue;
			}

			if (count_arr[id - 1] > 0)
			{
				while (true)
				{
					std::cout << "Выбранный товар: " << name_arr[id - 1] << std::endl;
					std::cout << "Количество товаров на складе: " << count_arr[id - 1] << std::endl;
					std::cout << "Введите количество товара: ";
					std::cin >> count;

					if (count<1 || count>count_arr[id - 1])
					{
						std::cerr << "ERROR" << std::endl;

					}



					else {
						break;

					}


				}
			}
			else {
				std::cerr << "Товара на складе нет" << std::endl;

				continue;
			}


			std::cout << "Товар: " << name_arr[id - 1] << std::endl << "Количество: " << count << std::endl;
			std::cout << "1-Подтвердить" << std::endl << "2-Отмена " << std::endl;
			std::cin >> confirm;
			if (confirm == 1)
			{
				if (First)//формирование чека при первой покупке
				{
					sum_count += count*8;
					name_arr_receipt[size_receipt - 1] = name_arr[id - 1];
					count_arr_receipt[size_receipt - 1] = count;
					price_arr_receipt[size_receipt - 1] = price_arr[id - 1] * count;
					count_arr[id - 1] -= count;
					total_sum += price_arr[id - 1] * count;

					First = false;
				}
				else {
					Add_size_receipt(id, count);
					sum_count += count*8;//в одной упаковке 8 ролл
					total_sum += price_arr[id - 1] * count;

				}

			}
			else {
				continue;
			}
			std::cout << "Купить еще один товар? " << std::endl;
			std::cout << "1-Да " << std::endl << "2 - Закончить покупки" << std::endl;
			std::cin >> confirm;
			if (confirm == 1) {
				continue;
			}
			break;




		} while (true);
		std::cout << "Итоговая сумма без учета скидок: " << total_sum<<std::endl;
		discount(sum_count, total_sum);
		//вывод чека перенес в функцию discount
		std::cout << "Итоговая сумма с учетом скидок: " << total_sum<<std::endl;
		//скидки
		do {
			std::cout << "Наличка или безнал?" << std::endl;
			std::cout << "1 - Наличка" << std::endl << "2 - Безнал" << std::endl;
			std::cin >> pay;

		} while (pay < 1 || pay>2);
		if (pay == 1)
		{
			cash += total_sum;
			cash_in_come += total_sum;
		}
		else if (pay == 2) {
			card_in_come += total_sum;
		}
		break;
	}
	system("cls");

}

void Add_size_receipt(int id, int count)//создание чека
{
	std::string* name_arr_receipt_temp = new std::string[size_receipt];
	int* count_arr_receipt_temp = new int[size_receipt];
	float* price_arr_receipt_temp = new float[size_receipt];
	for (int i = 0; i < size_receipt; i++)
	{
		name_arr_receipt_temp[i] = name_arr_receipt[i];//перезаписываем
		count_arr_receipt_temp[i] = count_arr_receipt[i];
		price_arr_receipt_temp[i] = price_arr_receipt[i];
	}
	delete[]name_arr_receipt;
	delete[]count_arr_receipt;
	delete[]price_arr_receipt;
	size_receipt++;
	name_arr_receipt = new std::string[size_receipt];
	count_arr_receipt = new int[size_receipt];
	price_arr_receipt = new float[size_receipt];

	for (int i = 0; i < size_receipt - 1; i++)
	{
		name_arr_receipt[i] = name_arr_receipt_temp[i];
		count_arr_receipt[i] = count_arr_receipt_temp[i];
		price_arr_receipt[i] = price_arr_receipt_temp[i];
	}
	delete[]name_arr_receipt_temp;
	delete[]count_arr_receipt_temp;
	delete[]price_arr_receipt_temp;

	name_arr_receipt[size_receipt - 1] = name_arr[id - 1];
	count_arr_receipt[size_receipt - 1] = count;
	price_arr_receipt[size_receipt - 1] = price_arr[id - 1] * count;
	count_arr[id - 1] -= count;


}

void Delete_arr_receipt()
{
	delete[]name_arr_receipt;
	delete[]count_arr_receipt;
	delete[]price_arr_receipt;
}

void Cout_recipt()
{
	std::cout << "Название\t\t\tколичество \t цена\n";
	for (int i = 0; i < size_receipt; i++)
	{

		std::cout << name_arr_receipt[i] << "\t\t" << count_arr_receipt[i] << "\t\t" << price_arr_receipt[i] << std::endl;//вывод на экран}

	}
	std::cout << std::endl;

}

void Change_price() {
	int id;
	float newPrice;
	do
	{
		std::cout << "Введите Id товара для изменения цены: ";
		std::cin >> id;


	} while (id < 1 || id > id_arr[size - 1]);
	std::cout << "\n\nВыбран товар: " << name_arr[id - 1] << " " << price_arr[id - 1];
	do
	{
		std::cout << "\nВведите новую цену: ";
		std::cin >> newPrice;


	} while (newPrice < 0.01 || newPrice > 20000.0);
	price_arr[id - 1] = newPrice;
	std::cout << "\nЦена успешно изменена!\n\n";
	Cout_storage();
}

void Remove_from_storage()
{

	int id;
	int count;
	do
	{
		std::cout << "Введите Id товара для списания: ";
		std::cin >> id;

	} while (id < 1 || id > id_arr[size - 1]);
	std::cout << "\n\nВыбран товар: " << name_arr[id - 1] << " = " << count_arr[id - 1] << "Штук\n\n";
	do
	{
		std::cout << "\nВведите кол-во товара, которое списать: ";
		std::cin >> count;

	} while (count < 0 || count  > count_arr[id - 1]);
	count_arr[id - 1] -= count;
	std::cout << "\nТовар успешно списан!"<<std::endl;
	system("cls");
	Cout_storage();

}

void Add_to_storage()
{

	int id;
	int count;
	do
	{
		std::cout << "Введите Id товара для пополнения: ";
		std::cin >> id;

	} while (id < 1 || id > id_arr[size - 1]);
	std::cout << "\n\nВыбран товар: " << name_arr[id - 1] << " = " << count_arr[id - 1];
	do
	{
		std::cout << "\nПополнить: ";
		std::cin >> count;

	} while (count < 0 || count > 1000);
	count_arr[id - 1] += count;
	std::cout << "\nУспешно пополнено!"<<std::endl;

}


void DeleteElementByIndex()
{
	int* id_arr_temp = new int[size];
	std::string* name_arr_temp = new std::string[size];
	int* count_arr_temp = new int[size];
	float* price_arr_temp = new float[size];
	for (int i = 0; i < size; i++)
	{
		name_arr_temp[i] = name_arr[i];//перезаписываем
		count_arr_temp[i] = count_arr[i];
		price_arr_temp[i] = price_arr[i];
		id_arr_temp[i] = id_arr[i];
	}
	delete[]name_arr;
	delete[]count_arr;
	delete[]price_arr;

	size--;

	name_arr = new std::string[size];
	count_arr = new int[size];
	price_arr = new float[size];

	int index;
	do
	{
		std::cout << "Введите Id товара для удаления: ";
		std::cin >> index;

	} while (index < 1 || index > size+1);
	for (int i = 0, j = 0; i < size, j < size; i++, j++)
	{
		if (index - 1 == i) {
			i++;
			id_arr[j] = id_arr_temp[j];
			name_arr[j] = name_arr_temp[i];
			count_arr[j] = count_arr_temp[i];
			price_arr[j] = price_arr_temp[i];
		}
		else {
			id_arr[j] = id_arr_temp[j];
			name_arr[j] = name_arr_temp[i];
			count_arr[j] = count_arr_temp[i];
			price_arr[j] = price_arr_temp[i];
		}

	}
	delete[] id_arr_temp;
	delete[] name_arr_temp;
	delete[] count_arr_temp;
	delete[] price_arr_temp;
}

void Add_element_to_end()
{

	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	float* priceArrTemp = new float[size];
	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = id_arr[i];
		nameArrTemp[i] = name_arr[i];
		CountArrTemp[i] = count_arr[i];
		priceArrTemp[i] = price_arr[i];
	}
	delete[]id_arr;
	delete[]name_arr;
	delete[]count_arr;
	delete[]price_arr;
	size++;

	id_arr = new int[size];
	name_arr = new std::string[size];
	count_arr = new int[size];
	price_arr = new float[size];

	for (int i = 0; i < size - 1; i++)
	{
		id_arr[i] = idArrTemp[i];
		name_arr[i] = nameArrTemp[i];
		count_arr[i] = CountArrTemp[i];
		price_arr[i] = priceArrTemp[i];
	}
	id_arr[size - 1] = size;
	std::cout << "Введите имя нового товара: \n";
	Ignore();
	std::getline(std::cin, name_arr[size - 1], '\n');
	name_arr[size - 1] = name_arr[size - 1] + "\t";
	std::cout << "Введите кол-во нового товара: \n";
	std::cin >> count_arr[size - 1];
	std::cout << "\nВведите цену нового товара: \n";
	std::cin >> price_arr[size - 1];
	delete[]idArrTemp;
	delete[]nameArrTemp;
	delete[]CountArrTemp;
	delete[]priceArrTemp;
}

void Cash_status()
{
	total_in_come = card_in_come + cash_in_come;
	std::cout << "Наличные в кассе: " << cash << std::endl;
	std::cout << "Выручка в кассе: " << cash_in_come << std::endl;
	std::cout << "Выручка по безналу: " << card_in_come << std::endl;
	std::cout << "Итоговая выручка: " << total_in_come << std::endl;


}

void discount(int count, float &total_sum)
{

	if (count > 50) {
		total_sum = total_sum - 0.15*total_sum ;
		std::cout << "Количество суши превысило 50. Сумма на 15% меньше"<<std::endl;
	}
	
	if (total_sum > 3000) {
		for (int i = 0; i < size; i++)
		{
			if (count_arr[i]>=5)
			{
				count_arr[i] -= 5;

				std::cout << "Итоговая сумма более 3000 рублей. " << name_arr[i] << "5 штук бесплатно"<<std::endl;
				Add_size_receipt(i,5);
				name_arr_receipt[size_receipt - 1] = name_arr[i];
				price_arr_receipt[size_receipt-1] = 0;
				break;

			}
		}
	}
	Cout_recipt();

}

void Arm_storage()
{
	int id=0, count;
	float price;
	std::string name;
	int* idArrTempArm = new int[size_arm];
	std::string* nameArrTempArm = new std::string[size_arm];
	int* CountArrTempArm = new int[size_arm];
	float* priceArrTempArm = new float[size_arm];
	std::cout << "Вводите данные о товаре, если имя это end, то это конец ввода данных" << std::endl;
	//данные из переменных переходят во временый массив. Оттуда перекидываем 
	// в нормальный массив. Удаляем данные из временного массива. Перекидываем в 
	// него из нормального массива. удаляем нормальный массив. увеличиваем. 
	// возвращаем данные 

	

	while (id >= 0||id<500){
		std::cout<<std::endl;
		id++;
		std::cout << "\nВведите имя товара: ";
		std::getline(std::cin, name);

		if (name == "end")
			{
				break;
			}
		name = name + "\t";
		std::cout << "\nВведите количестово нового товара: ";
		std::cin >> count;
		Ignore();
		std::cout << "\nВведите цену товара: ";
		std::cin >> price;
		Ignore();
		


			
		nameArrTempArm[size_arm-1] = name;
		CountArrTempArm[size_arm-1] = count;
		priceArrTempArm[size_arm-1] = price;

		for (int i = 0; i < size_arm; i++)
		{
			name_arr_arm[i] = nameArrTempArm[i];
			count_arr_arm[i] = CountArrTempArm[i];
			price_arr_arm[i] = priceArrTempArm[i];
		}


		delete[]idArrTempArm;
		delete[]nameArrTempArm;
		delete[]CountArrTempArm;
		delete[]priceArrTempArm;
		size_arm++;
		idArrTempArm = new int[size_arm];
		nameArrTempArm = new std::string[size_arm];
		CountArrTempArm = new int[size_arm];
		priceArrTempArm = new float[size_arm];
		for (int i = 0; i < size_arm-1; i++)
		{
			nameArrTempArm[i] = name_arr_arm[i];
			CountArrTempArm[i] = count_arr_arm[i];
			priceArrTempArm[i] = price_arr_arm[i];
		}


		delete[]id_arr_arm;
		delete[]name_arr_arm;
		delete[]count_arr_arm;
		delete[]price_arr_arm;

		id_arr_arm = new int[size_arm];
		name_arr_arm = new std::string[size_arm];
		count_arr_arm = new int[size_arm];
		price_arr_arm = new float[size_arm];
		id_arr[id-1] = id;
	}


	size = size_arm-1;

	for (int i = 0; i < size; i++)
	{
		count_arr[i] = CountArrTempArm[i];
		name_arr[i] = nameArrTempArm[i];
		price_arr[i] = priceArrTempArm[i];
	}

	delete[]idArrTempArm;
	delete[]nameArrTempArm;
	delete[]CountArrTempArm;
	delete[]priceArrTempArm;
	
	Shop();
}

