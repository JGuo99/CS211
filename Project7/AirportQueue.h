class Stack{
    private:
        MyNODE *top;
    public:
        Stack(){
            top = NULL;
        }

        // A utility function to create a new linked list node.
        MyNODE* newNode(int k) {
            // MyNODE *tmp = (MyNODE *)malloc(sizeof(MyNODE));
            // tmp->airport = k;
            // tmp->next = NULL;
            MyNODE *tmp = new MyNODE(k, NULL);
            return tmp;
        }

        void push(int k){
            MyNODE *tmp = newNode(k);

            if (top == NULL){
                top = tmp;
            }else{
                tmp->next = top;
                top = tmp;
            }
        }

        MyNODE *pop(){
            if (top == NULL){
                // stack empty
                return NULL;
            }
            MyNODE *tmp = top;
            top = top->next;
            return tmp;
        }

        bool isEmpty(){
            return top == NULL;
        }
};

class AirportQueue{
    private:
        MyNODE *front, *rear;
    public:
    AirportQueue(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    // A utility function to create a new linked list node.
    MyNODE* newNode(int k) {
        MyNODE *tmp = (MyNODE *)malloc(sizeof(MyNODE));
        tmp->airport = k;
        tmp->next = NULL;
        return tmp;
    }

    // The function to add a key k to q
    void enQueue(int k){
        // Create a new LL node
        MyNODE *tmp = newNode(k);

        // If queue is empty, then new node is front and rear both
        if (rear == NULL) {
           front = rear = tmp;
           return;
        }

        // Add the new node at the end of queue and change rear
        rear->next = tmp;
        rear = tmp;
    }

    MyNODE * deQueue() {
        // If queue is empty, return NULL.
        if (front == NULL)
           return NULL;

        // Store previous front and move front one node ahead
        MyNODE *tmp = front;
        front = front->next;
      
        // If front becomes NULL, then change rear also as NULL
        if (front == NULL)
           rear = NULL;
        return tmp;
    }
};


// // A utility function to create an empty queue
// struct Queue *createQueue()
// {
//     struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
//     q->front = q->rear = NULL;
//     return q;
// }

// Function to remove a key from given queue q
