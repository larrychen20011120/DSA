# Array
# Introduction
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

## ADT (Abstract data type) of Array
```C++
class GeneralArray{
    public:
        GeneralArray(int length, float initValue = defaultValue);

        float Retrieve(index i);

        void Store(index i, float, x);
}
```
# Applications
## Polynomial
### ADT of Polynomial 
```C++
class Polynomial{
    public:
        // Construct the polynomial p(x) = 0
        Polynomial();
        
        //

}
```
## Sparse Matrices

## String
### ADT of String

```C++
class String{

 public:
    // constructor that initializes this to string init of length l
    String(char *init, int m);
    
    // override the == operator of string
    // if this is equals to t then return true; else return false
    bool operator==(String t);
    
    // override the ! operator of string
    // if this is empty then return true; else return false
    bool operator!();
    
    // return the length of this
    int length();

    // return the string whose elements are
    // those of this followed by those of t
    String concat(String t);
    
    // return the string starting at i and having length j 
    // from this string
    String substr(int i, int j);
    
    // return the index i such that pat matches the substring of this
    // that beginsat position i
    // return -1 if pat is eithor empty or not a substring of this
    int find(String pat);
}

```
### String Matchig
We will discuss two algorithm to match the string
1. Simple string match
2. KMP algorithm
#### Simple String Matching
#### KMP (Knuth-Morris-Pratt) algorithm
* Proposed by Knuth, Morris and Pratt
