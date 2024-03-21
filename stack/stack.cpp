#include <iostream>

using namespace std;


struct Stack {
    int len;
    int* data;
    int top;
};

void resizeStack(Stack& s, int l = 10);


void deleteStack(Stack& s) {
    if (s.data == NULL) delete s.data;
    s.data = NULL;
    s.len = 0;
    s.top = -1;
}

bool stack_is_empty(Stack& s) {
    return s.len == 0;
}

void newStack(Stack& s1, int len) {
    if (len < 0) throw - 1;
    s1.len = len;
    s1.top = -1;
    if (len == 0) s1.data = NULL;
    else {
        s1.data = new int[len];
    }
}

Stack newStack(int l) {
    if (l == 0) throw -1;
    Stack res;
    newStack(res, l);
    return res;
}

void pushStack(Stack& s, int  e) {
    (s.top)++;
    if (s.top >= s.len) resizeStack(s);
    s.data[s.top] = e;
}

int pull_stack(Stack& s) {
    if (stack_is_empty(s)) throw - 1;
    s.top--;
    return s.data[s.top + 1];
}

int stack_top(Stack s) {
    if (stack_is_empty(s)) throw - 1;
    return s.data[s.top];
}

void copyStack(Stack& s, Stack& new_s) {
    if (s.top >= new_s.len)
        resizeStack(new_s, s.top + 1 - new_s.len);
    new_s.top = s.top;
    for (int i = 0; i <= s.top; ++i) {
        new_s.data[i] = s.data[i];
    }
}
void resizeStack(Stack& s, int l) {
    Stack res = newStack(s.len + l);
    copyStack(s, res);
    deleteStack(s);
    s = res;
}


int main() {
    Stack s = newStack(1);
    pushStack(s, 2);
    pushStack(s, 4);
    pushStack(s, 1);
    pushStack(s, 3);
    Stack new_s = newStack(1);
    while(s.top!=-1){
        int x = pull_stack(s);
        cout<< x << " ";
        pushStack(new_s, x);
    }
    Stack new_s2 = newStack(1);
    cout<< '\n';
    while(new_s.top!=-1) {
        int x = pull_stack(new_s);
        cout << x << " ";
        pushStack(new_s2, x);
    }
    cout << "\n";
    while(new_s2.top != -1) {
        int x = pull_stack(new_s2);
        cout << x << " ";
    }
}