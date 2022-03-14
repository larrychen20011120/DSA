class MinHeap:
    def __init__(self, arr, length):
        self.arr = arr
        # start at index 1
        # parent => // 2
        # child => 2n or 2n + 1
        self.length = length

    def heapify(self, idx=1):
        if idx > self.length:
            return
        self.heapify(2 * idx)
        self.heapify(2 * idx + 1)

        if

    def printAll(self):
        for i in range(1, self.length + 1):
            print(self.arr[i], end=' ')
        print()

if __name__ == '__main__':
    N = int(input())
    line = (input()).split(' ')
    arr = [int(l) for l in line]
    min_heap = MinHeap(arr=arr, N)
    min_heap.heapify()
    min_heap.printAll()
