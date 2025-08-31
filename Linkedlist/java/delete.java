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


public class delete {
   private static  Node convertarrtolink(int[] arr){
    Node head = new Node (arr[0]);
     Node mover = head;
     for(int i =1;i<arr.length;i++){
        Node temp = new Node(arr[i]);
        mover.next = temp;
        mover=temp;
     }  
     return head;
}
private static void print(Node head){
  while(head!=null){
    System.out.print(head.data+" ");
    head = head.next;
  }
  System.out.println();
}

private static Node removesHead(Node head){
    if(head==null)return head;
    head = head.next;
    return head;
}
    public static void main(String[] args) {
        int[] arr = {2, 5, 6, 8};
        Node head = convertarrtolink(arr);
        // System.out.print(head.data);
    //        Node temp = head;
    // while(temp !=null){
    //     System.out.print(temp.data+ " ");
    //     temp=temp.next;
    // }
    head = removesHead(head);
    print(head);
    }
}
