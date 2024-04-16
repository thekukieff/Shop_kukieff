#include <iostream>
#include <string>
#include <limits>

//�����. ������� C����
//�� ������� NAMESPACE

//���������� �������
//��� ������� �� 1 ��������� Cout
int size = 10;
int* id_arr = new int[size];
std::string *name_arr = new std::string[size];
int *count_arr = new int[size];
float* price_arr = new float[size];


//�������
void Start();

void Ignore();

void Delete_main_arr();//�������� ���� ��� ��������

void Create_storage();//�������� ������

template <typename arr_type>

void Fill_arr(arr_type static_arr, arr_type dinArr, int size);//����������

void Cout_storage();//����� ��������

void Shop();//�������� �������


int main() {

	setlocale(LC_ALL, "ru");
	
	Start();
	Delete_main_arr();
	return 0;
}

void Start()
{
	std::cout << "����� ���������� � �����" << std::endl;

	std::string adminLogin = "Syshan";
	std::string adminPassword = "Syshi";
	std::string login, password;
	int choose;
	int exit = false;

	do {
		std::cout << "������� �����: ";
		std::getline(std::cin, login);

		std::cout << "������� ������: ";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "�������� ����� ��� ������" << std::endl;
			std::cout << "����������� ��� ���?" << std::endl << "1 - �����" << std::endl << "2 - ��������� � ���������";
			std::cin >> choose;
			Ignore();
			if (choose == 1){
				exit = true;
		}



		}
		else {
			exit = true;//��������� ����
			int chooseStorageType;
			do {
				std::cout << "�������� ������ ������: \n 1-������� \n 2 - ������� �������\n";
				std::cin >> chooseStorageType;

			} while (chooseStorageType<1|| chooseStorageType>2);

			Ignore();
			if (chooseStorageType == 1) {
				//������� � ���������
				Create_storage();
			}
			else if (chooseStorageType == 2) {
				std::cout << "� ����������\n";
			}
			else {
				std::cerr << "Error\n";
			}
		
		}
	
	}

	while (! exit);
	

	

}

void Ignore() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������� cin(����� ������ �����)�� ������ �� �����

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
	"���� � ����������","���� � ��������\t","���� � ������� ������","���� � �����������",
	"�����������\t","���� � ������\t","���� � ������\t","���� ������\t","���� ���������\t","���� � ����������"
	
	
	};
	int count[SIZE]{4,5,4,9,3,2,5,9,9,4};
	float price[SIZE]{542, 305, 499, 299, 399, 649, 549, 379, 259, 509};//���� �� 10 ����
	Fill_arr(id, id_arr, SIZE);//��������� ��� ������
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
	std::cout << "ID \t �������� ������\t\t���������� ������\t ����\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << id_arr[i]<< "\t" << name_arr[i] << "\t\t\t " << count_arr[i] << "\t\t " << price_arr[i] << "�" << std::endl;
	}

}

void Shop() {
	int choose;
	while (true)
	{
		do 
		{
			std::cout << "1-�������� �����\n";
			std::cout << "2-������ �������\n";
			std::cout << "3-�������� ����\n";
			std::cout << "4-������� �����\n";
			std::cout << "5-��������� �����\n";
			std::cout << "6-�������� �����\n";
			std::cout << "0-��������� �����\n";
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