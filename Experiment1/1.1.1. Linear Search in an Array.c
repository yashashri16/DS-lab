//Type your content h
#include<stdio.h>
int main() {
    int n, key;
    
    // Read array size
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read search key
    scanf("%d", &key);
    
    // Linear search
    int found = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = i;
            break;
        }
    }
    
    // Output result
    if(found != -1) {
        printf("found at position %d\n", found);
    } else {
        printf("%d not found\n", key);
    }
    
    return 0;
}
