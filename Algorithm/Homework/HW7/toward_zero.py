from sys import stdin, stdout

if __name__ == '__main__':
    N = int(stdin.readline())
    line = stdin.readline().split()
    arr = [int(l) for l in line]
    min = 500
    for a in arr:
