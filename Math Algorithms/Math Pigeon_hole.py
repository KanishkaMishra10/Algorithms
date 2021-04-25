
print("---In Pigeonhole Principle there are three entities: The number of Pigeons, The \
Number of PigeonHoles , and The minimum number of Pigeons in one Pigeonhole.---\n")
print("\n\tWe have taken into consideration all the 3 Conditions as follows: \n")
print("What input do you want to give? ")
choice=int(input(" 1: Input Number of Pigeons and Pigeonholes \n \
2: Input Pigeonholes and Required number of pigeons in 1 pigeonhole \n \
3: Input Number of Pigeons and Required number of pigeons in 1 pigeonhole \n  "))

if(choice==1):
    pigeon=int(input("Enter the number of pigeons: "))
    holes=int(input("Enter the number of holes: "))
    if(pigeon>holes):
        req=((pigeon-1)/holes)+1        #Calculates minimum number of Pigeon in 1 Pigeonhole
        num=round(req)
        if(num<req):
            print("Minimum Number of  Pigeons in 1 Pigeonhole: ",num+1)
        else:
             print("Minimum Number of  Pigeons in 1 Pigeonhole: ",num)
    else:   
        print("Invalid!")
if(choice==2):
    pigeon_hole=int(input("Enter the number of Pigeonholes: "))
    req_pg=int(input("Enter the Minimum Number of  Pigeons in 1 Pigeonhole: "))
    pigeon=((req_pg-1)*pigeon_hole)+1           #Calculates total number of Pigeons
    print("Number of pigeons are: ",pigeon)
if(choice==3):
    pigeon=int(input("Enter the number of Pigeons: "))
    req=int(input("Minimum Number of  Pigeons in 1 Pigeonhole: "))
    pigeon_holes=(pigeon-1)/(req-1)         #Calculates total number of PigeonHoles
    print("Number of Pigeon Holes are: ",round(pigeon_holes))







