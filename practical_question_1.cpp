// practiced constructing circular linked list using singly linked list
#include<iostream>

using namespace std;

struct node {
    string data;
    node* next = NULL;
};

struct it {
    private:
        node* ptr;

    public:
        it(node* p) : ptr(p) {}

        string& operator*() {return ptr->data;}
        node* get() {return ptr;}

        it& operator++() {
            ptr = ptr->next;
            return *this;
        }

        it operator++(int) {
            auto temp = *this;
            ptr = ptr->next;
            return temp;
        }

        friend bool operator==(const it& left, const it& right) {
            return left.ptr == right.ptr;
        }

        friend bool operator!=(const it& left, const it& right) {
            return left.ptr != right.ptr;
        }
};

class CircLL {
    private:
        node* head = NULL;

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
            node* temp = head;
            if(head) {
                head = head->next;
                delete temp;
            }
        }

        string current() {
            if(head)
                return head->data;
        }

        string next() {
            if(head) {
                node* last = head;
                while(last->next != end()) {
                    last = last->next;
                }
                last->next = head;
                node* temp = head;
                head = head->next;
                temp->next = NULL;
                return head->data;
            }
        }

        string previous() {
            if(head) {
                node* last = head;
                while(last->next != end()) {
                    last = last->next;
                }
                last->next = head;
                head = last;

                last = head->next;
                while(last->next != head) {
                    last = last->next;
                }
                last->next = NULL;

                return head->data;
            }
        }

        void printall() {
            for(it i = begin(); i != end(); i++) {
                cout << i.get()->data << endl;
            }
            cout << endl;
        }

        void insert(int index, string val) {
            if(size() == 0) index = 0;
            else index %= size();

            for(int i = 0; i < index; i++) {
                next();
            }

            push_front(val);

            for(int i = 0; i < index; i++) {
                previous();
            }                       
        }

        void remove(int index) {
            if(size() == 0) {
                cout << "Playlist is already empty" << endl;
                return;
            }

            index %= size();

            for(int i = 0; i < index; i++) {
                next();
            }

            pop_front();

            for(int i = 0; i < index; i++) {
                previous();
            }                       
        }

        int size() {
            node* temp = head;
            int count = 0;
            while(temp != end()) {
                count++;
                temp = temp->next;
            } 
            return count;
        }

        it begin() {return it(head);}
        it end() {return it(NULL);}    
};

int main() {

    CircLL playlist;

    playlist.push_front("Fix You - Coldplay");
    playlist.printall();

    playlist.push_front("Viva La Vida - Coldplay");
    playlist.printall();

    playlist.insert(1,"Yellow - Coldplay");
    playlist.printall();

    playlist.next();
    playlist.printall();

    playlist.next();
    playlist.printall();

    playlist.previous();
    playlist.printall();

    playlist.remove(1);
    playlist.printall();

    playlist.remove(4);
    playlist.printall();

    playlist.pop_front();
    playlist.printall();

    playlist.pop_front();
    playlist.printall();

    playlist.remove(10);
    playlist.printall();
    return 0;
}