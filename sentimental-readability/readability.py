# TODO

h = input("Enter the text:")

l = 0
v = 1
s = 0

i = 0

for i in range(len(h)):
    if str.isalpha(h[i]):
        l = l + 1

    elif h[i] == " ":
        v = v + 1

    elif h[i] == "." or h[i] == "?" or h[i] == "!":
        s = s + 1

L = 100 * (l / v)
S = 100 * (s / v)

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print(f"Grade", {index})
