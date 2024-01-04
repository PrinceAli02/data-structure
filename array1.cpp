// this code is taken from the book C++ Data Structure and Algorithm Design Principles

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class dynamic_array {
    private:
        T* data;
        size_t n;

    public:
        dynamic_array(int n) {
            this->n;
            data = new T[n];
        }

        dynamic_array(const dynamic_array<T>& other) {
            n = other.n;
            data = new T[n];

            for(int i = 0; i < n; i++) {
                data[i] = other[i];
            }
        }

        T& operator[](int index) {
            return data[index];
        }

        const T& operator[](int index) const {
            return data[index];
        }

        T& at(int index) {
            if(index < n) {
                return data[index];
            }
            throw "Index out of range";
        }

        size_t size() const {
            return n;
        }

        ~dynamic_array() {
            delete[] data;
        }

        T* begin() {return data;}
        const T* begin() const {return data;}
        T* end() {return data+n;}
        const T* end() const {return data+n;}

        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
            dynamic_array<T> result(arr1.size() + arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin());
            copy(arr2.begin(), arr2.end(), result.begin()+arr1.size());
            return result;
        }

        string to_string(const string& sep = ", ") {
            if(n == 0) return "";

            ostringstream os;
            os << data[0];

            for(int i = 1; i < n; i++) {
                os << sep << data[i];
            }
            
            return os.str();
        }
};

struct student {
    string name;
    int age;
};

ostream& operator<<(std::ostream& os, const student& s) {
    return(os << "[" << s.name << "," << s.age << "]");
}

int main() {
    int nStudents;
    cout << "Enter the number of students in class A: ";
    cin >> nStudents;

    dynamic_array<student> classA(nStudents);
    for(int i = 0; i < nStudents; i++) {
        cout << "hi";
        string name;
        int age;
        cout << "Enter student no. " << i+1 <<"'s name and age: ";
        student temp;
        temp.name = name;
        temp.age = age;
        classA[i] = temp; 
    }

    try {
        student temp;
        temp.name = "A";
        temp.age = 1;
        classA[nStudents] = temp;
    }
    catch (...) {
        cout << "Exception!" << endl;
    }

    auto classB = classA;
    cout << "copy classA to classB: " << classB.to_string() << endl;
    auto classC = classA+classB;
    cout << "combine classA and classB: " << classC.to_string() << endl;

//practicing git
// yeah changed branch

    return 0;
}