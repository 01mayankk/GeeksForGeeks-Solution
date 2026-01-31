class kQueues {
private:
    int *arr;        // main array to store elements
    int *front;      // front index of each queue
    int *rear;       // rear index of each queue
    int *next;       // next index (for queue linking & free list)
    int freeSpot;    // first free index
    int n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // Enqueue x into i-th queue
    void enqueue(int x, int i) {
        // If array is full
        if (freeSpot == -1) return;

        // Get free index
        int index = freeSpot;
        freeSpot = next[index];

        // First element in queue
        if (front[i] == -1) {
            front[i] = index;
        } else {
            next[rear[i]] = index;
        }

        next[index] = -1;
        rear[i] = index;
        arr[index] = x;
    }

    // Dequeue from i-th queue
    int dequeue(int i) {
        if (front[i] == -1) {
            return -1;
        }

        int index = front[i];
        front[i] = next[index];

        // If queue becomes empty
        if (front[i] == -1) {
            rear[i] = -1;
        }

        // Add freed index back to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Check if i-th queue is empty
    bool isEmpty(int i) {
        return front[i] == -1;
    }

    // Check if array is full
    bool isFull() {
        return freeSpot == -1;
    }
};
