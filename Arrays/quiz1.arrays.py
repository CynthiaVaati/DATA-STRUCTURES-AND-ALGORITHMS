def remove_duplicates(nums):
    if not nums:
        return 0
    
    i = 0  # Slow pointer
    
    for j in range(1, len(nums)):  # Fast pointer
        if nums[j] != nums[i]:  # Encounter a new unique element
            i += 1
            nums[i] = nums[j]
    
    return i + 1  # Length of unique elements

# Example usage
nums = [1, 1, 2, 2, 3, 4, 4]
length = remove_duplicates(nums)
print(length, nums[:length])  # Output: 4, [1, 2, 3, 4]
