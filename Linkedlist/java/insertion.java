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

public class insertion {

    // Convert array to linked list
    static Node convertarrtolink(int[] arr) {
        Node head = new Node(arr[0]);
        Node mover = head;
        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]);
            mover.next = temp;
            mover = temp;
        }
        return head;
    }

    // Remove Tail
    static Node removeTail(Node head) {
        if (head == null || head.next == null) return null;
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
        return head;
    }

    // Print Linked List
    static void print(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    // Remove Head
    static Node removesHead(Node head) {
        if (head == null) return head;
        return head.next;
    }

    // Remove Kth Node
    static Node removeK(Node head, int k) {
        if (head == null) return head;
        if (k == 1) {
            return head.next;
        }
        int cnt = 0;
        Node temp = head;
        Node prev = null;
        while (temp != null) {
            cnt++;
            if (cnt == k) {
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }

    // Remove Element by value
    static Node removeelement(Node head, int el) {
        if (head == null) return head;
        if (head.data == el) {
            return head.next;
        }
        Node temp = head;
        Node prev = null;
        while (temp != null) {
            if (temp.data == el) {
                prev.next = prev.next.next;
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        return head;
    }

    // Insert at head
    static Node insertHead(Node head, int val) {
        Node temp = new Node(val, head);
        return temp;
    }

    // Insert at tail
    static Node inserttail(Node head, int val) {
        if (head == null) {
            return new Node(val);
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        Node newNode = new Node(val);
        temp.next = newNode;
        return head;
    }

    // Insert at position k
    static Node insertPosition(Node head, int el, int k) {
        if (head == null) {
            if (k == 1) {
                return new Node(el);
            } else {
                return head;
            }
        }
        if (k == 1) {
            return new Node(el, head);
        }
        int cnt = 0;
        Node temp = head;
        while (temp != null) {
            cnt++;
            if (cnt == (k - 1)) {
                Node x = new Node(el, temp.next);
                temp.next = x;
                break;
            }
            temp = temp.next;
        }
        return head;
    }

    // Insert before a given value
    static Node insertbeforevalue(Node head, int el, int val) {
        if (head == null) {
            return null;
        }
        if (head.data == val) {
            Node newNode = new Node(el);
            newNode.next = head;
            return newNode;
        }
        Node temp = head;
        while (temp.next != null) {
            if (temp.next.data == val) {
                Node newNode = new Node(el);
                newNode.next = temp.next;
                temp.next = newNode;
                return head;
            }
            temp = temp.next;
        }
        return head;
    }

    // Main function to test
    public static void main(String[] args) {
        int[] arr = {2, 5, 6, 8};
        Node head = convertarrtolink(arr);

        System.out.print("Original List: ");
        print(head);

        head = insertHead(head, 20);
        System.out.print("After Insert Head 20: ");
        print(head);

        head = inserttail(head, 99);
        System.out.print("After Insert Tail 99: ");
        print(head);

        head = insertPosition(head, 50, 3);
        System.out.print("After Insert 50 at Position 3: ");
        print(head);

        head = insertbeforevalue(head, 15, 6);
        System.out.print("After Insert 15 before 6: ");
        print(head);

        head = removesHead(head);
        System.out.print("After Remove Head: ");
        print(head);

        head = removeTail(head);
        System.out.print("After Remove Tail: ");
        print(head);

        head = removeK(head, 2);
        System.out.print("After Remove 2nd Node: ");
        print(head);

        head = removeelement(head, 15);
        System.out.print("After Remove Element 15: ");
        print(head);
    }
}
