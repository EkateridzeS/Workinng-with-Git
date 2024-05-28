#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};


void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}


void del_node(list*& h, list*& t, list* r) {
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h) {
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}


void print(list* h) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}


void bubbleSort(list*& h, list*& t) {
    bool swapped;
    list* current;
    list* end = NULL;

    do {
        swapped = false;
        current = h;

        while (current->next != end) {
            if (current->inf > current->next->inf) {
                
                list* temp = current->next;
                if (current == h) {
                    h = temp;
                }
                else {
                    current->prev->next = temp;
                }
                current->next = temp->next;
                temp->prev = current->prev;

                if (current->next) {
                    current->next->prev = current;
                }
                else {
                    t = current; 
                }

                temp->next = current;
                current->prev = temp;
                swapped = true;
            }
            else {
                current = current->next;
            }
        }
        end = current; 
    } while (swapped);
}

int main() {
    int n, y;
    list* h = NULL;
    list* t = NULL;

    cout << "n= ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> y;
        push(h, t, y);
    }


    bubbleSort(h, t);

    
    print(h);

    return 0;
}
