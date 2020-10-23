package main

func calculFactoriel(n int) int {
	var res = 1

	for i := 0; i < n; i++ {
		res = (n - i) * res
	}
	return (res)
}

func calculExp(matrice [][]int) {
	var n = 0
	var res float64 = 0

	for i := 0; i < n; i++ {
		res = (calculMatrice(matrice, n) / calculFactoriel(n)) + res
	}
	display(res)
}

func calculSin(matrice [][]int) {
	var n = 1
	var res float64 = 0
	var precision = 0

	for i := 1; i < precision; i = i + 1 {
		if (i % 2) == 0 {
			res = res + (calculMatrice(matrice, n) / calculFactoriel(n))
		} else {
			res = res - (calculMatrice(matrice, n) / calculFactoriel(n))
		}
		n = n + 2
	}
	display(res)
}

func calculSinHyperbol(matrice [][]int) {
	var n = 1
	var res float64 = 0
	var precision = 0

	for i := 1; i < precision; i = i + 1 {
		res = res + (calculMatrice(matrice, n) / calculFactoriel(n))
		n = n + 2
	}
	display(res)
}

func calculCos(matrice [][]int) {
	var n = 0
	var res float64 = 0
	var precision = 0

	for i := 0; i < precision; i = i + 1 {
		if (i % 2) == 0 {
			res = res + (calculMatrice(matrice, n) / calculFactoriel(n))
		} else {
			res = res - (calculMatrice(matrice, n) / calculFactoriel(n))
		}
		n = n + 2
	}
	display(res)
}

func calculCosHyperbol(matrice [][]int) {
	var n = 0
	var res float64 = 0
	var precision = 0

	for i := 0; i < precision; i = i + 1 {
		res = res + (calculMatrice(matrice, n) / calculFactoriel(n))
		n = n + 2
	}
	display(res)
}

func display(matrix [][]float64) {
	side := len(matrice)
	for i:= range(side) {
		for j:= range(side) {
			fmt.Print(matrix[i][j])
		}
	}
}