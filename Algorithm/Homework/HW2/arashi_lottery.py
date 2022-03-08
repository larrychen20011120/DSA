from itertools import combinations
if __name__ == "__main__":
    line = input()
    line = line.split(' ')
    M = int(line[0])
    numbers = [int(line[i]) for i in range(1, M + 1)]
    all_comb = list(combinations(numbers, 6))
    for comb in all_comb:
        for c in comb:
            print(c, end=' ')
        print()
