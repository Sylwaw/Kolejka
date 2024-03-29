#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


class Kolejka {
private:
	string name;
	Kolejka *next;
public:
	Kolejka(string name = "Imie domyslne");
	~Kolejka();
	void push(Kolejka *head, string name);
	void print(Kolejka *head);
	void pop(Kolejka *head);
	void howMany(Kolejka *head);
}*head = NULL, *tmp = NULL;   // tmp=ogon



Kolejka::Kolejka(string name)
{
	this->name = name;
	cout << "Uruchomiono Konstruktor" << endl;
}
Kolejka::~Kolejka()
{
	cout << "Uruchomiono destruktor";
}

void Kolejka::push(class Kolejka *head, string name)
{
	if (tmp == NULL)
	{
		head->name = name;
		head->next = NULL;
		tmp = head;
		cout << "Pierwszy element" << endl;
	}
	else {
		Kolejka *nowy;
		nowy->name = name;
		nowy->next = NULL;
		tmp->next = nowy;
		tmp = nowy;
		cout << "Kolejny element" << endl;
	}
}

void Kolejka::pop(Kolejka *head)
{
	if (tmp == NULL)
	{
		cout << "Brak elementow w kolejce" << endl;
	}
	else
	{
		Kolejka *pom;
		pom = head;
		head = pom->next;
		delete(pom);
	}
}

void Kolejka::howMany(Kolejka *head)
{
	int licznik = 0;
	Kolejka *temp;
	temp = head;
	if (tmp == NULL)
	{
		cout << "Brak elementow w kolejce" << endl;
	}
	while (temp)
	{
		licznik++;
		temp = temp->next;
	}
	cout << "W kolejce znajduje sie " << licznik << " elementow" << endl;
}

void Kolejka::print(class Kolejka *head) {

	Kolejka *temp;
	temp = head;
	while (temp)
	{
		cout << "Imie:  " << temp->name << endl;
		temp = temp->next;
	}
}

int main() {

	Kolejka *baza = new Kolejka;
	//baza->pop(baza);
	baza->push(baza, "Kasia");
	baza->push(baza, "Alojzy");
	baza->push(baza, "Gosia");
	baza->push(baza, "Basia");
	baza->push(baza, "Stasia");

	cout << "\n\n\n";

	baza->print(baza);
	baza->howMany(baza);
	//baza->pop(baza);
	//baza->print(baza);


}