from bracketsCheck import Stack
def infixToPostfix(infixexpr):
    prec={}
    prec["*"]=3
    prec["/"]=3
    prec["+"]=2
    prec["-"]=2
    prec["("]=1
    op="*-/+()"
    opStack=Stack()#操作符栈
    postfixList=[]#输出到此列表
    for token in infixexpr:
        if token not in op:
            postfixList.append(token)#操作数可以直接输出。次序不变
        elif token =='(':
            opStack.push(token)
        elif token ==')':
            token=opStack.pop()
            while token!='(':#开始回溯
                postfixList.append(token) 
                token=opStack.pop()
        else:
            #下方用while时，会将前面合适的操作全部输出，
                #到最后while时，最多有一个+或-操作
            #如果下方用if, 只会输出一个合适的操作，
                #则两个以上*或/连在一起时，会留存前面的+或-
                #在最后输出所有的+-
            #由于它们的高优先级，存在于操作符中间的*/永远不会被留存
            while (not opStack.isEmpty()) and\
                (prec[opStack.peek()]>=prec[token]):
                postfixList.append(opStack.pop())
            opStack.push(token)#留存
    while not opStack.isEmpty():
        postfixList.append(opStack.pop())#输出剩下的+-
    print(postfixList)

#test="(A+B)*(C+D)"
test="(A+B)+C*b/C+A+(A+B)+C*b/C+A"
infixToPostfix(test)