package main

import (
	"fmt"
)

func display(matrix [][]float64) {
	for i:= range(matrix) {
		for j:= range(matrix) {
			fmt.Printf("%.2f", matrix[j][i])
			fmt.Print(" ")
		}
		fmt.Print("\n")
	}
}

func calculFactoriel(n float64) float64 {
	var res float64 = 1

	for i := float64(0); i < n; i++ {
		res = (n - i) * res
	}
	return res
}

func scale(matrix [][]float64, scalar float64) ([][]float64) {
	for i := range(matrix) {
		for j := range(matrix) {
			matrix[i][j] *= scalar
		}
	}
	return matrix
}

func added(matrix1 [][]float64, matrix2 [][]float64) ([][]float64) {
	for i := range(matrix1) {
		for j := range(matrix1) {
			matrix1[i][j] += matrix2[i][j]
		}
	}
	return matrix1
}

func multi(matrix1 [][]float64, matrix2 [][]float64) [][]float64 {
	var res [][]float64
	res = make([][]float64, len(matrix1))
	for i := range(res) {
		res[i] = make([]float64, len(matrix1[i]))
	}

	for i := range(matrix1) {
		for j := range(matrix1) {
			for k := range(matrix1) {
				res[i][j] += matrix1[i][k] * matrix2[k][j]
			}
		} 
	}
	return res
}

func powerMatrix(matrix [][]float64, power float64) [][]float64 {
	var res [][]float64
	res = make([][]float64, len(matrix))
	for i := range(res) {
		res[i] = make([]float64, len(matrix[i]))
	}

	for i := range(matrix) {
		for j := range(matrix) {
			if (i == j) {
				res[i][j] = 1.0
			} else {
				res[i][j] = 0
			}
		}
	}
	for i := 0; float64(i) < power; i = i+1 {
		res = multi(res, matrix)
	}
	return res
}

func calculExp(matrix [][]float64, precision float64) {
	var res [][]float64
	res = make([][]float64, len(matrix))
	for i := range(res) {
		res[i] = make([]float64, len(matrix[i]))
	}
	for i := range(matrix) {
		for j := range(matrix) {
			if (i == j) {
				res[i][j] = 1.0 
			 } else {
				 res[i][j] = 0
			}
		}
	}

	var i float64
	for i = 1; i < (precision+1); i = i+1 {
		powered := powerMatrix(matrix, i)
		scaled := scale(powered, 1/calculFactoriel(i))
		res = added(res, scaled)
	}
	display(res)
}

func calculCos(matrix [][]float64, precision float64) {
	var res [][]float64
	res = make([][]float64, len(matrix))
	for i := range(res) {
		res[i] = make([]float64, len(matrix[i]))
	}
	for i := range(matrix) {
		for j := range(matrix) {
			if (i == j) {
				res[i][j] = 1.0
			} else {
				res[i][j] = 0
			}
		}
	}

	var i float64
	for i = 1; i < (precision + 1); i = i +1 {
        temp := 2 * i
		powered := powerMatrix(matrix, temp)
		tmp := ((-1) * i / calculFactoriel(temp))
        scaled := scale(powered, tmp)
		res = added(res, scaled)
	}
	display(res)
}