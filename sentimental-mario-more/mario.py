from cs50 import get_int

while True:
    height = get_int("Enter the height: ")
    if height > 0 and height < 9:
        break
for row in range(height):
    for space in range(height - row - 1, 0, -1):
        print(" ", end="")
    for hash in range(row + 1):
        print("#", end="")
    print("  ", end="")
    for right_hash in range(row + 1):
        print("#", end="")
    print("\n", end="")
