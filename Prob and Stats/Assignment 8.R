data = read.csv('./Clt-data.csv')
dim(data)
head(data,10)
dataMean=mean(data$Wall.Thickness)
hist(data$Wall.Thickness,xlab = 'X- Axis')
abline(v = dataMean, col = 'red' )


store = c ()
n=9000
for (i in 1:n)
  store[i] = mean(sample(data$Wall.Thickness,10,replace = TRUE))
hist(store,col='red')
abline(v=mean(store),col = 'blue')


store = c ()
n=9000
for (i in 1:n)
  store[i] = mean(sample(data$Wall.Thickness,50,replace = TRUE))
hist(store,col='red')
abline(v=mean(store),col = 'blue')


store = c ()
n=9000
for (i in 1:n)
  store[i] = mean(sample(data$Wall.Thickness,500,replace = TRUE))
hist(store,col='red')
abline(v=mean(store),col = 'blue')


store = c ()
n=9000
for (i in 1:n)
  store[i] = mean(sample(data$Wall.Thickness,9000,replace = TRUE))
hist(store,col='red')
abline(v=mean(store),col = 'blue')