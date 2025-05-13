def main():
    # Get the number of elements from the user
    n = int(input("Enter the number of elements: "))

    if n <= 0:
        print("Invalid input. The array must have at least one element.")
        return

    arr = []
    sum_elements = 0
    max_element = float('-inf')  # Initialize to negative infinity

    # Get the array elements from the user and compute sum & max in one loop
    print("Enter {n} integers:")
    for _ in range(n):
        num = int(input())
        arr.append(num)
        sum_elements += num  # Compute sum
        if num > max_element:  # Compute max
            max_element = num

    # Display the results
    print(f"Sum of elements: {sum_elements}")
    print(f"Maximum element: {max_element}")

# Run the main function
if __name__ == "__main__":
    main()
