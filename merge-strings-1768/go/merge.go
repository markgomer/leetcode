package main


func mergeAlternately(word1 string, word2 string) string {
    mergedString := ""
    for i := 0; i < len(word1) || i < len(word2); i++ {
        if i < len(word1) {
            mergedString += string(word1[i])
        }
        if i < len(word2) {
            mergedString += string(word2[i])
        }
    }
    return mergedString
}
