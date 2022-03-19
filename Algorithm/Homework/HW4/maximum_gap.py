if __name__ == "__main__":
    N = int(input())
    line = input().split(' ')
    arr = [int(l) for l in line]

    if N < 2:
        print(0)
    else:
        max_diff = 0
        arr.sort()
        for i in range(N - 1):
            if arr[i + 1] - arr[i] > max_diff:
                max_diff = arr[i + 1] - arr[i]
        print(max_diff)
