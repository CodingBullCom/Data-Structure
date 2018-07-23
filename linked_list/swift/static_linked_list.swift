class LinkedListNode<T> {

    var item: T? = nil
    var next: LinkedListNode<T>? = nil

    init(item: T) {
        self.item = item
    }
}

struct LinkedList<T> {
    var head: LinkedListNode<T>? = nil

    mutating func insert(item: T) {
        let newNode = LinkedListNode<T>(item: item)
        newNode.next = head
        head = newNode
    }

    func printAll() {
        var temp = head
        while temp != nil {
            print((temp!.item)!, separator: " ", terminator: " ")
            temp = temp?.next
        }
        if head != nil {
          print()
        }
    }
}

var linkedList = LinkedList<Int>()
for i in 10...20 {
    linkedList.insert(item: i)
}
linkedList.printAll()
