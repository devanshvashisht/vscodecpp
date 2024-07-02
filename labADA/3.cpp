#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        this->head = NULL;
    }
    void takeInput()
    {
        
        Node *tail = NULL;
        int data;
        cout << "Enter the data" << endl;
        cin >> data;
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
            cout << "enter the data" << endl;
            cin >> data;
        }
        
    }

    void printLL()
    {
        Node *temp =head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void insertNode(int data, int pos)
    {
        int size = 0;
        Node *temp1 = head;

        Node *newNode = new Node(data);
        int count = 0;
        Node *temp = head;
        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            
        }
        while (count < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            Node *a = temp->next;
            temp->next = newNode;
            newNode->next = a;
        }
        
    }
    int findPos(int element)
    {
        int count = 0;
        Node *temp = head;
        while (temp->data != element && temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (temp->data == element)
        {
            return count;
        }
        return -1;
    }
    void deleteNode(int i)
    {
        int count = 0;
        Node *temp = head;
        if (i == 0)
        {
            Node *rough = temp;
            head = temp->next;
            delete rough;
            
        }
        while (count < i - 1 && temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *a = temp->next;
            Node *b = a->next;
            temp->next = b;
            delete a;
        }
        
    }
};

int main(){
    LinkedList L1;
    L1.takeInput();
    L1.printLL();
    int data , pos;
    cout << "enter the data" << endl;
    cin >> data;
    cout << "Enter the position " << endl;
    cin >> pos;
    L1.insertNode(data,pos);
    L1.printLL();
    int val;
    cout << "Enter the element you want to find" << endl;
    cin>> val;
    int ans = L1.findPos(val);
    cout << ans << endl;


}p;