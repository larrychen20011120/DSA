class Stack:
    def __init__(self):
        self.top = -1
        self.container = list()
        self.top_item = None

    def push(self, set):
        self.top += 1
        self.container.append(set)
        self.update()

    def pop(self):
        if self.top == -1:
            # You can't pop out anything
            return None
        else:
            self.top -= 1
            self.update()
            return self.container.pop()

    def update(self):
        self.top_item = self.container[self.top]

    def get_top_item(self):
        return self.top_item

class MySet:
    def __init__(self, num_of_el=0, subset=list()):
        self.num_of_el = num_of_el
        self.subset = subset

    def is_equal(self, set):
        if self.num_of_el != set.num_of_el:
            return False
        else:
            for i in range(self.num_of_el):
                if self.subset[i] != set.subset[i]:
                    return False
            return True

    def clone(self):
        subset = self.subset.copy()
        return MySet(num_of_el=self.num_of_el, subset=subset)

    def insert(self, item):
        for i in range(self.num_of_el):
            if self.subset[i] == item:
                return
            elif self.subset[i] > item:
                self.subset.insert(i, item)
                self.num_of_el += 1
                return

        self.subset.append(item)
        self.num_of_el += 1


class AllSets:
    def __init__(self):
        self.num_of_set = 0
        self.sets = [MySet()] # where in stack and sets[0] is for null set

    def src_pos(self, myset):
        for idx, s in enumerate(self.sets):
            if s.is_equal(myset): # already in the sets
                del myset
                return idx
        self.sets.append(myset)
        self.num_of_set += 1
        return self.num_of_set

    def add(self, item1, item2):
        myset = self.sets[item2].clone()
        myset.insert(item1)
        return self.src_pos(myset)


    def intersect(self, item1, item2):
        iter1 = 0
        iter2 = 0
        set1 = self.sets[item1]
        set2 = self.sets[item2]
        subset = []
        while (iter1 < set1.num_of_el) and (iter2 < set2.num_of_el):
            if set1.subset[iter1] == set2.subset[iter2]:
                subset.append(set1.subset[iter1])
                iter1 += 1
                iter2 += 1
            elif set1.subset[iter1] > set2.subset[iter2]:
                iter2 += 1
            else:
                iter1 += 1
        myset = MySet(num_of_el=len(subset), subset=subset)
        return self.src_pos(myset)


    def union(self, item1, item2):
        iter1 = 0
        iter2 = 0
        set1 = self.sets[item1]
        set2 = self.sets[item2]
        subset = []
        while (iter1 < set1.num_of_el) and (iter2 < set2.num_of_el):
            if set1.subset[iter1] == set2.subset[iter2]:
                subset.append(set1.subset[iter1])
                iter1 += 1
                iter2 += 1
            elif set1.subset[iter1] > set2.subset[iter2]:
                subset.append(set2.subset[iter2])
                iter2 += 1
            else:
                subset.append(set1.subset[iter1])
                iter1 += 1

        while (iter1 < set1.num_of_el):
            subset.append(set1.subset[iter1])
            iter1 += 1

        while (iter2 < set2.num_of_el):
            subset.append(set2.subset[iter2])
            iter2 += 1

        myset = MySet(num_of_el=len(subset), subset=subset)
        return self.src_pos(myset)

if __name__ == "__main__":

    N = int(input()) # input how many operations will do next
    stack = Stack() # the stack to store sets
    all = AllSets()

    for i in range(N):
        cmd = input()

        if cmd == 'PUSH':
            stack.push(0)
        elif cmd == 'DUP':
            stack.push(stack.get_top_item())
        elif cmd == 'UNION':
            item1 = stack.pop()
            item2 = stack.pop()
            item = all.union(item1, item2)
            stack.push(item)
        elif cmd == 'INTERSECT':
            item1 = stack.pop()
            item2 = stack.pop()
            item = all.intersect(item1, item2)
            stack.push(item)
        else: # ADD
            item1 = stack.pop()
            item2 = stack.pop()
            item = all.add(item1, item2)
            stack.push(item)

        print(all.sets[stack.get_top_item()].num_of_el)
