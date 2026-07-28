def add(a, b):
    print("Addition of 2 numbers is", a + b)

def sub(a, b):
    print("Subtraction of 2 numbers is", a - b)

def mul(a, b):
    print("Multiplication of 2 numbers is", a * b)

def div(a, b):
    if b != 0:
        print("Division is", a / b)
    else:
        print("Number cannot be divided by 0")

def mod(a, b):
    if b != 0:
        print("Modulus is", a % b)
    else:
        print("Number cannot be divided by 0")


a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

while True:
    print("\n1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Modulus")
    print("6. Exit")

    ch = int(input("Enter your choice: "))

    if ch == 1:
        add(a, b)

    elif ch == 2:
        sub(a, b)

    elif ch == 3:
        mul(a, b)

    elif ch == 4:
        div(a, b)

    elif ch == 5:
        mod(a, b)

    elif ch == 6:
        print("Exiting...")
        break

    else:
        print("Invalid Choice")