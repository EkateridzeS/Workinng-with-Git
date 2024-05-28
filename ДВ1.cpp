#include <iostream>
using namespace std;
struct list {
	int inf;
	list* next;
	list* prev;
};
//������� �������� � ����� ������
void push(list*& h, list*& t, int x) {
	list* r = new list; //������ ����� �������
	r->inf = x;//��������� �������������� ���� ������ ��������
	r->next = NULL; //��������� ��������� ���� ������ ��������
	if (!h && !t) { //���� ������ ����
		r->prev = NULL; //r ����� ������ ���������
		h = r;//������ � ����� ��������� �� r
	}
	else {
		t->next = r; //��������� ��� ������ ��� ������ - ��� r
		r->prev = t;//���������� ��������� ��� r ����� t
	}
	t = r; //����� t ����� ��������� �� r
}
//������� ������� �� ������ �������, �� ������� ��������� r
void del_node(list*& h, list*& t, list* r) {
	if (r == h && r == t) //���� � ������ ���� �������
		h = t = NULL; //�� ������ ����� ������
	else if (r == h) { //���� ���� ������� ������ ������� � ������
		h = h->next; //�� �������� ������ h �� ���� �������
		h->prev = NULL;
	}
	else if (r == t) { //���� ������� ��������� �������
		t = t->prev; //�������� ����� �� ���� ������� �����
		t->next = NULL;
	}
	else {//������ ����� ��������� ������� � �������� ������
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r; //������� r
}
//����� ��������� ������
void print(list*& h, list*& t) {
	list* p = h;//��������� �� ������
	while (p) { //���� �� ����� �� �����
		cout << p->inf << " ";//�������
		p = p->next;//������� � ����������
	}
}

list* minz(list*& h) {
	list* min = h;
	list* p = h->next;
	while (p) {
		if (p->inf < min->inf) {
			min = p;
		}
		p = p->next;
	}
	return min;
}


//������� ��� ��������� ������ � ������������ � ��������
void result(list*& h, list*& t) {
	list* min = minz(h);
	list* p = h;//��������� �� ������
	while (p != min) {//���� �� ����� �� ����� ������
		push(h, t, p->inf);
		del_node(h, t, p); //������� ���
		p = h;//����������� p ��������� �������
	}
}

int main() {
	int n, y;
	//�������������� ������
	list* h = NULL;
	list* t = NULL;
	cout << "n= ";
	cin >> n;//��� ���������� ���������
	for (int i = 0; i < n; i++) { //���� ����� ���������
		cin >> y;
		push(h, t, y); //���������� �������� � ����
	}
	result(h, t);
	print(h, t);//������� ���������� ������
	return 0;
}