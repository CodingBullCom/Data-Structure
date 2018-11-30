class LinkedListNode<E> {
    var next: LinkedListNode<E>? = nil
    var data: E? = nil

    init(data: E) {
        self.data = data
    }
}

struct Queue<E> {

    var head: LinkedListNode<E>? = nil
    var tail: LinkedListNode<E>? = nil

    mutating func enqueue(element: E) {
        let newNode = LinkedListNode<E>(data: element)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = tail?.next
        }
    }

    mutating func dequeue() -> E? {
        if head != nil {
            let temp = head?.data
            head = head?.next
            return temp
        }
        return nil
    }

    func printQueue() {
        var temp = head
        while temp != nil {
            if let value = temp?.data {
                print(value, separator: " ", terminator: "->")
            }
            temp = temp?.next
        }
        print("nil")
    }
}

var queue = Queue<Int>()
for item in [29, 73, 99, 28, 46, 10, 42, 93, 64, 56, 82, 19, 83] {
    queue.enqueue(element: item)
}
queue.printQueue()
_ = queue.dequeue()
_ = queue.dequeue()
_ = queue.dequeue()
_ = queue.dequeue()

queue.printQueue()
