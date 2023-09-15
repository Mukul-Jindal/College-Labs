# Q1
c <- seq(from = 5, to = 30, by = 5)
c
min(c)
max(c)
print(paste("max value:", max(c)))
print(paste("min value:", min(c)))

# Q2
fac <- as.integer(readline(prompt = "Enter a number: "))
factorial <- 1
if (fac < 0) {
  print(paste("error"))
} else if (fac == 0) {
  print("Factorial of 0 is 1")
} else {
  for (i in 1:fac)
  {
    factorial <- factorial * i
  }
  print(paste("Factorial of ", fac, " is ", factorial))
}

# Q3
number <- as.integer(readline(prompt = "Enter a number"))
n1 <- 1
n2 <- 1
count <- 1
if (number <= 0) {
  print("Enter a positive number")
} else if (number == 1) {
  print("Seq:")
  print(n1)
} else {
  print("fibonacci seq:")
  print(n1)
  print(n2)
  while (count < number) {
    nth <- n1 + n2
    print(nth)
    n1 <- n2
    n2 <- nth
    count <- count + 1
  }
}

# Q4
number1 <- as.integer(readline(prompt = "Enter 1st number: "))
number2 <- as.integer(readline(prompt = "Enter 2nd number: "))
operator <- as.character(readline(prompt = "Enter the operator: "))
if (operator == "+") {
  print(paste(number1, operator, number2, "=", number1 + number2, sep = " "))
} else if (operator == "-") {
  print(paste(number1, operator, number2, "=", number1 - number2, sep = " "))
} else if (operator == "*") {
  print(paste(number1, operator, number2, "=", number1 * number2, sep = " "))
} else {
  print(paste(number1, operator, number2, "=", number1 / number2, sep = " "))
}

# Q5
# Exploring Plot
x <- seq(from = 1, to = 5, by = 1)
y <- seq(from = 1, to = 15, by = 3)
plot(x, y)
plot(x, y, type = "l")
plot(x, y, type = "l", main = "Exploring plot", xlab = "X-axis", ylab = "Y-axis")
plot(x, y, cex = 2)
plot(x, y, pch = 10)

# Exploring Pie
x <- c(10, 20, 30, 40)
mylabel <- c("Apples", "Bananas", "Cherries", "Dates")
colors <- c("blue", "yellow", "green", "black")
pie(x)
pie(x, init.angle = 90)
pie(x, labels = mylabel, main = "Fruits")
pie(x, labels = mylabel, main = "Fruits", col = colors)
legend("bottomright", mylabel, fill = colors)

# Exploring barplot
x <- c("A", "B", "C", "D")
y <- c(2, 4, 6, 8)
barwidth <- c(1, 2, 3, 4)
barplot(y, names.arg = x)
barplot(y, names.arg = x, col = "red")
barplot(y, names.arg = x, density = 10)
barplot(y, names.arg = x, col = "red", width = barwidth)
barplot(y, names.arg = x, col = "red", width = barwidth, horiz = TRUE)
