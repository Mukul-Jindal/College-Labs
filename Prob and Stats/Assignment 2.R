# Q1 A
matrix<-c(rep("gold",20),rep("silver",30),rep("bronze",50))
sample(matrix,10)

# Q1 B
sample(c("succ","fail"),replace = TRUE,size = 10,prob = c(0.9,0.1))

# Q3
probability<-function(a,b,c){
  ans<-(a*c)/b
  return (ans)
}
rain = 0.2
cloudy = 0.4
cloudyGivenRainy = 0.85
print(probability(rain,cloudy,cloudyGivenRainy))

# Q4
data("iris")
head(iris)
structure(iris)
str(iris)
range(iris$Sepal.Length)
mean(iris$Sepal.Length)
median(iris$Sepal.Length)
quantile(iris$Sepal.Length,probs = c(0.25,0.75))
sd(x = iris$Sepal.Length)
var(iris$Sepal.Length)

range(iris$Sepal.Width)
mean(iris$Sepal.Width)
median(iris$Sepal.Width)
quantile(iris$Sepal.Width,probs = c(0.25,0.75))
sd(x = iris$Sepal.Width)
var(iris$Sepal.Width)

range(iris$Petal.Length)
mean(iris$Petal.Length)
median(iris$Petal.Length)
quantile(iris$Petal.Length,probs = c(0.25,0.75))
sd(x = iris$Petal.Length)
var(iris$Petal.Length)

range(iris$Petal.Width)
mean(iris$Petal.Width)
median(iris$Petal.Width)
quantile(iris$Petal.Width,probs = c(0.25,0.75))
sd(x = iris$Petal.Width)
var(iris$Petal.Width)
summary(iris)

lapply(iris[,1:4], sd)
