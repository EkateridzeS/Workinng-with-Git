#include<iostream>
using namespace std;

struct queue {
    int inf;
    queue* next;
};

void push(queue*& h, queue*& t, int x) {
    queue* r = new queue; 
    r->inf = x;
    r->next = NULL;
    if (!h && !t) { 
        h = t = r; 
    }
    else {
        t->next = r; 
        t = r;
    }
}

int pop(queue*& h, queue*& t) {
    int i = h->inf; 
    queue* r = h;
    h = h->next;
    if (!h) 
        t = NULL;
    delete r; 
    return i;
}


bool Pr(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void result(queue*& h, queue*& t) {
    queue* h_S = NULL, * t_S = NULL;
    int x;

    while (h && t) {

        x = pop(h, t);
        if (Pr(x)) {

            push(h_S, t_S, x);
            break;
        }
        else {
            push(h, t, x);

        }
    }

    while (h) {
        push(h_S, t_S, pop(h, t));
    }

    while (h_S) {
        push(h, t, pop(h_S, t_S));
    }
}

int main() {
    queue* h = NULL, * t = NULL;
    int n, x;
    cout << "n="; cin >> n;
    cout << "Input element\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }
    
    result(h, t); cout << "New queue\n";
    while (h && t) 
        cout << pop(h, t) << " ";
    return 0;
}
