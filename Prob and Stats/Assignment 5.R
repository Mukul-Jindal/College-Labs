#Q1 A

a = 1-punif(45,0,60)
a

#Q1 B
b = punif(30,0,60) - punif(19,0,60)
b

#Q2 A
a = dexp(x = 3,rate = 1/2)
a
#Q2 B
x<- seq(0,5,0.04)
x
y<- dexp(x,1/2)
plot(x = x,y = y)
#Q2 C
c = pexp(q = 3,rate = 1/2)
c
#Q2 D
y<-pexp(q = x,rate = 1/2)
plot(x,y)
#Q2 E
n=1000
sim = rexp(n,1/2)
plot(density(sim))

#Q3 A
alpha = 2
beta = 1/3
a=pgamma(1,shape = alpha, scale=beta,lower.tail = FALSE)
a
b= qgamma(0.70,shape=alpha,scale = beta)
b