#include<iostream>

using namespace std;

struct node {
    string data;
    node* next = NULL;
};

class CircLL {
    private:
        node* head;

    public: 
        void push_front(string val) {
            node* temp = new node;
            temp->data = val;

            if(head != NULL) {
                temp->next = head;
            }
            head = temp;
        }

        void pop_front() {
            node* temp = this->head;
            if(head) {
                head = head->next;
                delete temp;
            }
        }

        node* get_head() {
            return head;
        }
        
};

int main() {

    CircLL playlist;

    playlist.push_front("1");
    playlist.push_front("2");





    playlist.pop_front();

    node* temp = playlist.get_head();
    cout << "deleted:  "<<temp->data << endl;
    temp = temp->next;
    
    cout << "what: " << temp->data << endl;

    // temp = playlist->get_head();
    

    cout << "f";


    return 0;
}