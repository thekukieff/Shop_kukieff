#include <iostream>
#include <string>
#include <limits>

//�����. ������� C����
//�� ������� NAMESPACE
void Start();
//������� ������� ignor







int main() {
	setlocale(LC_ALL, "ru");
	Start();


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
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������� cin(����� ������ �����)�� ������ �� �����
			std::cin >> choose;
			if (choose == 1){
				exit = true;
		}



		}
		else {
			exit = true;//��������� ����
			int chooseStorageType;
			do {
				std::cout << "�������� ������ ������: \n 1-������� \n 2 - ������� �������";
				std::cin >> chooseStorageType;
			} while (chooseStorageType<1|| chooseStorageType>2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������� cin(����� ������ �����)�� ������ �� �����
			if (chooseStorageType == 1) {
				//������� � ���������
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
