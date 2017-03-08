#include <iostream>
using namespace std;

class score
{
private:
	int id;
	string name;
	int point;
public:
	score() {}
	score(int _id, string _name, int _point) : id(_id), name(_name), point(_point)
	{	}
public:
	int getId() { return id; }
	string getName() { return name; }
	int getPoint() { return point; }
};

score InputInfo(int index);
void SortInfo(score* Student);
void PrintInfo(score* Student);

int main()
{
	score Student[5];

	for (int i = 0; i < 5;i++)
		Student[i] = InputInfo(i);

	SortInfo(Student);
	PrintInfo(Student);
	system("pause");
	return 0;
}

score InputInfo(int index)
{
	int id;
	char name[10] = {};
	int point;
	cout << index + 1 << "번째 학생정보 입력중" << endl;
	cout << "학번 입력 : ";
	cin >> id;
	cin.ignore();
	cout << "이름 입력 : ";
	cin.getline(name, sizeof(name));
	cout << "점수 입력 : ";
	cin >> point;
	cin.ignore();
	cout << endl;

	return score(id, name, point);
}

void SortInfo(score* Student)
{
	score temp;

	for (int a = 0; a < 5; a++)
	{
		for (int b = (a + 1); b < 5; b++)
		{
			if (Student[a].getPoint() < Student[b].getPoint())
			{
				temp = Student[a];
				Student[a] = Student[b];
				Student[b] = temp;
			}
		}
	}
}

void PrintInfo(score* Student)
{
	cout << "석차　학번　　　　이름　　점수" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "　　　" << Student[i].getId() << "　" << Student[i].getName().c_str() << "　" << Student[i].getPoint() << endl;
	}
}
