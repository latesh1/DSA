#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {
        // constructor
    }

    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // 1
    cout << "Popped element: " << q.pop() << endl; // 1
    cout << "Front element: " << q.peek() << endl; // 2
    cout << "Is Empty: " << q.empty() << endl;     // 0 (false)

    q.pop();
    q.pop();

    cout << "Is Empty after popping all elements: " << q.empty() << endl; // 1 (true)

    return 0;
}
