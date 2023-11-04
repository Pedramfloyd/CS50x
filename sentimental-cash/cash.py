# TODO
from cs50 import get_float

dollars = get_float("How much?")

while dollars <= 0:
    dollars = get_float("How much? ")

cents = dollars * 100

quarter = 0
dim = 0
nickel = 0
penny = 0


while cents > 0:
    if cents >= 25:
        cents -= 25
        quarter += 1

    elif cents >= 10:
        cents -= 10
        dim += 1

    elif cents >= 5:
        cents -= 5
        nickel += 1

    else:
        cents -= 1
        penny += 1

coins = quarter + dim + nickel + penny

print(coins)
