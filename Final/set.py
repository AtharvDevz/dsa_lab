x=[4, 7, 8, 9, 0]
y=[4, 6, 2, 0]
z = [4, 7, 8]

def addElement(x, ele):
    if(ele in x):
        print("Element is there")
    else:
        x.append(ele)
        
def removeElement(x, ele):
    if(ele in x):
        x.remove(ele)
    else:
        print("element is not therer")
        
def unionSet(x, y):
    U = list(set(x) | set(y))
    return U

def intersectionSet(x, y):
    I = list(set(x) & set(y))
    return I

def differenceSet(x, y):
    l1 = x
    l2 = intersectionSet(x, y)
    D = set(l1) - set(l2)
    return D

def isSubset(x, y):
    if(set(x).issubset(set(y))):
        print("yes")
    else:
        print("no")
        
print("x = ", x)
print("y = ", y)
print("z = ", z)

addElement(x, 9)
addElement(x, 23)
addElement(x, 67)

removeElement(x, 9)

print("x = ", x)

print(unionSet(x, y))
print(intersectionSet(x, y))
print(differenceSet(x, y))

isSubset(x, y)
isSubset(z, x)
isSubset(x, z)