#include <iostream>
using namespace std;

struct stack {
    char inf;
    stack* next;
};

void push(stack*& h, char x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

char pop(stack*& h) {
    char i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

void reverse(stack*& h) {
    stack* head1 = NULL;
    while (h) {
        push(head1, pop(h));
    }
    h = head1;
}

bool isVowel(char k) {
    return k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u';
}

void B(stack*& h) {
    stack* GL = NULL;
    stack* SOGL = NULL;

    while (h) {
        char c = pop(h);
        if (!isVowel(c)) {
            push(SOGL, c);
        }
        else {
            push(GL, c);
        }
    }

    reverse(SOGL);
    reverse(GL);

    while (SOGL) {
        push(h, pop(SOGL));
    }

    while (GL) {
        push(h, pop(GL));
    }
}

int main() {
    stack* h = NULL;
    int n;

    cout << "Enter the number of characters: ";
    cin >> n;

    

    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        push(h, x);
    }

    B(h);

    

    while (h) {
        cout << pop(h) << " ";
    }

    return 0;
}
