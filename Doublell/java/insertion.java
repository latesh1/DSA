import java.util.*;

class Node {
    int data;
    Node next;
    Node back;

    Node(int data1, Node next1, Node back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = null;
        back = null;
    }
}

public class insertion {

    static Node convertarrtodll(List<Integer> arr) {
        Node head = new Node(arr.get(0));
        Node prev = head;
        for (int i = 1; i < arr.size(); i++) {
            Node temp = new Node(arr.get(i), null, prev);
            prev.next = temp;
            prev = temp;
        }
        return head;
    }

    static void print(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    static Node deleteHead(Node head) {
        if (head == null || head.next == null) {
            return null;
        }
        Node prev = head;
        head = head.next;
        head.back = null;
        prev.next = null;
        return head;
    }

    static Node deleteTail(Node head) {
        if (head == null || head.next == null) {
            return null;
        }
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        Node newtail = tail.back;
        newtail.next = null;
        tail.back = null;
        return head;
    }

    static Node deletek(Node head, int k) {
        if (head == null) return null;

        int cnt = 0;
        Node knode = head;
        while (knode != null) {
            cnt++;
            if (cnt == k) break;
            knode = knode.next;
        }

        if (knode == null) return head;

        Node prev = knode.back;
        Node front = knode.next;

        if (prev == null && front == null) {
            return null;
        } else if (prev == null) {
            return deleteHead(head);
        } else if (front == null) {
            return deleteTail(head);
        }

        prev.next = front;
        front.back = prev;
        knode.next = null;
        knode.back = null;
        return head;
    }

    static void deleteNode(Node temp) {
        Node prev = temp.back;
        Node front = temp.next;
        if (front == null) {
            prev.next = null;
            temp.back = null;
            return;
        }
        prev.next = front;
        front.back = prev;
        temp.next = null;
        temp.back = null;
    }

    static Node insertbeforehead(Node head, int val) {
        Node newHead = new Node(val, head, null);
        head.back = newHead;
        return newHead;
    }

    static Node insertBeforeTail(Node head, int val) {
        if (head.next == null) {
            return insertbeforehead(head, val);
        }
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
        }
        Node prev = tail.back;
        Node newNode = new Node(val, tail, prev);
        prev.next = newNode;
        tail.back = newNode;
        return head;
    }

    static Node insertbeforekthelement(Node head, int k, int val) {
        if (k == 1) {
            return insertbeforehead(head, val);
        }
        Node temp = head;
        int cnt = 0;
        while (temp != null) {
            cnt++;
            if (cnt == k) break;
            temp = temp.next;
        }
        Node prev = temp.back;
        Node newNode = new Node(val, temp, prev);
        prev.next = newNode;
        temp.back = newNode;
        return head;
    }

    static void insertBeforeNode(Node node, int val) {
        Node prev = node.back;
        Node newNode = new Node(val, node, prev);
        prev.next = newNode;
        node.back = newNode;
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(12, 5, 8, 7);
        Node head = convertarrtodll(arr);

        // head = deleteHead(head);
        // head = deleteTail(head);
        // head = deletek(head, 4);
        // head = insertbeforehead(head,10);
        // head = insertBeforeTail(head,10);
        // head = insertbeforekthelement(head,1,10);
        insertBeforeNode(head.next, 100);
        print(head);
    }
}
