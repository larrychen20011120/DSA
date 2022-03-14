import statistics

def insertion_sort(arr, start, end):
    for i in range(start + 1, end):
        j = i
        while j > start:
            if arr[j] < arr[j - 1]:
                temp = arr[j]
                arr[j] = arr[j - 1]
                arr[j - 1] = temp
                j -= 1
            else:
                j = -1

def quick_sort(arr, start, end):
    if end - start > 5:
        middle = ( start + end ) // 2
        median = statistics.median((arr[start], arr[middle], arr[end - 1]))
        iter1 = start
        iter2 = end - 1
        while iter1 != iter2:
            if arr[iter1] > median:
                temp = arr[iter2]
                arr[iter2] = arr[iter1]
                arr[iter1] = temp
                iter2 -= 1
            elif arr[iter1] == median:
                pass
            else:
                iter1 += 1
        arr[iter1] = median
        quick_sort(arr, start, iter1)
        quick_sort(arr, iter1 + 1, end)
    else:
        insertion_sort(arr, start, end)

def merge_sort(arr, start, end):
    if end - start == 1:
        return
    middle = (start + end) // 2
    merge_sort(arr, start, middle)
    merge_sort(arr, middle, end)
    merge(arr, start, middle, end)

def merge(arr, start, middle, end):
    INFINITY = 50001
    left_arr = arr[start: middle]
    right_arr = arr[middle: end]
    left_arr.append(INFINITY)
    right_arr.append(INFINITY)
    iter_l = 0
    iter_r = 0
    idx = start
    while iter_l < middle - start and iter_r < end - middle:
        if left_arr[iter_l] < right_arr[iter_r]:
            arr[idx] = left_arr[iter_l]
            iter_l += 1
        else:
            arr[idx] = right_arr[iter_r]
            iter_r += 1
        idx += 1

if __name__ == "__main__":
    N = int(input())
    line = (input()).split(' ')
    arr = [int(l) for l in line]
    merge_sort(arr, 0, N)
    for a in arr:
        print(a, end=' ')
    print()
