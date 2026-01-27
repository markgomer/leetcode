package main

import "fmt"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	isIt := true
	sTable := make(map[rune]int)
	tTable := make(map[rune]int)

	// count ocurrences
    for _, c := range s {
		sTable[c]++
    }
	for _, c := range t {
		tTable[c]++
	}
	for _, c := range s {
		if sTable[c] != tTable[c] {
			isIt = false
			break
		}
	}
	return isIt
}

func main() {
	var isTrue bool;
    isTrue = isAnagram("racecar", "carrace");
	if isTrue {
		fmt.Println("CORRECT")
	} else {
		fmt.Println("WRONG")
	}
    isTrue = isAnagram("jar", "jam");
	if isTrue {
		fmt.Println("WRONG")
	} else {
		fmt.Println("CORRECT")
	}
}
