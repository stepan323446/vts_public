# How to write correctly trougao

## Table of contents

* [Figure](#figure)
    * [Without spaces](#simple-type-without-spaces)
    * [With spaces](#with-spaces)
* [Variables in figure](#variables-in-figure)
* [Letters](#letters)
* [Special figures](#special-figures)
    * [Piramide](#piramide)
    * [Piramide with median](#piramide-with-median)

## Figure

We have 4 types of figure.

### Simple type without spaces

1. The simplest figure. 
```
*
* *
* * *
* * * *
* * * * *
```
We just use 2 loops, where col depending by every row
```c
const int trougao_size = 5;

for(int row = 0; row < trougao_size; row++) {
    // We use "col <= row" because we have limit for columns count for every row
    /*
        0               <= 0
        0, 1            <= 1
        0, 1, 2         <= 2
        0, 1, 2, 3      <= 3
        0, 1, 2, 3, 4   <= 4
    */
    for(int col = 0; col <= row; col++) {
        printf("* ");
    }
    // New line
    printf("\n");
}
```
2. Reverse
```
* * * * *
* * * *
* * *
* *
*
```
We use same principe, where col depending by every row AND trougao size
```c
const int trougao_size = 5;
for (int row = 0; row < trougao_size; row++)
{
    // We have (trougao_size - row) where we count columns
    /*
        0, 1, 2, 3, 4   < (5 - 0)
        0, 1, 2, 3      < (5 - 1)
        0, 1, 2         < (5 - 2)
        0, 1            < (5 - 3)
        0               < (5 - 4)
    */
    for (int col = 0; col < trougao_size - row; col++)
    {
        printf("* ");
    }
    // New line
    printf("\n");
}
```

### With spaces
The principle remains the same, but we only need to add spaces before the numbers. To do this, we use the third loop, which adds them

3. The simplest figure with spaces
```
        *
      * *
    * * *
  * * * *
* * * * *
```
We use same code like first example, but we add `for` for spaces
```c
const int trougao_size = 5;

for(int row = 0; row < trougao_size; row++) {
    // Spaces
    /*
    We start from 0 to (trougao_size 5 - 1) - row
        0, 1, 2, 3      < 5-1-0
        0, 1, 2         < 5-1-1
        0, 1            < 5-1-2
        0               < 5-1-3
        nothing         < 5-1-4
    */
    for(int space = 0; space < trougao_size - 1 - row; space++) {
        printf("  ");
    }

    // Same
    for(int col = 0; col <= row; col++) {
        printf("* ");
    }
    // New line
    printf("\n");
}
```
> Space symbols must be same count like for output symbol count per column. For example, "* " need 2 spaces 

4. Reverse with spaces
```
* * * * *
  * * * *
    * * *
      * *
        *
```
We use same code like second example, but we add `for` for spaces
```c
const int trougao_size = 5;
for (int row = 0; row < trougao_size; row++)
{
    // Spaces
    /*
        nothing         < 0
        0               < 1
        0, 1            < 2
        0, 1, 2         < 3
        0, 1, 2, 3      < 4
    */
    for (int space = 0; space < row; space++)
    {
        printf("  ");
    }

    // Same
    for (int col = 0; col < trougao_size - row; col++)
    {
        printf("* ");
    }
    // New line
    printf("\n");
}
```

## Variables in figure

We can use numbers by `row` and `col` as variables in a loop.

But when changing each figure, you need to come up with something new, so it’s more universal to create a new variable and change it either when changing a row or when changing a column

We have `number` variable

1. Changing numbers by row
```
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
```

```c
const int trougao_size = 5;
// variable for numbers
int number = 1;

for(int row = 0; row < trougao_size; row++) {
    // Same as first example for figure
    for(int col = 0; col <= row; col++) {
        printf("%d ", number);
    }
    printf("\n");
    // Change number + 1 for new row
    number++;
}
```
2. Reverse changing numbers by row

```
5
4 4
3 3 3
2 2 2 2
1 1 1 1 1
```
Everything is the same, but we start with the maximum and gradually reduce the number every row

```c
const int trougao_size = 5;
// variable for numbers (start from max)
int number = trougao_size;

for(int row = 0; row < trougao_size; row++) {
    // Same as first example for figure
    for(int col = 0; col <= row; col++) {
        printf("%d ", number);
    }
    printf("\n");
    // Change number -1 for new row
    number--;
}
```

3. Changing numbers by column

```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```

We put the `number` variable inside the first loop. With each new row the number returns to its previous state

```c
const int trougao_size = 5;


for(int row = 0; row < trougao_size; row++) {
    // variable for numbers, every new row we start from one
    int number = 1;

    // Same as first example for figure
    for(int col = 0; col <= row; col++) {
        printf("%d ", number);

        // Change number +1 for new column
        number++;
    }
    printf("\n");
}
```

4. Reverse changing numbers by column

```
5
5 4
5 4 3
5 4 3 2
5 4 3 2 1
```

We also use a `number`, but start with the size of the triangle

```c
const int trougao_size = 5;

for(int row = 0; row < trougao_size; row++) {
    // variable for numbers, every new row we start from trougao_size
    int number = trougao_size;

    // Same as first example for figure
    for(int col = 0; col <= row; col++) {
        printf("%d ", number);

        // Change number -1 for new column
        number--;
    }
    printf("\n");
}
```

5. Reverse changing numbers by column depending by count columns

```
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
```

We have 2 variables: `numberRow` outside and `number` inside main for. `numberRow` for start number in row, `number` for change number every column.

```c
const int trougao_size = 5;
int numberRow = 1;
for (int row = 0; row < trougao_size; row++)
{
    // variable for numbers, every new row we start from trougao_size
    int number = numberRow;

    // Same as first example for figure
    for (int col = 0; col <= row; col++)
    {
        printf("%d ", number--);
    }
    printf("\n");
    numberRow++;
}
```

## Letters

Everything is very easy here. We do everything exactly the same as with variables, but instead of a `number` there will be an `index` that will refer to an array with letters.

```c
const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'}
// variable for index
int index = 0;

for(int row = 0; row < trougao_size; row++) {
    // Same as first example for figure
    for(int col = 0; col <= row; col++) {
        printf("%c ", letters[index]);
    }
    printf("\n");
    // Change index + 1 for new row
    index++;
}
```
```
A
B B
C C C
D D D D
E E E E E
```

## Special figures

### Piramide

#### Simple piramide

There are special figures for group 3. In fact, everything is the same, you just need to use the spaces correctly.

For example:
<table>
    <tr>
        <th></th>
        <th>Piramide</th>
        <th>Right triangle</th>
    <tr>
    <tr>
        <td>View</td>
        <td>
            <pre>
  * 
 * * 
* * *</pre>
        </td>
        <td>
<pre>
    * 
  * * 
* * *
</pre>
        </td>
    </tr>
    <tr>
        <td>Spaces</td>
        <td>1</td>
        <td>2</td>
    </tr>
    <tr>
        <td>Symbols</td>
        <td>2</td>
        <td>2</td>
    </tr>
</table>

Thus, in order for us to create a pyramid, we need to write the same code as [above](#with-spaces), but instead of 2 spaces per 2 characters, **make 1 space per 2 characters**

```
* * * * * 
 * * * * 
  * * * 
   * * 
    * 
```
```c
// Same code
const int trougao_size = 5;
for (int row = 0; row < trougao_size; row++)
{
    for (int space = 0; space < row; space++)
    {
        // one space instead of two
        printf(" ");
    }

    // Same
    for (int col = 0; col < trougao_size - row; col++)
    {
        // 2 symbols
        printf("* ");
    }
    printf("\n");
}
```

#### Piramide with median

A pyramid with a center is built completely differently.

```
    *
   1*2
  11*22
 111*222
1111*2222

 * - center
```
Inside one loop we have 3 loops:
* loop for spaces (like [above](#with-spaces))
* loop for left side trougao (1)
* loop for right side trougao (2)

```c
int trougao_size = 5;

for(int row = 0; row  < trougao_size; row++) {
    // Spaces
    for(int space = trougao_size - row - 1; space > 0; space--) {
        printf(" ");
    }
    // Left side, same as 1 example for figure, but place -1
    for(int col = 0; col <= row - 1; col++) {
        printf("1");
    }
    // Center
    printf("*");
    // Right side, same as 1 example for figure, but place -1
    for(int col = 0; col <= row - 1; col++) {
        printf("2");
    }
    printf("\n");
}
```
> The loop for the left and right sides is identical

> The number of characters must be equal to the number of spaces in `printf`

> The left and right side same as [above](#simple-type-without-spaces),  but for columns we constantly subtract -1 to center

**Examples:**
```
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```
```c
int trougao_size = 5;

for(int row = 0; row  < trougao_size; row++) {
    // Spaces like figure 3 with spaces
    for(int space = 0; space < trougao_size - 1 - row; space++) {
        printf(" ");
    }
    // Left sire
    for(int col = 0; col <= row - 1; col++) {
        printf("*");
    }
    // Center
    printf("*");
    // Right side
    for(int col = 0; col <= row - 1; col++) {
        printf("*");
    }
    printf("\n");
}
// New trougao with 4 size
trougao_size--;

for(int row = 0; row  < trougao_size; row++) {
    // Space to move the piece a little to the right
    printf(" ");
    
    // Spaces like figure 4 with spaces
    for(int space = 0; space < row; space++)
    {
        printf(" ");
    }
    // Left side like figure 4, but -1
    for(int col = 0; col < trougao_size - row - 1; col++) {
        printf("*");
    }
    // Center
    printf("*");

    // Right side like figure 4, but -1
    for(int col = 0; col < trougao_size - row - 1; col++) {
        printf("*");
    }
    printf("\n");
}
return 0;
```