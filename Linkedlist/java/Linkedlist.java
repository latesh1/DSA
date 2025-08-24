class Node {
    int data;
    Node next;

    // Constructor with next pointer
    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1;
    }

    // Constructor without next pointer (defaults to null)
    Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}

public class Linkedlist {
    public static void main(String[] args) {
        int[] arr = {2, 5, 6, 8};
        Node y = new Node(arr[3]);  // creates a node with data = 8
        System.out.print(y.data);   // prints 8
    }
}
