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

struct SortedLinkedList<E> {

    typealias T = E
    var head: LinkedListNode<T>? = nil
    func isEmpty() -> Bool {
        return head == nil
    }

    func first() -> E? {
        return head?.item
    }

    mutating func insert(item: E, comparator: (_ firstElement: E, _ secondElement: E) -> Bool ) {
        let newNode = LinkedListNode<E>(item: item)
        if isEmpty() {
            head = newNode
            return
        }

        var current = head
        var previous: LinkedListNode<T>? = nil

        while current != nil {
            if comparator(current!.item!, newNode.item!) {
                previous = current
                current = current?.next
            } else {
                newNode.next = current
                if previous == nil {
                    head = newNode
                    return
                } else {
                    newNode.next = current
                    previous!.next = newNode
                    return
                }
            }
        }
        previous!.next = newNode
    }

    mutating func remove() -> E? {
        let temp = head?.item
        head = head?.next
        return temp
    }

    func printAll() {
        var temp = head
        while temp != nil {
            print((temp!.item)!, separator: " ", terminator: " ")
            temp = temp?.next
        }
        if head != nil {
          print()
        } else {
          print("No data to print")
        }
    }
}

let testArr = [76, 10, 92, 67, 81, 12, 40, 52, 97, 20, 38, 27, 43, 88, 74]
print("\n ** Welcome to Generic sorted LinkedList program written in swift ** ")
print("\nTest Data Set")
for i in testArr {
    print(i, separator: " ", terminator: " ")
}
print("\n\nSorted LinkedList content(Incremental Order)")
var incLinkedList = SortedLinkedList<Int>()
for i in  testArr {
    incLinkedList.insert(item: i) { (val1: Int, val2: Int) in val1 < val2 }
}
incLinkedList.printAll()
print("\nSorted LinkedList content(Decremental Order)")
var dcsLinkedList = SortedLinkedList<Int>()
for i in  testArr {
    dcsLinkedList.insert(item: i) { (val1: Int, val2: Int) in val1 > val2 }
}
dcsLinkedList.printAll()
print("\nRemoving first two node from sorted linked list (Decremental Order)")

_ = dcsLinkedList.remove()
_ = dcsLinkedList.remove()
_ = dcsLinkedList.printAll()
print()
