# # Q1
# prob7=dbinom(x = 7,prob = 1/6,size = 12)
# prob7
# prob8=dbinom(x = 8,prob = 1/6,size = 12)
# prob8
# prob9=dbinom(x = 9,prob = 1/6,size = 12)
# prob9
# prob7_9=pbinom(size = 12,prob = 1/6,q = 9)-pbinom(size = 12,prob = 1/6,q = 6)
# prob7_9

# #Q2
# percentGreaterThanX=pnorm(q = 84,mean = 72,sd = 15.2,lower.tail = FALSE)
# percentGreaterThanX

# # Q3
# lambda = 5
# probInOneHour = ppois(lambda = lambda,q = 0)
# probInOneHour
# lambda = lambda * 10 
# ans = ppois(q = 50,lambda = lambda) - ppois(q = 47,lambda = lambda)
# ans

# # Q4
# numberOfProcessors = 250
# x=dhyper(3,n = 17,m = 233,k = 5)
# print(x)

# # Q5
x = seq(0, 31)
pmf=dbinom(x,31,0.447)
plot(x,pmf)
cdf = pbinom(x,31,0.447)
plot(x, cdf)
print(mean(x))
print(var(x))
print(sd(x))
