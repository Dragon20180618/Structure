class Stack(object):
    def __init__(self):
        self.item=[]
    def push(self,value):
        self.item.append(value)
    def pop(self):
        return self.item.pop()
    def peek(self):
        return self.item[-1]
    def isEmpty(self):
        if self.item==[]:
            return True
        else:
            return False
def main():
    a="{()[](}"
    left="{(["
    right="})]"
    stack=Stack()
    Truth=True
    for i in a:
        if i in left:
            stack.push(i)
        else:
            if left.index(stack.peek())==right.index(i):
                stack.pop()
            else:
                Truth=False
    if stack.isEmpty()==False:
        Truth=False
    print(Truth)
# main()