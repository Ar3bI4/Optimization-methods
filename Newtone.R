func = function(x1,x2) { sqrt(x1^2 + 2*x2^2 + 1) + 0.5*x1 - 0.5*x2}
fprx = function(x1,x2) { x1/sqrt(x1^2 + 2*x2^2 + 1) + 0.5}
fpry = function(x1,x2) { 2*x2/sqrt(x1^2 + 2*x2^2 + 1) - 0.5}
fprxx = function(x1,x2) {(2*x2^2+1)/(x1^2 + 2*x2^2 + 1)^(3/2)}
fprxy = function(x1,x2) { -(2*x1*x2)/(x1^2 + 2*x2^2 + 1)^(3/2)}
fpryx = function(x1,x2) { -(2*x2*x1)/(x1^2 + 2*x2^2 + 1)^(3/2)}
fpryy = function(x1,x2) {(2*x1^2+2)/(x1^2 + 2*x2^2 + 1)^(3/2)}
norm = function(x1,x2) {sqrt((fprx(x[1,1],x[2,1])^2)+(fpry(x[1,1],x[2,1])^2))}
e = 0.0000000001
x = rbind(c(0.59),c(0.59))
print(norm(x[1,1],x[2,1]))
i= 0
while (norm(x[1,1],x[2,1]) > e) {
  #Hesse = rbind (c (fprxx(x[1,1],x[2,1]),fprxy(x[1,1],x[2,1])),c(fpryx(x[1,1],x[2,1]),fpryy(x[1,1],x[2,1])))
  Hesset = rbind (c(fpryy(x[1,1],x[2,1]), (-1)*fpryx(x[1,1],x[2,1])), c((-1)*fprxy(x[1,1],x[2,1]), fprxx(x[1,1],x[2,1])))
  hesse = (1/(fprxx(x[1,1],x[2,1])*fpryy(x[1,1],x[2,1]) - fpryx(x[1,1],x[2,1])*fprxy(x[1,1],x[2,1]))) * Hesset
  #hesse = solve(Hesse)
  grad = rbind (c(fprx(x[1,1],x[2,1])),c(fpry(x[1,1],x[2,1])))
  x = x - (hesse%*%grad)
  i = i+1 }
round(i,0)
#v <- c(
round(x,-log10(e))
round(func(x[1,1],x[2,1]),-log10(e))
round(norm(x[1,1],x[2,1]),-log10(e))