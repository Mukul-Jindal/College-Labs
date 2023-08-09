6+5

#Normal arithmetic
x<-15
x-1
5*x->x

#vector 
x<-c(1,2,3)
x
x^2

#Sequence commands
1:10
seq(from=1,to=30,by=5)
seq(1,30,5)

#Repeating the number
rep(3,5)
rep(3:5,each=2)

#creating a vector
y<-c(5,9,2,14,15)
y[2]
y[2:4]

z<-c("hello","meeting") #use double inverted commas for Strings/char
z

#matrix
matrix(1:12,nrow = 3,ncol = 4,byrow = TRUE)
diag(4)
diag(1:3,4)

#ai * aj multiplication
1:5 %o% 1:5
A<-matrix(c(1:8,10),3,3)
A
x<-c(1,2,3)
x

A%*%x # matrix multiplication
t(A) #transpose
det(A) # determinant
diag(A) # diagonal
solve(A) # inverse