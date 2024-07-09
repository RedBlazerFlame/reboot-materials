from random import randint
from os import system

def randtcase():
    n = randint(1, 1000)
    x = randint(1, n)

    a = list(map(lambda x: randint(1, 10 ** 9), range(n)))

    tcase = []
    tcase.append(str(n))
    tcase.append(" ")
    tcase.append(str(x))
    tcase.append("\n")
    tcase.append(" ".join(map(str, a)))

    return "".join(tcase)

system("g++ -o meansummain meansummain.cpp")
system("g++ -o meansumbrute meansumbrute.cpp")

for i in range(1000):
    with open("meansumtest/test.in", "w+") as f:
        f.write(randtcase())
    
    system('./meansummain <"meansumtest/test.in" >"meansumtest/test-main.out"')
    system('./meansumbrute <"meansumtest/test.in" >"meansumtest/test-brute.out"')

    with open("meansumtest/test-brute.out", "r+") as f1, open("meansumtest/test-main.out", "r+") as f2:
        if(f1.read() != f2.read()):
            print("FAILED")
            exit(1)