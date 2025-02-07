package main

import "fmt"

func binarySearch(arr []int, target int) int  {
	left, right := 0, len(arr)-1
	for left <= right {
		mid := (left+right) / 2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1 
}

func main()  {
	arr := []int{1, 3, 5, 7, 9}
	fmt.Println(binarySearch(arr, 7))  // 3 
}
