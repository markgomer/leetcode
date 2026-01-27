// func hasDuplicate(nums []int) bool {
//     seen := make(map[int]bool)
//     for _, num := range nums {
//         if seen[num] == true {
//             return true
//         }
//         seen[num] = true
//     }
//     return false
// }

#include <stdio.h>
struct Check
{
    int num;
    int exists;
};

int
hasDuplicate(int nums[], int size)
{
    printf("size: %d\n\n",size);

    struct Check check = {
        .num = 0, .exists = 0
    };
    struct Check c[size];
    for (int i = 0; i < size; i++)
    {
        c[i] = check ;
        printf("num: %d\n\n", c[i].num);
    }

    return 0;
}


int
main(int argc, char *argv[])
{
    int arr[] = {1,2,3,4};
    hasDuplicate(arr, 4);
}
