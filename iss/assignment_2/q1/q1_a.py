import time
import math
import matplotlib.pyplot as plt
# import sys
def get_seed(n):
    # t = time.localtime()
    # hours = str(t.tm_hour).rjust(2,'0')
    # minutes = str(t.tm_min).rjust(2,'0')
    # seconds = str(t.tm_sec).rjust(2,'0')
    milliseconds = str((time.time_ns())%(10**(n))).rjust(n,'0')

    seed = int(milliseconds)

    return seed

randomnumbers =[]
histo_randomnumbers = []

def countDigit(n): 
    if n==0 :
        return 0
    return math.floor(math.log10(n)+1)

# sys.setrecursionlimit(10000)

def pseudo_rand_num_generator(seed, k,n):
    if(k==0):
        return
    strseed = str(seed)
    if(len(strseed)%2==1):
        strseed = '0'+str(seed)
    length = len(strseed)
    start = (length//2) - n//2
    seed = int(strseed[start:start+n])
    randomnumbers.append(seed)
    pseudo_rand_num_generator(seed*seed,k-1,n)
    return

# print(seed[(len(seed)-6)//2:(len(seed)-6)+6])
# print(countDigit(seed))

# print(countDigit(999999*999999))

def print_n_plot():
    print(randomnumbers)
    print(histo_randomnumbers)

    plt.hist(histo_randomnumbers)

    plt.show()
    return


def pseudo_rand_num_gen(n,no_of_it):


    seed = get_seed(n)

    # print(seed)

    # n = 6 # n = no of digits in the seed
    # no_of_it = 50 # no of iterations/ random numbers you want must be even

    pseudo_rand_num_generator(seed,no_of_it,n)

    for num in randomnumbers:
        histo_randomnumbers.append(float(num/pow(10,countDigit(num))))

    print_n_plot()

    return histo_randomnumbers

n = 18
no_of_it = 50
pseudo_rand_num_gen(n,no_of_it)

# print_n_plot()

