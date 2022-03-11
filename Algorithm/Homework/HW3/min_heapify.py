class min_heap:
    def __init__(self):
        self.arr = [-1] * 1024
        self.length = 0

    def insert(self, value):
        idx = 0
        while True:
            if value < self.arr[idx]:
                temp = self.arr[idx]
                self.arr[idx] = value
                self.heapify(temp, idx)
                break
            

    def heapify(self, value, index)


if __name__ == '__main__':
    N = int(input())
    line = (input()).split(' ')
    arr = [l for l in line]
