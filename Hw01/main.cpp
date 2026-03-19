#include <iostream>

using namespace std;

const enum Status
{
	HP = 0,
	MP,
	Attack,
	Defence,
	Level
};


void Data_Initalize(int& Data, int mark, string Text); 
void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
void using_Potion(int* potion);
void Stutus_up(int& Status_Hp, int& Potion, Status Kind);
void Status_Demage_Up(int& Status_ATF, Status Kind);


int main(void)
{
	int character_Status[5] = { 0, };
	int Potion_data[2] = { 0, };
	int Menu_Number = 0;
	bool Status_Check_b = true;
	

	cout << " HP / MP / 공격력 / 방어력  순으로 데이터를 입력하세요 " << endl;
	Data_Initalize(character_Status[0], 50, "HP");
	Data_Initalize(character_Status[1], 50, "MP");
	Data_Initalize(character_Status[2], 0, "공격력");
	Data_Initalize(character_Status[3], 0, "방어력");

	setPotion(5,&Potion_data[0],&Potion_data[1]);

	while (true)
	{
		cout << endl<<" ---------------------------------------" << endl;
		cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4,방어력 UP / 5.현재 능력치 / 6. Level UP / 0. 나가기" << endl;
		cin >> Menu_Number;
		if (Menu_Number == 0)
		{
			cout << " 프로그램을 종료합니다 .";
			break;
		}
		else
		{
			if (Menu_Number >= 1 && Menu_Number <= 4)
			{
				--Menu_Number;
				if ((Status)Menu_Number == Status::MP || (Status)Menu_Number == Status::HP)
					Stutus_up(character_Status[Menu_Number], Potion_data[Menu_Number], (Status)Menu_Number);
				else
					Status_Demage_Up(character_Status[Menu_Number], (Status)Menu_Number);

			}
			else if (Menu_Number == 5)
			{
				cout << "Level : " << character_Status[4]<<endl;
				cout << "HP : " << character_Status[0]<< endl;
				cout << "MP : " << character_Status[1]<< endl;
				cout << "공격력 :" << character_Status[2]<<endl;
				cout << "방어력 : " << character_Status[3] << endl;
				cout << "HP 포션 : " << Potion_data[0] << endl;
				cout << "MP 포션 : " << Potion_data[1] << endl<<endl;
			}
			else if (Menu_Number == 6)
			{
				setPotion(1, &Potion_data[0], &Potion_data[1]);
				character_Status[4]++;
			}
			else
				cout << "정상적이지 않은 번호입니다 다시 입력해 주세요 ." << endl;

		}
	}


	return 0;
}


void Data_Initalize(int &Data,int mark,string Text)// Data 초기화 함수 
{
	bool Check = true;
	// 일정 값 아래로 입력하게 된다면 이하로 입력할수 없다는 출력과 함께 
	// 다시 값을 입력하게 함수화 하였다.
	while (Check) 
	{
		cout << "------------------------------------------" << endl;
		cout << Text << " 는"<< mark << " 초과하여 입력해 주세요!! " << endl;
		cout << Text <<"  : ";
		cin >> Data;
		if (Data > mark)
			Check = false;
		else
			cout << mark << "이하로 입력할 수 없습니다.다시 입력해 주세요 ." << endl;

	}
}
void Stutus_up(int &Status_Hp,int &Potion,Status Kind)
{
	// enum 을 활용하여서 HP 와 MP 값을 증가 + potion 을 소비 및 포션이 없을 떄를 대비하여 조건문을 활용 하였다.
	// 포인터를 사용하는 것이 아닌 참조를 활용하여 사용해 보았다. 포인터는 주소값을 들고 있지만 주소값 자체를 들고 오면 
	// 포인터 처럼 사용할 수는 있다.
	if (Potion > 0)
	{
		if (Kind == Status::HP)
			cout << "HP";
		else if (Kind == Status::MP)
			cout << "MP";

		cout << "가" << 20 << " 증가 되었습니다. 포션 1개가 차감되었습니다. " << endl;
		Status_Hp += 20;
		--Potion;
	}
	else
	{
		cout << " 해당 포션이 부족합니다 ." << endl;
	}
}
void Status_Demage_Up(int& Status_ATF, Status Kind)
{
	// 공격력 증가 함수 . 2배 증가면 그저 나 자신을 더하거나 *2 를 할수도 있따.
	if (Kind == Status::Attack)
		cout << "공격력";
	else if (Kind == Status::Defence)
		cout << "방어력";
	cout << " 증가했습니다 . " << endl;
	Status_ATF += Status_ATF;
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	// pointer 를 호출하여서 레벨업 시 1개씩 증가 와
	// 초기화시 5개 각각 뿌리는 것을 하나로 통합하여 작성 하였다.
	cout << " 포션이 증가되었습니다 " << endl;
	*p_HPPotion += count;
	*p_MPPotion += count;
}

void using_Potion(int *potion)
{
	// 포인터를 억지로 사용한 코드... 정도?..
	--potion;
	cout << " 남은 포션의 갯수 " << potion << endl;

}