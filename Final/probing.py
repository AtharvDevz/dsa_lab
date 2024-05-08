countL = 0
countQ = 0

# Hashing function
def hashFun(phoneNO):
    # fold technique
    sum = 0
    for i in range(0, len(phoneNO), 3):
        sum = sum + int(phoneNO[i:i+3])
    return sum%10

def linearProbe(index, size):
    global countL
    for i in range(1, size-1):
        newIndex = (index + i) % size
        if(liP[newIndex] == -1):
            return newIndex
        countL += 1
    print("hashtable is full")


def quadraticProbe(index, size):
    global countQ
    for i in range(1, (size//2)+1):
        newIndex = (index + i**2)% size
        if(qP[newIndex] == -1):
            return newIndex
        i += 1
        countQ += 1
    print("HashTable is Full")

liP = [-1]*10
qP = [-1]*10
print(liP)
print(qP)
# size = int(input("Enter Number of Phone NO : "))

x= ['976567088', '950364098', '801083065', '567976088', '364098950', '976088567']
print(x)


print("Linear Probe")
for i in x:
    number = i
    index = hashFun(number)
    if(liP[index] != -1):
        newIndex = linearProbe(index, 10)
        print("newIndex : ", newIndex)
        liP[newIndex] = number
    else:
        liP[index] = number
        
print(liP)
print(countL)

print("Quadratic Probe")
for i in x:
    number = i
    index = hashFun(number)
    if(qP[index] != -1):
        newIndex = quadraticProbe(index, 10)
        print("newIndex : ", newIndex)
        qP[newIndex] = number
    else:
        qP[index] = number
        
print(qP)
print(countQ)
