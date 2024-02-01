// Shared printer printing list simulation

#include<iostream>
#include<queue>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Job {
    private:
        int task_id;
        string user;
        int page_count;
    
    public:
        Job(int t, string u, int p) : task_id(t), user(u), page_count(p) {};
        void print() {
            cout << "Task ID: " << task_id << endl 
            << "Name: " << user << endl 
            << "Page Count: " << page_count << endl;
        }
};

class Printer {
    private:
        queue<Job> list;

    public:
        void addTask();
        void processTasks();
};

void Printer::addTask() {
    string n;
    cout << "Name: ";
    cin >> n;
    int pc;
    cout << "Page counts: ";
    cin >> pc;

    Job j(list.size()+1,n,pc);
    list.push(j);
    cout << "Prints ready to be printed." << endl << endl;
}

void Printer::processTasks() {
    if(list.size() == 0) {
        cout << "There is nothing to print." << endl << endl;
    }

    while(list.size() > 0) {
        cout << "The following print is getting printed: " << endl;
        list.front().print();
        sleep_for(seconds(2));
        list.pop();
        cout << "Printing complete!" << endl << endl;
    }
}

int main() {
    Printer p;
    while(true) {
        cout << "1 : Add Print" << endl
        << "2: Process Print(s)" << endl
        << "3: quit" << endl;
        string c;
        cin >> c;
        if(c == "1") {p.addTask();}
        else if(c == "2") {p.processTasks();}
        else if(c == "3") {break;}
        else {cout << "Wrong Input. Try again" << endl << endl;}
    }

    return 0;
}
