# ReadMe for Power Method Pseudocode

## Overview

This is an implementation of the **Power Method**, a numerical algorithm used to find the dominant eigenvalue (largest eigenvalue in magnitude) and the corresponding eigenvector of a given square matrix. The method is iterative and relies on an initial guess vector and a tolerable error to determine convergence.

---

## Steps Breakdown

### Step 1: Start
The algorithm begins execution.

---

### Step 2: Input
The following inputs are required:
- **Order of Matrix (n):** The size of the square matrix (n × n).
- **Tolerable Error (e):** The threshold for convergence.

---

### Step 3: Read Matrix (A)
Read the elements of the matrix `A` row by row.  
For each element `Ai,j`:
1. Loop through rows (`i`) from 1 to `n`.
2. Loop through columns (`j`) from 1 to `n`.
3. Store the values in the matrix `A`.

---

### Step 4: Read Initial Guess Vector (X)
Input the initial guess for the eigenvector `X`:
1. Loop through each element (`Xi`) of the vector from 1 to `n`.

---

### Step 5: Initialize
Set the initial eigenvalue (`Lambda_Old`) to 1.

---

### Step 6: Multiplication (X_NEW = A * X)
Compute the new vector `X_NEW` as the matrix-vector product of `A` and `X`:
1. For each element `i` of the vector `X_NEW`, initialize `Temp` to 0.0.
2. For each column `j`, compute `Temp += Ai,j * Xj`.
3. Set `X_NEWi = Temp`.

---

### Step 7: Replace X by X_NEW
Update the guess vector `X` with the values of `X_NEW`:
1. For each element `i`, set `Xi = X_NEWi`.

---

### Step 8: Find the Largest Element (Lambda_New)
Determine the largest absolute value of the elements in `X`:
1. Initialize `Lambda_New = |X1|`.
2. Compare each subsequent element (`|Xi|`) to `Lambda_New`.
3. If `|Xi| > Lambda_New`, update `Lambda_New`.

---

### Step 9: Normalization
Normalize the vector `X` by dividing each element by `Lambda_New`:
1. For each element `i`, compute `Xi = Xi / Lambda_New`.

---

### Step 10: Display
Output the following:
- The current dominant eigenvalue (`Lambda_New`).
- The normalized eigenvector (`X`).

---

### Step 11: Check Accuracy
Verify the convergence by checking the difference between successive eigenvalues:

1. If `|Lambda_New - Lambda_Old| > e`:
   - Update `Lambda_Old = Lambda_New`.
   - Return to **Step 6** for another iteration.
2. Otherwise, proceed to the next step.

---

### Step 12: Stop
The algorithm terminates when convergence is achieved.

---

## Notes
- **Inputs:** Ensure that the initial guess vector `X` is non-zero to avoid division errors during normalization.
- **Convergence:** The algorithm may fail to converge if the matrix does not have a dominant eigenvalue.
- **Usage:** This method is particularly effective for sparse or large matrices in numerical computations.
