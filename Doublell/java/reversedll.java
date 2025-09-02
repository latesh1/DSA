import java.util.*;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int data1, Node next1, Node prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = null;
        prev = null;
    }
}

public class reversedll {

    static Node reverseDll(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node prev = null;
        Node current = head;
        while (current != null) {
            prev = current.prev;
            current.prev = current.next;
            current.next = prev;
            current = current.prev;
        }
        return prev.prev;
    }

    // Function to build a doubly linked list from list
    static Node buildDLL(List<Integer> arr) {
        if (arr.isEmpty()) return null;
        Node head = new Node(arr.get(0));
        Node curr = head;
        for (int i = 1; i < arr.size(); i++) {
            Node temp = new Node(arr.get(i));
            curr.next = temp;
            temp.prev = curr;
            curr = temp;
        }
        return head;
    }

    // Function to print doubly linked list
    static void print(Node head) {
        Node curr = head;
        while (curr != null) {
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(12, 5, 8, 7);
        Node head = buildDLL(arr);

        System.out.print("Original DLL: ");
        print(head);

        head = reverseDll(head);

        System.out.print("Reversed DLL: ");
        print(head);
    }
}
