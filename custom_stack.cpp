#include <iostream>
#include <stack>

using namespace std;

void EnQueue(stack<int> &s1, stack<int> &s2, int val) {

    if (s1.empty() ) {
        s1.push(val);
        return;
    }

    if (!s1.empty() || s2.empty()) {
        s1.push(val);
    }
    cout << "Value inserted in Queue : " << val << endl;
}

int DeQueue(stack<int> &s1, stack<int> &s2) {

    if (s2.empty()) {
        while(!s1.empty()) {
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }
    }

    int result = s2.top();
    cout << "Poped :" << result << endl;
    s2.pop();
    return result;
}



int main(){

    stack<int> s1;
    stack<int> s2;

    EnQueue(s1,s2,1);
    EnQueue(s1,s2,2);
    EnQueue(s1,s2,3);
    DeQueue(s1,s2);



    cout << "Welcome to queue implementation by using stacks";
    return 0;
}
