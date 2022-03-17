//
// Created by 熊文豪 on 2022/3/9.
//

#include <iostream>

template<typename T> class SeqList {
public:
    SeqList();

    explicit SeqList(int size);

    explicit SeqList(T values[]);

    void insert(int pos, T value);

    void insert(T value);

    T remove(int pos);

    T remove(T value);

    int search(T value);

    void set(int pos, T value);

    T get(int pos);

    int length();

    void print();

protected:
    int size{};
    T *data;
    int n{};
};

template<typename T>SeqList<T>::SeqList() {
    SeqList(16);
}

template<typename T>SeqList<T>::SeqList(int size) {
    this->size = size;
    this->n = 0;
    this->data = new T[size];
}

template<typename T>SeqList<T>::SeqList(T *values) {
    this(values->length * 2);
    for (int i = 0; i < values->size; i++) {
        this->data[i] = values[i];
    }
}

template<typename T>void SeqList<T>::insert(int pos, T value) {
    if (pos < 0 || pos > this->size) {
        std::cout << "pos is out of range" << std::endl;
        return;
    }
    if (this->n == this->size) {
        this->data = new T[this->size * 2];
    }
    for (int i = 0; i < pos; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->data[pos] = value;
    for (int i = pos; i < this->n; i++) {
        this->data[i + 1] = this->data[i + 2];
    }
    this->n++;
}

template<typename T>void SeqList<T>::insert(T value) {
    this->insert(this->size - 1, value);
}


template<typename T>T SeqList<T>::remove(int pos) {
    T x = this->data[pos];
    if (pos < 0 || pos > this->n) {
        std::cout << "pos is out of range" << std::endl;
        return -1;
    }
    for (int i = pos; i < this->n - 1; i++) {
        this->data[i] = this->data[i + 1];
    }
    this->n--;
    this->data[this->n] = 0;
    return x;
}

template<typename T>T SeqList<T>::remove(T value) {
    int pos = this->search(value);
    if (pos == -1) {
        std::cout << "value is not exist" << std::endl;
        return -1;
    }
    return this->remove(pos);
}

template<typename T>int SeqList<T>::search(T value) {
    for (int i = 0; i < this->n; i++) {
        if (this->data[i] == value) {
            return i;
        }
    }
    return -1;
}


template<typename T>void SeqList<T>::set(int pos, T value) {
    if (pos < 0 || pos > this->size) {
        std::cout << "pos is out of range" << std::endl;
        exit(0);
    }
    this->data[pos] = value;
}

template<typename T>T SeqList<T>::get(int pos) {
    return this->data[pos];
}

template<typename T>int SeqList<T>::length() {
    return this->n;
}

template<typename T>void SeqList<T>::print() {
    std::cout << "( ";
    for (int i = 0; i < this->n; i++) {
        std::cout << this->data[i] << " ";
    }
    std::cout << ")" << std::endl;
}
