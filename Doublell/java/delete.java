class Node {
    int data;
    Node next;
    Node back;

    Node(int data1, Node next1, Node back1) {
        this.data = data1;
        this.next = next1;
        this.back = back1;
    }

    Node(int data1) {
        this.data = data1;
        this.next = null;
        this.back = null;
    }
}

public class delete {
    private static void print(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    private static Node convertarrtodl(int[] arr) {
        Node head = new Node(arr[0]);
        Node prev = head;
        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i], null, prev);
            prev.next = temp;
            prev = temp;
        }
        return head;
    }

    private static Node deleteHead(Node head) {
        if (head == null || head.next == null) {
            return null;
        }
        Node prev = head;
        head = head.next;
        head.back = null;
        prev.next = null;
        // In Java, we don't use "delete" (garbage collector handles it)
        return head;
    }
    private static Node deleteTail(Node head){
    if(head==null || head.next==null){
        return null;
    }
    Node tail = head;
    while(tail.next!=null){
        tail=tail.next;
    }
    Node newtail = tail.back;
    newtail.next = null;
    tail.back=null;

    return head;
}

    public static void main(String[] args) {
        int[] arr = {12, 5, 6, 8};
        Node head = convertarrtodl(arr); 
        head = deleteTail(head);       
        print(head);                  
    }
}
