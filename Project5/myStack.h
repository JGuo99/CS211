
template<class T>
class stack {
private:
    T *data;
    int capacity;
    int size;

    void resize();

    bool needResize();

public:
    //initialize stack (constructor)
    stack() {
        capacity = 5;
        data = new T[capacity];
        size = 0;
    }

    void push(T item);

    T pop();

    bool isEmpty();

    void reset();

    T top(); //keep track of top element
};

template<class T>
void stack<T>::push(T item) {
    if (needResize()) {
        resize();
    }
    data[size++] = item;
}

template<class T>
T stack<T>::pop() {
    if (capacity <= 0) return -1;
    return data[--size];
}

template<class T>
bool stack<T>::needResize() {
    return (size == capacity);
}

template<class T>
void stack<T>::resize() {
    T *newdata = new T[2 * capacity];
    for (int i = 0; i < capacity; i++) {
        newdata[i] = data[i];
    }
    data = newdata;
    capacity *= 2;
}

template<class T>
bool stack<T>::isEmpty() {
    return (size == 0);
}

template<class T>
void stack<T>::reset() {
    delete[] data;
    size = 0;
    capacity = 5;
    data = new T[capacity];
}

template<class T>
T stack<T>::top() {
    if (!isEmpty())
        return data[size - 1];
    return -1;
}


