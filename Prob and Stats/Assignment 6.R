#install.packages("pracman")
library('pracma')

#Q1 A
f <- function(x,y){ 2*(2*x+3*y)/5}
i = integral2(f,xmin = 0,xmax = 1,ymin = 0,ymax = 1)
i$Q

#Q1 B

gx= function(y){f(1,y)}
gxi = integral(gx,xmin = 0,xmax = 1)
gxi

#Q1 C

hy = function(x){f(x,0)}
hyi = integral(hy,xmin = 0,xmax = 1)
hyi

#Q1 D

gxy = function(x,y){x*y*f(x,y)}
gxyi = integral2(gxy,xmin = 0,xmax = 1,ymin = 0,ymax = 1)
gxyi$Q


#Q2 
f = function(x,y){(x+y)/30}
x= c(0:3)
y=c(0:2)

#A
m = matrix(c(f(0,0:2),f(1,0:2),f(2,0:2),f(3,0:2)),nrow = 4,ncol = 3,byrow = TRUE)
m

#B
ans = sum(m)
if(ans == 1){
  print("JMF")
} else
{
  print("Not JMF")
}

#c
marginalx = apply(m,MARGIN = 1,FUN = sum)
marginalx

#d
marginaly = apply(m,MARGIN = 2,FUN = sum)
marginaly

#e
m[1,2]/marginaly[2]

#f
ex = sum(x*marginalx)
ex
ey = sum(y*marginaly)
ey

exx = sum(x*x*marginalx)
variancex = exx - ex**2
variancex

eyy = sum(y*y*marginaly)
variancey = eyy - ey**2
variancey


exy = sum(x*y*f(x,y))
exy

covXY = exy - (ex*ey)
covXY

corCoeff = covXY/sqrt(variancex*variancey)
corCoeff