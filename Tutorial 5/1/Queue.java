// Queue.java

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() {
        data = (T[]) new Object[MAX_CAPACITY];
        head = 0;
        tail = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) {
        this.data = (T[]) new Object[MAX_CAPACITY];
        head = 0;
        tail = data.length;
        for (int i = 0; i < data.length; i++) {
            this.data[i] = data[i];
        }
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() {
        if (head == tail) {
            return null;
        }
        return data[head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() {
        if (head == tail) {
            return null;
        }
        T element = data[head];
        head++;
        return element;
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) {
        if (tail < MAX_CAPACITY) {
            data[tail] = o;
            tail++;
        }
    }

    // Menghitung panjang queue.
    public int size() {
        return tail - head;
    }

    // Getter attribute
    public T[] getData() {
        return data;
    }
    public int getHead() {
        return head;
    }
    public int getTail() {
        return tail;
    }

    // public static void main(String[] args) {
    //     Queue<Integer> queue = new Queue<>();
    //     queue.push(1);
    //     queue.push(2);
    //     queue.push(3);
    //     System.out.println("Peek: " + queue.peek()); 
    //     System.out.println("Pop: " + queue.pop());
    //     System.out.println("Pop: " + queue.pop());
    //     System.out.println("Size: " + queue.size());
    //     System.out.println("Peek: " + queue.peek()); 

    //     Queue<Integer> queue2 = new Queue<>(new Integer[]{4, 5, 6});
    //     queue2 = queue;
        
    //     System.out.println("Peek: " + queue2.peek());
    // }
}