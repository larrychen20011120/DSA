# Array
# Introduction
* a set of pairs: <mark>(index, value)</mark>
  * For each index, there is a value associated with that index
  * implemented by using ==consecutive memory==
* ordered list

|    | list[0] | list[1] | list[2] | list[3] | list[4] | list[5] |
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| memory address   | base_address = a   | a + sizeof(int)   | a + 2 * sizeof(int)   | a + 3 * sizeof(int) | a + 4 * sizeof(int) | a + 5 * sizeof(int)|
| int_value | value0 | value1 | value2 | value3 | value4 |  value5  |

* Advantages:
* Disadvantages:
  * ==data movement== during insertion and deletion
  * waste space in storing n ordered list of varying size

## ADT of Array
```C++
class GeneralArray{
    public:
        GeneralArray(int length, float initValue = defaultValue);

        float Retrieve(index i);

        void Store(index i, float, x);
}
```
# Applications
Apply array structure at different problems, there are three examples we'll discuss.
1. Polynomial
    >focus on the special case called ==sparse==
2. Sparse Matrix
     > focus on the ==transpose== operation of matrix
3. String (char array)
     > focus on the ==string matching==
     
## Polynomial 
* Representation 1
    * Intuitively, we may use an array named **coefficent** with the shared size called **maxDegree**
    * For all polynomials, their **degree $\leq$ maxDegree**
    * the **index** of the coefficient array means the **exponent** corresponding to that coefficient
    * **Waste space** when the degree of the polynomial is much smaller than maxDegree (most space are unused)

* Representation 2
    * make some improvements on representation 1
    * Instead of using shared data maxDegree, we turn to create a **new attribute** called **degree** for indicating that polynomial's degree
    * the **index** of the coefficient array also indicates the **exponent**
    * However it's still **space-consuming** when it comes to **sparse** situation

* ==Representation 3==
    * more suitable for sparse polynomial (there are many ==zero terms== in it)  
    * 

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
* character array ==end with '\0'==

    | H | E | L | L | O |  | W | O | R| L | D | \0 |
    |----|----|----|----|----|----|----|----|----|----|----|----|
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
### String Matching
We will discuss 2 algorithms about string matching
1. Simple string match
2. ==KMP algorithm==
#### Simple String Matching
* an intuitive way to match string
* every time we shift only one character when not matching
* complexity = ==O(lengthP * lengthS)==
#### KMP (Knuth-Morris-Pratt) algorithm
* Proposed by Knuth, Morris and Pratt (Three smart guys)
* consist of two phases
    *  Generate an array to indicate the moving direction
    *  Use the array to move and match string 
* the main idea of it: ==shifting many words== when not matching 

    * in order to do that, we need to generate the **failure function**

* failure function

    :::warning
    If p = p<sub>0</sub>p<sub>1</sub>…p<sub>n-1</sub> is a pattern, then its failure function, f is defined as 
    $$ f(n)= \begin{cases} max(k), & \text {if                 $p_0$ $p_1$...$p_k$ = $p_{j-k}$ $p_{j-k+1}$...$p_j$ and 0 $\leq$ k < j } \\  -1, & \text{otherwise} \end{cases} $$
      
    :::
* complexity = ==O(lengthP + lengthS)== 
