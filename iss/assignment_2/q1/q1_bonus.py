from q1.q1_b import my_code,computer_code
import matplotlib.pyplot as plt

def positive(n):
    if n <0:
        return -n
    else:
        return n


my_pi = [my_code(10) for i in range(10)]
random_pi = [computer_code(100) for i in range(10)]
pi = 3.14159

my_error = [positive((my_pi[i]-pi)/pi) for i in range(10)]
random_error = [positive((random_pi[i]-pi)/pi) for i in range(10)]

x = [i for i in range(1,11)]

plt.figure(figsize=(10, 6))
plt.plot(x, my_error,color='blue',label='My error', marker='o', linestyle='-')
plt.plot(x, random_error,color='red',label='random error', marker='o', linestyle='-')
plt.xlabel('Attempt no')
plt.ylabel('error')
plt.title('error estimation graph')
plt.xticks(x)
plt.grid(True)
plt.show()


