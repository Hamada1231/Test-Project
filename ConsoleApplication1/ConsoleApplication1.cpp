
#include <iostream>
using namespace std;
class linkedlist {
    struct node {
        int item;
        node* next;





    };
    node* first, * last;
    int length;
public:
    linkedlist() {
        first = NULL;
        last = NULL;
        length = 0;

    }
    bool isempty() { return length == 0; }
    void insertfirst(int element) {
        node* newnode = new node;
        newnode->item = element;
        if (length == 0)
        {
            first = last = newnode;
            newnode->next = NULL;
            length++;

        }
        else {
            newnode->next = first;
            first = newnode;
            length++;


        }

    }
    void insertlast(int element) {
        node* newnode = new node;
        newnode->item = element;
        if (length == 0)
        {
            first = last = newnode;
            newnode->next = NULL;
            length++;

        }
        else {
            node* cur = first;
            for (int i = 1;i < length;i++)
                cur = cur->next;
            cur->next = newnode;
            newnode->next = NULL;
            last = newnode;
            length++;

        }
        


    }
    void insertpos(int pos,int element) {
        node* newnode = new node;
        if (pos<0 || pos>length)
            cout << "out of range" << endl;
        else if (pos == 0) {
            insertfirst(element);
            length++;
        }
        else if (pos == length) {

            insertlast(element);
            length++;
        }
        else {
            node* cur = first;
            newnode->item = element;
            for (int i = 1;i < pos;i++) {
                cur = cur->next;

            }
            cur->next = newnode;
            newnode->next = cur->next;
            length++;

        }

    }
    void print() {
        node* cur1 = first;
        while (cur1 != NULL) {
            cout << cur1->item << " ";
            cur1= cur1->next;


        }



    }

    void removefirst() {

        if (isempty()) {

            cout << " is empty" << endl;
        }
        else {
            node* cur = first;
            first = first->next;
            delete cur;
            length--;

        }
    }
    void removelast() {
        if (isempty()) {

            cout << " is empty" << endl;
        }

        else {
            node* cur=first->next, *pre=first;
            while (cur != last) {
                pre = cur;
                cur = cur->next;

            }
            delete cur;
            pre->next = NULL;
            last = pre;
            
            length--;


        }

    }
    void removepos(int element) {
        node* cur , * pre;
        if (isempty()) {

            cout << " is empty" << endl;
        }
        if (first->item ==element) {
            cur = first;
            first = first->next;
            delete cur;
            length--;


        }
        else {
            pre = first;
            cur = first->next;
            while (cur != NULL) {
                if (cur->item == element)
                    break;
                pre = cur;
                cur = cur->next;
            }
                
                if (cur == NULL) {
                    cout << "notfound" << endl;
                }
                else {
                    pre->next = cur->next;
                    if (cur = last)
                        last = pre;
                    delete cur;
                    length--;
                }

            }

        }
    void reverse() {
        node* pre = NULL;
        node* cur = first;
        node* next = cur->next;
        while (cur != NULL || next != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            


        }
        first = pre;


    }
    int search(int element) {
        node* cur = first;
        int pos = 0;
        while (cur != NULL) {
            if (cur->item == element)
                return pos;
            cur = cur->next;
            pos++;

        }
            
        



    }

    
};
  

int main()
{
    linkedlist l;
    l.insertfirst(1);
    l.insertfirst(2);
    l.insertlast(3);
    l.insertpos(0, 0);
    l.insertfirst(10);
   cout<<l.search(3)<<endl;
    l.print();
}
