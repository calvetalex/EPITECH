package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func loop(list [][]int) {
	var res float64 = 1

	var i float64
	for i = 0; i <= 1.001; i = i + 0.001 {
		for j := 0; j < len(list); j = j + 2 {
			res = divide(list[j], list[j+1], i) * res
		}
		fmt.Printf("%.3f -> %.5f\n", i, res)
		res = 1
	}
}

func divide(num []int, den []int, x float64) float64 {
	var numtr float64 = 0
	var dentr float64 = 0
	var res float64 = 0

	numtr = calcul(num, x)
	dentr = calcul(den, x)
	if numtr == dentr {
		res = 1
	} else {
		res = numtr / dentr
	}
	return res
}

func calcul(nbrs []int, x float64) float64 {
	var res float64 = 0

	for i := float64(0); i < float64(len(nbrs)); i = i + 1 {
		res = math.Pow(x, float64(i))*float64(nbrs[int(i)]) + res
	}
	return (res)
}

func disp() {
	fmt.Print("USAGE\n\t./107transfer [num den] *\n")
	fmt.Print("\nDESCRIPTION\n\tnum\tpolynomial numerator defined by its coefficients\n")
	fmt.Print("\tden\tpolynomial denominator defined by its coefficients\n")
}

func checkinput(array []string) int {
	for i := 0; i < len(array); i = i + 1 {
		for j := 0; j < len(array[i]); j = j + 1 {
			if (array[i][j] < '0' || array[i][j] > '9') && array[i][j] != '*' && array[i][j] != '-' {
				return 84
			}
		}
	}
	return 0
}

func main() {
	if (len(os.Args[1:])%2) == 0 && len(os.Args[1:]) != 0 {
		res := checkinput(os.Args[1:])
		if res == 84 {
			os.Exit(84)
		}
		var pol [][]int
		pol = make([][]int, (len(os.Args) - 1))
		for i := 0; i < len(os.Args)-1; i = i + 1 {
			tmp := strings.Split(os.Args[i+1], "*")
			pol[i] = make([]int, len(tmp))
			for j := 0; j < len(tmp); j = j + 1 {
				nb, _ := strconv.Atoi(tmp[j])
				pol[i][j] = nb
			}
		}
		loop(pol)
		os.Exit(0)
	} else if len(os.Args[1:]) == 1 {
		if os.Args[1] == "-h" {
			disp()
			os.Exit(0)
		} else {
			os.Exit(84)
		}
	} else {
		os.Exit(84)
	}
}
