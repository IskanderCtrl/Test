// spisok.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
void createList(node*& head)
{
	head = NULL;
	int i, n;
	cout << "Vvedite kol-vo elementov v spiske" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node* q = new node;
		cin >> q->data;
		q->next = head;
		head = q;
	}
}
void showList(node* head)
{
	node* q = head;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->next;
	}
	cout << endl;
}
void push1(node*& head)
{
	node* a = new node;
	cin >> a->data;
	a->next = head;
	head = a;
}
void push2(node* head)
{
	int t;
	cin >> t;
	node* q = head;
	node* a = new node;
	cin >> a->data;
	bool s = true;
	while (q->next != NULL&&s)
	{
		if (q->data == t)
		{
			a->next = q;
			s = false;
		}
		q = q->next;
	}
}
void push3(node* head)
{
	int t;
	cin >> t;
	node* q = head;
	node* a = new node;
	cin >> a->data;
	bool s = true;
	while (q->next != NULL && s)
	{
		if (q->data == t)
		{
			a->next = q->next;
			q->next = a;
			s = false;
		}
		q = q->next;
	}
}
void push4(node* head)
{
	node* q = head;
	node* a = new node;
	cin >> a->data;
	while (q->next != NULL)
	{
		q = q->next;
	}
	a->next = NULL;
	q->next = a;
}
void delete1(node*& head)
{
	node* q = head;
	head = head->next;
	delete q;
}
void delete2(node* head)
{
	node* q = head;
	while (q->next != NULL)
		q = q->next;
	delete q;
}
void delete3(node* head)
{
	int t;
	cin >> t;
	node* q = head;
	bool s = true;
	while (q->next != NULL && s)
	{
		if (q->data == s)
		{
			node* p = q->next;
			q->next = p->next;
			delete p;
			s = false;
		}
		q = q->next;
	}
}
void ind4(node*& head)
{
	node* q = head;
	node* a = head;
	if (head != NULL)
	{
		if (head->next == NULL)
		{
			if (head->data < 0)
			{
				head = NULL;
				delete q;
			}
		}
		else
		{
			while (q != NULL)
			{
				if (head->data < 0)
				{
					head = head->next;
					delete q;
					q = head;
					a = head;
				}
				else
				{
					if (q->data >= 0)
					{
						if (q == head)
							q = q->next;
						else
						{
							q = q->next;
							a = a->next;
						}
					}
					else
					{
						a->next = q->next;
						delete q;
						q = a->next;
					}
				}
			}
		}
	}
}
void deleteList(node*& head)
{
	node* a = head;
	while (head != NULL)
	{
		head = head->next;
		delete a;
		a = head;
	}
}
int main()
{
	node* head;
	createList(head);
	//push1(head);
	//push2(head);
	//push3(head);
	//push4(head);
	//delete1(head);
	//delete2(head);
	//delete3(head);
	ind4(head);
	showList(head);
	deleteList(head);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
