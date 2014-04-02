%% Position Jump Process I
M=50;
L=5;
h=L/M;
x=linspace(0,L,M);
t=0;
dt=0.0001;
N=zeros(1,M);
N(11)=75000;
N(21)=25000;

for i=1:M
    x(i)=(2*i-1)*h/2;
end

while t < 1+dt
    for j=1:100000
    for i=1:M
       if N(i) > 0
            a=rand(1,1);
            if and(a >= 0.80, i == 1)
                N(i)=N(i)-1;
            end
            if a >= 0.98
                b=rand(1,1);
                if and(b <= 0.5, i < 50)
                    N(i)=N(i)-1;
                     N(i+1)=N(i+1)+1;
                end
                if and(b > 0.5, i > 1)
                    N(i)=N(i)-1;
                    N(i-1)=N(i-1)+1;
                end
            end
       end       
    end
    end
    t=t+dt;
end


figure,
bar(x,N),




