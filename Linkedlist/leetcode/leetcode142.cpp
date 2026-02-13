#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

// Helper function to create a cycle in the linked list
ListNode* createCycleList(vector<int> vals, int pos) {
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = NULL;

    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) cycleNode = curr;
    }

    if (pos == 0) cycleNode = head;
    if (cycleNode != NULL) {
        curr->next = cycleNode; // create cycle
    }

    return head;
}

int main() {
    Solution sol;

    // Testcase 1: list with cycle
    vector<int> vals1 = {3, 2, 0, -4};
    int pos1 = 1; // cycle at index 1 (node with value 2)
    ListNode* head1 = createCycleList(vals1, pos1);
    ListNode* ans1 = sol.detectCycle(head1);
    if (ans1) {
        cout << "Cycle detected at node with value: " << ans1->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    // Testcase 2: list without cycle
    vector<int> vals2 = {1, 2, 3};
    int pos2 = -1; // no cycle
    ListNode* head2 = createCycleList(vals2, pos2);
    ListNode* ans2 = sol.detectCycle(head2);
    if (ans2) {
        cout << "Cycle detected at node with value: " << ans2->val << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
