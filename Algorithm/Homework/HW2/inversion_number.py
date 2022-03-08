if __name__ == '__main__':
    N = int(input())
    line = input()
    line = line.split(' ')
    arr = [int(l) for l in line]
    inver_num = [0] * N
    bigger_lists = [list() for i in range(N)]
    sum = 0

    for i in range(N - 2, -1, -1):
        for j in range(i + 1, N):
            if arr[i] > arr[j]:
                inver_num[i] = 1 + inver_num[j]
                for bigger in bigger_lists[j]:
                    if arr[i] > arr[bigger]:
                        inver_num[i] += 1
                    elif arr[i] < arr[bigger]:
                        bigger_lists[i].append(bigger)

                break # end the loop
            elif arr[i] < arr[j]:
                bigger_lists[i].append(j)

            else:
                inver_num[i] = inver_num[j]
                for bigger in bigger_lists[j]:
                    bigger_lists[i].append(bigger)

        add = inver_num[i] % 524287
        sum += add
        sum %= 524287

    print(sum)
