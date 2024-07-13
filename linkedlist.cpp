#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeInput()
{
    int data;
    cout << "enter the data" << endl;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cout << "Enter the data" << endl;
        cin >> data;
    }
    return head;
}

int length(Node *head)
{
    int count = 0;
    if (head->next == NULL)
    {
        return 1;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    count++;
    return count;
}

void printIthNode(Node *head, int i)
{
    int len = length(head);
    int idx = 0;
    Node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (i >= len)
            {
                return;
            }
            else
            {
                if (idx == i)
                {
                    cout << temp->data << endl;
                    return;
                }
                else
                {
                    idx++;
                    temp = temp->next;
                }
            }
        }
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}
int findNode(Node *head, int n)
{
    int index = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return index;
        }
        else
        {
            index++;
            temp = temp->next;
        }
    }

    return -1;
}

Node *append(Node *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    int size = length(head);
    if (n >= size || n == 0)
    {
        return head;
    }
    int position = 1;
    Node *temp = head;
    while (position != size - n)
    {
        position++;
        temp = temp->next;
    }
    Node *x = temp->next;
    Node *a = temp->next;

    temp->next = NULL;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = head;
    return x;
}

Node *deleteNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;

    if (i == 0)
    {
        Node *rough = temp;
        head = temp->next;
        delete rough;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        temp->next = b;
        delete a;
    }
    return head;
}
Node *removeDuplicate(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            Node *a = temp->next;
            Node *b = a->next;
            temp->next = b;
            delete a;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt = curr->next;
    while (nxt != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = curr->next;
    }
    curr->next = prev;
    print(curr);
}
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverseLL(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

Node *midpoint(Node *head)
{
    int size = length(head);
    Node *slow = head;
    Node *fast = head->next;
    if (size % 2 != 0)
    {
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    else
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}

Node *reverse(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *nxt = current->next;
    while (nxt != NULL)
    {

        current->next = prev;
        prev = current;
        current = nxt;
        nxt = current->next;
    }
    return prev;
}
Node *mergeTwoLinkedList(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 != NULL && head2 == NULL)
    {
        return head1;
    }
    else if (head1 == NULL && head2 != NULL)
    {
        return head2;
    }
    Node *finalHead = NULL;
    Node *finalTail = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            if (finalHead == NULL)
            {
                finalHead = temp2;
                finalTail = temp2;
                temp2 = temp2->next;
            }
            else
            {
                Node *newnode = new Node(temp2->data);
                finalTail->next = newnode;
                finalTail = finalTail->next;
                temp2 = temp2->next;
            }
        }
        else
        {
            if (finalHead == NULL)
            {
                finalHead = temp1;
                finalTail = temp1;
                temp1 = temp1->next;
            }
            else
            {
                Node *newnode = new Node(temp1->data);
                finalTail->next = newnode;
                finalTail = finalTail->next;
                temp1 = temp1->next;
            }
        }
    }
    while (temp1 != NULL)
    {
        Node *newnode = new Node(temp1->data);
        finalTail->next = newnode;
        finalTail = finalTail->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        Node *newnode = new Node(temp2->data);
        finalTail->next = newnode;
        finalTail = finalTail->next;
        temp2 = temp2->next;
    }
    return finalHead;
}

Node *evenAfterOdd(Node *head)
{
    Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH = NULL;
    Node *evenT = NULL;
    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            if (oddH == NULL)
            {
                oddH = head;
                oddT = head;
                head = head->next;
            }
            else
            {
                Node *newnode = new Node(head->data);
                oddT->next = newnode;
                oddT = oddT->next;
                head = head->next;
            }
        }
        else
        {
            if (evenH == NULL)
            {
                evenH = head;
                evenT = head;
                head = head->next;
            }
            else
            {
                Node *newnode = new Node(head->data);
                evenT->next = newnode;
                evenT = evenT->next;
                head = head->next;
            }
        }
    }
    oddT->next = NULL;
    evenT->next = NULL;
    oddT->next = evenH;

    return oddH;
}
Node *skipMdeleteN(Node *head, int M, int N)
{
    if (N == 0)
    {
        return head;
    }
    if (M == 0)
    {
        return NULL;
    }

    int delNode = 0;
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (count == M)
        {
            while (delNode != N && temp -> next != NULL)
            {
                Node *a = temp->next;
                Node *b = a->next;
                temp->next = b;

                delete a;
                delNode++;
            }
            temp = temp -> next;
            count = 1;
            delNode = 0;
        } 
        else
        {
            temp = temp->next;
            count++;
        }
    }
    return head;
}

Node *rotate(Node *head, int k)
{
    
    int count = 0;
    while (count != k)
    {
        Node *start = head;
        Node *end = head;
        Node *prev = head;

        while (end->next != NULL)
        {
            end = end->next;
        }
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        end->next = start;
        prev->next = NULL;
        head = start;
        count++;
    }
    return head;
}
Node * swapNodes(Node * head, int i, int j){
    Node * p1 = head;
    Node * c1 = head;
    Node * p2 = head;
    Node * c2 = head;
    if(i==0 || j==0){
        
    }
}
int main()
{
    Node *head = takeInput();
    print(head);
    int m, n;
    cin >> m;
    cin >> n;
    Node *head1 = skipMdeleteN(head, m, n);
    print(head1);
}
