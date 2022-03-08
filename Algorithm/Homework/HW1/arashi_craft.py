class Stack:
    def __init__(self, number):
        self.top = 0
        self.container = [number]

    def push(self, number):
        self.container.append(number)
        self.top += 1

    def pop(self):
        self.top -= 1
        return self.container.pop()

    def all_above(self, element, itself=False):
        pile = list()
        while self.container[self.top] != element:
            pile.insert(0, self.pop())

        if itself is True:
            pile.insert(0, self.pop())
        return pile

    def is_empty(self):
        return True if self.top == -1 else False

    def print_out_sequence(self):
        for el in self.container:
            print(el + 1, end=' ')
        print()

if __name__ == "__main__":
    line = input()
    line = line.split(' ')
    N = int(line[0])
    M = int(line[1])

    blocks = [Stack(i) for i in range(N)]
    position = [i for i in range(N)]

    for i in range(M):
        line = input()
        line = line.split(' ')
        # -1 in order to correct it to starting at 0
        block_a = int(line[1]) - 1
        block_b = int(line[3]) - 1
        pos_a = position[block_a]
        pos_b = position[block_b]


        if pos_a == pos_b: # invalid input command
            continue

        if line[0] == 'move':
            if line[2] == 'onto':
                # put all above block_a and block_b back to the origin place
                # move block_a onto block_b
                pile = blocks[pos_a].all_above(block_a) + blocks[pos_b].all_above(block_b)
                for p in pile:
                    position[p] = p
                    blocks[p].push(p)

                blocks[pos_b].push(block_a)
                position[block_a] = pos_b
                blocks[pos_a].pop()

            else:
                pile = blocks[pos_a].all_above(block_a)
                for p in pile:
                    position[p] = p
                    blocks[p].push(p)

                blocks[pos_b].push(block_a)
                blocks[pos_a].pop()
                position[block_a] = pos_b

        else:
            if line[2] == 'onto':
                pile = blocks[pos_b].all_above(block_b)
                for p in pile:
                    position[p] = p
                    blocks[p].push(p)
                pile = blocks[pos_a].all_above(block_a, itself=True)
                for p in pile:
                    position[p] = pos_b
                    blocks[pos_b].push(p)
            else:
                pile = blocks[pos_a].all_above(block_a, itself=True)
                for p in pile:
                    position[p] = pos_b
                    blocks[pos_b].push(p)

    for i in range(N):
        print(str(i + 1) + ":", end=' ')
        blocks[i].print_out_sequence()
