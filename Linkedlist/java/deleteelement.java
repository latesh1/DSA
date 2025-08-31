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


public class deleteelement{
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
 private static Node removeTail(Node head){
    // c heck for single element in ll where head and tail are same 
    if(head == null || head.next ==null)return null;
    // copy of head
    Node temp = head;
    // check for the element close to nullptr
   while(temp.next.next !=null){
       temp=temp.next; 
   }
//    delete the tai;
//    set the element before tail to point to null
   temp.next = null;
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
private static  Node removeK(Node head,int k){
    if(head==null )return head;
    if(k==1){
        Node temp = head;
        head = head.next;
        return head;
    }
    int cnt =0;
    Node temp = head;
    Node prev =null;
    while(temp!=null){
        cnt++;
        if(cnt==k){
            prev.next = prev.next.next;
            
            break;
        }
        prev =temp;
        temp = temp.next;

    }
    return head;
}
private static  Node removeelement(Node head,int el){
    if(head==null )return head;
    if(head.data ==el){
        Node temp = head;
        head = head.next;
      
        return head;
    }
    
    Node temp = head;
    Node prev =null;
    while(temp!=null){
    
        if(temp.data==el){
            prev.next = prev.next.next;
            
            break;
        }
        prev =temp;
        temp = temp.next;

    }
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
    head = removeelement(head,2);
    print(head);
    }
}
