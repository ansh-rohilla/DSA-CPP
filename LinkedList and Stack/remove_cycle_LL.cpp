#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // No cycle
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // Step 2: Find starting point of cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;  // start of cycle
    }
};

int main() {
    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ↑         |
    //           |_________|

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating cycle (5 -> 3)
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}