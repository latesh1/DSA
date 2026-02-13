#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        // constructor
    }

    void push(int x) {
        q.push(x);
        // Rotate the queue to make last pushed element at front
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;   // 30
    cout << "Pop: " << st.pop() << endl;   // 30
    cout << "Top: " << st.top() << endl;   // 20
    cout << "Is Empty: " << st.empty() << endl; // 0 (false)

    st.pop();
    st.pop();

    cout << "Is Empty after popping all elements: " << st.empty() << endl; // 1 (true)

    return 0;
}
