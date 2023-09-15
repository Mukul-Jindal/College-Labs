# Q1
x=c(0,1,2,3,4)
probX = c(0.41,0.37,0.16,0.05,0.01)
print(x[3])
expected_Value = sum(x*probX)
print(expected_Value)
expected_Value = weighted.mean(x = x,w = probX)
print(expected_Value)
expected_Value = c(x%*%probX)
print(expected_Value)


# Q2

express <- function (t){
    t*0.1*exp(-0.1*t)
}

integration123<- integrate(express,lower = 0,upper = Inf)
print(integration123$value)

# Q3
x = c(0,1,2,3)
probX = c(0.1,0.2,0.2,0.5)

y= 10 *x - 12 
expectedValue = sum(y * probX)
print(expectedValue)

# Q4
firstMoment1 <- function(t){t*0.5*exp(-1*abs(t))}
firstMoment2 <- function(t){t*t*0.5*exp(-1*abs(t))}
firstMoment <- integrate(firstMoment1,lower = 1,upper = 10)
secondMoment <- integrate(firstMoment2,lower = 1,upper = 10)
print(firstMoment$value)
print(secondMoment$value)

variance = secondMoment$value - (firstMoment$value*firstMoment$value)
print(variance)

# Q5
f<- function (y){(3/4)*(1/4)^(sqrt(y)-1)}
x<-3
y=x^2
p<- f(y)
print(p)

f<-function(y){(3/4)*(1/4)^ (sqrt(y)-1)}
x<-c(1,2,3,4,5)
y<-x^2
exp1 <- sum(y*f(y))
print(exp1)

exp2<-sum(y*y*f(y))
var<- exp2 - (exp1)^2
print(var)