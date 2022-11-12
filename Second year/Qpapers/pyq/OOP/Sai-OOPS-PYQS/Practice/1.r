# roll d dice; find P(total = k)
23 probtotk <- function(d,k,nreps) {
4 count <- 0
5 # do the experiment nreps times -- like doing nreps notebook lines
6 for (rep in 1:nreps) {
7 sum <- 0
8 # roll d dice and find their sum
9 for (j in 1:d) sum <- sum + roll()
10 if (sum == k) count <- count + 1
11 }
12 return(count/nreps)
13 }
14
15 # simulate roll of one die; the possible return values are 1,2,3,4,5,6,
16 # all equally likely
17 roll <- function() return(sample(1:6,1))
18
19 # example
20 probtotk(3,8,1000)