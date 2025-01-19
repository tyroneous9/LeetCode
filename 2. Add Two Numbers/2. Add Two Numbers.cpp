/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

ex1
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

ex2
Input: l1 = [0], l2 = [0]
Output: [0]

ex3
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sum = new ListNode();
    ListNode* sumDigit = sum;
    int carry = 0;
    int num = 0;

    while (l1 != NULL || l2 != NULL) {
        num = carry;
        if (l1 != NULL) {
            num += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            num += l2->val;
            l2 = l2->next;
        }

        carry = num / 10;
        sumDigit->next = new ListNode(num % 10);
        sumDigit = sumDigit->next;
    }

    if (carry > 0) {
        sumDigit->next = new ListNode(carry);
    }

    return sum->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test case 1 (Example 1)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "Test Example 1:" << endl;
    ListNode* result1 = addTwoNumbers(l1, l2);
    printList(result1);

    // Clean up l1, l2, and result1
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (result1 != nullptr) {
        ListNode* temp = result1;
        result1 = result1->next;
        delete temp;
    }

    // Test case 2 (Example 2)
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(0);

    cout << "Test Example 2:" << endl;
    ListNode* result2 = addTwoNumbers(l3, l4);
    printList(result2);

    // Clean up l3, l4, and result2
    while (l3 != nullptr) {
        ListNode* temp = l3;
        l3 = l3->next;
        delete temp;
    }

    while (l4 != nullptr) {
        ListNode* temp = l4;
        l4 = l4->next;
        delete temp;
    }

    while (result2 != nullptr) {
        ListNode* temp = result2;
        result2 = result2->next;
        delete temp;
    }

    // Test case 3 (Example 3)
    ListNode* l5 = new ListNode(9);
    l5->next = new ListNode(9);
    l5->next->next = new ListNode(9);
    l5->next->next->next = new ListNode(9);
    l5->next->next->next->next = new ListNode(9);
    l5->next->next->next->next->next = new ListNode(9);
    l5->next->next->next->next->next->next = new ListNode(9);

    ListNode* l6 = new ListNode(9);
    l6->next = new ListNode(9);
    l6->next->next = new ListNode(9);
    l6->next->next->next = new ListNode(9);

    cout << "Test Example 3:" << endl;
    ListNode* result3 = addTwoNumbers(l5, l6);
    printList(result3);

    // Clean up l5, l6, and result3
    while (l5 != nullptr) {
        ListNode* temp = l5;
        l5 = l5->next;
        delete temp;
    }

    while (l6 != nullptr) {
        ListNode* temp = l6;
        l6 = l6->next;
        delete temp;
    }

    while (result3 != nullptr) {
        ListNode* temp = result3;
        result3 = result3->next;
        delete temp;
    }

    return 0;
}
