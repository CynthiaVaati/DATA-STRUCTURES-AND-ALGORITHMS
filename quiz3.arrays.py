def contains_duplicate(nums):
    seen = set()
    
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    
    return False

# Example usage
nums = [1, 2, 3, 4, 1]
print(contains_duplicate(nums))  # Output: True

nums = [1, 2, 3, 4, 5]
print(contains_duplicate(nums))  # Output: False
