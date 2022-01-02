import math

state = 0


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def speak(self):
        print("My name is ", self.name)


p1 = Person("John", 36)


def my_function(x, y):
    return x+y


def check_state(c):
    global state

    if c > 0:
        state = 1
    else:
        state = 0


def main():
    # this is a comment
    
    a = 3
    b = 4
    c = my_function(a, b)
    check_state(c)

    print("c: ", c)
    print("state: ", state)

    p1 = Person("John", 20)
    p1.speak()


if __name__ == '__main__':
    main()
