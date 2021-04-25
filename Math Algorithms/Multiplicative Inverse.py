def gcd(a,b):       #Chalculates the gcd opf 2 numbers
    if(a==0):
        return b
    elif(a<b):
        return 0
    else:
        rem=1
        while(rem!=0):
            rem=a%b
            if(rem!=0):
                a=b
                b=rem
            else:
                return b
                break

def congruence(a,b,m):      #Checks the congruency 
    if((a-b)%m==0):
        return True
    else:
        return False

def mul_inverse(a,m):       #uses the linear congruenge formula
    for i in range(1,m):    #multiplicate inverse has to be between 0 & m-1
        if(congruence(a*i,1,m)):        #Finds MI
            print("Multiplicative Inverse: ",i)

print("\n\t----Modulo Multiplicative Inverse----\n")
a=int(input("Enter the number: "))
m=int(input("Enter the modulo: "))


if(gcd(m,a)!=1):        #When both the numbers are not co-prime
    print("Multiplicative Inverse does not exist")
else:
    mul_inverse(a,m)


