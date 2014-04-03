%% Second Test of the Jump Process I
M = 50;
L = 5;
h = L/M;
x = linspace(0,L,M);
N = zeros(1,M);
N(11) = 75000;
N(21) = 25000;
j=1;

for t = 1:10000
    for i = 1:M
       if N(i) >0
           j = 1;
           aux = N(i);
          while j < aux + 1
             a = rand(1,1);
             if and(i == 1, a >= 0.8)
                N(i) = N(i) - 1; 
             end
             if and(a >= 0.98, i > 1)
                b = rand(1,1);
                if and(b <= 0.5, i < M)
                   N(i) = N(i) - 1;
                   N(i+1) = N(i+1) +1;
                end
                if b > 0.5
                   N(i) = N(i) - 1;
                   N(i-1) = N(i-1) + 1;
                end
             end
             j = j + 1;
          end
       end
    end
end

figure,
bar(x,N)