"""number converter program"""

binaryNum = input("Enter a binary string: ")
decimalNum = 0
exponent = len(binaryNum) - 1
for digit in binaryNum:
    #if digit == '0' or digit == '1':
    decimalNum += int(digit) * 2 ** exponent
    exponent -= 1
    #else:
    #    print("Error: The string contains non binary digits")
    #    break
print("%0s in decimal is %0d" %(binaryNum,decimalNum))

while len(binaryNum) % 4 != 0:
    binaryNum = "0" + binaryNum

for group in range(0, len(binaryNum),4):
    something = binaryNum[group:group+4]
    print(something)

decimalNum = input("Enter a decimal: ")
originalNum = decimalNum

decimalParts = decimalNum.split('.')
if decimalParts[0].isdigit() and decimalParts[-1].isdigit():
    decimalNum = int(decimalParts[0])
    fractionPart = float("." + decimalParts[-1])
    binaryNum = ""
    if decimalNum == 0:
        binaryNum = "0"
    else:
        while decimalNum > 0:
            remainder = decimalNum % 2
            decimalNum = decimalNum // 2
            binaryNum = str(remainder) + binaryNum
    binaryNum += "."
    for digits in range(0,16):
        x = fractionPart * 2
        parts = str(x).split('.')
        binaryNum += parts[0]
        fractionPart = float("." + parts[1])
        if fractionPart == 0:
            break


    print("%0s in binary is %0s" %(originalNum,binaryNum))

hexNum = input("Enter a hexadecimal number: ")
binaryNum = ""

for digit in hexNum:
    if digit == '0':
        binaryNum += "0000"
    elif digit == '1':
        binaryNum += "0001"
    elif digit == '2':
        binaryNum += "0010"
    elif digit == '3':
        binaryNum += "0011"
    elif digit == '4':
        binaryNum += "0100"
    elif digit == '5':
        binaryNum += "0101"
    elif digit == '6':
        binaryNum += "0110"
    elif digit == '7':
        binaryNum += "0111"
    elif digit == '8':
        binaryNum += "1000"
    elif digit == '9':
        binaryNum += "1001"
    elif digit in ['A','a']:
        binaryNum += "1010"
    elif digit in['B','b']:
        binaryNum += "1011"
    elif digit in ['C','c']:
        binaryNum += "1100"
    elif digit in ['D','d']:
        binaryNum += "1101"
    elif digit in ['E','e']:
        binaryNum += "1110"
    elif digit in ['F','f']:
        binaryNum += "1111"
    else:
        print("Error: The string contains non hexadecimal digits")
        break
print("%0s in binary is %0s" %(hexNum,binaryNum))