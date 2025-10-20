# cpp-determinant-laplace

Determinant calculator using Laplace's expansion and recursion in C++.

## What is Laplace's expansion?

Laplace's expansion is a method for calculating the determinant of an $n \times n$ matrix. It consists in the sum of a product for each element of a row or column. As it follows:

$$
\det(A) = \sum_{j=1}^{n} (-1)^{i+j} a_{ij} \ m_{ij}
$$

is the formula for a certain row i, with j variyng through the columns. In this equation, $m_{ij}$ represents another determinant: the determinant of the original matrix without the $i^\text{th}$ row and the $j^\text{th}$ column. This motivated me to describe this expansion through recursive callings, since the determinant will return a series of determinants, that will once again return a series of determinants and so on, being $1 \times 1$ the base case, where the determinant is the sole element of the matrix.

## How does it work?

The code relies on three functions. One of them returns a matrix without the $i^\text{th}$ row and $j^\text{th}$ column (specified as parameters). This function is called inside the function that returns the determinant by summing all the products for each element of said row or column. At last, but not least, there is a function that returns the row or column with the greatest amount of zeros, purely for optimization purposes. If a given element is zero, there is no need to calculate the determinant of its minor matrix, because its product will inevitably amount to zero.

## Complexity

 Although interesting, this algorithm has poor performance. Given an $n \times n$ matrix, expanding requires computing $n$ other matrices. This means $O(n!)$, which is really troubling for $n > 10$. In the worst scenario, there are no zeros, which means the optimization function will have no use at all. There is a more efficient way to calculate determinants with computers called Gaussian elimination, which I am yet to put my efforts into trying to develop. Even so, i believe this piece of code to be an interesting exercise.
