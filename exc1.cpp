#include <iostream>


class DinamicArr {

public:
    size_t capacity;
    size_t size;
    double* arr;
    static const size_t initial_capacity=2;

    DinamicArr() { //constructor
        capacity = initial_capacity;
        size=0;
        arr=new double[capacity];
    };

    DinamicArr(size_t size_, double elem) {
        size=size_;
        arr=new double[size_];
        for (int i=0; i<size ;++i) {
            arr[i]=elem;
        }
    };

    DinamicArr(const DinamicArr& rhs) {
        size=rhs.size;
        capacity=rhs.capacity;
        arr= new double[capacity];
        for (int i=0;i<size;++i) {
            arr[i]=rhs.arr[i];
        }
    };

    ~DinamicArr() { // destructor
        delete[] arr;
    };

    void push_back(double l) {
        if (capacity==size) {
            capacity =2;
            double* arr_new=new double[capacity];
            for(int i=0;i<size;++i) {
                arr_new[i]=arr[i];
            }
            delete[] arr;
            arr=arr_new;
        }
        arr[size]=l;
    };
    double operator[](const int index) const {
        if (index < 0 || index >= size())
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

    double& operator[](int index) {
        if (index < 0 || index >= size()) {
            std::cout << size << " " << index;
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }


    DinamicArr &operator=(const DinamicArr &rhs) {
        if (this == &rhs)
            return *this;
        size = rhs.size();
        delete[] arr;
        arr = new double[rhs.capacity()];
        for (int i = 0; i < rhs.size(); ++i) {
            arr[i] = rhs[i];
        }
        return *this;
    }

};


int main() {
    return 0;
}