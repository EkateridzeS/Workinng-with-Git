#include <iostream>
using namespace std;
struct list {
	int inf;
	list* next;
	list* prev;
};
//вставка элемента в конец списка
void push(list*& h, list*& t, int x) {
	list* r = new list; //создаём новый элемент
	r->inf = x;//заполняем информационное поле нового элемента
	r->next = NULL; //заполняем ссылочное поле нового элемента
	if (!h && !t) { //если список пуст
		r->prev = NULL; //r будет первым элементом
		h = r;//голова р будет ссылаться на r
	}
	else {
		t->next = r; //следующий для хвоста для хвоста - это r
		r->prev = t;//предыдущим элементом для r будет t
	}
	t = r; //хвост t будет указывать на r
}
//функция удаляет из списка элемент, на который ссылается r
void del_node(list*& h, list*& t, list* r) {
	if (r == h && r == t) //если в списке один элемент
		h = t = NULL; //то список будет пустым
	else if (r == h) { //если надо удалить первый элемент в списке
		h = h->next; //то сдвигаем голову h на один элемент
		h->prev = NULL;
	}
	else if (r == t) { //если удаляем последний элемент
		t = t->prev; //сдвигаем хвост на один элемент влево
		t->next = NULL;
	}
	else {//случай когда удаляемый элемент в середине списка
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r; //удаляем r
}
//вывод элементов списка
void print(list*& h, list*& t) {
	list* p = h;//указатель на голову
	while (p) { //пока не дошли до конца
		cout << p->inf << " ";//выводим
		p = p->next;//переход к следующему
	}
}
//функция для изменения списка в соответствии с заданием
void result(list*& h, list*& t) {
	list* k = NULL;
	list* q = NULL;
	list* p = h;//указатель на голову
	while (p) {//пока не дошли до конца списка
		//		list* k = p->next; //сохраняем указатель на следующий элемент
		if (p->inf % 2 != 0) {
			if (!k) {
				k = p;
			}
			q = p;
		}
		p = p->next;
	}
			del_node(h, t, k); 
			del_node(h, t, q);
	}

int main() {
	int n, y;
	//инициализируем список
	list* h = NULL;
	list* t = NULL;
	cout << "n= ";
	cin >> n;//вод количества элементов
	for (int i = 0; i < n; i++) { //ввод самих элементов
		cin >> y;
		push(h, t, y); //добавление элемента в стек
	}
	result(h, t);
	print(h, t);//выводим полученный список
	return 0;
}