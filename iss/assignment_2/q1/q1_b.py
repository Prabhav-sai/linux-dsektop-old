from q1.q1_a import no_of_it,n,pseudo_rand_num_gen
import random
import matplotlib.pyplot as plt

def get_pi(x,y,a):
    points_in_circle = 0
    for i in range((a//2)):
        if x[i]*x[i]+y[i]*y[i]<1 :
            points_in_circle +=1

    prob = points_in_circle/(a//2)

    pi = 4*prob

    return pi

def my_code(no):
    no = 5
    for i in range(no):
        histo_randomnumbers = pseudo_rand_num_gen(n,no_of_it)

    a = len(histo_randomnumbers)

    x = [(histo_randomnumbers[num*2]*2)-1 for num in range(a//2)]
    y = [(histo_randomnumbers[num*2+1]*2)-1 for num in range(a//2)]

    return get_pi(x,y,a)

def computer_code(a):
    x = [random.uniform(-1,1) for i in range(a//2)]
    y = [random.uniform(-1,1) for i in range(a//2)]

    return get_pi(x,y,a)
def run():
    print(my_code(10))
    print(computer_code(1000))

run()


