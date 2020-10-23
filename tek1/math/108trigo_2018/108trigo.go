package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func disp() {
	fmt.Print("USAGE\n\t./108trigo fun a0 a1 a2 ...\n")
	fmt.Print("\nDESCRIPTION\n\tfun\tfunction to be applied, among at least \"EXP\", \"COS\", \"SIN\", \"COSH\" and \"SINH\"\n")
	fmt.Print("\tai\tcoeficients of the matrix\n")
}

func verif(str []string) int {
	nbSq := math.Sqrt(float64(len(str[2:])))
	nbRes := math.Pow(nbSq, 2)
	if str[1] == "EXP" || str[1] == "COS" || str[1] == "SIN" || str[1] == "COSH" || str[1] == "SINH" {
		if nbRes == float64(len(str[2:])) {
			return (0)
		} else {
			return 1
		}
	}
	return 1
}

func calcMatrix(tab [][]float64, tab2 [][]float64) [][]float64 {
	var nb float64 = 0
	var matrice [][]float64

	matrice = make([][]float64, len(tab))
	for x := 0; x < len(tab); x = x + 1 {
		matrice[x] = make([]float64, (len(tab)))
	}
	for i := range tab {
		for j := range tab2 {
			for k := range tab2 {
				nb = nb + (tab[i][k] * tab2[k][j])
			}
			matrice[i][j] = nb
			nb = 0
		}
	}
	return matrice
}

func creatematrix(str []string) [][]float64 {
	var matrix [][]float64
	var nb = 0
	lenght := math.Sqrt(float64(len(str)))
	matrix = make([][]float64, int(lenght))
	j := 0

	for i := 0; i < int(lenght); i = i + 1 {
		matrix[i] = make([]float64, int(lenght))
		for k := 0; k < int(lenght); k = k + 1 {
			nb, _ = strconv.Atoi(str[k+j])
			matrix[i][k] = float64(nb)
		}
		j = j + int(lenght)
	}
	return matrix
}

func main() {
	if len(os.Args[1:]) != 0 {
		if len(os.Args[1:]) == 1 {
			if os.Args[1] == "-h" {
				disp()
				os.Exit(0)
			} else {
				os.Exit(84)
			}
		} else if verif(os.Args) == 0 {
			matrix := creatematrix(os.Args[2:])
			res := 0
			switch os.Args[1] {
			case "EXP":
				calculExp(matrix, 50)
				break
			/*case "SIN":
				calculSin(matrix)
				break
			case "COS":
				calculCos(matrix, 50)
				break
			case "COSH":
				calculCosHyperbol(matrix)
				break
			case "SINH":
				calculSinHyperbol(matrix)
				break*/
			default:
				res = 1
				break
			}
			if (res == 0) {
				os.Exit(0)
			} else {
				os.Exit(84)
			}
		} else {
			os.Exit(84)
		}
	} else {
		os.Exit(84)
	}
}
