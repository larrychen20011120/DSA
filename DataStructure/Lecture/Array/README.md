# Array
## Introduction
* a set of pairs: **<index, value>**
  * For each index, there is a value associated with that index
* implemented by using **consecutive memory**
* ordered list
|    | list[0] | list[1] | list[2] | list[3] | list[4] | list[5] |
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| memory address   | base_address = a   | a + sizeof(int)   | a + 2 * sizeof(int)   | a + 3 * sizeof(int) | a + 4 * sizeof(int) | a + 5 * sizeof(int)|
| int_value | value0 | value1 | value2 | value3 | value4 |  value5  |
* Advantages:
* Disadvantages:
  * data **movement** during insertion and deletion
  * waste space in storing n ordered list of varying size

## ADT(Abstract data type) of Array
```C++
class GeneralArray{
    public:
        GeneralArray(int j, float initValue = defaultValue);

        float Retrieve(index i);

        void Store(index i, float, x);
}
```
