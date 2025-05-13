#rotate array
def rotate(nums, k):
    n = len(nums)
    k %= n  # Handle cases where k > n
    
    def reverse(start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start + 1, end - 1
    
    reverse(0, n - 1)       # Reverse entire array
    reverse(0, k - 1)       # Reverse first k elements
    reverse(k, n - 1)       # Reverse remaining elements

# Example usage
nums = [1, 2, 3, 4, 5, 6, 7]
rotate(nums, 3)
print(nums)  # Output: [5, 6, 7, 1, 2, 3, 4]
