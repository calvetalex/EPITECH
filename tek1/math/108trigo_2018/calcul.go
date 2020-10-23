package test

import (
	"fmt"
)

func calculFactoriel(n float64) float64 {
	var res float64 = 1

	for i := float64(0); i < n; i++ {
		res = (n - i) * res
	}
	return res
}

func initResMatrix(matrice [][]float64) [][]float64 {
	var res [][]float64
	res = make([][]float64, len(matrice))

	for k := range(res) {
		res[k] = make([]float64, len(matrice))
	}
	for i := range matrice {
		for j := range matrice {
			res[i][j] = 0.0
		}
	}
	return res
}

func calculMatriceExpn(matrice [][]float64, n float64) [][]float64 {
	res := matrice

	for i := float64(0); i < n; i = i + 1 {
		res = calcMatrix(res, matrice)
	}
	return res
}

func calculMatriceDivision(matrice [][]float64, nb float64) [][]float64 {
	for i := 0; i < len(matrice); i = i + 1 {
		for j := 0; j < len(matrice[i]); j = j + 1 {
			matrice[i][j] = matrice[i][j] / nb
		}
	}
	return matrice
}

func addMatrice(matrice1 [][]float64, matrice2 [][]float64) [][]float64 {
	for i := 0; i < len(matrice1); i = i + 1 {
		for j := 0; j < len(matrice1[i]); j = j + 1 {
			matrice1[i][j] = matrice1[i][j] + matrice2[i][j]
		}
	}
	return matrice1
}

func subMatrice(matrice1 [][]float64, matrice2 [][]float64) [][]float64 {
	for i := 0; i < len(matrice1); i = i + 1 {
		for j := 0; j < len(matrice1[i]); j = j + 1 {
			matrice1[i][j] = matrice1[i][j] - matrice2[i][j]
		}
	}
	return matrice1
}

func calculExp(matrice [][]float64) {
	var n float64 = 2
	var res = initResMatrix(matrice)

	for i := float64(0); i < n; i = i + 1 {
		res = addMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
	}
	display(res)
}

func calculSin(matrice [][]float64) {
	var n float64 = 1
	var precision int = 5
	var res = initResMatrix(matrice)

	for i := 1; i < precision; i = i + 1 {
		if i%2 == 0 {
			res = addMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		} else {
			res = subMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		}
		n = n + 2
	}
	display(res)
}

func calculSinHyperbol(matrice [][]float64) {
	var n float64 = 1
	var precision float64 = 5.0
	var res = initResMatrix(matrice)

	for i := float64(1); i < precision; i = i + 1 {
		res = addMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		n = n + 2
	}
	display(res)
}

func calculCos(matrice [][]float64) {
	var n float64 = 0
	var precision int = 5
	var res = initResMatrix(matrice)

	for i := 0; i < precision; i = i + 1 {
		if i%2 == 0 {
			res = addMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		} else {
			res = subMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		}
		n = n + 2
	}
	display(res)
}

func calculCosHyperbol(matrice [][]float64) {
	var n float64 = 0
	var precision float64 = 0
	var res = initResMatrix(matrice)

	for i := float64(0); i < precision; i = i + 1 {
		res = addMatrice(res, calculMatriceDivision(calculMatriceExpn(matrice, n), calculFactoriel(n)))
		n = n + 2
	}
	display(res)
}

func display(matrix [][]float64) {
	for i:= range(matrix) {
		for j:= range(matrix) {
			fmt.Print(matrix[i][j])
			fmt.Print(" ")
		}
		fmt.Print("\n")
	}
}